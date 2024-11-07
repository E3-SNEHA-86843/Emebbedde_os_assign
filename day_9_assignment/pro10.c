#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h>

int main(){

	int ret,cnt = 0,s;
	while(cnt<5){
	
		ret = fork();
		if(ret == -1 ){
		
			printf("fork() failed\n");
			_exit(0);
		}else if(ret == 0){
		
			sleep(5);
			_exit(0);
		}else{
		
			cnt++;
			printf("child count: %d\nchild with parent pid:%d\n",cnt,getppid());
		}
		waitpid(ret,&s,0);
	}
	return 0;
}
