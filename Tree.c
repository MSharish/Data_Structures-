
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	struct node * left;
	struct node * right;
	struct node * parent;
	int data;
};

void insert_tree( struct node * new_node, struct node * temp);

void display( struct node * node);

void delete( int key);

struct node * fetch_address( int key,struct node * node);

void real_delete_function(struct node * temp_address);

struct node * rec_function( struct node * addr);

struct node * root = NULL;

struct node * temp = NULL;

int main(int argc, char *argv[]) {
	
	int choice,data,delete_element;
	struct node * new_node;
	printf("1.Insert into tree\n2.Display tree\n3.Delete Elements from tree\n4.Exit\n");

while (scanf("%d",&choice))	{

		
	switch ( choice){
	
		case 1: new_node = malloc(sizeof (struct node));
		        printf("Enter the data\n");
		        scanf("%d",&new_node->data);
		        temp = root;
		        new_node->left = NULL;
		        new_node->right = NULL;
		        insert_tree(new_node,temp);
		        break;
		
		case 2:temp = root;
		       display(temp);
		       printf("\n");
		       break;
		
		case 3:temp = root;
		       printf ("Enter the element you want to delete\n");
		       scanf("%d",&delete_element);
		       delete(delete_element);
		       break;
		
		case 4: exit(0);
		       break;
		
		
	}
	    printf("1.Insert into tree\n2.Display tree\n3.Delete Elements from tree\n4.Exit\n");
		printf("Enter your choice\n");
 }
	
}

void insert_tree( struct node * new_node, struct node * temp){
	
      if ( root == NULL){
	     
	      root = new_node;
	      new_node->parent = NULL;
	
	 }
	   
	  else{
		
		if ( new_node->data <= temp->data){
			
			if ( temp->left == NULL){
			     temp->left  = new_node;
			     new_node->parent = temp;
			
			}
			else
			    insert_tree(new_node,temp->left);
				
	
		 }
		if ( new_node->data > temp->data){
				
				if ( temp->right == NULL){
				     temp->right  = new_node;
				     new_node->parent = temp;
				
				}
				else
				    insert_tree(new_node,temp->right);
					
		
			 }
		
	  } 

	
}

void display(struct node * node){
	
	if ( node == NULL){
		
	
	}
	else {
		printf("%d\t",node->data);
		display(node->left);
		display(node->right);
		
	}
	
}

void delete( int key){
	
	struct node * temp_address = NULL;
	temp = root;
	temp_address = fetch_address(key,temp);
	printf ("The temp->address data = %d\n",temp_address->data);

	//temp = root;
	real_delete_function(temp_address);
	
}

struct node * fetch_address( int key, struct node * node){
	
     while ( node->data != key){
	   
	   if ( key > node->data)
	      node = node->right;
	   else 
	      node = node->left;
	
      }

    return node;
	
}

void real_delete_function(struct node * temp_address){
	
	struct node * some_address;
	printf("Inside real_delete-function\n");
	

  // if a node has no children	
	
	if ( ( temp_address->left == NULL) && ( temp_address->right == NULL) ){
		  printf("Its a leaf\n");
		
		if ( temp_address->parent->left == temp_address){
			
			printf("parent's right child\n");
			temp_address->parent->left = NULL;
			free(temp_address);
			
		}
		
		else if ( temp_address->parent->right == temp_address){
			printf("parent's left child\n");		
			temp_address->parent->right = NULL;
		    free(temp_address);
					
		}
	}
	
	// if a node has only 1 child
	
	else if ( ( temp_address->left == NULL) || ( temp_address->right == NULL) ){
		
		  printf("Either one of the child is NULL\n");
		
		if ((temp_address->right == NULL)&& (temp_address->data > temp_address->parent->data)){
			
			temp_address->parent->right = temp_address->left;
			free(temp_address);
			
		}
		else if ((temp_address->right == NULL)&& (temp_address->data <= temp_address->parent->data)){
			
			temp_address->parent->left = temp_address->left;
			free(temp_address);
			
		}
		else if ((temp_address->left == NULL)&& (temp_address->data > temp_address->parent->data)){
			
			temp_address->parent->right = temp_address->right;
			free(temp_address);
			
			
		}
		else if ((temp_address->left == NULL)&& (temp_address->data <= temp_address->parent->data)){
			
			temp_address->parent->left = temp_address->right;
			free(temp_address);
			
		}
		
		
	}


   // if a node has both the children
    else if (( temp_address->left != NULL) && ( temp_address->right != NULL)){
	
	
	   if (temp_address->right->left == NULL ){
		     printf("The next child's left child is NULL\n");
		
		     temp_address->data = temp_address->right->data;
		     temp_address = temp_address->right;
		     free(temp_address);
		
	    }
	  else{
	
	    some_address = rec_function(temp_address->right);
	    temp_address->data  = some_address->data;
	    free(some_address);
	  }
	
    }
	
}

struct node * rec_function( struct node * addr){
	
	while (( addr->left != NULL) && ( addr->right!=NULL))
		
		addr = addr->left;
		
	return addr->left;
		
}

