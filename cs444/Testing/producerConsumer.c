#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include "mt19937ar.h"

#define BUFFER_SIZE 32
#define NUM_THREADS 5

//Creating the struct
struct item
{
	int value;
	int wait;
};

//Creating some global variables to initializes threads,semaphores and mutex 
pthread_t myThreads[NUM_THREADS];
pthread_mutex_t myMutex = PTHREAD_MUTEX_INITIALIZER;
sem_t takenSpace;
sem_t emptySpace;
struct item buffer[BUFFER_SIZE];

//function declarations
int randomNumer(int, int);
void* producer(void*);
void* consumer(void*);


int main(int argc, char** argv)
{
	int x, y, z;									//Creating variables for the for loops
	sem_init(&takenSpace, 0, 0);							//Initializing the semaphores
	sem_init(&emptySpace, 0, 32);
	
		
	for(x=0; x<atoi(argv[1]); x++)							//Creating the producers and consumers.
	{
		pthread_create(&myThreads[x], NULL, producer, (void*)x);
		//printf("Created a producer\n");
	}
	
	for(y=0; y<atoi(argv[2]); y++)
	{
		pthread_create(&myThreads[y], NULL, consumer, (void*)y);
		//printf("Created a consumer\n");
	}
	
	for(z=0; z<NUM_THREADS; z++)
	{
		pthread_join(myThreads[z], NULL);
		//printf("joining\n");
	}
	pthread_mutex_destroy(&myMutex);
	
	return 0;
}


int randomNumber(int min, int max)
{
	unsigned long randomNum;
	randomNum = 0.0;
	int range = (max - min + 1) + min;
	unsigned int eax;
	unsigned int ebx;
	unsigned int ecx;
	unsigned int edx;

	char vendor[13];
	
	eax = 0x01;

	__asm__ __volatile__(
	                     "cpuid;"
	                     : "=a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx)
	                     : "a"(eax)
	                     );
	
	if(ecx & 0x40000000){
		//use rdrand
		unsigned int temp = 0;
		__asm__ __volatile__(
					"rdrand %0;"
					: "r="(temp)
				    );
		randomNum = temp % range;
	}
	else{
		//use mt19937
		randomNum = genrand_int32();
		randomNum = randomNum % range;
	}

	return randomNum;
}

void* producer(void* tid)
{
	int semValue, productValue, consumerWait, producerWait;						//Initializing variables
	int threadID = (int)tid;									//Creating a thread ID
	while(1)
	{
		productValue = randomNumber(1,10);							//Creating a product value
		consumerWait = randomNumber(2,9);							//Creating a consumer wait time in the struct
		producerWait = randomNumber(3,7);							//Creating a producer wait time.
	
		printf("Producer %d is sleeping for %d seconds.\n", threadID, producerWait);		//Waiting
		sleep(producerWait);
		
		struct item event = {productValue, consumerWait};					//Creating the struct
		
		sem_wait(&emptySpace);									//Decrementing the empty space semaphore
		pthread_mutex_lock(&myMutex);								//Locking this thread so no data can be changed.
		sem_getvalue(&emptySpace, &semValue);							//Grabbing the value of the semaphore, and using that as an index.
		buffer[semValue]=event;									//Assining the product to the buffer using the semaphore value as index.
		pthread_mutex_unlock(&myMutex);								//Unlocking the thread.
		sem_post(&takenSpace);									//Incrementing the space that is taken by the products.
	
		printf("Producer %d added an item. \n", threadID);
	}
}

void* consumer(void* tid)
{
	int semValue;											//Initializing values
	int threadID = (int)tid;									//Creating a threadID

	struct item event;										//Creating a product that can be a copy
	while(1)
	{
		sem_wait(&takenSpace);									//Decrements the taken space semaphore.
		pthread_mutex_lock(&myMutex);								//Locks the thread so no data can be changed.
		sem_getvalue(&emptySpace, &semValue);							//Grabs the value from the taken space semaphore and stores it.
		event = buffer[semValue];								//Assigns the empty item, to the item that was in the buffer space indicated by the semaphore.
		pthread_mutex_unlock(&myMutex);								//Unlocks the thread.
		sem_post(&emptySpace);									//Increments the emptySpace semaphore.
		printf("Consumer %d is sleeping for %d seconds.\n", threadID, event.wait);
		sleep(event.wait);
	
		printf("Consumer %d's value is %d.\n", threadID, event.value);
	}
}

