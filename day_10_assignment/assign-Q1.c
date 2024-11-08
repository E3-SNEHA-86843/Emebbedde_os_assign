#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<string.h>


int main(){

	int pid,sig;
	printf("Enter pid :");
	scanf("%d",&pid);
	printf("Enter sig :");
	scanf("%d",&sig);
	
	int r = kill(pid,sig);
	if(r == 0)
	{
		printf("process is killed\n");
	}else{
		perror("failed to kill :\n");
	}
	return 0;
}
