#include"header.h"

int main(int argc, char const *argv[])
{
    char* buffer = NULL;
    int buffer_size = 0;
    int offset = 0;

    printf("Buffer size: ");
    scanf("%d", &buffer_size);

    /* buffer = (char*) malloc(buffer_size + 1); */
    buffer = (char*) malloc(sizeof(char) * buffer_size + 1);
    if(NULL == buffer)
    {
        fprintf(stderr, "Error when allocating memory for the buffer!\n");
        exit(EXIT_FAILURE);
    }

    getchar();
    printf("The string: ");
    fgets(buffer, buffer_size + 1, stdin);

    if ('\n' == buffer[strlen(buffer) - 1])
        buffer[strlen(buffer) - 1] = '\0';

    printf("Index from which to start reading the number: ");
    scanf("%d", &offset);

    printf("Result: %u\n", getValue(buffer, offset, buffer_size));

    /* memory deallocation */
    if(NULL != buffer)
    {
        free(buffer);
        buffer = NULL;
    }

    return 0;
}