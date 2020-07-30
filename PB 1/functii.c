#include"header.h"

/**
 * \fn void printBits(uint32_t decimal_value)
 * \brief Function that prints a 32 bits (decimal) number in binary (base 2).
 * \param[in] decimal_value The input value that will be printed in binary.
 * \return void
 **/
void printBits(uint32_t decimal_value)      
{   
    /* recursiv */
    /* if (decimal_value == 0)
        return;    
    printBits(decimal_value >> 1);
    if ((decimal_value & 1) == 0)
        printf("%u", 0);
    else
        printf("%u", 1); */
        
    /*
     * 1 (10) = 0001 (2)
     * 3 (10) = 0011 (2)
     * sizeof(decimal_value) = 4
     * 1 << 3 = 1000 (2)
     * 1 << 2 = 0100 (2)
     * 1 << 1 = 0010 (2)
     * 1 << 0 = 0001 (2)
     * 1000 & 0011 = 0
     * 0100 & 0011 = 0
     * 0010 & 0011 = 1
     * 0001 & 0011 = 1
     * 
     * The number will be displayed on 32 bits because sizeof(decimal_value) = 4 bytes.
     */
    printf("%d (10) = ", decimal_value);
    for (int i = sizeof(decimal_value) * 8 - 1; i >= 0; --i)
    {
        if (0 == ((1 << i) & decimal_value))
            printf("%u", 0);
        else
            printf("%u", 1);

        if (0 == i % 4)
            printf(" ");                
    }
    printf("(2)\n");
}