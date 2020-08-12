#include"header.h"

int main(int argc, char const *argv[])
{
    Node* node = NULL;
    char read_word[MAX_LINE];
    char write_word[MAX_LINE][MAX_LINE];
    int i = 0;
    int number_of_word = 0;
    
    FILE* fptr = fopen("in.txt", "r");
    if (NULL == fptr)
    {
        DBG_PRINT(1, "Error opening file with function fopen!");
        exit(EXIT_FAILURE);
    }
    
    while (NULL != fgets(read_word, sizeof(read_word), fptr))
    {
        strcpy(write_word[number_of_word], read_word);
        ++number_of_word;
    }

    for (i = 0; i < number_of_word; i++)
    {
        if (write_word[i][strlen(write_word[i]) - 1] == '\n')
            write_word[i][strlen(write_word[i]) - 1] = '\0';
        insert_node(&node, write_word[i]);
    }

    printf("Words before sorting:\n");
    print_node(node);

    printf("\nWords after sorting:\n");
    sort_node(&node);
    print_node(node);

    fclose(fptr);
    if (NULL != node)   
    {
        free(node);
        node = NULL;
    }

    return 0;
}
