#include <stdio.h>
#include <stdbool.h>

int main(void) {
  int n, m, i, j, k, y, ind=0;
  int alloc[20][20], max[20][20], avail[20];

  printf("Enter the no of processes: ");
  scanf("%d", &n);
  printf("Enter the no of resources: ");
  scanf("%d", &m);

  int need[n][m], safe_sequence[n], work[m];
  bool finish[n];

  printf("Enter the allocation matrix\n");
  for(i=0; i<n; i++) {
    for(j=0; j<m; j++) {
      scanf("%d", &alloc[i][j]);
    }
  }

  printf("Enter the max matrix\n");
  for(i=0; i<n; i++) {
    for(j=0; j<m; j++) {
      scanf("%d", &max[i][j]);
    }
  }

  printf("Enter the avail matrix\n");
  for(i=0; i<m; i++) {
    scanf("%d", &avail[i]);
  }

  for(i=0; i<n; i++) {
    finish[i]=false;
  }
  for(j=0; j<m; j++) {
    work[j]=avail[j];
  }

  printf("The Need Matrix is \n");
  for(i=0; i<n; i++) {
    for(j=0; j<m; j++) {
      need[i][j]=max[i][j]-alloc[i][j];
      printf("%d ", need[i][j]);
    }
    printf("\n");
  }

  for(k=0; k<n; k++) {
    for(i=0; i<n; i++) {
      if(finish[i]==false) {
        int flag=0;
        for(j=0; j<m; j++) {
          if(need[i][j]>work[j]) {
            flag=1;
            break;
          }
        }
        if(flag==0) {
          safe_sequence[ind++]=i;
          for(y=0; y<m; y++) {
            work[y]+=alloc[i][y];
          }
          finish[i]=true;
        }
      }
    }
  }
  printf("\nSafe Sequence is \n");
  for(i=0; i<=n-1; i++) {
    printf("P%d, ", safe_sequence[i]);
  }
  printf("\n");

  return 0;
}