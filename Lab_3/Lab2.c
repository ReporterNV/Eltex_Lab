#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
char name[256];
float lenght;
unsigned stops;
float price; 
}pass;

pass input(){
pass in;
puts("Enter name of tour: ");
scanf("%255s", in.name); 
puts("Enter route lenght: ");
scanf("%f", &in.lenght);
puts("Enter number of stops: ");
scanf("%u", &in.stops);
puts("Enter price of tour: ");
scanf("%f", &in.price);
return in;
}


int fsort(const void *a, const void *b){
pass *y = (pass*) a;
pass *z = (pass*) b;
if((float)y->price < (float)z->price)
return 1;
else 
return -1;
}

int main(){
unsigned int count = 0;
printf("Enter number of tours: ");
scanf("%u", &count);

puts("");

pass* mass = calloc(count, sizeof(pass));



for(int i =0; i <count; i++)
	mass[i] = input();

qsort(mass, count, sizeof(pass), fsort);

for(int i = 0; i< count; i++){
	printf("Pass #%d :\n", i+1);
	printf("Name of tour: %s\n", &mass[i].name);
	printf("Route lenght: %f\n", mass[i].lenght);
	printf("Number of stops: %d\n", mass[i].stops);
	printf("Price of  tour: %f\n\n", mass[i].price);
}


return 0;
}
