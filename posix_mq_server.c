#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <mqueue.h>

#include "protocol.h"

int main()
{
    char buffer[SIZE + 1];

    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = SIZE;
    attr.mq_curmsgs = 0;

    mqd_t handle = mq_open(ID, O_CREAT | O_RDONLY, 0644, &attr);

    if (handle == -1) {
        puts ("Failed to get handle");
        return 1;
    }

    for(;;) {
        ssize_t num_bytes = mq_receive(handle, buffer, SIZE, NULL);
        if (num_bytes == -1) {
            printf("Failed to read");
        }
        else {
            buffer[num_bytes] = '\0';
            printf("Received: %s\n", buffer);
        }
    }

    if (mq_close(handle) != -1) {
        mq_unlink(ID);
    }

    return 0;
}
