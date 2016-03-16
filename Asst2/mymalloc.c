//christian suasi and alec fray
//systems programming cs214 
//pa2 error detecting malloc() and free()


//header files
#include <stdlib.h>
#include <stdio.h>
#include "mymalloc.h"

static char myblock[5000];
static void *mementries[5000];


//intitalize memenetries
void initmementries(){
	int i;
	for ( i=0; i < 5000; i++){
		mementries[i] = NULL;
	}
	return;
}

//remove NULL and store element into entry the element into mementries 
void removeElement(void *ptr){
	int i;
	for ( i=0; i < 5000; i++ ){
		if( mementries[i] == NULL) {
			mementries[i] = ptr;
			return;
		}
	}
	return;
}

//checks if mementries position at i is valid for replacement
//sets position to NULL and returns 1 if successful
int openElement(void *ptr){
	int i;
	for ( i=0; i<5000; i++ ){
		if( mementries[i] == ptr){
			mementries[i] = NULL;
			return 1;
		}
	}
	return 0;
}



void *mymalloc(unsigned int size, char *file, int line){


	
	static mementry *root;
	mementry *succ, *p;	
	
	static int initialized = 0;	
	if(size == 0){
		fprintf(stderr,"ERROR! Cannot malloc size 0 bytes in FILE: '%s' on LINE: '%d\n", file , line);
	}


	if (!initialized){
		initmementries();
		root = (mementry *)myblock;
		root->prev = root->succ = 0;
		root->size = 5000 - sizeof(mementry);
		root->isfree = 1;
		initialized = 1;
	}
	
	p = root;

	while ( p != 0 ){
		if ( p->size < size ){
			p = p->succ;
		}
		else if ( p->isfree != 1){
			p = p->succ;
		}
		else if ( p->size < (size + sizeof(mementry)+20) ){
			p->isfree = 0;
			removeElement( (void*) p+sizeof(mementry) );
			return (char *) p+sizeof(mementry);
		}
		else{
			succ = (mementry *)((char*) p+sizeof(mementry) + size);
			succ->prev = p;
			succ->succ = p->succ;

			if( p->succ !=0 ){
				p->succ->prev = succ;
			}	
			p->succ = succ;
			succ->size = p->size - sizeof(mementry) - size;
			succ->isfree = 1;
			p->size = size;
			p->isfree = 0;
			removeElement( (void*) p+sizeof(mementry) );
			printf("SUCCESS! mymalloc ran perfectly\n");
			return (char*) p+sizeof(mementry);
		}
	}
	fprintf(stderr, "ERROR! No space available in on LINE: %d in FILE: %s\n", line, file);
	return 0;
}	

void myfree( void *p, char *file, int line ){

	mementry *ptr, *pred, *succ;

	if ( p == NULL ){
		fprintf(stderr, "ERROR! Freeing memory that was never allocated  on LINE: %d in FILE: %s\n", line, file);
		return;
	}
	if ( !openElement( (void*)p) ){
		fprintf(stderr, "ERROR! Address passed was not returned from mymalloc() or has already been freed on LINE: %d in %s\n", line , file);
		return;
	}
	
	ptr = (mementry*)((char*)p - sizeof(mementry));
	pred = ptr->prev;
	if (pred != 0 && pred->isfree == 1){
		pred->size += sizeof(mementry) + ptr->size;
		pred->succ = ptr->succ;
		if ( ptr->succ != 0 ){
			ptr->succ->prev = pred;
		}
	}
	else{
		ptr->isfree = 1;
		pred = ptr;
	}
	succ = ptr->succ;
	if ( succ != 0 && succ->isfree == 1 ){
		pred -> size += sizeof(mementry) + succ->size;
		pred -> succ = succ->succ;
		if ( succ->succ !=0 ){
			succ->succ->prev = pred;
		}
	}

	
}

//check if all mementries hav been freed
void isAllFree(){
	int i;
	for ( i=0; i<5000; i++){
		if(mementries[i] != NULL){
			fprintf(stderr, "ERROR! Not all mementries were freed\n");
			return;
		}
	}
	return;
}
