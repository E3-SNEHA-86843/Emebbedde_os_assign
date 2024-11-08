#include<stdio.h>
#include"rectangle.h"
void rectangle(){

	int area,length,width;

	printf("Enter length and width:");
	scanf("%d%d",&length,&width);

	area= length*width;
	printf("area= %d\n",area);

}
