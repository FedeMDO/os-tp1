#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Implementation de Listes et Listes doublement chaineé
#include "dlist.h" 
#include "list.h"

List init_list(List li, int from, int to){
    if(from < to){
        for (int i = from; i <= to; i++){
            li = push_back_list(li, i);
        }
        printf("La liste\n");
        print_list(li);
    }
    return li;
}

List concatLists(List first, List second){
    first->end->next = second->begin;
    first->end = second->end;
    return first;
}

DList fromListToDlist(List li, DList dli){
    ListNode *temp = li->begin;

    while (temp != NULL)
    {
        dli = push_back_dlist(dli, temp->value);
        temp = temp->next;
    }
    print_dlist(dli);
    return dli;
}

DList fromDListToCircular(DList dli){
    int m = 20;
    for (int i = 15; i <= m; i++){
        dli = push_back_dlist(dli, i);
    }
    printf("    La liste: \n    ");
    print_dlist(dli);

    // Circulaire (the first node has a reference to the last node of the list)
    dli->begin->back = dli->end;
    dli->end->next = dli->begin;
    return dli;
}

DList init_dlist(DList dli, int from, int to){
    for (int i = from; i <= to ; i++){
        dli = push_back_dlist(dli, i);
    }
    printf("    La liste: \n    ");
    print_dlist(dli);
    return dli;
}

void descendant_order_list(DList dli, int n){
    DListNode *temp2Desc= dli->end; // begin from the end

    // if n > list length then we cant work
    // we do n = length and we say it to the client ok 
    if(n > dli->length){
        printf("Sorry, the max length of the given list is %d. Changing value of n from %d to %d \n", 
                dli->length, n, dli->length);
        n = dli->length;
    } else if (n < 1) {
        return;
    }
    printf("    n final value is %d, we will iterate %d times\n", n, n);   

    // start the descending loop n iterations.
    int j = 0;
    printf("    ");   
    while (j < n)
    {
        printf("[%d] ", temp2Desc->value);
        temp2Desc = temp2Desc->back;
        j++;
    }
    printf("\n");   
    return;
}

void showingCircularBehavior(DList dli){
    printf("    Demonstration (boucle 10 fois harcoded): \n");
    DListNode *dTemp = dli->begin;
    int i = 0;
    printf("    ");
    while (i < 10)
    {
        printf("%d ", dTemp->value);
        dTemp = dTemp->next;
        i++;
    }
    printf("\n");
}

void square_list(List li){
    printf("RESULT: \n");    
    ListNode *temp2Square = li->begin;

    while (temp2Square != NULL)
    {
        printf("[%f] ",((double) temp2Square->value * (double) temp2Square->value));
        temp2Square = temp2Square->next;
    }
    printf("\n");   
    return; 
}

int main(int argc, char const *argv[])
{
    printf("\n1 - Créez une liste chaînée contenant les n premiers entiers dans l’ordre croissant \n");
    List list1 = new_list();
    list1 = init_list(list1, 1, 10);

    printf("\n2 - Créez une fonction qui renvoie la longueur d’une liste \n");
    printf("Longueur du List1: %d\n", list_length(list1));

    printf("\n3 - Moyenne \n");
    average_list(list1);

    printf("\n4 - Écrivez une fonction qui retourne la liste des carrés d’une autre liste \n");
    square_list(list1);

    printf("\n5 - Retirez le premier élément \n");
    list1 = pop_front_list(list1);
    print_list(list1);

    printf("\n6 - Retirez le dernier élément \n");
    list1 = pop_back_list(list1);
    print_list(list1);

    printf("\n7 - Ajoutez un élément à la fin. Value 97 \n");
    list1 = push_back_list(list1, 97);
    print_list(list1);

    printf("\n8 - Ajoutez un élément au début. Value 57 \n");
    list1 = push_front_list(list1, 57);
    print_list(list1);

    printf("\n9 - Écrire une fonction qui concatène deux listes \n");
    List list2 = new_list();
    printf("creating list2 (that is going to be concatened with list1) \n");
    printf("we want list2 first, so we put list2 as the first argument \n");

    list2 = init_list(list2, 100, 110);
    list2 = concatLists(list2, list1);
    printf("RESULT: \n");
    print_list(list2);

    printf("\n10 - Transformez votre liste en une liste doublement chaînée \n");
    DList dlist1 = new_dlist();
    dlist1 = fromListToDlist(list1, dlist1);

    printf("\n11 - Créez une liste doublement chaînée circulaire \n");
    printf("    Initialization du Liste doublement chainée \n");
    DList dlist2 = new_dlist();
    dlist2 = fromDListToCircular(dlist2);
    printf("    Comportement circulaire prêt \n");

    // Demontration (10 fois)
    showingCircularBehavior(dlist2);

    printf("\n12 - Afficher les les n premiers entiers dans l’ordre décroissant \n");
    DList dlist3 = new_dlist();
    dlist3 = init_dlist(dlist3, 80, 100);
    descendant_order_list(dlist3, 12); 

    return 0;
}

