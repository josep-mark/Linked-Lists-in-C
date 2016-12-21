#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/* definition of linked list helper functions */


/*
 * this function adds a node to the beginning of the linked list
 * -returns head_node - or NULL if error
 */
struct_of_ints* add_to_top (struct_of_ints* head_node, int value ) {

	/* allocate memory for the new node */
	struct_of_ints* new_node = NULL ;
	new_node = malloc (sizeof(struct_of_ints)) ;

	/* check if malloc worked, otherwise, populate new node */
	if (new_node == NULL) return NULL ;
	new_node->value = value ;
	new_node->prev  = NULL  ;
	new_node->next  = head_node ;

	/* update former head pointer's links */
	if (head_node) head_node->prev = new_node ;

	/* return new head node */
	return new_node ;
}

/*
 * this function adds a node to the end of the linked list
 * -returns head_node - or NULL if error
 */
struct_of_ints* add_to_end (struct_of_ints* head_node, int value ) {

	/*Allocate memory for the new node*/
	struct_of_ints* new_node = NULL;
	new_node = malloc (sizeof(struct_of_ints));

	
	/*Check if malloc worked*/
	if (new_node == NULL) return NULL;

	if (head_node == NULL){						//case where there are no nodes
		new_node->value = value;				//set head node to new node, and assign its value, head_node next is null, last in list
		head_node = new_node;
		head_node->next = NULL;					
		return head_node;
	}


	
	while(head_node->next){						//find the last node
		head_node = head_node->next;
	}
	
	head_node->next = new_node;					//set head_node next to new node
	new_node->value = value;					//set value for new node
	new_node->prev = head_node;					//set new node previous address to last in list
	new_node->next = NULL;						//new node next is null because it is last

	// if (head_node) head_node->next = new_node;
	
	while(head_node->prev){						//reset head node to first
		head_node = head_node->prev;
	}

	return head_node ;							//return head node
}


/*
 * deletes the first instance of the "value" from the list
 * -returns head_node - or NULL if node isn't in list
 */
struct_of_ints*	delete_node (struct_of_ints* head_node, int value ) {
	struct_of_ints * temp_node = NULL;
	temp_node = malloc (sizeof(struct_of_ints));

	if(temp_node == NULL) return NULL;

	while(head_node){
		if(head_node->value == value){
			if(head_node->next && head_node->prev){		//case where the node is not first or last
				temp_node = head_node;					//Set temp node equal to head node
				temp_node->prev = head_node->prev;		//temp prev = head prev
				temp_node->next = head_node->next;		//temp next = head next
				head_node = head_node->prev;			//move back to previous node
				head_node->next = temp_node->next;		//set next pointer to skip the node
				head_node = head_node->next;			//move to the node after
				head_node->prev = temp_node->prev;		//set previous node to the node before
				free(temp_node);						//delete temp_node/the node with the values
				while (head_node->prev){
					head_node = head_node->prev;
				}
				return head_node;
			}
			if(head_node->next==NULL){					//case where the node is last
				head_node = head_node->prev;
				temp_node = head_node->next;
				head_node->next = NULL;
				free(temp_node);
				while (head_node->prev){				//reset head node
					head_node = head_node->prev;
				}
				return head_node;
			}
			if(head_node->prev==NULL){					//case where the node is first
				head_node = head_node->next;
				temp_node = head_node->prev;
				head_node->prev = NULL;
				free(temp_node);
				while (head_node->prev){				//reset head node
					head_node = head_node->prev;
				}
				return head_node;
			}
		}
		head_node = head_node->next;
	}

	free(temp_node);

	return NULL ;
}

/*
 * searches list for first instance of the "value" passed in
 * -returns node if found - or a NULL if node isn't in list
 */
struct_of_ints* search_list (struct_of_ints* head_node, int value ) {

	while (head_node){
		if (head_node->value == value){
			return head_node;
		}
		head_node = head_node->next;
	}

	return NULL ;
}


/*
 * sorts linked list in acending order: 1, 2, 3...
 * -returns new head of linked list after sort, or NULL if list is empty
 */
struct_of_ints* sort_list (struct_of_ints* head_node ) {
	int holder;

	if(head_node == NULL || head_node->next == NULL) return head_node;
	

	while(head_node->next){
		if (head_node->value > head_node->next->value){
			holder = head_node->value;
			head_node->value = head_node->next->value;
			head_node->next->value = holder;
			if(head_node->prev) sort_list(head_node->prev);
		}
		head_node = head_node->next;
	}

	
	while(head_node->prev){
		head_node = head_node->prev;
	}

	return head_node;
}


/*
 * sorts linked list in decending order: 3, 2, 1...
 * -returns new head of linked list after sort, or NULL if list is empty
 */
struct_of_ints* sort_list_rev (struct_of_ints* head_node ) {
	int holder;

	if(head_node == NULL || head_node->next==NULL) return head_node;

	while(head_node->next){
		if(head_node->value < head_node->next->value){
			holder = head_node->value;
			head_node->value = head_node->next->value;
			head_node->next->value = holder;
			if(head_node->prev) sort_list_rev(head_node->prev); 
		}
		head_node = head_node->next;
	}

	while(head_node->prev){
		head_node = head_node->prev;
	}

	return head_node ;
}


/*
 * prints entire linked list to look like an array
 */
void print_list (struct_of_ints* head_node ) {
	struct_of_ints * current_node = head_node;
	int i = 0 ;
	// if (head_node) printf ("\tlist[%d]=%d \n", i, head_node->value ) ;

	while (head_node){
		printf ("\tlist[%d]=%d \n", i, head_node->value);
		i++;
		head_node = head_node->next;
	}

	/* CIT 593 to do: this code only prints the first node,
			  print out the rest of the list! */

	/* To learn more about printf() - consult textbook, section 11.5.4 */

}


/*
 * delete every node in the linked list
 * returns NULL if successful, otherwise head node is returned
 */
struct_of_ints* delete_list (struct_of_ints* head_node ) {
	if(head_node == NULL) return NULL;
	// if(head_node->next == NULL) free(head_node);
	struct_of_ints * place_holder = head_node;
	head_node = head_node->next;

	while(head_node){
		free(place_holder);
		place_holder = head_node;
		head_node = head_node->next;
	}

	free(head_node);
	free(place_holder);

	return head_node ;
}
