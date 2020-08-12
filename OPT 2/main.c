#include"header.h"

int main(int argc, char const *argv[])
{
    FILE* fptr = NULL;
    int option = 0;
    char* file_name = NULL;
    int repeat_action = 1;
    char* complete_file_name = NULL;

    char string_array[DIM_MAX_STRING_ARRAY][DIM_MAX_STRING_ARRAY];

    while (1 == repeat_action)
    {
        printf("Choose an option:\n");
        printf("1.Open file.\n2.Save file.\n3.Print file content.\n4.Write text at position.\n");
        printf("5.Delete text fron position.\n6.Undo.\n7.Redo.\n:");
        scanf("%d", &option);
        printf("\n");

        switch (option)
        {
        case 1:
            printf("You selected open file.\n");
            file_name = open_file();
            complete_file_name = strcat(file_name, ".txt");
            break;

        case 2:
            printf("You selected save file.\n");
            fptr = save_file(file_name, complete_file_name);
            break;    
        
        case 3:
            printf("You selected print file content.\n");
            print_file_content(complete_file_name);
            break;

        case 4:
            printf("You selected write text at position.\n");
            write_text_at_position(string_array, fptr);
            break;

        case 5:
            printf("You selected delete text from position.\n");
            delete_text_from_position(string_array, fptr);
            break;     

        case 6:
            printf("You selected undo.\n");
            break;

        case 7:
            printf("You selected redo.\n");
            break;           

        default:
            fprintf(stderr, "'%d' is not an option!\n", option);
            break;
        }

        printf("\nRepeat action?\n[1]->Yes [0]->No: ");
        scanf("%d", &repeat_action);
        printf("\n");
    }

    /* memory deallocation */
    if (NULL != file_name)
    {
        free(file_name);
        file_name = NULL;
    }

    if (NULL != complete_file_name)
    {
        free(complete_file_name);
        complete_file_name = NULL;
    }

    return 0;
}