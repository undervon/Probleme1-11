#include"header.h"

int main(int argc, char const *argv[])
{
    COMPONENT_DATA* component_info = NULL;

    int size = 0;

    void* buffer = NULL;
    size_t buffer_size = 0;

    size_t* result = (size_t*)malloc(sizeof(size_t));
    if (NULL == result)
    {
        DBG_PRINT(1, "Error when allocating memory for the result!");
        exit(EXIT_FAILURE);
    }

    component_info = (COMPONENT_DATA*)malloc(sizeof(COMPONENT_DATA));
    if (NULL == component_info)
    {
        DBG_PRINT(1, "Error when allocating memory for the component_info!");
        exit(EXIT_FAILURE);
    }

    printf("The buffer size: ");
    scanf("%zu", &buffer_size);
    
    buffer = (void*)malloc(sizeof(void) * buffer_size);
    if (NULL == buffer)
    {
        DBG_PRINT(1, "Error when allocating memory for the buffer!");
        exit(EXIT_FAILURE);
    }

    printf("Value for the attributes: ");
    scanf("%d", &component_info->attributes);

    printf("Size fot the name: ");
    scanf("%zu", &component_info->name_size);

    component_info->name = (char*)malloc(sizeof(char) * component_info->name_size + 1);
    if (NULL == component_info->name)
    {
        DBG_PRINT(1, "Error when allocating memory for the component_info->name_size!");
        exit(EXIT_FAILURE);
    }

    getchar();
    printf("Imput the name: ");
    fgets(component_info->name, component_info->name_size + 1, stdin);

    if ('\n' == component_info->name[strlen(component_info->name - 1)])
        component_info->name[strlen(component_info->name) - 1] = '\0';

    printf("\n");   

    size = serializeData(component_info, buffer, buffer_size, result);
    
    if (0 == *result) 
    {
        DBG_PRINT(5, "Serialize data:\nSerialize size: %d\nAttributes: %d\nName: %s\nName size: %zu\n", 
        size, component_info->attributes, component_info->name, component_info->name_size);

        size = deserializeData(buffer, buffer_size, component_info, result);
    }
    else
    {
        DBG_PRINT(1, "Serialize error!");
        exit(EXIT_FAILURE);
    }

    if (0 == *result)
        DBG_PRINT(5, "Deserialize data:\nDeserialize size: %d\nAttributes: %d\nName: %s\nName size: %zu\n", 
        size, component_info->attributes, component_info->name, component_info->name_size);
    else
    {
        DBG_PRINT(1, "Deserialize error!");
        exit(EXIT_FAILURE);
    }

    /* memory deallocation */   
    if (NULL != buffer)  
    {
        free(buffer);
        buffer = NULL;
    }

    if (NULL != result)  
    {
        free(result);
        result = NULL;
    }
        
    if (NULL != component_info->name)  
    {
        free(component_info->name);
        component_info->name = NULL;
    }

    if (NULL != component_info)  
    {
        free(component_info);
        component_info = NULL;
    }
    return 0;
}