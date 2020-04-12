#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5

int stack[MAXSIZE];
int sp = 0;
int no_of_items = 0;

void push ( int data);
void pop();
void display();
void smallest_element();

int main(int argc, char *argv[]) {
	
	char choice;
	int data;
	
	printf("1.Push\n2.Pop\n3.Display\n4.find_smallest_element\n5.exit application\n");
	
	printf("enter your choice\n");
	
	
	
	while ( scanf ("%c",&choice) != -1) {
		
		switch ( choice){
			
			case '1':printf("enter the data\n");
			         scanf("%d",&data);
			         push(data);
			         break;
			
			case '2':pop();
			         break;
			
			
			case '3':display();
			         break;
			
			case '4':smallest_element();
			         break;
                        case '5': printf("thank you for using my service, exiting application\n");
                                 exit(0);			
			default:printf("enter your choice\n");
			        break;
			
		}
		
	}
			         
			         
}

void push(int data){
	
	int temp;
	
	if(sp == MAXSIZE)
	   printf("stack is full\n");
	
	
	
	else{
	
		    stack[++sp] = data;
		    no_of_items++;
	
		
}

}

void pop(){
	if( sp == 0)
      printf("Stack is empty\n");

   else{ 
	printf("The poped element is %d\n", stack[sp]);
	sp -= 1;
	no_of_items--;
   }
	
}


void display(){

	int i;
	
	if( sp == 0)
	  printf( "no elements to display\n");
	
	
	for (i = 1; i<= no_of_items; i++)
	   printf("%d\n",stack[i]);
	
}

void smallest_element(){
	
	int i, temp,j;
	
	for ( i =1; i<= no_of_items;i++){
		
		for ( j=i+1; j<= no_of_items; j++) {
			
			if( stack[i] > stack[j]){
				
				temp = stack[i];
				stack[i] = stack[j];
				stack[j] = temp;
				
			}
			
			
		}
		
		
		
	}
	
	printf( "the smallest element is %d\n", stack[1]);
}
