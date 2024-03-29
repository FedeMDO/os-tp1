#ifndef __LIST__H__
#define __LIST__H__

    /* Définition d'une Liste */
	typedef struct List
	{
		int length;
		struct ListNode *begin;
		struct ListNode *end;
	}*List;

	/* Définition d'un maillon de la Liste */
	typedef struct ListNode
	{
		int value;
		struct ListNode *next;
	}ListNode;

    /* Prototypes Listes */
	List new_list(void);
	int is_empty_list(List li);
	void average_list(List li);
	int list_length(List li);
	void print_list(List li);
	List push_back_list(List li, int x);
	List push_front_list(List li, int x);
	List pop_back_list(List li);
	List pop_front_list(List li);

#endif