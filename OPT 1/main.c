#include"header.h"

int main(int argc, char const *argv[])
{
    Node* node = NULL;
    char* word[NUMBER_OF_WORD] = {"test", "functionalitate", "program", "opt1", "test", "functionalitate"};
    int i = 0;

    for (i = 0; i < NUMBER_OF_WORD; i++)
        insert(&node, word[i]);

    print(node);
    printf("\nAfter sort:\n\n");
    sort(&node);
    print(node);

    return 0;
}
