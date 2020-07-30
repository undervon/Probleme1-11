#include"header.h"

int main(int argc, char const *argv[])
{
    uint32_t decimal_value = 0;
    
    printf("Give a value based on 10: ");
    scanf("%u", &decimal_value);

    printBits(decimal_value);
    printf("\n");
    return 0;
}