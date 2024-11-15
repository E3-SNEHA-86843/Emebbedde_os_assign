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
	int arr2[2];
	int sum;
	fd=open(fifo_path,O_RDONLY);
	if(fd < 0){
	
		perror("open () failed");
		_exit(1);
	}
	printf("P2:waiting for a message\n");
	ret = read(fd,arr2,sizeof(arr2));
	if(ret < 0){
	
		perror("read() failed");
		close(fd);
		exit(1);
	}
	printf("P2:message received: %d bytes no as %d and %d\n",ret,arr2[0],arr2[1]);


	sum= arr2[0] + arr2[1];
	printf("Server:sun=%d\n",sum);

	fd2=open(fifo_path,O_WRONLY);
	if(fd2 < 0){

                perror("open() failed");
		close(fd);
                _exit(1);
        }

	ret = write(fd2,&sum,sizeof(sum));
	
	if(ret<0){
	
		perror("write() failed");
		close(fd);
		close(fd2);
		exit(1);
	}
	return 0;
}
