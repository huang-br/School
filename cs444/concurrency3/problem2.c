#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define NUM_THREADS 2
#define RANGE_MIN 0
#define RANGE_MAX 10

pthread_t searcher[NUM_THREADS];
pthread_t inserter[NUM_THREADS];
pthread_t deleter[NUM_THREADS];

pthread_mutex_t sLock;
pthread_mutex_t iLock;
pthread_mutex_t dLock;

struct listNode
{
	int val;
	struct listNode* next;
}*head;

int randomNumber();
void* search();
void* insert();
void* del();

int main()
{
	srand(time(NULL));
	struct listNode *newList;
	newList = (struct listNode *)malloc(sizeof(struct listNode));
	newList -> val = randomNumber();
	newList -> next = NULL;

	int i;

	for(i=0; i < NUM_THREADS; i++)
	{
		pthread_create(&searcher[i], NULL, search, NULL);
		pthread_create(&inserter[i], NULL, insert, NULL);
		pthread_create(&deleter[i], NULL, del, NULL);
	}

	for(i=0; i < NUM_THREADS; i++)
	{
		pthread_join(searcher[i], NULL);
		pthread_join(inserter[i], NULL);
		pthread_join(deleter[i], NULL);
	}

	return 0;
}

int randomNumber()
{
	return RANGE_MIN + rand() % (RANGE_MAX + 1 - RANGE_MIN);
}

void* search()
{
	struct listNode *temp;
	while(1)
	{
		if(!pthread_mutex_trylock(&sLock))
		{
			temp = head;
			if(temp == NULL)
			{
				printf("The linked list is empty.\n");
			}
			else
			{
				while(temp != NULL)
				{
					printf("%d is in the list.\n", temp -> val);
					temp = temp -> next;
				}
			}
			pthread_mutex_unlock(&sLock);
		}
		sleep(10);
	}
}

void* insert()
{
	struct listNode *newNode;
	struct listNode *temp;
	int i;
	while(1)
	{
		if(!pthread_mutex_lock(&iLock))
		{
			newNode = (struct listNode *)malloc(sizeof(struct listNode));
			i = randomNumber();
			printf("Inserting %d into the list.\n", i);
			newNode -> val = i;
			newNode -> next = NULL;
			if(head == NULL)
			{
				head = newNode;
			}
			else
			{
				temp = head;
				while(temp -> next != NULL)
				{
					temp = temp -> next;
				}
				temp -> next = newNode;
			}
			pthread_mutex_unlock(&iLock);
			sleep(5);
		}
	}
}

void* del()
{
	struct listNode *temp;
	struct listNode *prev;
	int i;
	int deleteVal;
	while(1)
	{
		if(!pthread_mutex_trylock(&iLock))
		{
			if(!pthread_mutex_trylock(&sLock))
			{
				if(!pthread_mutex_trylock(&dLock))
				{
					temp = head;
					deleteVal = randomNumber();
					while(temp != NULL)
					{
						if(temp -> val == deleteVal)
						{
							printf("Deleting %d from the list.\n", deleteVal);
							if(temp == head)
							{
								head = temp -> next;
								free(temp);
								break;
							}
							else
							{
								prev -> next = temp -> next;
								free(temp);
								break;
							}
						}
						else
						{
							prev = temp;
							temp = temp -> next;
						}
					}
				}
			}
			pthread_mutex_unlock(&dLock);
			pthread_mutex_unlock(&sLock);
			pthread_mutex_unlock(&iLock);
		}
		sleep(5);
	}
}


