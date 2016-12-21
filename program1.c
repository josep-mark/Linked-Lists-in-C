#include <stdio.h>
#include "linked_list.h"


int print_menu() {

	int choice = 0 ;

	/* To learn more about printf() & scanf() - consult textbook, section 11.5.4 */

	printf ("\nLinked List Utility Menu\n") ;
	printf ("\ttype: (0) to exit\n") ;
	printf ("\ttype: (1) to print list\n" ) ;
	printf ("\ttype: (2) to add to start of list\n" ) ;
	printf ("\ttype: (3) to add to end of list\n" ) ;
	printf ("\ttype: (4) to search the list\n" ) ;
	printf ("\ttype: (5) to sort the list\n" ) ;
	printf ("\ttype: (6) to sort the list in reverse\n" ) ;
	printf ("\ttype: (7) to delete the entire list\n" ) ;
	printf ("\ttype: (8) to delete a node\n" ) ;

	/* TO DO: add menu items to test other linked list helper functions */
	// printf ("\ttype: (3) to print the list\n" ) ;

	scanf  ("%d", &choice ) ;
	return choice ;

}


int main () {

	int choice = 0 ;
	int number = 0 ;
	struct_of_ints* head_pointer = NULL ;


	while (1) {
  	   choice = print_menu() ;

	   /* To learn more about "switch" statement - consult textbook: 13.5.1 */
	   switch (choice) {
		case 1 :
			print_list (head_pointer) ;
			break ;

		case 2 :
			printf ("\tEnter number to add to list: " );
			scanf  ("%d", &number ) ;
			head_pointer = add_to_top (head_pointer, number ) ;
			break ;

		case 3 :
			printf ("\tEnter number to add to the end of the list: " );
			scanf  ("%d", &number ) ;
			head_pointer = add_to_end (head_pointer, number ) ;
			break ;

		case 4 :
			printf ("\tEnter number to search for: " );
			scanf  ("%d", &number ) ;
			head_pointer = search_list (head_pointer, number ) ;
			if(head_pointer){
				printf("\tFound it!\n");
			}
			if (head_pointer == NULL) printf("\tValue not in list");
			break ;

		case 5 :
			head_pointer = sort_list(head_pointer);
			break;

		case 6 :
			head_pointer = sort_list_rev(head_pointer);
			break;

		case 7 :
			head_pointer = delete_list(head_pointer) ;
			break ;

		case 8 :
			printf ("\tEnter a value to delete: " );
			scanf  ("%d", &number ) ;
			head_pointer = delete_node(head_pointer, number);
			break;


		default :
			printf ("\nExiting Program\n") ;
			head_pointer = delete_list(head_pointer) ;
			/* TO DO: check for clean delete */
			return 0 ;
			break ;
	   }
	}


	return 0 ;

}

