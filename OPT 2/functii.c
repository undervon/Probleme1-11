#include"header.h"

char* open_file(void)
{
    char buffer[DIM_BUFFER];
    char* file_name = NULL;

    getchar();
    printf("Enter the file name: ");
    fgets(buffer, sizeof(buffer), stdin);

    file_name = (char*)malloc(sizeof(char) * strlen(buffer) + 1);
    if (NULL == file_name)
    {
        fprintf(stderr, "Error when allocating memory for the file_name!\n");
        exit(EXIT_FAILURE);
    }
    
    strcpy(file_name, buffer);

    if ('\n' == file_name[strlen(file_name) - 1])
        file_name[strlen(file_name) - 1] = '\0';

    return file_name;
}

FILE* save_file(char* file_name, char* complete_file_name)
{
    FILE* fptr = fopen(complete_file_name, "w");
    if (NULL == fptr)
    {
        DBG_PRINT(1, "Error opening file with function fopen!");
        exit(EXIT_FAILURE);
    }

    if ('\n' == complete_file_name[strlen(complete_file_name) - 1])
        complete_file_name[strlen(complete_file_name) - 1] = '\0';

    printf("The '%s' file has been saved!\n", complete_file_name);

    return fptr;
}

void print_file_content(char* complete_file_name)
{
    char c;
    FILE* fptr = NULL;

    printf("\n");
    fptr = fopen(complete_file_name, "r");
    if (NULL == fptr)
    {
        DBG_PRINT(1, "Error opening file with function fopen!");
        exit(EXIT_FAILURE);
    }

    while (EOF != (c = fgetc(fptr)))
        printf("%c", c);

    fclose(fptr);
    printf("\n");
}

void write_text_at_position(char string_array[DIM_MAX_STRING_ARRAY][DIM_MAX_STRING_ARRAY], FILE* fptr)
{
    uint32_t insert_position = 0;
    char buffer[DIM_BUFFER];

    printf("Insert position: ");
    scanf("%o", &insert_position);

    getchar();
    printf("Enter the file content: ");
    fgets(buffer, sizeof(buffer), stdin);

    if (insert_position >= DIM_MAX_STRING_ARRAY)
        DBG_PRINT(1, "The string is too large!");
}

void delete_text_from_position(char string_array[DIM_MAX_STRING_ARRAY][DIM_MAX_STRING_ARRAY], FILE* fptr)
{

}