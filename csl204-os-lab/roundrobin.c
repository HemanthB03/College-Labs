#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 10

struct process {
    int pid;
    int burst;
    int waiting;
    int turnaround;
    int remaining;
};

int main(void) {
    int n, i, quantum, total_waiting=0, total_turnaround=0, time=0, done=0;
    float avg_waiting, avg_turnaround;
    struct process p[MAX_PROCESS];

    printf("Enter the number of process(max %d): ", MAX_PROCESS);
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        p[i].pid=i;
        printf("Enter the burst time of process %d: ", i);
        scanf("%d", &p[i].burst);
        p[i].remaining=p[i].burst;
    }
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    while(done<n) {
        for(i=0; i<n; i++) {
            if(p[i].remaining>0) {
                if(p[i].remaining<=quantum) {
                    time+=p[i].remaining;
                    p[i].remaining=0;
                    p[i].turnaround=time;
                    p[i].waiting=p[i].turnaround-p[i].burst;
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
        total_waiting+=p[i].waiting;
        total_turnaround+=p[i].turnaround;
    }
    avg_waiting=(float)total_waiting/n;
    avg_turnaround=(float)total_turnaround/n;

    printf("\nTotal waiting time: %d\n", total_waiting);
    printf("\nAverage waiting time: %f\n", avg_waiting);
    printf("\nTotal turn around time: %d\n", total_turnaround);
    printf("\nAverage turn around time: %f\n", avg_turnaround);

    return 0;
}
