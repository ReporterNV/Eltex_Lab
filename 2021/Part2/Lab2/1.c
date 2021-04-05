   //Последовательность прямоугольных матриц вещественных чисел, предваренная двумя целыми переменными - размерностью матрицы.
  //Я не понял условия задачи. Это матрица матриц? Или там имелось в виду про 1 матрицу?

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
  //Реализация для 1ой матрицы

float *ReadMatrix(int x, int y)
{

	float *a = (float *)malloc(sizeof(float) * (x * y));
	printf("%d:%d\n", x, y);
	
	for(int i = 0; i< x*y; i++){
		scanf("%f", &a[i]);
		
		//Тут должен быть кусок кода с очисткой терминала. Но ничего не сработало.
		//printf("\b\b");
		//for(int j = 0; j < i; j++){
		//printf("%4.3f", a[j]);
		//}
		////

	}

	return a;
}

void PrintMatrix(float *matrix, int x, int y)
{
	for(int i=1; i <= x*y;i++){
			if(i%y == 1)	
			printf("[");
			printf("%4.3f\t", matrix[i-1]);
			if(i%y == 0)	
			printf("\b\b\b]\n");
	}
	printf("\n");
}

void main()
{

	int x, y = 0;
	//Получаем размерность
	printf("Enter x: ");
	scanf("%d", &x);

	printf("Enter y: ");
	scanf("%d", &y);
	float *ptr = ReadMatrix(x, y);
	PrintMatrix(ptr, x,y);

	free(ptr);
}
