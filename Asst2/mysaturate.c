#include <stdlib.h>
#include <stdio.h>
#include "mymalloc.h"

#define malloc(x) mymalloc( x, __FILE__ , __LINE__ )
#define free(x) myfree( x, __FILE__, __LINE__ )

int main (int argc, char **argv){
	
	int i;
	for ( i=0; i<5000; i++){
		char *ptr = (char*)malloc(0);
		if (ptr == 0){
			break;
		}
	}
	
	printf("saturate in use");

	atexit(isAllFree);
	
	return 0;
}

