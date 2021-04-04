#include<stdio.h>
#define N 5

int mass[N];

int fact(int a){

mass[0] = 1;
mass[1] = 2;


for (int i = 1; i<=N; i++)
	mass[i] = mass[i-1]*i;
return(mass[N]);
}

int factorial(int a){
int b;
if( (a - 1) > 0)
return a*factorial(a-1);
else
return 1;
}


void main(){

	printf("%d\n", factorial(N));
	printf("%d\n", fact(N));


}
