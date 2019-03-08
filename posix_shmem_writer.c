#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h> 
#include <stdio.h> 
#include "protocol.h"

int main() 
{ 
    /* strings written to shared memory */
    const char* message_0 = "HelloWorld"; 
  
    /* create the shared memory object */
    int shm_fd = shm_open(ID, O_CREAT|O_RDWR, 0666);
  
    /* configure the size of the shared memory object */
    ftruncate(shm_fd, SIZE); 
  
    /* memory map the shared memory object */
    void *ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0); 
  
    /* write to the shared memory object */
    sprintf(ptr, "%s", message_0); 
    
    return 0; 
} 
