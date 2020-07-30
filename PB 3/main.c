#include"header.h"

int main(int argc, char const *argv[])
{
    char* data = NULL;
    int data_size = 0;

    printf("String size: ");
    scanf("%d", &data_size);

    /* data = (char*) malloc(data_size + 1); */
    data = (char*) malloc(sizeof(char) * data_size + 1);
    if (NULL == data)
    {
        fprintf(stderr, "Error when allocating memory for the data!\n");
        exit(EXIT_FAILURE);
    }
    
    getchar();
    printf("The contents of the string: ");
    fgets(data, data_size, stdin);

    if ('\n' == data[strlen(data) - 1])
        data[strlen(data) - 1] = '\0'; 

    handleData(&progressCallback, data, data_size);

    /* memory deallocation */
    if(NULL != data)
    {
        free(data);
        data = NULL;
    }

    return 0;
}