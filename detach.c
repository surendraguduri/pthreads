#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void *thread(void *arg)
{
 	pthread_detach(pthread_self());
	sleep(2);
 	printf("\nIn Thread...!\n");
	for(int i=1;i<=100;i++)
		printf("\n Val:: %d",i);
	printf("out from Thread");
 	//pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
 	pthread_t tid;
 	int ret = pthread_create(&tid, NULL, thread, NULL);
	
 	if (ret != 0) 
        {
 	 	printf("Thread Creation Error\n");
 	 	return -1;
 	}
 	printf("Thread created in Main\n");
	printf("\n In main...");
	//pthread_join(tid,NULL);
 	pthread_exit(NULL);
	printf("\n After exit main...");
	return 0;
}

