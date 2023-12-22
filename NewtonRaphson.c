#include<stdio.h>

#include<math.h>
#include <stdlib.h>

#define f(x) 3*x-cos(x)-1
#define g(x) 3 + sin(x)

void main(){
	float x, y, f1, f, g, e=0.00001;
	
	up:
	//initial value from user
	printf("Enter the Initial Value: ");
	scanf("%f",&x);
	
	//torable error
//	printf("Enter the torable error: ");
//	scanf("%f",&e);
	
	float step=0.0;
	do{
		f=f(x);
		g=g(x);
		
			if(g==0.0){
				printf("Mathematical Error.");
				goto up;
			}
			
		y=x-(f/g);
		x=y;
		step+=1.0;
		
		
		f1=f(y);
		printf("For iteration %.1f, The value of x %.1f is %.1f",step,step,x);
	
	}
	while(fabs(f1)>e);
		
		printf("\n Root is: %f",y);
		
}