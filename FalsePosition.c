#include<stdio.h>
#include<conio.h>
#include<math.h>

//#define f(x) x*sin(x)-1
#define f(x) x * log10(x)+ pow(e,x)*sin(x)-2.5

void main(){
	float a,b,x,fa,fb,fx,e;
	up:
	printf("Enter to initial guesses:\n");
	scanf("%f%f",&a,&b);
	printf("Enter tolerable error:\n");
	scanf("%f",&e);
	fa=f(a);
	fb=f(b);
	if(fa*fb>0){
		printf("Wrong initial guesses.\n");
		goto up;
			
	}
	do{
		x=(a*fb-b*fa)/(fb-fa);
		fx=f(x);
		if(fa*fx<0){
			b=x;
			fb=fx;
		}
		else{
			a=x;
			fa=fx;
			
		}

	}
	while(fabs(fx)>e);
	printf("\n Root is:%.5f",x);
	
}