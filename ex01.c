#include<stdio.h>
#include<pthread.h>

#define NUM_LOOPS 1000000000
long long sum = 0;

void counting_thread(int offset)
{
	int i;
	for(i = 0;i<NUM_LOOPS;i++)
	{
	sum = sum+offset;
	}
}

int main(void)
{
	counting_thread(1);
//	counting_thread(-1);
	printf("Sum = %lld\n",sum);
	return 0;
}
