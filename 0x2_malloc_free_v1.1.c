#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>


/*
- The memory which is allocated in heap ontains a meta block ahead of the actual data stored address. 
  The Meta block contains information as to what is there in the data block and is used to locate the 
  size of the data block, next data block address, and a variable that indicates is the current data block is free or not.
*/
struct meta_block
{
	int size;
	struct meta_block *next;
	bool is_free; 			//False if the data block is not free
}

//This can be coupled in our malloc implementation to indicate the information about the data that we store such that - 

//Custom Malloc
void * myMalloc(int size)
{	
    struct meta_block *p;

    //get the current value of break_pointer
    p = (struct meta_block *)sbrk(0);

    //Allocating the size requested
    if(sbrk(size + sizeof(struct meta_block)) == NULL)
    {
        return NULL;
    }else
    {
    	p->size = size;
    	p->next = NULL;
    	p->is_free = FALSE;
        return (p+1);
    }
}

