#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char name[256];
	float lenght;
	unsigned stops;
	float price;
} pass;

pass input()
{
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

int main()
{
	unsigned int count = 0;
	printf("Enter number of tours: ");
	scanf("%u", &count);

	puts("");

	if ((count < 1) || (count > 5)) {
		fprintf(stderr, "Wrong number");
		return 1;
	}
	pass start[4];

	for (int i = 0; i < count; i++)
		start[i] = input();

	for (int i = 0; i < count; i++) {
		printf("Pass #%d :\n", i + 1);
		printf("Name of tour: %s\n", &start[i].name);
		printf("Route lenght: %f\n", start[i].lenght);
		printf("Number of stops: %d\n", start[i].stops);
		printf("Price of  tour: %f\n\n", start[i].price);
	}

	return 0;
}
