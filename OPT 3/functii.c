#include"header.h"

/**
 * \fn void sent_message(msg_buffer buffer, key_t key)
 * \brief Function that puts a message in the message queue.
 * \param[in] buffer Message structure.
 * \param[in] key The key.
 * \return void
 **/
void sent_message(msg_buffer buffer, key_t key)
{
    int msgqid = 0;
    int msgflg = IPC_CREAT | 0666;
    size_t buffer_size = 0;

    /* Get the message queue ID for the given key */
    if (0 > (msgqid = msgget(key, msgflg)))
    {
        DBG_PRINT(1, "Error on msgget!");
        exit(EXIT_FAILURE);
    }

    /* Message type */
    buffer.msg_type = 1;

    buffer_size = strlen(buffer.msg_text) + 1;

    if (0 > msgsnd(msgqid, &buffer, buffer_size, IPC_NOWAIT))
    {
        printf("%d, %ld, %s, %ld\n", msgqid, buffer.msg_type, buffer.msg_text, buffer_size);
        exit(EXIT_FAILURE);
    }
    else
        printf("Message '%s' sent!\n", buffer.msg_text);
}

/**
 * \fn void recovery_message(msg_buffer buffer, key_t key)
 * \brief Function that removes a message from the message queue.
 * \param[in] buffer Message structure.
 * \param[in] key The key.
 * \return void
 **/
void recovery_message(msg_buffer buffer, key_t key)
{
    int msgqid = 0;

    if (0 > (msgqid = msgget(key, 0666)))
    {
        DBG_PRINT(1, "Error on msgget!");
        exit(EXIT_FAILURE);
    }

    /* Receive an answer of message type 1 */
    if (0 > msgrcv(msgqid, &buffer, MAX_TEXT, 1, 0))
    {
        DBG_PRINT(1, "Error on msgrcv!");
        exit(EXIT_FAILURE);
    }

    printf("Message is: %s\n", buffer.msg_text);
}