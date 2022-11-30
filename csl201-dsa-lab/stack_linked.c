#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
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
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                push();
                break;
            case 2:
                pop();
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

void push() {
    printf("Enter data: ");
    scanf("%d", &data);
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=head;
    head=temp;

}

void pop() {
    if(head==NULL) {
        printf("Stack underflow\n");
    }
    else {
        ptr=head;
        head=head->link;
        printf("%d was popped\n", ptr->data);
        free(ptr);
    }
}

void display() {
    if(head==NULL) {
        printf("Stack is empty\n");
    }
    else {
        ptr=head;
        printf("\n");
        while(ptr!=NULL) {
            printf("%d\n", ptr->data);
            ptr=ptr->link;
        }
    }
}