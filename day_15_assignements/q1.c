#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

struct input
{
 int min;
 int max;
};

struct output
{
 int sum;
};

void*sum(void*para)
{
int i;
 struct input*ip=(struct input*)para;
 struct output*op=(struct output*)malloc(sizeof(struct output));
 
 for(i=ip->min;i<=ip->max;i++)
 {
   op->sum=op->sum+i;
   printf("sum:%d+%d=%d\n",op->sum,i,op->sum+i);
  
 }


return op;
}

int main()
{
  pthread_t th;
  struct input ip={.min=2, .max=20};
  struct output *out;
  pthread_create(&th,NULL,sum,&ip);
  pthread_join(th,(void**)&out);

  printf("main:sum:%d\n",out->sum);
}
