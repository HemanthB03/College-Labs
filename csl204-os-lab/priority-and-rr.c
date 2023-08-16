#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 10

struct process {
    int pid;
    int priority;
    int btime;
    int wtime;
    int ttime;
    int remaining;
};



void priorityScheduling() {
    int i, j, n;
    float totwtime=0, totttime=0;
    struct process temp;
    struct process p[MAX_PROCESS];

    printf("\nPriority Scheduling\n");
    printf("Enter the no of processes: ");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        p[i].pid=i;
        printf("Enter the burst time of process %d: ", i);
        scanf("%d", &p[i].btime);
        printf("Enter the priority time of process %d: ", i);
        scanf("%d", &p[i].priority);
    }

    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if(p[i].priority>p[j].priority) {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }

    p[0].wtime=0;
    p[0].ttime=p[0].btime;
    for(i=1; i<n; i++) {
        p[i].wtime=p[i-1].wtime+p[i-1].btime;
        p[i].ttime=p[i].wtime+p[i].btime;
        totttime+=p[i].ttime;
        totwtime+=p[i].wtime;
    }

    printf("\nTotal waiting time: %f\n", totwtime);
    printf("\nAverage waiting time: %f\n", totwtime/n);
    printf("\nTotal turn around time: %f\n", totttime);
    printf("\nAverage turn around time: %f\n", totttime/n);
}

void roundRobinScheduling() {
    int n, i, quantum, total_waiting=0, total_turnaround=0, time=0, done=0;
    float avg_waiting, avg_turnaround;
    struct process p[MAX_PROCESS];
    total_waiting=0, total_turnaround=0, time=0, done=0;
    printf("Enter the number of process(max %d): ", MAX_PROCESS);
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        p[i].pid=i;
        printf("Enter the burst time of process %d: ", i);
        scanf("%d", &p[i].btime);
        p[i].remaining=p[i].btime;
    }
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);
    while(done<n) {
        for(i=0; i<n; i++) {
            if(p[i].remaining>0) {
                if(p[i].remaining<=quantum) {
                    time+=p[i].remaining;
                    p[i].remaining=0;
                    p[i].ttime=time;
                    p[i].wtime=p[i].ttime-p[i].btime;
                    done++;
                }
                else {
                    time+=quantum;
                    p[i].remaining-=quantum;
                }
            }
        }
    }
    for(i=0; i<n; i++) {
        total_waiting+=p[i].wtime;
        total_turnaround+=p[i].ttime;
    }
    avg_waiting=(float)total_waiting/n;
    avg_turnaround=(float)total_turnaround/n;

    printf("\nTotal waiting time: %d\n", total_waiting);
    printf("\nAverage waiting time: %f\n", avg_waiting);
    printf("\nTotal turn around time: %d\n", total_turnaround);
    printf("\nAverage turn around time: %f\n", avg_turnaround);
}

int main(void) {
    int choice;
    printf("Menu:\n");
    printf("1. Priority Scheduling\n");
    printf("2. Round Robin Scheduling\n");
    printf("3. Exit\n");
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                priorityScheduling();
                break;
            case 2:
                roundRobinScheduling();
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }
    }
    while(choice != 3);

    return 0;
}
