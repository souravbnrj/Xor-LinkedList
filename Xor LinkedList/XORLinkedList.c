#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
struct linked
{
	int data;
	struct linked *npx;
};
typedef struct linked node;

node *XOR(node *a,node *b)
{
	node *address;
	address=(node *)((uintptr_t )(a)^(uintptr_t)(b));
	return(address);
	
}
node *insert(node **head)
{   
    int data;
    printf("Enter the data,-1 for exit\n");
    scanf("%d",&data);
    system("cls");
    while(data!=-1){
	
	node *nnode;
	nnode=(node *)malloc(sizeof(node));
	nnode->data=data;
	nnode->npx=XOR(*head,NULL);
	if(*head!=NULL)
	{
		node *next=XOR((*head)->npx,NULL);
		(*head)->npx=XOR(nnode,next);
		
	}
	*head=nnode;
	printf("Enter the data,-1 for exit\n");
    scanf("%d",&data);
    system("cls");
}
    node *curr=*head;
	node *prev=NULL;
	node *next;
	while(curr!=NULL)
	{
		
		next=XOR(prev,curr->npx);
		prev=curr;
		curr=next;
		
	}
	return(prev);
}
node *beg(node **head)
{  
 if(*head==NULL)
      {
      	printf("No data found enter data frist\n");
      	return(*head);
	  }
 int i;
 node *nnode,*next;
 printf("Enter the data\n");
 scanf("%d",&i);
 system("cls");
 nnode=(node *)malloc(sizeof(node));
 nnode->data=i;
 next=XOR((*head)->npx,NULL);
 (*head)->npx=XOR(nnode,next);
 nnode->npx=XOR(*head,NULL);
 *head=nnode;
 printf("Your element %d have been added\n",i);
	system("pause");
	system("cls");
 return(*head);
}
node *end(node **head)
{  
   if(*head==NULL)
      {
      	printf("No data found enter data frist\n");
      	return(*head);
	  }
	int i;
 node *nnode,*next,*curr,*prev;
 printf("Enter the data\n");
 scanf("%d",&i);
 system("cls");
 nnode=(node *)malloc(sizeof(node));
 nnode->data=i;
 curr=*head;
 prev=NULL;
 while(curr!=NULL)
	{
		
		next=XOR(prev,curr->npx);
		prev=curr;
		curr=next;
		
	}
	next=XOR(prev->npx,NULL);
    prev->npx=XOR(next,nnode);
	nnode->npx=XOR(prev,NULL);
	printf("Your element %d have been added\n",i);
	system("pause");
	system("cls");
	return(*head);
}
node *dbeg(node **head)
{   
    if(*head==NULL)
      {
      	printf("No data found enter data frist\n");
      	return(*head);
	  }
	node *ptr,*addrs,*next;
	ptr=*head;
	addrs=XOR(ptr->npx,NULL);
	next=XOR(addrs->npx,*head);
	addrs->npx=XOR(next,NULL);
	*head=addrs;
	free(ptr);
	printf("Your Element have been deleted From begining\n");
	system("PAUSE");
	system("cls");
	return(*head);
	
}
node *d_end(node **head)
{   
    if(*head==NULL)
      {
      	printf("No data found enter data frist\n");
      	return(*head);
	  }
	node *curr,*prev,*next;
    curr=*head;
   prev=NULL;
  while(curr!=NULL)
	{
	
		next=XOR(prev,curr->npx);
		prev=curr;
		curr=next;
		
	}
	next=XOR(prev->npx,NULL);
	curr=XOR(next->npx,prev);
	next->npx=XOR(curr,NULL);
	free(prev);
	printf("Your Element have been deleted From ending\n");
	system("PAUSE");
	system("cls");
	return(*head);
	
}
node *i_betw(node **head)
{
	if(*head==NULL)
      {
      	printf("No data found enter data frist\n");
      	return(*head);
	  }
	  int num,n;
	  printf("Enter the value after which new data \n");
	  scanf("%d",&num);
	 node *curr=*head;
	 node *prev=NULL;
	 node *next;
	 printf("Enter the value\n");
	scanf("%d",&n);
	node *nnode;
	nnode=(node *)malloc(sizeof(node));
    nnode->data=n;
	while(curr->data!=num)
	{
		next=XOR(prev,curr->npx);
		prev=curr;
		curr=next;
		
	}
   
	next=XOR(curr->npx,prev);
	curr->npx=XOR(prev,nnode);
	nnode->npx=XOR(curr,next);
	printf("Your data have been entered\n");
	system("pause");
	system("cls");
	return(*head);
}

void printxor(node *addr)
{   if(addr==NULL)
      {
      	printf("No data found enter data frist\n");
      	return;
	  }
	node *curr=addr;
	node *prev=NULL;
	node *next;
	printf("\nThis are the nodes of this linked list: \n");
	while(curr!=NULL)
	{
		printf("%d ",curr->data);
		next=XOR(prev,curr->npx);
		prev=curr;
		curr=next;
		
	}
	
}
main()
{
	node *head=NULL;
	int num;
	do
	{
	 printf("\n\n***** Task Menu *****\n");
	 printf("Press  1 for create new node :\n");
	 printf("Press  2 for print the data\n");
	 printf("Press  3 for Adding element in begning\n");
	 printf("Press  4 for Adding element in end\n");
	 printf("Press  5 for Deleting element in beginig\n");
	 printf("Press  6 for Deleting element in end\n");
	 printf("Press  7 for entering after the data\n");
	 printf("Enter -1 for Exit the menu\n");
	 scanf("%d",&num);
	 system("cls");
	 switch(num)
	 {
	 	case 1 :head=insert(&head);
	 	            break;
	 	case 2 : printxor(head);
		            break;
		case 3 : head=beg(&head);
		             break;
		case 4 : head=end(&head);
		             break;	
		case 5 : head=dbeg(&head);
		            break;
		case 6 : head=d_end(&head);
		             break;
		case 7 : head=i_betw(&head);
		             	break;
	}
	}while(num!=-1);
}


