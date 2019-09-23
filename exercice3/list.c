#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

/**
* Retourne une Liste vide
* @return Une nouvelle Liste
*/
List new_list(void)
{
	return NULL;
}

/*----------------------------------------------------------------*/

/**
* Teste si une Liste est vide
* @param li La Liste
* @return true si la DListe ne contient pas d'éléments, false sinon
*/
Bool is_empty_list(List li)
{
	if(li == NULL)
		return true;

	return false;
}

/*----------------------------------------------------------------*/

/**
* Retourne la longueur d'une Liste
* @param li La Liste
* @return Le nombre d'éléments de la Liste
*/
int list_length(List li)
{
	if(is_empty_dlist(li))
		return 0;

	return li->length;
}

/*----------------------------------------------------------------*/

/**
* Retourne le premier élément de la Liste
* @param li La DListe
* @return Le premier entier
*/
int list_first(List li)
{
	if(is_empty_dlist(li))
		exit(1);

	return li->begin->value;
}

/**
* Retourne le dernier élément de la Liste
* @param li La Liste
* @return Le dernier entier
*/
int list_last(List li)
{
	if(is_empty_dlist(li))
		exit(1);

	return li->end->value;
}

/*----------------------------------------------------------------*/

/**
* Affiche une Liste
* @param li La Liste à parcourir
*/
void print_list(List li)
{
	if(is_empty_list(li))
	{
		printf("Rien a afficher, la Liste est vide.\n");
		return;
	}

	DListNode *temp = li->begin;

	while(temp != NULL)
	{
		printf("[%d] ", temp->value);
		temp = temp->next;
	}

	printf("\n");
}

/*----------------------------------------------------------------*/

/**
* Insère un élément en fin de Liste
* @param li La DListe
* @param x L'entier à ajouter
* @return La Liste avec son élément ajouté
*/
List push_back_list(List li, int x)
{
	ListNode *element;

	element = malloc(sizeof(*element));

	if(element == NULL)
	{
		fprintf(stderr, "Erreur : probleme allocation dynamique.\n");
		exit(EXIT_FAILURE);
	}

	element->value = x;
	element->next = NULL;

	if(is_empty_dlist(li))
	{
		li = malloc(sizeof(*li));

		if(li == NULL)
		{
			fprintf(stderr, "Erreur : probleme allocation dynamique.\n");
			exit(EXIT_FAILURE);
		}

		li->length = 0;
		li->begin = element;
		li->end = element;
	}
	else
	{
		li->end->next = element;
		li->end = element;
	}

	li->length++;

	return li;
}

/*----------------------------------------------------------------*/

/**
* Insère un élément en début de Liste
* @param li La Liste
* @param x L'entier à ajouter
* @return La Liste avec son élémént ajouté
*/
List push_front_list(List li, int x)
{
	ListNode *element;

	element = malloc(sizeof(*element));

	if(element == NULL)
	{
		fprintf(stderr, "Erreur : probleme allocation dynamique.\n");
		exit(EXIT_FAILURE);
	}

	element->value = x;
	element->next = NULL;

	if(is_empty_dlist(li))
	{
		li = malloc(sizeof(*li));

		if(li == NULL)
		{
			fprintf(stderr, "Erreur : probleme allocation dynamique.\n");
			exit(EXIT_FAILURE);
		}

		li->length = 0;
		li->begin = element;
		li->end = element;
	}
	else
	{
		element->next = li->begin;
		li->begin = element;
	}

	li->length++;

	return li;
}

/*----------------------------------------------------------------*/

/**
* Retire un élément en fin de DListe
* @param li La DListe
* @param x L'entier à supprimer
* @return La DListe moins l'élément supprimé
*/
List pop_back_list(List li)
{
	if(is_empty_dlist(li))
	{
		printf("Rien a supprimer, la DListe est deja vide.\n");
		return new_dlist();
	}

	if(li->begin == li->end)
	{
		free(li);
		li = NULL;

		return new_dlist();
	}

	DListNode *temp = li->end;

	li->end->next = NULL;
	temp->next = NULL;
	temp->back = NULL;

	free(temp);
	temp = NULL;

	li->length--;

	return li;
}

/*----------------------------------------------------------------*/

/**
* Retire un élément en début de Liste
* @param li La Liste
* @param x L'entier à supprimer
* @return La Liste moins l'élément supprimé
*/
List pop_front_list(List li)
{
	if(is_empty_dlist(li))
	{
		printf("Rien a supprimer, la DListe est deja vide.\n");
		return new_list();
	}

	if(li->begin == li->end)
	{
		free(li);
		li = NULL;

		return new_list();
	}

	ListNode *temp = li->begin;

	li->begin = li->begin->next;
	temp->next = NULL;

	free(temp);
	temp = NULL;

	li->length--;

	return li;
}

/*----------------------------------------------------------------*/

/**
* Nettoie complètement une Liste de ses éléments
* @param li La Liste à effacer
* @return Une nouvelle Liste (vide)
*/
List clear_list(List li)
{
	while(!is_empty_list(li))
		li = pop_back_list(li);

	return new_list();
}