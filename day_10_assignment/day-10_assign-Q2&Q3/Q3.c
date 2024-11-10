#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(){
int pid,pid1,pid2,pid3,pid4,pid5,pid6,ret, err,s,s1,s2,s3,s4,s5,s6;
printf("program Started\n");
pid1=fork();
if(pid1 ==0){
  err =execlp("gcc","gcc", "-c", "circle.c" ,NULL);
  printf("Circle .o file created");
  if(err < 0){
   perror("exec() failed");
   _exit(1);

  }
}
pid2=fork();
if(pid2 ==0){
  err =execlp("gcc","gcc", "-c", "square.c" ,NULL);
  printf("square .o file created");
  if(err < 0){
   perror("exec() failed");
   _exit(1);
}
  }
pid3=fork();
if(pid3 ==0){
  err =execlp("gcc","gcc", "-c", "rectangle.c" ,NULL);
  printf("rectangle .o file created");
  if(err < 0){
   perror("exec() failed");
   _exit(1);

  }
}

pid4=fork();
if(pid4 ==0){
  err =execlp("gcc","gcc", "-c", "main.c" ,NULL);
  printf("main .o file created");
  if(err < 0){
   perror("exec() failed");
   _exit(1);

  }
}

pid5=fork();
if(pid5 ==0){
  err =execlp("gcc","gcc", "-o", "circle.o" ,"rectangle.o", "square.o", "main.o" ,NULL);
  printf("Program.out .o file created");
  if(err < 0){
   perror("exec() failed");
   _exit(1);

  }
}


pid6=fork();
if(pid6 ==0){
  err =execlp("./program.out","./program.out",NULL);
  printf("Program.out file created");
  if(err < 0){
   perror("exec() failed");
   _exit(1);

  }
 } 
else{
   while(waitpid(pid, &s, 0) > 0);
   printf("Program complete with exit status: %d\n",WEXITSTATUS(s));
}
  printf("parent finished\n");
  return 0;

}
