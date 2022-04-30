#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void print_n(char* p, int x){
	printf("p is \"%s\" and x is %i\n",p,x);
}


int main(){
	
	printf("Hello world!\n");
	
	char* a = "Hello";
	char* b = "World!"; 
	
 
	printf("%s %s\n",a,b);
	print_n("stroutup", 99);
	print_n("yourmom", 69);
	print_n("zsebibaba", 12);

	return 0;
}