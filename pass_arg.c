#include <stdio.h>
#include <pthread.h>

int val=10;
pthread_t tid;

void* add_num(void *ptr)
{    
     int *data_ptr = (int*) ptr;//from void pointer to integer pointer
     int data = *data_ptr;
     

     printf("\n Entered value       :: %d",val);
     printf("\n data                :: %d",data);
     printf("\n Multiplication is   :: %d",(val*data)); 
     printf("\n pthread ID          :: %lu\n",pthread_self());
}

int main(void)
{
    int data, ret=0;

    printf("\n Enter a number:: ");
    scanf("%d",&data);

    ret = pthread_create(&tid,0,&add_num,&data);
    if (ret) 
    {
            printf("ERORR; return code from pthread_create() is %d\n", ret);
            return -1;
    }
    printf("pthread is created successfully...");
    
    pthread_join(tid,NULL);

    return 0;
}
