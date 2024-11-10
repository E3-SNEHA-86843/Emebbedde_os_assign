#include<stdio.h>
#include"square.h"

void square(){

	int side;
	printf("\nEnter the Length of Side : ");
       	scanf("%d",&side);
       	int area = side * side;
       	printf("\nArea of Square : %d", area);
      
}
