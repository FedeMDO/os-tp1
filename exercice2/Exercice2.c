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
    //Open file
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
    /* Question 3 : Memory-map the file. */
    mapped = mmap(0, fsize, PROT_READ, MAP_PRIVATE, fd, 0);

    /* Question 4 : Inversion des octets*/

    //On crée un tableau buf dans lequel on va afficher les octets inversés
    char buf[(int)fsize];

    //On crée une boucle qui permet d'inverser les octets
    int y = 0;
    for (i = (int)fsize - 1; i >= 0; i--)
    {
        char c = mapped[i];
        buf[y] = c;
        y++;
    }
    // "\0" va permettre de s'arrêter à la fin du fichier afin d'exclurer les octets cachés
    buf[y] = '\0';

    //Affichage
    printf("mapped one %s\n", mapped);
    printf("inverted one %s\n", buf);


    /* Question 5 et 6*/
    //On libère l'espace adressé par mmap
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