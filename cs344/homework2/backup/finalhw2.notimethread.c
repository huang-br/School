#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define NUM_ROOMS 7
#define MAX_CONNECTIONS 6
#define TOTAL_ROOMS 10

/*creating the types of rooms*/
enum room_type
{
	START_ROOM,
	END_ROOM,
	MID_ROOM
};

/*Creating the rooms*/
struct room
{
	enum room_type type;
	const char *name;
	int numConnections;
	int maxConnections;
	int indexNum;
	struct room *connections[NUM_ROOMS];
};

/*Room Names*/
const char *roomNames[TOTAL_ROOMS] = 
{
	"Library",
	"Kitchen",
	"Greenhouse",
	"DiningHall",
	"Dormitory",
	"Labratory",
	"Courtyard",
	"Bathroom",
	"Hallway",
	"Storage"
};

/*Functions*/
void generateRooms(struct room roomList[]);	//Creates and initializes rooms as well as connects them.
int connectRooms(int, int, struct room[]);	//Connects the rooms.
int checkConnection(int, int, struct room[]);	//checking for valid room connections.
void printRooms(struct room[]);		//Made for debugging
void createRoomFiles(struct room[]);	//Creats a directory and then creates all the room files.
void game(struct room[]);	//Plays the game. Requires input.
int getInput(struct room);	//Checks the players input.


int main()
{
	srand(time(0));
	
	struct room rooms[NUM_ROOMS];
	generateRooms(rooms);
	
	//printRooms(rooms);
	createRoomFiles(rooms);

	game(rooms);

	return 0;
}

/*Functions*/

void generateRooms(struct room roomList[])
{
	int namesTaken[TOTAL_ROOMS];
	memset(namesTaken, 0, sizeof(namesTaken));
	int k=0;

	for(k=0; k < NUM_ROOMS; k++)
	{
		/*Assigning connections names*/
		roomList[k].numConnections = 0;
		roomList[k].maxConnections = 3 + rand() % (MAX_CONNECTIONS - 3);

		/*Assigning index numbers*/
		roomList[k].indexNum = k;

		/*Assigning room Names*/
		int notTaken = 1;
		while(notTaken == 1)
		{
			int roomIndex = rand()%TOTAL_ROOMS;
			if(namesTaken[roomIndex] == 0)
			{
				roomList[k].name = roomNames[roomIndex];
				namesTaken[roomIndex] = 1;
				notTaken = 0;
			}
		}

		/*Assigning room types*/
		if(k == 0)
		{
			roomList[0].type = START_ROOM;
		}
		else if(k == NUM_ROOMS - 1)
		{
			roomList[NUM_ROOMS - 1].type = END_ROOM;
		}
		else
		{
			roomList[k].type = MID_ROOM;
		}
	}

	//Connecting the rooms
	int i=0;
	for(i=0; i < NUM_ROOMS; i++)
	{
		int j;
		for(j=0; j < roomList[i].maxConnections; j++)
		{
			int randomRoom = rand() % NUM_ROOMS;
			if(connectRooms(i, randomRoom, roomList) == 0)
			{
				randomRoom = rand() % NUM_ROOMS;
				connectRooms(i, randomRoom, roomList);
			}
			
		}
	}
}

int connectRooms(int r1, int r2, struct room roomList[])
{
	struct room *room1 = &roomList[r1];
	struct room *room2 = &roomList[r2];

	//The rooms are already connected
	if(checkConnection(r1,r2,roomList) == 1)
	{
		return 0;
	}
	//Room alreay has all of its connections filled.
	else if(room1 -> numConnections == room1 -> maxConnections)
	{
		return 1;
	}
	//The room that we are trying to connect to has its connections filled.
	else if(room2 -> numConnections == room2 -> maxConnections)
	{
		return 0;
	}
	//The rooms are connecting to iteslf.
	else if(r1 == r2)
	{
		return 0;
	}
	//A good connection has been made.
	else
	{
		room1 -> connections[room1 -> numConnections] = room2;
		room2 -> connections[room2 -> numConnections] = room1;
		room1 -> numConnections++;
		room2 -> numConnections++;
		return 1;
	}
}

int checkConnection(int r1, int r2, struct room roomList[])
{
	struct room *room1 = &roomList[r1];
	struct room *room2 = &roomList[r2];
	
	//Checking it the room is already connected.
	int k=0;
	for(k=0; k < room1 -> numConnections; k++)
	{
		if(room1 -> connections[k] == room2)
		{
			return 1;
		}
	}
	return 0;
}

