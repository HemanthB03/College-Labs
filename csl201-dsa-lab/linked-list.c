#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* link;
};

struct node *head=NULL, *ptr=NULL, *temp=NULL, *prev=NULL, *current=NULL;
int data, key;

void insertFirst();
void inserLast();
void insertAfterKey();
void deleteFirst();
void deleteLast();
void deleteKey();
void display();

int main(void) {
	int ch;
	printf("\n----Menu----\n");
	printf("1.Insert First\n2.Insert Last\n3.Insert After A Key\n");
	printf("4.Delete First\n5.Delete Last\n6.Delete A Key\n");
	printf("7.Display\n8.Exit\n");
	do {
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1:
				insertFirst();
				break;
			case 2:
				inserLast();
				break;
			case 3:
				insertAfterKey();
				break;
			case 4:
				deleteFirst();
				break;
			case 5:
				deleteLast();
				break;
			case 6:
				deleteKey();
				break;
			case 7:
				display();
				break;
			case 8:
				printf("Exiting....\n");
				break;
			default:
				printf("Option not in menu, try again\n");
				break;
		}
	}
	while(ch!=8);
	return 0;
}

void insertFirst() {
	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL) {
		printf("Memory Underflow\n");
		return;
	}
	printf("Enter data: ");
	scanf("%d", &data);
	temp->data=data;
	temp->link=head;
	head=temp;
	display();
}

void inserLast() {
	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL) {
		printf("Memory Underflow\n");
		return;
	}

	printf("Enter data: ");
	scanf("%d", &data);

	temp->data=data;
	if(head==NULL) {
		temp->link=head;
		head=temp;
	}
	else {
		ptr=head;
		while(ptr->link!=NULL) {
			ptr=ptr->link;
		}
		ptr->link=temp;
		temp->link=NULL;
	}
	

	display();
}

void insertAfterKey() {
	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL) {
		printf("Memory Underflow\n");
		return;
	}

	printf("Enter data: ");
	scanf("%d", &data);
	printf("Enter key to insert after: ");
	scanf("%d", &key);

	temp->data=data;
	ptr=head;
	while(ptr->data!=key && ptr!=NULL) {
		ptr=ptr->link;
	}
	if(ptr==NULL) {
		printf("Key not in list\n");
		return;
	}
	temp->link=ptr->link;
	ptr->link=temp;

	display();
}

void deleteFirst() {
	if(head==NULL) {
		printf("List is empty\n");
		return;
	}
	printf("%d was deleted\n", head->data);
	prev=head;
	head=head->link;
	free((void*)prev);
	display();
}

void deleteLast() {
	if(head==NULL) {
		printf("List is empty\n");
		return;
	}
	current=head;
	prev=head;
	while(current->link!=NULL) {
		prev=current;
		current=current->link;
	}
	printf("%d was deleted\n", current->data);
	prev->link=NULL;
	free((void*)current);
	display();
}

void deleteKey() {
	if(head==NULL) {
		printf("List is empty\n");
		return;
	}
	printf("Enter key to delete: ");
	scanf("%d", &key);

	current=head;
	prev=head;
	while(current->data!=key && current!=NULL) {
		prev=current;
		current=current->link;
	}
	if(current==NULL) {
		printf("Key not in list\n");
		return;
	}
	printf("%d was deleted\n", current->data);
	prev->link=current->link;
	free((void*)current);
	display();
}

void display() {
	if(head==NULL) {
		printf("List is empty\n");
		return;
	}
	printf("Current list is\n");
	ptr=head;
	while(ptr!=NULL) {
		printf("%d, ", ptr->data);
		ptr=ptr->link;
	}
	printf("\n");
}