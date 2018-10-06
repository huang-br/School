#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_THREADS 10
#define RANGE_MIN 1
#define RANGE_MAX 20
#define HAIRCUT_TIME 10
#define WAITING_ROOM_CHAIRS 5

pthread_t customers[NUM_THREADS];
pthread_t barber;

sem_t barberChair;
sem_t waitingChairs;
sem_t barberSleep;
sem_t haircut;


void get_hair_cut(int);
void cut_hair();
void* customer(); 
void* barberfunc();

int main(int argc, char *argv[])
{
	sem_init(&waitingChairs, 0, WAITING_ROOM_CHAIRS);
	sem_init(&barberChair, 0, 1);
	sem_init(&barberSleep, 0, 0);
	sem_init(&haircut, 0, 0);

	pthread_create(&barber, NULL, barberfunc, NULL);
	int i;
	for(i = 0; i < WAITING_ROOM_CHAIRS; i++)
	{
		pthread_create(&customers[i], NULL, customer, (void*)i);
	}

	pthread_join(barber, NULL);
	for(i = 0; i < WAITING_ROOM_CHAIRS; i++)
	{
		pthread_join(customers[i], NULL);
	}


	return 0;
}

void get_hair_cut(int ID)
{
	printf("Customer %d is getting a haircut for %d seconds.\n", ID, HAIRCUT_TIME);
	sleep(HAIRCUT_TIME);
	printf("Customer %d is done getting a haircut.\n", ID);
}

void cut_hair()
{
	printf("Barber is cutting hair for %d seconds.\n", HAIRCUT_TIME); 
	sleep(HAIRCUT_TIME);
	printf("Barber has finished cutting hair.\n");
}

void* customer(int ID)
{
	while(1)
	{
		//random customer appearance time.
		sleep(rand() % (RANGE_MAX + 1 - RANGE_MIN) + RANGE_MIN);

		int waitingRoom;
		int barber;
		sem_getvalue(&waitingChairs, &waitingRoom);
		sem_getvalue(&barberChair, &barber);
		if(waitingRoom == WAITING_ROOM_CHAIRS && barber == 1)
		{
			sem_post(&barberSleep);
			sem_wait(&barberChair);
			printf("Customer %d is waking up the barber.\n", ID);
		}
		else if(waitingRoom == 0)
		{
			printf("The waiting room is full, the customer is leaving.");
			return;
		}
		else
		{
			printf("Customer %d is waiting for a haircut.", ID);
			sem_wait(&waitingChairs);
			sem_wait(&barberChair);
		}
		sem_post(&haircut);
		get_hair_cut(ID);
	}
}

void* barberfunc()
{	
	while(1)
	{
		int barber;
		int waitingRoom;
		sem_getvalue(&barberChair, &barber);
		sem_getvalue(&waitingChairs, &waitingRoom);
		if(waitingRoom == WAITING_ROOM_CHAIRS && barber == 1)
		{
			printf("Barber is going to sleep.\n");
			sem_wait(&barberSleep);
			printf("Barber has woken up!\n");
		}
		sem_post(&barberChair);
		sem_wait(&haircut);
		cut_hair();
	}
}

