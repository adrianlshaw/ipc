#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <mqueue.h>
#include <fcntl.h>
#include "protocol.h"

int main()
{
    char buffer[SIZE] = { 0 };

    mqd_t handle = mq_open(ID, O_WRONLY);

    if (handle == -1) {
        puts ("Failed to get handle");
        return 1;
    }

    memcpy(buffer, "FOO", 4);

    if (mq_send(handle, buffer, SIZE, 0) == -1) {
        puts ("Failed to send");
        return 2;
    }

    puts ("Sent FOO");

    mq_close(handle);

    puts("Exiting");
    return 0;
}
