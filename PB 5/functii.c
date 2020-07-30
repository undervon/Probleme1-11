#include"header.h"

/**
 * \fn int serializeData(COMPONENT_DATA* component_info, void* buffer, size_t buffer_size, size_t* result)
 * \brief Serialize; this function serializes the content of the component_info and fills the passed buffer with it.
 * \param[in] component_info Has all the members initialized and filled with valid data.
 * \param[in/out] buffer Is allocated by the caller before calling this function and will contain the serialized data if big enough.
 * \param[in] buffer_size Size in bytes of the already allocated buffer passed to this function.
 * \param[in/out] result 0 success, non-zero error.
 * \return int return_size size in bytes of the serialized data that must be filled in buffer.
 **/
int serializeData(COMPONENT_DATA* component_info, void* buffer, size_t buffer_size, size_t* result)
{
    int return_size = 0;

    if (strlen(component_info->name) < buffer_size)
    {
        memcpy((int*)buffer, &component_info->attributes, sizeof(component_info->attributes));
        memcpy((size_t*)buffer + sizeof(component_info->attributes), &component_info->name_size, 
        sizeof(component_info->name_size));
        /* memcpy((char*)buffer + sizeof(component_info->attributes) + sizeof(component_info->name_size), 
        &component_info->name, strlen(component_info->name)); */
        strncpy((char*)buffer + sizeof(component_info->attributes) + sizeof(component_info->name_size), 
        component_info->name, component_info->name_size);

        return_size = sizeof(component_info->attributes) + component_info->name_size + 
        sizeof(component_info->name_size);
        *result = 0;
    }
    else
    {
        *result = -1;
        return_size = -1;
    }

    return return_size;
}

/**
 * \fn int deserializeData(void* buffer, size_t buffer_size, COMPONENT_DATA* component_info, size_t* result)
 * \brief Deserialize; this function deserializes the content of the buffer and fills component_info with it.
 * \param[in] buffer A buffer that is already allocated and contains the serialized data.
 * \param[in] buffer_size Size in bytes of buffer.
 * \param[in/out] component_info A valid pointer to a component_info that will be initialized with the data contained in the buffer.
 * \param[in/out] result 0 success , non-zero error.
 * \return int return_size size in bytes of the serialized data that must be filled in buffer.
 **/
int deserializeData(void* buffer, size_t buffer_size, COMPONENT_DATA* component_info, size_t* result)
{
    int return_size = 0;

    if (0 == *result) 
    {
        memcpy(&(component_info->attributes), (int*)buffer, sizeof(component_info->attributes));
        memcpy(&(component_info->name_size), (size_t*)buffer + sizeof(component_info->attributes), 
        sizeof(component_info->name_size));
        /* memcpy(&(component_info->name), (char*)buffer + sizeof(component_info->attributes) + 
        sizeof(component_info->name_size), strlen(component_info->name)); */
        strncpy(component_info->name, (char*)buffer + sizeof(component_info->attributes) + 
        sizeof(component_info->name_size), component_info->name_size);

        return_size = sizeof(component_info->attributes) + component_info->name_size + sizeof(component_info->name_size);
        *result = 0;
    }
    else
    {
        return_size = -1;
        *result = -1;
    }

    return return_size;
}