#include<stdio.h>
#include"circle.h"
#define pi 3.14

void circle(){

	int circle1,radius;
	printf("Eneter radius:");
	scanf("%d",&radius);
	circle1= pi*radius*radius;
	printf("area of circle:%d\n",circle1);
	
}
