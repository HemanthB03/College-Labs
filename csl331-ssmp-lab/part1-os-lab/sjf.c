#include <stdio.h>
#include <stdlib.h>

struct process {
    int pid;
    int btime;
    int wtime;
    int ttime;
}p[10];

int main(void) {
    int i, j, n;
    int totwtime=0, totttime=0;
    struct process temp;

    printf("\nSJF Scheduling\n");
    printf("Enter the no of processes: ");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        p[i].pid=i;
        printf("Enter the burst time of process %d: ", i);
        scanf("%d", &p[i].btime);
    }

    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if(p[i].btime>p[j].btime) {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }

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

    return 0;
}