#include<stdio.h>
#include<dirent.h>
void recursive(struct dirent*dname){
	if(dname->d_type != ){
		return;
	}
	printf("Name = "

}

int main(int argc,char *argv[]){

	DIR *dp;
	printf("a rgc : %d \n",argc);
	dp=opendir(argv[1] );
	if (dp == NULL)
	{
		printf("opendir falied ...\n");
		exit(1);
	}
	//--------------------------------------------------------
	struct dirent *ent;

	while (   (ent=readdir(dp))  != NULL )
	{
		printf("Inode : %lu \n",ent->d_ino);
		printf("Name  : %s \n",ent->d_name);
	}
	//------------------------------------------------------------

	int ret=closedir(dp);
	if( ret == 0)
	{
		printf("dir closed sucsessfully..\n");
	}
	else
	{
		printf("dir not closed sucsessfully..\n");
	}

	return 0;

}		
