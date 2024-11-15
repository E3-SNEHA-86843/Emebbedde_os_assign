#include <stdio.h>
#include <unistd.h>

int main() {
    int ret, arr[2],count=0;
    char buf[] = "A";
    ret = pipe(arr);
    if(ret < 0) {
        perror("pipe() failed");
        _exit(1);
    }
    while(1){
    	write(arr[1], buf, 1);
    	count++;
    	printf("count: %d\n", count);
    }

    close(arr[1]);
    close(arr[0]);
    return 0;
}
