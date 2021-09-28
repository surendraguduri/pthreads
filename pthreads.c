#include <stdio.h>
#include <pthread.h>
#include <unistd.h> // sleep

void* my_thread(void *ptr)
{    
     printf("\n Entered in pthread");
     printf("\n pthread ID    :: %lu\n",pthread_self());//pthread_t var = pthread_self();
     sleep(2);
     printf("\n Thread stop");
}

int main(void)
{
    pthread_t tid;
    int ret;

    ret = pthread_create(&tid,NULL,&my_thread,NULL);
    if (ret !=0) 
    {
            printf("ERORR; return code from pthread_create() is %d\n", ret);
            return -1;
    }
    printf("Pthread is created successfully...");
    
    //int pthread_create(pthread_t *thread, const pthread_attr_t *attr,void *(*start_routine) (void *), void *arg);
   
    printf("\n\n Main function...");
    printf("\n PID:: %d\n", getpid());
    sleep(5);
    return 0;
}