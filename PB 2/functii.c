#include"header.h"

/**
 * \fn uint32_t getValue(char* buffer, int offset, int buffer_size)
 * \brief Function that returns a uint_32 (value transformed from a string).
 * \param[in/out] buffer The string to be read.
 * \param[in] offset From which position (index) starts reading the strings.
 * \param[in] buffer_size String size.
 * \return uint32_t return_value Value to return.
 **/
uint32_t getValue(char* buffer, int offset, int buffer_size)
{
    uint32_t return_value = 0;
    if (offset > buffer_size) 
    {
        fprintf(stderr, "The offset is larger than the size of the buffer!\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        int i = 0;
        for (i = offset; i < buffer_size; ++i)
        {
            if ('\0' == buffer[i])
                break;
            else if ('0' < buffer[i] && '9' > buffer[i])
                return_value = return_value * 10 + (buffer[i] - '0');
            else
            {
                fprintf(stderr, "The string does not only contain numbers!\n");
                exit(EXIT_FAILURE);
            }
        }
    }
    return return_value;
}