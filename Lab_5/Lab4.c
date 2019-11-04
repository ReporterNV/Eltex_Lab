#include<stdio.h>
#include<string.h>
#include<dlfcn.h>
#include<stdlib.h>



int main(){

	
void* lib_handle = dlopen("./libDLL.so", RTLD_LAZY); 


if(!lib_handle){
fprintf(stderr,"ERROR:%s\n", dlerror());
return -1;
}

int (*multiply)(int, int);

*(void **) &multiply = dlsym(lib_handle, "multiply");

if(multiply == NULL){
fprintf(stderr,"ERROR:%s\n", dlerror());
return -1;
}

float *division(int, int);
*(void **) &division =  dlsym(lib_handle, "division");

if(division == NULL){
fprintf(stderr,"ERROR:%s\n", dlerror());
return -1;
}



printf("Multiply: %d\n", multiply(5,7));
printf("Division: %.5f\n", division(1,5));

dlclose(lib_handle);
return 0;
}
