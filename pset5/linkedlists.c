#include <stdio.h>
#include <stdlib.h>

struct node{ //STRUCTURE OF NODE
	int value;
	struct node * next;
};
typedef struct node node_t;

node_t * create_new_node(int value){ //CREATES A NODE
	node_t *result = malloc(sizeof(node_t));
	result->value = value;
	result->next = NULL;
	return result;
}

node_t * insert_after_head(node_t ** head, node_t * node_to_insert){ //PASSES A POINTER TO A POINT
	node_to_insert->next = *head;                                    //THIS ALLOWS US TO CHANGE THE HEAD POINTER
	*head = node_to_insert;										     //INSERTS CREATED NODE AT FRONT OF LIST
	return node_to_insert;
}

node_t * insert_after_node(node_t *node_to_insert_after, node_t * newnode){ //PLACES NEW NODE AT THE PREVIOUS SELECTED POSITION!
	newnode->next = node_to_insert_after->next;
	node_to_insert_after->next = newnode;
	return 0;
}

node_t *find_node(node_t * head, int value){
	node_t * tmp = head;
	while(tmp != NULL){
		if(tmp->value == value){
			return tmp;
		}
		else{
			tmp = tmp->next;
		}
	}
	return 0;
}

node_t * insert_at_last(node_t * head, node_t * newnode){ //PLACES NEW NODE AT THE LAST ELEMENT!
	node_t * temp = head;

	while(temp != NULL){
		if(temp->next != NULL){
			temp = temp->next;
		}
		else{
			temp->next = newnode;
			break;
		}
	}
	return 0;
}

void printlist(node_t * head){
	node_t *temp = head;

	while(temp != NULL){
		printf("%d ", temp->value);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
	node_t * head = NULL;
	node_t * tmp;
	node_t * position;
	int i;

	for(i = 0; i < 10; i++)
	{
		tmp = create_new_node(i);
		insert_after_head(&head, tmp); //INSERTS NEW NODE AT THE FRONT OF THE LIST
	}

	//tmp = find_node(head, 0);                                    //This part here will make it so that it will place the node created below right after this node! But
	//printf("Found node with value %d: \n", tmp->value);          //this is primarily for finding an element in a node
	//insert_after_node(tmp, create_new_node(100));

	i = 1000;
	tmp = create_new_node(i);
	insert_at_last(head, tmp);

	printlist(head);
	return 0;
}