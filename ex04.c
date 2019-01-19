#include<stdio.h>
#include<pthread.h>

//int num_of_times = 5;
int num = 2;
int num_of_times = 10;

pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER; 

void* print_even()
{	
	
	pthread_mutex_lock(&lock1);

	while(num_of_times>0){
	while((num%2)!=0)
	{
		pthread_cond_wait(&cond1,&lock1);
		//num_of_times--;
	}	
	printf("%d\n",num);
	num = num+1;
	num_of_times--;
	pthread_cond_signal(&cond1);
	//pthread_mutex_unlock(&lock1);
	}
	pthread_mutex_unlock(&lock1);
	pthread_exit(NULL);
}

void* print_odd()
{	


	pthread_mutex_lock(&lock1);
	while(num_of_times>0){
	while((num%2)==0)
	{
		pthread_cond_wait(&cond1,&lock1);
		//num_of_times--;
	}	
	printf("%d\n",num);
	num = num+1;
	num_of_times--;
	pthread_cond_signal(&cond1);
	//pthread_mutex_unlock(&lock1);
}
	pthread_mutex_unlock(&lock1);
	pthread_exit(NULL);
}


int main(void)
{
	pthread_t id1;
	pthread_create(&id1,NULL,print_even,NULL);
	
	pthread_t id2;
	pthread_create(&id2,NULL,print_odd,NULL);
	

	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	
	printf("Thank you\n");

	return 0;
}
