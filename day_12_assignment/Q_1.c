#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/msg.h>

#define mq_key 0x123
typedef struct msg{

	long id;
	int data,data1,sum;
}msg_t;

int main(){

	int mqid,pid,s,ret,ret2;
	mqid = msgget(mq_key,IPC_CREAT | 0600);
	
	if(mqid < 0){
	
		perror("msgget() failed....");
		_exit(1);
	}
	pid = fork();
	if(pid == 0){
	
		msg_t m1;
		m1.id = 101;
		printf("child: enter two number:");
		scanf("%d%d",&m1.data,&m1.data1);
		ret = msgsnd(mqid,&m1,sizeof(msg_t)-sizeof(long),0);
		if(ret < 0)
			perror("child: msgsnd() failed");
		else
			printf("child: message sent : %d\t%d\n",m1.data,m1.data1);

		sleep(1);
		printf("child :waiting for parent msg..\n");
		sleep(1);
		ret2 = msgrcv(mqid,&m1,sizeof(msg_t)-sizeof(long),101,0);
		sleep(1);
                if(ret2 < 0)
                        perror("msgrcv() failed\n");
                else
                        printf("child:received: %d\n",m1.sum);
		sleep(1);
		printf("child terminate...\n");

	}else{
	
		msg_t m2;
		printf("parent: waiting for child message..\n");

		sleep(1);
		ret = msgrcv(mqid,&m2,sizeof(msg_t)-sizeof(long),101,0);
		if(ret < 0)
			perror("msgrcv() failed\n");
		else{
			printf("parent:received:%d and %d\n",m2.data,m2.data1);
		
			m2.sum =m2.data+m2.data1;
			ret2 = msgsnd(mqid,&m2,sizeof(msg_t)-sizeof(long),0);
			sleep(1);
                if(ret2 < 0)
                        perror("parent sum msg: msgsnd() failed");
                else
                        printf("parent: message sent : %d\n",m2.sum);
		sleep(1);
		printf("waiting for child terminate\n");
		sleep(1);
		waitpid(pid,&s,0);
		printf("Parent terminate...\n");

		}
		//	waitpid(pid,&s,0);
	}
	return 0;
}
