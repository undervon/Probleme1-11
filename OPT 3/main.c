#include"header.h"

int main(int argc, char const *argv[])
{
    int repeat_action = 1;
    key_t key = 1234;
    msg_buffer buffer;

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
            scanf("%[^\n]", buffer.msg_text);
            getchar();
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
