#include <stdio.h>

int stack[50], n, data, top=-1;

void push();
void pop();
void display();

int main() {

    int ch;

    printf("Enter the size of stack(<=50): ");
    scanf("%d", &n);

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
    if(top==n-1) {
        printf("Stack overflow\n");
    }
    else {
        printf("Enter the element to push: ");
        scanf("%d", &data);
        top++;
        stack[top]=data;
    }
}

void pop() {
    if(top==-1) {
        printf("Stack underflow\n");
    }
    else {
        printf("%d was popped\n", stack[top]);
        top--;
    }
}

void display() {
    int i;
    if(top==-1) {
        printf("Stack is empty\n");
    }
    else {
        printf("Stack is: \n");
        for(i=top; i>=0; i--) {
            printf("%d\n", stack[i]);
        }
    }

}