#include"header.h"

int main(int argc, char const *argv[])
{
    int* object = allocInLib();

    printf("Value for object: ");
    scanf("%d", &*object);

    printf("The value of the object is: %d\n", *object);

    freeInLib(object);
    return 0;
}