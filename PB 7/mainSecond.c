#include<stdio.h>
#include<stdlib.h>
#include <dlfcn.h>
#include"../p4h.h"

int main(int argc, char const *argv[])
{
    int* object = NULL;
    int handle_error = 0;

    /* open the needed object */
    void* handle = dlopen("/home/ldvon/Desktop/Probleme1-11/PB 7/libsample.so", RTLD_LOCAL | RTLD_LAZY);
    if (NULL == handle)
    {
        DBG_PRINT(1, "Error when allocating memory for the handle!");
        exit(EXIT_FAILURE);
    }

    /* find the address of function and data objects */
    int* (*allocInLib)(void) = (int* (*)(void))dlsym(handle, "allocInLib");
    if (NULL == allocInLib)
    {
        DBG_PRINT(1, "Error when allocating memory for the allocInLib!");
        exit(EXIT_FAILURE);
    }

    void (*freeInLib)(int *) = (void (*)(int *))dlsym(handle, "freeInLib");
    if (NULL == freeInLib)
    {
        DBG_PRINT(1, "Error when allocating memory for the freeInLib!");
        exit(EXIT_FAILURE);
    }

    object = allocInLib();
    printf("Value for object: ");
    scanf("%d", &*object);
    printf("The value of the object is: %d\n", *object);
    freeInLib(object);

    handle_error = dlclose(handle);
    if (0 != handle_error)
    {
        DBG_PRINT(1, "Error to close the handle!");
        exit(EXIT_FAILURE);
    }
    return 0;
}

/**
 * Support links.
 * https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.bpxbd00/dlsym.htm
 * https://stackoverflow.com/questions/1354537/dlsym-dlopen-with-runtime-arguments
 * 
 * Commands for the compiling on the command line.
 * gcc -o ex2 mainSecond.c -L. -lsample -ldl
 * ./ex2
 **/