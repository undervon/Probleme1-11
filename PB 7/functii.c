#include"header.h"

/**
 * \fn int* allocInLib(void)
 * \brief Memory allocation function.
 * \param void
 * \return int* object Object.
 **/
int* allocInLib(void)
{
    int* object = (int*)malloc(sizeof(int));
    if (NULL == object)
    {
        DBG_PRINT(1, "Error when allocating memory for the object!");
        exit(EXIT_FAILURE);
    }

    DBG_PRINT(2, "Successful allocation!");

    return object;
}

/**
 * \fn void freeInLib(int* object)
 * \brief Memory release function.
 * \param[in] object Object.
 * \return void
 **/
void freeInLib(int* object)
{
    if (NULL != object)
    {
        free(object);
        object = NULL;

    }
    DBG_PRINT(2, "Deallocation successfully!");
}