//debug tool
void printRooms(struct room roomList[])
{
	int k=0;
	for(k=0; k < NUM_ROOMS; k++)
	{
		printf("Name: %s\nNumber of Connections: %d\nMax connections: %d\nRoom Type: %d\n", roomList[k].name, roomList[k].numConnections, roomList[k].maxConnections, roomList[k].type);
		int j=0;
		printf("Connections:\n");
		for(j=0; j < roomList[k].numConnections; j++)
		{
			printf("%s\n",roomList[k].connections[j] -> name);
		}
		printf("\n");
	}
}
	
void createRoomFiles(struct room roomList[])
{
	//Making the directory.
	int newdir;
	pid_t pid = getpid();
	int id = pid;
	char name[30];
	sprintf(name, "huangbr.rooms.%d", id);
	newdir = mkdir(name, S_IRUSR | S_IWUSR |S_IXUSR | S_IRGRP | S_IWGRP | S_IXGRP | S_IROTH | S_IWOTH | S_IXOTH);

	//making the files
	chdir(name);

	int i=0;
	for(i=0; i < NUM_ROOMS; i++)
	{
		FILE *fp = fopen(roomList[i].name,"w+");
		fprintf(fp, "%s\n", "This is a test");
		fprintf(fp, "%s%s\n", "ROOM NAME:", roomList[i].name);
		int j;
		for(j=0; j < roomList[i].numConnections; j++)
		{
			fprintf(fp, "%s %d: %s\n", "CONNECTIONS:", j+1, roomList[i].connections[j] -> name);
		}
		if(roomList[i].type == START_ROOM)
		{
			fprintf(fp, "%s\n", "ROOM TYPE: START_ROOM");
		}
		else if(roomList[i].type == END_ROOM)
		{
			fprintf(fp, "%s\n", "ROOM TYPE: END_ROOM");
		}	
		if(roomList[i].type == MID_ROOM)
		{
			fprintf(fp, "%s\n", "ROOM TYPE: MID_ROOM");
		}
		fclose(fp);
	}
}

void game(struct room roomList[])
{
	//Starting the game.
	int next = getInput(roomList[0]);
	int done = roomList[next].type;

	//Creating the visited directory
	struct room *path = malloc(sizeof(struct room*) * NUM_ROOMS);
	int counter = 0;
	int capacity = NUM_ROOMS;
	path[counter] = roomList[next];

	//Continuing to play the game.
	while(done != 1)
	{
		//Getting the next move.
		next = getInput(roomList[next]);

		//Allocating more memory if needed.
		if(counter > NUM_ROOMS)
		{
			capacity = capacity * 2;
			path = realloc(path, capacity * sizeof(struct room*));
		}
		counter++;
		path[counter] = roomList[next];
		done = roomList[next].type;
	}

	//Adding the last move to path.
	counter++;
	path[counter] = roomList[next];

	//Wining messege.
	printf("YOU HAVE FOUND THE END ROOM. CONGRATULATIONS!\nYOU TOOK %d STEPS. YOUR PATH TO VICTORY WAS:\n",counter);
	int k;
	for(k=0; k < counter; k++)
	{
		printf("%s\n",path[k].name);
	}
}

int getInput(struct room curRoom)
{
	int goodInput = 0;
	char *input[50];
	int j;
	int compare;
	while(goodInput == 0)
	{
		printf("CURRENT LOCATION: %s\n", curRoom.name);
		int k;
		printf("POSSIBLE CONNECTIONS:");
		for(k=0; k < curRoom.numConnections; k++)
		{
			printf("%s ",curRoom.connections[k] -> name);
		}
		printf("\n");
		printf("WHERE TO? > ");	

		//Getting the input.
		scanf("%s",input);
		printf("\n");

		//Comparing the names. Produces a warning...not sure how to fix.
		for(j=0; j < curRoom.numConnections; j++)
		{
			compare = strcmp(input, curRoom.connections[j] -> name);
			if(compare == 0)
			{
				break;
			}
		}
		if(compare == 0)
		{
			int index = curRoom.connections[j] -> indexNum;
			return index;
		}
		else
		{
			printf("\n");
			printf("HUH? I DON'T UNDERSTAND THAT ROOM. TRY AGAIN.\n");
			printf("\n"); 
		}
	}
}
