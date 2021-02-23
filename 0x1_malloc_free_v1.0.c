/***************************************************************************************************************************
Project :       Heap Manager
Version :       1.0
Author  :       Ajay
Date    :       1/2/2021
***************************************************************************************************************************/

/**************************************************************************************************************************
    This is a very primitive and initial implementation of malloc() and free(), just testing out sbrk() sys call.

    The files are named according to their versions and I will hopefully be releasing more better versions as I make
    these functions more generic, robust and complete, as I learn more about it.

    Please bear with me till the complete development process.
***************************************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <assert.h>
#include <stdlib.h>


//Custom Malloc
void * myMalloc(int size)
{
    void *p;

    //get the current value of break_pointer
    p = sbrk(0);

    //Allocating the size requested
    if(sbrk(size) == NULL)
    {
        return NULL;
    }else
    {
        return p;
    }
}

//Custom free()
void myFree(int numberOfBytes)
{
    assert(numberOfBytes > 0);

    //Make it a negative value
    sbrk(numberOfBytes * -1);
}




//Application
int main(int argc, char **argv)
{
    char *p = (char *)malloc(10);
    strncpy(p, "Hello", strlen("Hello"));
    printf("p = %s \n", p);
    myFree(10);
return 0;
}
