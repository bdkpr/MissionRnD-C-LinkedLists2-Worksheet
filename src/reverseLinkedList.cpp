/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

void insertion_first(struct node **, int);

struct node * reverseLinkedList(struct node *head) {
	if (head == NULL){			//validation check
		return NULL;
	}
	struct node *reverse_head,*p=head;
	reverse_head = NULL;
	if (p != NULL){							/* for reversing the linked list,here i fallowed insertion first logic*/
		insertion_first(&reverse_head, p->num);
		p = p->next;
	}
	for (; p != NULL;p=p->next){
		insertion_first(&reverse_head, p->num);		//insertion first.
	}
	return reverse_head;						//returning the reversed linked list.
}

void insertion_first(struct node **h, int data){				//insertion first body.
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->num = data;
	temp->next = NULL;
	if (*h == NULL){
		*h = temp;
	}
	else{
		temp->next = *h;
		*h = temp;
	}
}