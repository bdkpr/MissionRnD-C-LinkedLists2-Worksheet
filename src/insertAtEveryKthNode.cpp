/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

void k_nodes_forward(struct node **, int);

struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (K < 1||head == NULL){			//validity check
		return NULL;
	}

	struct node *temp, *k_th_node=head;

	while (k_th_node != NULL){
		k_nodes_forward(&k_th_node, K);				//it will move K nodes forward and will point to the k th node
		if (k_th_node != NULL){						/*if the k th node is not null we will add the one k node to it */
			temp = (struct node *)malloc(sizeof(struct node));
			temp->num = K;
			temp->next = k_th_node->next;
			k_th_node->next = temp;
			k_th_node = k_th_node->next->next;
		}
	}
	return head;			//after inserting returning the head.
}

void k_nodes_forward(struct node **h, int k){		//here we will move K nodes forward,and point to the k th node.
	int i;
	for (i = 1; *h != NULL&&i < k; i++){
		*h = (*h)->next;
	}
}