#include"header.h"

/**
 * \fn bool isEmpty(Node* node)
 * \brief Function that indicates whether the list is empty or not.
 * \param[in] *node Structure.
 * \return bool true when the list is empty / false otherwise
 **/
bool isEmpty(Node* node)
{
    if (NULL == node)
        return true;
    else
        return false;
}

/**
 * \fn void insert_node(Node** node, char* value)
 * \brief Function that inserts a string in the list.
 * \param[in/out] **node Structure.
 * \param[in] *value String.
 * \return void
 **/
void insert_node(Node** node, char* value)
{
    Node* temp_node = (*node);
    int ok = 0;

    if (false == isEmpty(temp_node))
    {
        while(NULL != temp_node)
        {
            if (0 == strcmp(temp_node->word, value))
            {
                ++temp_node->freq;
                ok = 1;
            }
            temp_node = temp_node->next;
        }
    }
    if (0 == ok)
    {
        if (true == isEmpty(*node))
        {
            (*node) = (Node*)malloc(sizeof(Node));
            if (NULL == (*node))
            {
                DBG_PRINT(1, "Error when allocating memory for the node!");
                exit(EXIT_FAILURE);
            } 
            (*node)->word = value;
            (*node)->freq = 1;
        }
        else
        {
            Node* aux_node = (Node*)malloc(sizeof(Node));
            if (NULL == aux_node)
            {
                DBG_PRINT(1, "Error when allocating memory for the aux_node!");
                exit(EXIT_FAILURE);
            }
            aux_node->word = value;
            aux_node->freq = 1;
            aux_node->next = (*node);
            (*node) = aux_node;
        }
    }
}

/**
 * \fn void print_node(Node* node)
 * \brief Function that displays the contents of the list.
 * \param[in] *node Structure.
 * \return void
 **/
void print_node(Node* node)
{
    while (NULL != node)
    {
        printf("'%s' -> ", node->word);
        printf("%d\n", node->freq);
        node = node->next;
    }
}

/**
 * \fn void sort_node(Node** node)
 * \brief Function that sorts the list in descending order.
 * \param[in/out] **node Structure.
 * \return void
 **/
void sort_node(Node** node)
{
    Node* node_temp1 = (Node*)malloc(sizeof(Node));
    if (NULL == node_temp1)
    {
        DBG_PRINT(1, "Error when allocating memory for the node_temp1!");
        exit(EXIT_FAILURE);
    }
    Node* node_temp2 = (Node*)malloc(sizeof(Node));
    if (NULL == node_temp2)
    {
        DBG_PRINT(1, "Error when allocating memory for the node_temp2!");
        exit(EXIT_FAILURE);
    }

    node_temp1 = (*node);
    node_temp2 = (*node);

    while (NULL != node_temp1)
    {
        while (NULL != node_temp2)
        {
            if (node_temp1->freq > node_temp2->freq)
            {
                Node* node_aux = (Node*)malloc(sizeof(Node));
                if (NULL == node_aux)
                {
                    DBG_PRINT(1, "Error when allocating memory for the node_aux!");
                    exit(EXIT_FAILURE);
                }

                node_aux->freq = node_temp1->freq;
                node_aux->word = node_temp1->word;

                node_temp1->freq = node_temp2->freq;
                node_temp1->word = node_temp2->word;

                node_temp2->freq = node_aux->freq;
                node_temp2->word = node_aux->word;
            }
            node_temp2 = node_temp2->next;
        }
        node_temp2 = (*node);
        node_temp1 = node_temp1->next;
    }
}