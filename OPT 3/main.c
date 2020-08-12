#include"header.h"

int main(int argc, char const *argv[])
{
    int repeat_action = 1;
    key_t key = 1234;
    msg_buffer buffer;
    char read_buffer[DIM_BUFFER];

    while (1 == repeat_action)
    {
        short option;
        printf("1.Sent message.\n2.Recovery message.\nOption: ");
        scanf("%hd", &option);
        
        switch (option)
        {
        case 1:
            getchar();
            printf("Enter a message: ");
            fgets(read_buffer, sizeof(read_buffer), stdin);
            /* scanf("%[^\n]", buffer.msg_text); */

            strcpy(buffer.msg_text, read_buffer);
            if ('\n' == buffer.msg_text[strlen(buffer.msg_text) - 1])
                buffer.msg_text[strlen(buffer.msg_text) - 1] = '\0';

            sent_message(buffer, key);
            break;

        case 2:
            recovery_message(buffer, key);
            break;

        default:
            printf("Is't a option!\n");
            break;
        }

        printf("\nRepeat action?\n[1]-Yes\t[2]->No:");
        scanf("%d", &repeat_action);
        printf("\n");
    }

    return 0;
}
