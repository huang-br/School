#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define SLEEP_TIME 5

sem_t Tobacco;
sem_t Paper;
sem_t Matches;
sem_t Agent;
sem_t tobaccoSem;
sem_t paperSem;
sem_t matchesSem;

pthread_t agent_A, agent_B, agent_C;
pthread_t smoker_Tobacco, smoker_Paper, smoker_Matches;
pthread_t pusher_Tobacco, pusher_Paper, pusher_Matches;

pthread_mutex_t pusherLock;

int isTobacco = 0;
int isPaper = 0;
int isMatches = 0;

void* agentA();
void* agentB();
void* agentC();
void* pusherTobacco();
void* pusherPaper();
void* pusherMatches();
void* smokerTobacco();
void* smokerPaper();
void* smokerMatches();

int main()
{
	sem_init(&Tobacco, 0, 0);
	sem_init(&Paper, 0, 0);
	sem_init(&Matches, 0, 0);
	sem_init(&Agent, 0, 1);
	sem_init(&tobaccoSem, 0, 0);
	sem_init(&paperSem, 0, 0);
	sem_init(&matchesSem, 0, 0);

	pthread_mutex_init(&pusherLock, NULL);
	pthread_create(&agent_A, NULL, agentA, NULL);
	pthread_create(&agent_B, NULL, agentB, NULL);
	pthread_create(&agent_C, NULL, agentC, NULL);
	pthread_create(&smoker_Tobacco, NULL, smokerTobacco, NULL);
	pthread_create(&smoker_Paper, NULL, smokerPaper, NULL);
	pthread_create(&smoker_Matches, NULL, smokerMatches, NULL);
	pthread_create(&pusher_Tobacco, NULL, pusherTobacco, NULL);
	pthread_create(&pusher_Paper, NULL, pusherPaper, NULL);
	pthread_create(&pusher_Matches, NULL, pusherMatches, NULL);

	pthread_join(agent_A, NULL);
	pthread_join(agent_B, NULL);
	pthread_join(agent_C, NULL);
	pthread_join(smoker_Tobacco, NULL);
	pthread_join(smoker_Paper, NULL);
	pthread_join(smoker_Matches, NULL);
	pthread_join(pusher_Tobacco, NULL);
	pthread_join(pusher_Paper, NULL);
	pthread_join(pusher_Matches, NULL);

	return 0;
}

void* agentA()
{
	while(1)
	{
		sem_wait(&Agent);
		printf("AgentA put out Tobacco and Paper.\n");
		sem_post(&Tobacco);
		sem_post(&Paper);
	}
}
		
void* agentB()
{
	while(1)
	{
		sem_wait(&Agent);
		printf("AgentB put out Paper and Matches.\n");
		sem_post(&Paper);
		sem_post(&Matches);
	}
}

void* agentC()
{
	while(1)
	{
		sem_wait(&Agent);
		printf("AgentC put out Tobacco and Matches.\n");
		sem_post(&Tobacco);
		sem_post(&Matches);
	}
}

void* pusherTobacco()
{
	while(1)
	{
		sem_wait(&Tobacco);
		pthread_mutex_lock(&pusherLock);
		if(isPaper)
		{
			isPaper = isPaper - 1;
			sem_post(&matchesSem);
		}
		else if(isMatches)
		{
			isMatches = isMatches - 1;
			sem_post(&paperSem);
		}
		else
		{
			isTobacco = isTobacco + 1;
		}
		pthread_mutex_unlock(&pusherLock);
	}
}

void* pusherPaper()
{
	while(1)
	{
		sem_wait(&Paper);
		pthread_mutex_lock(&pusherLock);
		if(isMatches)
		{
			isMatches = isMatches - 1;
			sem_post(&tobaccoSem);
		}
		else if(isTobacco)
		{
			isTobacco = isTobacco - 1;
			sem_post(&matchesSem);
		}
		else
		{
			isPaper = isPaper + 1;
		}
		pthread_mutex_unlock(&pusherLock);
	}
}

void* pusherMatches()
{
	while(1)
	{
		sem_wait(&Matches);
		pthread_mutex_lock(&pusherLock);
		if(isPaper)
		{
			isPaper = isPaper - 1;
			sem_post(&tobaccoSem);
		}
		else if(isTobacco)
		{
			isTobacco = isTobacco - 1;
			sem_post(&paperSem);
		}
		else
		{
			isMatches = isMatches + 1;
		}
		pthread_mutex_unlock(&pusherLock);
	}
}

void* smokerTobacco()
{
	while(1)
	{
		sem_wait(&tobaccoSem);
		sem_post(&Agent);
		printf("Smoker with Tobacco is smoking.\n");
		sleep(SLEEP_TIME);
	}
}

void* smokerPaper()
{
	while(1)
	{
		sem_wait(&paperSem);
		sem_post(&Agent);
		printf("Smoker with Paper is smoking.\n");
		sleep(SLEEP_TIME);
	}
}

void* smokerMatches()
{
	while(1)
	{
		sem_wait(&matchesSem);
		sem_post(&Agent);
		printf("Smoker with Matches is smoking.\n");
		sleep(SLEEP_TIME);
	}
}

