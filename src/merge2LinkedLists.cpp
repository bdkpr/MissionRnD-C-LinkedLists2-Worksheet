/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>

struct node {
	int num;
	struct node *next;
};

void add_node(struct node **, int);
struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1 == NULL && head2 == NULL){		//validation
		return NULL;
	}
	struct node *h1, *h2, *result=NULL;
	h1 = head1;
	h2 = head2;
	/*Applying merge logic
		here we compare  first unpicked element in head1 with first unpicked element in head2
		if head1 element is small we add that to result value and move head1 forward
		head2 element is small we that and move head2
	*/
	for (; h1 != NULL&&h2 != NULL;){
		if (h1->num <= h2->num){
			add_node(&result, h1->num);
			h1 = h1->next;
		}
		else{
			add_node(&result, h2->num);
			h2 = h2->next;
		}		
	}
	/*If any one reached to end then we add the remaining list to the result	*/
	while (h1 != NULL){
		add_node(&result, h1->num);
		h1 = h1->next;
	}
	while (h2 != NULL){
		add_node(&result, h2->num);
		h2 = h2->next;
	}
	return result;
}

void add_node(struct node **h, int data){		//creation of the list
	struct node *temp = (struct node *)malloc(sizeof(struct node)),*p;
	temp->num = data;
	temp->next = NULL;
	if (*h == NULL){
		*h = temp;
	}
	else{
		p = *h;
		while (p->next != NULL){
			p = p->next;
		}
		p->next = temp;
	}
}