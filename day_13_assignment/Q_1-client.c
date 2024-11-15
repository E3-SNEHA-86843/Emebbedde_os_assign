#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

#define fifo_path "/tmp/myfifo"

int main(){

	int fd,fd2,ret;
	int arr[2];
	int sum;

	if(mkfifo(fifo_path,0666) == -1){
	
		perror("mkfifo() failed");
		exit(1);
	}

	fd=open(fifo_path,O_WRONLY);
	if(fd < 0){
	
		perror("open() failed");
		_exit(1);
	}
	printf("client:Enter two value to sent server:\n");
	
	for(int i=0;i<2;i++){
		scanf("%d",&arr[i]);
	}

	ret = write(fd,arr,sizeof(arr));
	if(ret<0){
	
		perror("write() failed");
		close(fd);
		exit(1);
	}

	printf("client:message sent: %d and %d\n",arr[0],arr[1]);

	fd2=open(fifo_path,O_RDONLY);
	 if(fd < 0){

                perror("open () failed");
                _exit(1);
        }

	ret = read(fd2,&sum,sizeof(sum));
	if(ret <0){
	
		perror("read() failed");
		close(fd);
		close(fd2);
		exit(1);
	}
	printf("client:message received from server: %d\n",sum);
	close(fd);
	close(fd2);
	return 0;
}
