#ifndef mymalloc_h
#define mymalloc_h

void *mymalloc( unsigned int size, char *file, int line);
void myfree( void *p, char *file, int line);
void isAllFree();

typedef struct mem_Entry{
	
	struct mem_Entry *succ, *prev;
	int isfree;
	unsigned int size;

}mementry;

#endif
