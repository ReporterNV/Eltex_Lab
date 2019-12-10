#include<stdio.h>
#include<stdlib.h>

int main(){
int threads, min, max;
printf("Enter number of threads:");
scanf("%d", &threads);

printf("Enter min:");
scanf("%d", &min);

printf("Enter max:");
scanf("%d", &max);
int mod = (max - min + 1) % threads; 
int step = (max-min+1-mod)/threads;
printf("\n mod: %d\n", mod);
printf("\n step: %d\n", step);
if(threads > (max - min))
	printf("RANGE %d:%d\n", min, max);
else
	for(int i=min;i < max;i+= step){
		if((i+step+mod-1) >= max){
		printf("Check %d:%d\n", i, max);	
		break;
		}else{
		printf("Check %d:%d\n", i, i+step-1);	
		}
}

return 0;
}

