   //Последовательность прямоугольных матриц вещественных чисел, предваренная двумя целыми переменными - размерностью матрицы.
  //Я не понял условия задачи. Это матрица матриц? Или там имелось в виду про 1 матрицу?

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
  //Реализация для 1ой матрицы
//Выводить в файл
char *FILENAME = "1.txt";
char *FILEOUT  = "2.txt";

float *ReadMatrix(FILE *file, int x, int y)
{

	float *a = (float *)malloc(sizeof(float) * (x * y));
	printf("%d:%d\n", x, y);
	
	for(int i = 0; i< x*y; i++){
		fscanf(file, "%f\n", &a[i]);
		
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


void Clear(float** main, int size){

	for(int i = 0; i<size;i++){
	free(main[i]);
	}

}

int main()
{
	FILE *file = fopen(FILENAME, "r+");
	FILE *out  = fopen(FILEOUT , "w+");
	float **MainPtr; 
	int size = 1;
	int x, y = 0;
	

	fscanf(file, "%d\n", &x);
	fscanf(file, "%d\n", &y);
	float *ptr = ReadMatrix(file, x, y);
	//PrintMatrix(ptr, x,y);

	if(!feof(file)){
		MainPtr = malloc(sizeof(float **)*(size));
		MainPtr[0] = ptr;	
		fscanf(file, "%d\n", &x);
		fscanf(file, "%d\n", &y);
		ptr = ReadMatrix(file, x, y);
		PrintMatrix(ptr, x,y);
		MainPtr[1] = ptr;
		size++;
	}else{
	return 0;
	}

	while(!feof(file)){
		MainPtr = realloc(MainPtr, sizeof(float**)*(++size));
		MainPtr[size] = ptr;
		fscanf(file, "%d\n", &x);
		fscanf(file, "%d\n", &y);
		float *ptr = ReadMatrix(file, x, y);
		PrintMatrix(ptr, x,y);

	}

	Clear(MainPtr,size);
	fclose(file);
	fclose(out);
	free(MainPtr);
return 0;
}

