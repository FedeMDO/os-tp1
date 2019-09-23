#ifndef __DLIST__H__
#define __DLIST__H__

	/* Définition d'un Booléen */
	typedef enum
	{
		false,
		true
	}Bool;

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

	/* Définition d'un maillon de la DListe */
	typedef struct DListNode
	{
		int value;
		struct DListNode *back;
		struct DListNode *next;
	}DListNode;

	/* Définition d'une DListe */
	typedef struct DList
	{
		int length;
		struct DListNode *begin;
		struct DListNode *end;
	}*DList;


	/* Prototypes Listes */
	List new_list(void);
	Bool is_empty_list(List li);
	int list_length(List li);
	int list_first(List li);
	int list_last(List li);
	void print_list(List li);
	List push_back_list(List li, int x);
	List push_front_list(List li, int x);
	List pop_back_list(List li);
	List pop_front_list(List li);
	List clear_list(List li);

	/* Prototypes Listes Doublement Chainee */
	DList new_dlist(void);
	Bool is_empty_dlist(DList li);
	int dlist_length(DList li);
	int dlist_first(DList li);
	int dlist_last(DList li);
	void print_dlist(DList li);
	DList push_back_dlist(DList li, int x);
	DList push_front_dlist(DList li, int x);
	DList pop_back_dlist(DList li);
	DList pop_front_dlist(DList li);
	DList clear_dlist(DList li);

#endif