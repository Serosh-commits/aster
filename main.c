#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>

#define MEM_SEG 4096
int main(int argc, char *argv[]){
    
    if(argc != 2){
        fprintf(stderr,"Usage: aster <input file>\n");
        return EXIT_FAILURE;
    }

    int fd = open(argv[1], O_RDONLY);

    if(fd == -1){
        perror("open");
        return EXIT_FAILURE;
    }

    char buffer[MEM_SEG];

    ssize_t  bytes_read = read(fd, buffer, sizeof(buffer));

    if(bytes_read == -1){
        perror("read");
        close(fd);
        return EXIT_FAILURE;
    }

    fwrite(buffer, 1 , (size_t)bytes_read, stdout);
    close(fd);
    return EXIT_SUCCESS;
}
