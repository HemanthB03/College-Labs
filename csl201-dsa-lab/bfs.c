#include <stdio.h>

int a[20][20], q[20], visited[20], n, f=-1, r=-1;

void bfs(int v) {
    int i;
    for(i=0; i<n; i++) {
        if(a[v][i]!=0 && visited[i]==0) {
            r=r+1;
            q[r]=i;
            visited[i]=1;
            printf("V%d, ", i);
        }
    }
    f=f+1;
    if(f<=r) {
        bfs(q[f]);
    }
}

int main() {

    int v, i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        visited[i]=0;
    }
    printf("Enter the adjacency matrix of the graph: \n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the starting vertex: ");
    scanf("%d", &v);

    f=0;
    r=0;
    q[r]=v;

    printf("BFS traversal is: ");
    visited[v]=1;
    printf("V%d, ", v);

    bfs(v);

    return 0;
}