#include <stdio.h>
#include <stdlib.h>

void insertFront();
void insertEnd();
void insertAt();
void deleteFront();
void deleteEnd();
void deleteKey();
void display();

struct node {
    int data;
    struct node *link;
};

struct node *head=NULL, *ptr, *temp, *prev, *current;
int data, key;

int main() {

    int ch;

    do {
        printf("\n----Menu----\n");
        printf("1.Insert at beginning\n");
        printf("2.Insert at end\n");
        printf("3.Insert after a key\n");
        printf("4.Delete from beginning\n");
        printf("5.Delete from end\n");
        printf("6.Delete a key\n");
        printf("7.Display\n");
        printf("8.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                insertFront();
                break;
            case 2:
                insertEnd();
                break;
            case 3:
                insertAt();
            case 4:
                deleteFront();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                deleteKey();
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting........\n");
                break;
            default:
                printf("Option not in menu, try again\n");
                break;
        }
    }
    while(ch!=8);

    return 0;
}


void insertFront() {
    printf("Enter data: ");
    scanf("%d", &data);
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=head;
    head=temp;
}

void insertEnd() {
    ptr=head;
    printf("Enter data: ");
    scanf("%d", &data);
    temp = (struct node *)malloc(sizeof(struct node));
    while (ptr->link!=NULL) {
        ptr=ptr->link;
    }
    temp->data=data;
    ptr->link=temp;
    temp->link=NULL;
}

void insertAt() {
    ptr=head;
    printf("Enter data: ");
    scanf("%d", &data);
    printf("Enter key to insert after: ");
    scanf("%d", &key);
    temp = (struct node *)malloc(sizeof(struct node));
    while(ptr->data!=key && ptr->link!=NULL) {
        ptr=ptr->link;
    }
    if(ptr->link==NULL) {
        printf("Key not in list\n");
    }
    else {
        temp->data=data;
        temp->link=ptr->link;
        ptr->link=temp;
    }
}

void deleteFront() {
    if(head==NULL) {
        printf("List empty\n");
    }
    else {
        prev=head;
        head=head->link;
        free((void*)prev);
    }
}

void deleteEnd() {
    if(head==NULL) {
        printf("List empty\n");
    }
    else {
        current=head;
        prev=head;
        while(current->link!=NULL) {
            prev=current;
            current=current->link;
        }
        free((void*)prev->link);
        prev->link=NULL;
    }
    
}

void deleteKey() {
    printf("Enter key to delete: ");
    scanf("%d", &key);
    if(head==NULL) {
        printf("List empty\n");
    }
    else {
        current=head;
        prev=head;
        while(current->link!=NULL && current->data!=key) {
            prev=current;
            current=current->link;
        }
        if(current==NULL) {
            printf("Element not found\n");
        }
        else {
            free((void*)prev->link);
            prev->link=current->link;
        }
    }
}

void display() {
    if(head==NULL) {
        printf("\nList empty\n");
    }
    else {
        ptr=head;
        printf("\n");
        while(ptr!=NULL) {
            printf("(%d)->", ptr->data);
            ptr=ptr->link;
        }
        printf("(nullptr)\n");
    }
    
}