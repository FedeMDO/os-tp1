#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/*Globals*/
//On définit ici les variables globales
int const initialized_global = 0;
int uninitialized_global;
int heap_variable;
int pid, status, i;

/*Exercice 1 : Segmentation mémoire */

int main(){
    //On définit la variable stack_variable pour obtenir l'adresse de la stack
    int stack_variable;
    int *heap_variable = malloc(sizeof(int)); /*On utilise un malloc pour obtenir l'adresse du heap */

    /*On affiche ici les différentes adresses*/
    printf("Affichage adresse data : %p\n",&initialized_global);
    printf("Affichage adresse BBS : %p\n",&uninitialized_global);
    printf("Affichage adresse Heap %p\n",&heap_variable);
    printf("Affichage adresse Stack %p\n",&stack_variable);

    //Question bonus
    printf("Affichage adresse de la fonction main() %p\n", &main);
    

    //Question pmap
    pid = fork();
    if(pid == -1){
        // error
        return 1;
    }
    if (pid > 0)
    {
        // parent process
        printf("Je suis le père PID: %d\n", getpid());
        wait(&status);
    }
    else if (pid == 0)
    {   
        // child process
        printf("Je suis le fils PID: %d\n", getpid());
        char buffer[50];
        const int i = getppid(); 
        sprintf(buffer, "%d", i);         
        execlp("pmap","pmap","-X", buffer, NULL);
    }
    return 0;
}
