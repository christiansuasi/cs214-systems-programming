#include <stdlib.h>
#include <stdio.h>
#include "mymalloc.h"

#define malloc( x ) mymalloc( x, __FILE__ , __LINE__ )
#define free( x ) myfree( x, __FILE__ , __LINE__ )

int main( ){

	//test case 1 empty block size
	printf("testcase 1 empty block size\n");
	int *ptr = (int*) malloc(0);	

	//test case 2 mementries fit into myblock, no errors
	printf("testcase 2 mementries fit into myblock, no errors\n");
	int *ptr1 = (int*) malloc(sizeof(int));
	*ptr1 = 123;

	//test case 3 mementry is equal to myblock size
	printf("testcase 3 mementry is equal to myblock size\n");
	int *ptr2 = (int*) malloc(5000);

	//test case 4 mementry is greater than myblock size
	printf("testcase 4 mementry is greater than myblock size\n");
	int *ptr3 = (int*) malloc(6000);

	//test case 5 freeing unallocated memory
	printf("testcase 5 freeing unalloacted memory\n");	
	int x = 100;
	free( &x );
	
	//test case 6 freeing something that was already freed
	printf("testcase 6 freeing an already freed ptr\n");
	free(ptr);
	free(ptr);

	//test case 7 perfectly working free
	printf("testcase 7 perfectly working free\n");
	int *ptr4 = malloc (32);
	free ( ptr1 );


	//all memory allocated should be free	
	atexit(isAllFree);
	
	return 0;
}

