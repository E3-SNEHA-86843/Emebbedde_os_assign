#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h>

int main(){

	int ret,cnt = 0,s;

	for(int i=1;i<6;i++){	
		ret = fork();
		 cnt++;
		if(ret == -1 ){
		
			printf("fork() failed\n");
			_exit(0);
		}else if(ret == 0){

			printf("child count: %d\nchild with parent pid:%d\n",cnt,getppid());
                        printf("child pid:%d\n",getpid());
			waitpid(ret,&s,0);
			_exit(0);
		}
		sleep(5);
	}
	for(int i=1;i<6;i++){
	
		waitpid(ret,&s,0);
	}
	return 0;
}
