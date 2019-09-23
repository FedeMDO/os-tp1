#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Implementation de Listes et Listes doublement chaineé
#include "dlist.h" 
#include "list.h"

int main(int argc, char const *argv[])
{
    // 1 Créez une liste chaînée contenant les n premiers entiers dans l’ordre croissant
    printf("\n1 - Créez une liste chaînée contenant les n premiers entiers dans l’ordre croissant \n");
    List list1 = new_list();
    int i, n = 10;
    for (i = 1; i <= n; i++){
        list1 = push_back_list(list1, i);
    }
    printf("La liste\n");
    print_list(list1);

    // 2 Créez une fonction qui renvoie la longueur d’une liste.
    printf("\n2 - Créez une fonction qui renvoie la longueur d’une liste \n");
    printf("Longueur du List1: %d\n", list_length(list1));

    // 3 Créez une fonction qui renvoie la moyenne d’une liste
    printf("\n3 - Moyenne \n");
    average_list(list1);

    // 4 Écrivez une fonction qui retourne la liste des carrés d’une autre liste passée en para-mètre.
    printf("\n4 - Écrivez une fonction qui retourne la liste des carrés d’une autre liste \n");
    printf("TODO\n");// TODO    

    // 5 Retirez le premier élément d’une liste.
    printf("\n5 - Retirez le premier élément \n");
    list1 = pop_front_list(list1);
    print_list(list1);

    // 6 Retirez le dernier élément d’une liste.
    printf("\n6 - Retirez le dernier élément \n");
    list1 = pop_back_list(list1);
    print_list(list1);

    // 7 Ajoutez un élément à la fin d’une liste.
    printf("\n7 - Ajoutez un élément à la fin. Value 97 \n");
    list1 = push_back_list(list1, 97);
    print_list(list1);

    // 8 Ajoutez un élément au début d’une liste.
    printf("\n8 - Ajoutez un élément au début. Value 57 \n");
    list1 = push_front_list(list1, 57);
    print_list(list1);

    // 9 Écrire une fonction qui concatène deux listes
    printf("\n9 - Écrire une fonction qui concatène deux listes \n");
    printf("TODO\n");// TODO    
    
    // 10 Transformez votre liste en une liste doublement chaînée
    printf("\n10 - Transformez votre liste en une liste doublement chaînée \n");
    DList dlist1 = new_dlist();
    ListNode *temp = list1->begin;

    while (temp != NULL)
    {
        dlist1 = push_back_dlist(dlist1, temp->value);
        temp = temp->next;
    }
    print_dlist(dlist1);

    // 11 Créez une liste doublement chaînée circulaire (adaptez les fonctions précédentes)
    printf("\n11 - Créez une liste doublement chaînée circulaire \n");

    printf("    Initialization du Liste doublement chainée \n");
    DList dlist2 = new_dlist();
    dlist2 = push_back_dlist(dlist2, 1);
    dlist2 = push_back_dlist(dlist2, 2);
    dlist2 = push_back_dlist(dlist2, 3);
    printf("    La liste: \n    ");
    print_dlist(dlist2);

    // Circulaire (the first node has a reference to the last node of the list)
    dlist2->begin->back = dlist2->end;
    dlist2->end->next = dlist2->begin;
    printf("    Comportement circulaire prêt \n");

    // Demontration (10 fois)
    printf("    Demonstration (boucle 10 fois harcoded): \n");
    DListNode *dTemp = dlist2->begin;
    i = 0;
    printf("    ");
    while (i < 10)
    {
        printf("%d ", dTemp->value);
        dTemp = dTemp->next;
        i++;
    }
    printf("\n");

    // 12 Afficher les les n premiers entiers dans l’ordre décroissant.
    printf("\n12 - Afficher les les n premiers entiers dans l’ordre décroissant \n");
    printf("TODO\n");// TODO    

    return 0;
}

