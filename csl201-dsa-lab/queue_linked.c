#include <stdio.h>
#include <stdlib.h>

void enqueue();
void dequeue();
void display();

struct node {
    int data;
    struct node *link;
};

struct node *head, *ptr;
int data;

int main() {
    int ch;

    do {
        printf("\n----Menu----\n");
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting........\n");
                break;
            default:
                printf("Option not in menu, try again\n");
                break;
        }
    }
    while(ch!=4);

    return 0;
}

void enqueue() {
    ptr=head;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &data);
    temp->data=data;

    if(head==NULL) {
        head=temp;
        temp->link=NULL;
    }
    else {
        while (ptr->link!=NULL) {
            ptr=ptr->link;
        }
        ptr->link=temp;
        temp->link=NULL;
    }
}

void dequeue() {
    if(head==NULL) {
        printf("Queue underflow\n");
    }
    else {
        ptr=head;
        head=head->link;
        printf("%d was deleted\n", ptr->data);
        free(ptr);
    }
}

void display() {
    if(head==NULL) {
        printf("Queue is empty\n");
    }
    else {
        ptr=head;
        printf("\n");
        while(ptr!=NULL) {
            printf("%d, ", ptr->data);
            ptr=ptr->link;
        }
        printf("\n");
    }
}