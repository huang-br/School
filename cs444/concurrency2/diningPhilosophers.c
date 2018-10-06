#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

//philosopher struct
struct philosopher
{
	char* name;
	int pos;
	int eating;
	int thinking;
};

//Function Declarations
void think(char*);
void eat(char*);
int rightFork(int);
int leftFork(int);
void getForks(int);
void putForks(int);
void* dinner(void*);
int randomNumber(int, int);
void* printStatus();

//global variables for the semaphores and philosophers
sem_t forks[4];
struct philosopher p[4];

int main()
{
	//creating the fork semaphores
	sem_init(&forks[0], 0, 1);	
	sem_init(&forks[1], 0, 1);
	sem_init(&forks[2], 0, 1);
	sem_init(&forks[3], 0, 1);
	sem_init(&forks[4], 0, 1);
	
	//Creating threads for the Philosophers 
	pthread_t t0, t1, t2, t3, t4, t5;
	
	//Creating the Philosophers/Ninja Turtles
	struct philosopher Leo = {"Leo", 0, 0, 0,};
	struct philosopher Mikey = {"Mikey", 1, 0, 0,};
	struct philosopher Donnie = {"Donnie", 2, 0, 0,};
	struct philosopher Raph = {"Raph", 3, 0, 0,};
	struct philosopher Splinter = {"Splinter", 4, 0, 0,};
	
	//Assigning the ninja turtles to the array.
	p[0] = Leo;
	p[1] = Mikey;
	p[2] = Donnie;
	p[3] = Raph;
	p[4] = Splinter;
	
	//Creating the threads.
	pthread_create(&t0, NULL, dinner, &p[0]);
	pthread_create(&t1, NULL, dinner, &p[1]);
	pthread_create(&t2, NULL, dinner, &p[2]);
	pthread_create(&t3, NULL, dinner, &p[3]);
	pthread_create(&t4, NULL, dinner, &p[4]);
	pthread_create(&t5, NULL, printStatus, NULL);

	//Joining the threads.
	pthread_join(t0, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	pthread_join(t4, NULL);
	pthread_join(t5, NULL);

	return 0;
}

//Thinking. Waits a random amount of time between 1 and 20 seconds.
void think(char* name)
{
	int time = randomNumber(1,20);
	printf("%s is thinking for %d seconds.\n",name, time);
	sleep(time);
}

//Eating. Waits a random amount of time between 2 and 9 seconds.
void eat(char* name)
{
	int time = randomNumber(2,9);
	printf("%s is eating for %d seconds.\n", name, time);
	sleep(time);
}

int rightFork(int pos)
{
	return pos;
}

int leftFork(int pos)
{
	return ((pos + 1) % 5);
}

//Picking up the forks.
//Even seated philosophers use the left fork.
void getForks(int pos)
{
	//Picking the up the left fork first
	if(pos % 2 == 0)
	{
		sem_wait(&forks[leftFork(pos)]);
		printf("Fork %d is picked up.\n", leftFork(pos));
		sem_wait(&forks[rightFork(pos)]);
		printf("Fork %d is picked up.\n", rightFork(pos));
	}
	//Picking up the right fork first
	else
	{
		sem_wait(&forks[rightFork(pos)]);
		printf("Fork %d is picked up.\n", rightFork(pos));
		sem_wait(&forks[leftFork(pos)]);
		printf("Fork %d is picked up.\n", leftFork(pos));
	}


}

//Putting the forks back.
void putForks(int pos)
{
	sem_post(&forks[leftFork(pos)]);
	printf("Placed up fork %d down.\n", leftFork(pos));
	sem_post(&forks[rightFork(pos)]);
	printf("Placed up fork %d down.\n", rightFork(pos));
}

//The function for the main threads. This is where the philosophers eat and think.
void* dinner(void* P)
{
	struct philosopher* newPhilo = (struct philosopher*)P;
	char* name = newPhilo -> name;
	int pos = newPhilo -> pos;

	while(1)
	{
		newPhilo -> thinking = 1;
		think(name);
		newPhilo -> thinking = 0;
		getForks(newPhilo -> pos);
		newPhilo -> eating = 1;
		eat(name);
		newPhilo -> eating = 0;
		putForks(newPhilo -> pos);
	}

}

//Random Value Generator
int randomNumber(int min, int max)
{
	unsigned long randomNum;
	randomNum = 0.0;
	int range = (max - min + 1) + min;
	randomNum = genrand_int32();
	return randomNum % range;
}

//Printing Function
void* printStatus()
{
	while(1)
	{
		//system("clear");
		int i;
		int j;
		int semval;
		printf("************************************\n");
		printf("%-12s%-12s%-12s\n", "Name", "Eating", "Thinking");
		for(i=0;i<5;i++)
		{
			printf("%-12s%-12d%-12d\n", p[i].name, p[i].eating, p[i].thinking);
		}
		printf("************************************\n");
		printf("************************************\n");
		printf("%-12s%-12s\n","Fork Number", "Fork Status");
		for(j=0;j<5;j++)
		{
			sem_getvalue(&forks[j],&semval);
			printf("%-12d%-12d\n",j,semval);
		}
		printf("************************************\n");
		sleep(5);
	}
}








