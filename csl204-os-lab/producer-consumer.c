#include <stdio.h>
#include <stdlib.h>

int mutex=1;
int full=0, empty=5;
int x=0;

void producer() {
    --mutex;
    ++full;
    --empty;
    x++;
    printf("Producer produces item %d\n", x);
    ++mutex;
}

void consumer() {
    --mutex;
    --full;
    ++empty;
    printf("Consumer consumes item %d\n", x);
    x--;
    ++mutex;
}

int main(void) {
    int ch;
    printf("\n---MENU---\n");
    printf("1.Producer\n2.Consumer\n3.Exit\n");
    
    do {
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                if((mutex==1) && (empty!=0)) {
                    producer();
                }
                else {
                    printf("Buffer is full\n");
                }  
                break;
            case 2:
                if((mutex==1) && (full!=0)) {
                    consumer();
                }
                else {
                    printf("Buffer is empty\n");
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Option not in menu\n");
                break;
        }
    }
    while(ch!=3);

    return 0;
}