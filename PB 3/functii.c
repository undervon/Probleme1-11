#include"header.h"

/**
 * \fn void progressCallback(int index, int data_size)
 * \brief Callback function that displays the percentage between index and size size.
 * \param[in] index Index.
 * \param[in] data_size String size.
 * \return void
 **/
void progressCallback(int index, int data_size)
{
    printf("%.2lf%%\n", 100 * (double)index / (double)data_size);
}

/**
 * \fn void handleData(void (*progressCallback)(int index, int data_size), char* data, int data_size)
 * \brief Function that displays each decimal value of each byte in the string.
 * \param[in] progressCallback() Callback function.
 * \param[in] data The string.
 * \param[in] data_size String size.
 * \return void
 **/
void handleData(void (*progressCallback)(int index, int data_size), char* data, int data_size)
{
    int i = 0;
    while (i < data_size && '\0' != data[i])
    {
        printf("%d: ", data[i]);
        ++i;
        progressCallback(i, strlen(data));
    }
}