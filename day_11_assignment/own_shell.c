#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include<signal.h>

void sigint_handler(int sig){

	printf("signal caught:%d\n",sig);
}
void signalchild_handler(){

	int s;
	waitpid(-1,&s,0);
	printf("exit status of child:%d\n",s);
}

int main(){
	char cmd[512], *ptr, *args[32];
	int i,ret,err,s;
	signal(SIGINT, sigint_handler);
	signal(SIGCHLD,signalchild_handler);
	while(1){
		printf("cmd> ");
		gets(cmd);
		i=0;
		ptr = strtok(cmd, " ");
		args[i] = ptr;
		i++;
		do{
			ptr = strtok(NULL," ");
			args[i] = ptr;
			i++;
		}while(ptr!=NULL);
		if(strcmp(args[0], "exit") == 0)
			_exit(0);
		else if(strcmp(args[0],"cd") == 0)
			chdir(args[1]);
		else if(i>1 && strcmp (args[i-2],"&")==0){
			args[i-2]=NULL;
			 ret = fork();
                        if(ret == 0){
                                err = execvp(args[0],args);
                                if(err < 0){
                                        perror("exec() failed\n");
                                        _exit(0);
				}
			}
		}else{
			ret = fork();
			if(ret == 0){	
				err = execvp(args[0],args);
				if(err < 0){
					perror("exec() failed\n");
					_exit(1);
				}
			}
			else{
			waitpid(-1,&s,0);
		}
	}
	}
	return 0;
}
