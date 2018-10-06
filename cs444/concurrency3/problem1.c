#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

#define NUM_THREADS 5
#define RANGE_MIN 0
#define RANGE_MAX 10

pthread_t myThreads[NUM_THREADS];
sem_t available;
sem_t check;

void* useResource(void*);
int randomNumber();

int main()
{
	int i;
	sem_init(&available, 0, 3);
	sem_init(&check, 0, 1);

	for(i=0; i < NUM_THREADS; i++)
	{
		pthread_create(&myThreads[i], NULL, useResource, (void*)i);
	}
	for(i=0; i < NUM_THREADS; i++)
	{
		pthread_join(myThreads[i], NULL);
	}

	return 0;
}

void* useResource(void *id)
{
	int* threadID = (int*)id;
	int freeResource;
	int stopResource = 0;
	while(1)
	{
		int waitVal = randomNumber();
		if(stopResource == 1)
		{
			printf("Thread %d is waiting.\n", threadID);
			sem_wait(&check);
			sem_post(&check);
		}
		sem_getvalue(&available, &freeResource);
		if(freeResource == 1)
		{
			sem_wait(&check);
			stopResource = 1;
		}
		sem_wait(&available);
		printf("Thread %d is using the resource for %d seconds...\n", threadID, waitVal);
		sleep(waitVal);
		printf("Thread %d is done.\n", threadID);
		sem_getvalue(&available, &freeResource);
		if(freeResource == 2)
		{
			sem_post(&check);
			stopResource = 0;
		}
		sem_post(&available);
	}
}

int randomNumber()
{
	return RANGE_MIN + rand() % (RANGE_MAX + 1 - RANGE_MIN);
}

