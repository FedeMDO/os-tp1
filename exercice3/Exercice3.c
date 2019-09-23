#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Implementation de Listes et Listes doublement chaineé
#include "dlist.h" 
#include "list.h"

int main(int argc, char const *argv[])
{
    // 1 Créez une liste chaînée contenant les n premiers entiers dans l’ordre croissant
    List list1 = new_list();
    int i, n = 10;
    for (i = 1; i <= n; i++){
        push_back_list(list1, i);
    }

    // 2 Créez une fonction qui renvoie la longueur d’une liste.
    printf("Longueur du List1: %d\n", list_length(list1));

    // 3 Créez une fonction qui renvoie la moyenne d’une liste
    average_list(list1);
    
    // 5 Retirez le premier élément d’une liste.
    list1 = pop_front_list(list1);

    // 6 Retirez le dernier élément d’une liste.
    list1 = pop_back_list(list1);

    // 7 Ajoutez un élément à la fin d’une liste.
    list1 = push_back_list(list1, 97);

    // 8 Ajoutez un élément au début d’une liste.
    list1 = push_front_list(list1, 97);
    
    // 9 Écrire une fonction qui concatène deux listes

    // 10 Transformez votre liste en une liste doublement chaînée
    DList dlist1 = new_dlist();
    ListNode *temp = list1->begin;

	while(temp != NULL)
	{
        push_back_dlist(dlist1, temp->value);
		temp = temp->next;
	}
    print_dlist(dlist1);

    // 11 Créez une liste doublement chaînée circulaire (adaptez les fonctions précédentes)
    
    // 12 Afficher les les n premiers entiers dans l’ordre décroissant.

    
    return 0;
}

