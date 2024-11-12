#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){

	int ret,ret1,arr[2],arr1[2],s,sum;
	int buf1,buf2;
	printf("Enter two no:");
	scanf("%d%d",&buf1,&buf2);
	ret = pipe(arr);
	if(ret < 0){
	
		perror("pipe() failed");
		_exit(1);

	}
	ret1 = pipe(arr1);
        if(ret1 < 0){

                perror("pipe() failed");
                _exit(1);
        }

	ret = fork();
	if(ret == 0){
	
		printf("child started..\n");
		sleep(1);
		printf("\n");
		close(arr[0]);
		//close(arr1[0]);
		write(arr[1],&buf1,sizeof(buf1));
		printf("child: written to pipe:%d and %d\n",buf1,buf2);
		//close(arr[1]);

		read(arr1[0],&sum,sizeof(sum));
                printf("child: read  from pipe sum :%d\n",sum);

		sleep(1);
		printf("pipe-2 is closing..\n");

		sleep(1);
		printf("child terminated\n");
		close(arr1[1]);
		close(arr1[0]);
	}else{
		printf("Parent started...\n");
		printf("\n");
		sleep(1);
	
		//close(arr[1]);		
		//close(arr1[1]);
		read(arr[0],buf2,sizeof(buf2));
		sleep(1);
		printf("parent: read  from pipe:%d and %d\n",buf1,buf2);
		sum=buf1+buf2;
	
		sleep(1);
		printf("parent: sending sum to child using new pipe\n");
		write(arr1[1],&sum,sizeof(sum));
                printf("parent: written to pipe sum: %d\n",sum);
		sleep(1);
		waitpid(ret,&s,0);
		printf("pipes are closing\n");
		close(arr[0]);
		close(arr1[1]);
		close(arr1[0]);
	}
	return 0;
}
