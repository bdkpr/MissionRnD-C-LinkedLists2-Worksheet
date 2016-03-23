/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	if (head == NULL){							//validation
		return -1;
	}
	struct node *short_node,*long_node,*previous;
	int median;
	previous=short_node = long_node=head;  
	/*here long_node moves 2 steps each time 
	       short node moves one step and 
		   previous node will hold the previous node of the short_node
	 For odd length loop will terminate when "long_node->next==NULL"
	 For even length loop will terminate at "long_node==NULL"
    */
	for (; long_node != NULL&&long_node->next != NULL; ){		
		previous = short_node;
		short_node = short_node->next;
		long_node = long_node->next->next;
	}
	if (long_node==NULL){					//for even length median is avg of middle pair of numbers.
		median = (short_node->num + previous->num) / 2;
	}
	else{
		median = short_node->num;
	}
	return median;
}