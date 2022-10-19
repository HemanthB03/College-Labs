#include <stdio.h>

int queue[50], n, data, front=-1, rear=-1;

void enqueue();
void dequeue();
void display();

int main() {

    int ch;

    printf("Enter the size of queue(<=50): ");
    scanf("%d", &n);

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
    if(rear==n-1) {
        printf("queue overflow\n");
    }
    else {

        if(rear==-1) {
            front++;
        }

        printf("Enter the element to insert: ");
        scanf("%d", &data);
        rear++;
        queue[rear]=data;
    }
}

void dequeue() {
    if(front<0 || front>rear) {
        printf("queue underflow\n");
    }
    else {
        printf("%d was deleted\n", queue[front]);
        front++;
    }
}

void display() {
    int i;
    if(front<0 || front>rear) {
        printf("queue is empty\n");
    }
    else {
        printf("queue is: ");
        for(i=front; i<=rear; i++) {
            printf("%d, ", queue[i]);
        }
    }

}