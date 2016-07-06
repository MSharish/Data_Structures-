// Implementation of Dictionary using Linked Lists in C programming. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 101

struct dictionary{       // structure of each record. 
	
	char name[100];
	char  id[100];
	struct dictionary * nd;
	
};


struct dictinary * hastable[MAXSIZE];

void insert ( char * name, char * id);

int delete(char * id);

int search(char *id);

void display();

unsigned hash(char * name);

void makenull();

void search_hashtable( char * id);



int main(int argc, char *argv[]) {
	
	char * name, *id;
	int ch, return_value;
	name = malloc(100);
	id = malloc(100);
	makenull();
	
	printf("1.Insert into Dictinary\n2.Search element in the dictionary\n3.Delete element from the dictionary\n4.Display the Dictionary\n 5. Any key to exit\n");
	
	while ( ( scanf("%d",&ch)) != EOF ){
		
		switch (ch){
			
			case 1: printf ("Enter the name\n");
			        scanf("%s",name);
			        printf("You entered = %s\n",name);
			        //gets(name);
			        printf("Enter the ID\n");
			        scanf("%s",id);
			        //gets(id);
			        insert(name,id);
			        break;
		    case 2: printf("Enter the ID you want to search\n");
		            scanf("%s",id);
		            return_value = search(id);
		            if ( return_value == 0)
		              printf("the record for specified id is not present\n");
		            break;
		    case 3: printf("Enter the ID of the record you want to delete\n");
		            scanf("%s",id);

		            return_value =  delete(id);
		            if ( return_value == 1)
		               printf("Record deleted successfully\n");
		            else 
		               printf("Deletion failed or record doesnt exists\n");
		            break;
		    case 4: display();
		            break;
			
			default: exit(0);
			
		}
		
		printf("1.Insert into Dictinary\n2.Search element in the dictionary\n3.Delete element from the dictionary\n4.Display the Dictionary\n 5. Any key to exit\n");
		
	}
	
	
}

void insert ( char * name, char * id){
	
	//printf("Inside the insert function\n");
	
	unsigned hash_code;
	
	struct dictionary * new_dictionary, * temp_iterator;
	int return_code;
	
	if ( search(id) == 0 ){    // if the record is not already present 
	      printf("No records present\n");
	     new_dictionary = malloc (sizeof(struct dictionary));
	     //printf("New Memory allocated\n");
	     hash_code = hash(name);
	    printf("The hash code = %d\n",hash_code);
	     if (hastable[hash_code] == NULL){
			
		    hastable[hash_code] =  new_dictionary;
		    strcpy(new_dictionary -> name,name);
		    strcpy(new_dictionary -> id ,id);
		    new_dictionary -> nd = NULL;
		
	     }
	    else{
		  temp_iterator = hastable[hash_code];
		  while ( temp_iterator->nd != NULL)
		      temp_iterator = temp_iterator->nd;
		
		  temp_iterator->nd = new_dictionary;
		  strcpy(new_dictionary -> name,name);
		  strcpy(new_dictionary -> id ,id);
		  
		  new_dictionary -> nd = NULL;
		
	    }
	
    }

  else { // If the record is already present

  }
     
}

unsigned hash(char * name){
	
	unsigned hashval;
		
	
		for ( hashval = 0; *name != '\0'; name++ ){
			
		  // printf("the value of letter = %d\n",*name);
		   hashval = *name + (31 * hashval);
		
		}
		
		
		return (hashval % MAXSIZE);
	
}

int search(char *id){
	struct dictionary * temp_iterator = NULL;
	
	int i,k=0;
	 
	for (i =0; i<= MAXSIZE-1;i++){
		
		if ( hastable[i] ==  NULL){
			
			k++;
		}
		else{
			
			//printf("The hastabe is not null\n");
			temp_iterator = hastable[i];
			while (temp_iterator->nd != NULL ){
				
				if ( strcmp(temp_iterator->id,id)==0){
					printf("The record  already exists\n");
					printf("******************\n");
					printf("%s\t%s\n",temp_iterator->name,temp_iterator->id);
					printf("******************\n");
				    return 1;
				
				}
				else 
				    temp_iterator = temp_iterator->nd;
				
			}
			
			 if ( strcmp(temp_iterator->id,id)==0){
				
				printf("The record  already exists\n");
				printf("******************\n");
				printf("%s\t%s\n",temp_iterator->name,temp_iterator->id);
				printf("******************\n");
			    return 1;
			
			
			}
			
			
		}
		
	}
	
	//printf("the value of k = %d\n",k);
	return 0;
	
}

int delete(char * id){
	struct dictionary * temp_iterator = NULL, * buf_iterator;
	int i,k=0;
	 
	for (i =0; i<= MAXSIZE-1;i++){
		
		if ( hastable[i] ==  NULL){
			
			//printf("The hash table is NULL\n");
			
			k++;
			//printf("the value of k = %d\n",k);
		}
		else{
			
			temp_iterator = hastable[i];
			
			if (strcmp(temp_iterator->id,id) == 0 ){
	            //printf("first element\n");
				hastable[i] = temp_iterator->nd;
				free(temp_iterator);
				return 1;
				
			}
				
			else{	
				  
				  if(temp_iterator->nd == NULL){
					
					
				   }
				else{
						   temp_iterator = temp_iterator->nd;
						   buf_iterator = hastable[i];
							
							while (temp_iterator->nd != NULL ){
								 
								
								if ( strcmp(temp_iterator->id,id)==0){
									buf_iterator ->nd =temp_iterator->nd;
									free(temp_iterator);
								    return 1;
								
								}
								else {
								    temp_iterator = temp_iterator->nd;
								    buf_iterator = buf_iterator->nd;
								}
								
							}
							
							 if ( strcmp(temp_iterator->id,id)==0){
								   
								    buf_iterator ->nd =temp_iterator->nd;
									free(temp_iterator);
								    return 1;
							
							 }
							
				    }// close of last else  from the top
				
					
			     }//close of second else from the top
			
		}// close of first else from the top
		
	} // close of for loop 
	
    //printf("the value of k = %d\n",k);
	return 0;
	
}


void display(){
	
	
	
}

void makenull(){
	
	int i;
	for ( i = 0; i<= MAXSIZE-1;i++){
		
		hastable[i] =  NULL;
		
	}
		
}

void search_hashtable( char * id){
	
	

	
}

