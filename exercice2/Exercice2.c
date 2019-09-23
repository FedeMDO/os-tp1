#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

/* This contains the mmap calls. */
#include <sys/mman.h>
#include <fcntl.h>

/* Global */
FILE *fp;

/* The file descriptor. */
int fd;

/* Information about the file. */
struct stat s;
int status;
size_t fsize;

/* The file name to open. */
const char *file_name = "Exercice2.txt";

/* The memory-mapped thing itself. */
const char *mapped;
int i;

/*Exercice 2 : Projection de fichier en mémoire*/

// Question 1 et 2
void openFile()
{
    fd = open(file_name, O_RDONLY);

    // get file info
    status = fstat(fd, &s);
}

void fileSize()
{
    //file size
    fsize = s.st_size;
    printf("Taille: %ld\n", fsize);
}

void mapFile()
{
    /* Memory-map the file. */
    mapped = mmap(0, fsize, PROT_READ, MAP_PRIVATE, fd, 0);
    char buf[(int)fsize];
    int y = 0;
    printf("%d\n", (int)fsize);
    for (i = (int)fsize - 1; i >= 0; i--)
    {
        if(mapped[i] != '\n'){
            char c = mapped[i];
            buf[y] = c;
            y++;
        }
    }
    buf[y] = '\0';
    printf("mapped one %s\n", mapped);
    printf("inverted one %s\n", buf);
    //mapped = mmap(0, fsize, PROT_READ, MAP_PRIVATE, fd, 0);
    if( munmap(0, fsize) == 0){
        printf("Munmap succesful\n");
    } else {
        printf("Munmap error\n");
    }
}

int main()
{
    openFile();
    fileSize();
    mapFile();
    return 0;
}