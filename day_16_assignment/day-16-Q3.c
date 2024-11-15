#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

pthread_mutex_t m;
pthread_cond_t c;
int sun_flag=0;
int flag=0;

void* sunbeam(void *para){

	while(1){
		char *str = "SUNBEAM\n";
		pthread_mutex_lock(&m);
		while(sun_flag == 1){
			pthread_cond_wait(&c,&m);
		}
		for(int i=0;str[i]!='\0';i++){
			write(1,&str[i],1);
			sleep(1);
		}

	sun_flag =1;
	flag=1;
	pthread_cond_signal(&c);

	pthread_mutex_unlock(&m);

	}
	return NULL;
}

void* infotech(void *para){

	while(1){
		pthread_mutex_lock(&m);
		while(flag == 0){
			pthread_cond_wait(&c,&m);
		}
		char *str="INFOTECH\n";
		for(int i=0;str[i]!='\0';i++){
	
			write(1,&str[i],1);
			sleep(1);
		}
		sun_flag=0;
		flag=0;

		pthread_cond_signal(&c);
		pthread_mutex_unlock(&m);
	}
	return NULL;
}
int main(){

	pthread_t st,it;
	pthread_mutex_init(&m,NULL);
	pthread_cond_init(&c,NULL);
	pthread_create(&it,NULL,infotech,NULL);
	pthread_create(&st,NULL,sunbeam,NULL);
	getchar();
	pthread_mutex_destroy(&m);
	pthread_cond_destroy(&c);
	return 0;
}
