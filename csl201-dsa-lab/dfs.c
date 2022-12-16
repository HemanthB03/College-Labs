#include <stdio.h>

int a[20][20], visited[20], n;

void dfs(int v) {
    int i;
    for(i=0; i<n; i++) {
        if(a[v][i]!=0 && visited[i]==0) {
            visited[i]=1;
            printf("V%d, ", i);
            dfs(i);
        }
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

    printf("DFS traversal is: ");
    visited[v]=1;
    printf("V%d, ", v);

    dfs(v);

    return 0;
}