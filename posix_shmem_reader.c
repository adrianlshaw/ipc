#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>
#include "protocol.h"

int main()
{
    /* open the shared memory object */
    int shm_fd = shm_open(ID, O_RDONLY, 0666);

    /* memory map the shared memory object */
    void *ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);

    if (ptr == MAP_FAILED) {
	puts("Map failed. Did you start the reader? Bailing");
	return 1;
    }

    /* read from the shared memory object */
    printf("%s", (char*)ptr);
    puts("");

    /* remove the shared memory object */
    shm_unlink(ID);
    return 0;
}
