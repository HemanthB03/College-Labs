#include <stdio.h>
#include <stdlib.h>

struct process {
    int pid;
    int btime;
    int wtime;
    int ttime;
}p[10], p1[10];

int i, j, n, ch;
int totwtime=0, totttime=0;
struct process temp;

void fcfs() {
    int totwtime=0, totttime=0;
    printf("\nFCFS Scheduling\n");
    p[0].wtime=0;
    p[0].ttime=p[0].btime;
    for(i=0; i<n; i++) {
        p[i].wtime=p[i-1].wtime+p[i-1].btime;
        p[i].ttime=p[i].wtime+p[i].btime;
        totttime+=p[i].ttime;
        totwtime+=p[i].wtime;
    }

    printf("\nTotal waiting time: %d\n", totwtime);
    printf("\nAverage waiting time: %d\n", totwtime/n);
    printf("\nTotal turn around time: %d\n", totttime);
    printf("\nAverage turn around time: %d\n", totttime/n);
}

void sjf() {
    int totwtime=0, totttime=0;
    for(i=0; i<n; i++) { 
        p1[i]=p[i];
    }
    printf("\nSJF Scheduling\n");
    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if(p1[i].btime>p1[j].btime) {
                temp=p1[i];
                p1[i]=p1[j];
                p1[j]=temp;
            }
        }
    }

    p1[0].wtime=0;
    p1[0].ttime=p1[0].btime;
    for(i=0; i<n; i++) {
        p1[i].wtime=p1[i-1].wtime+p1[i-1].btime;
        p1[i].ttime=p1[i].wtime+p1[i].btime;
        totttime+=p1[i].ttime;
        totwtime+=p1[i].wtime;
    }

    printf("\nTotal waiting time: %d\n", totwtime);
    printf("\nAverage waiting time: %d\n", totwtime/n);
    printf("\nTotal turn around time: %d\n", totttime);
    printf("\nAverage turn around time: %d\n", totttime/n);
}

int main(void) {
    printf("Enter the no of processes: ");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        p[i].pid=i;
        printf("Enter the burst time of process %d: ", i);
        scanf("%d", &p[i].btime);
    }

    printf("\n---Menu---\n");
    printf("1.FCFS\n2.SJF\n3.EXIT\n");
    do {
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                fcfs();
                break;
            case 2:
                sjf();
                break;
            case 3:
                printf("Exiting....\n");
                break;
            default:
                printf("Option not in menu\n");
        }   
    }
    while(ch!=3);
    
    return 0;
}