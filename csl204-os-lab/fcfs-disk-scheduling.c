#include <stdio.h>
#include <math.h>

int main(void) {
  int ioq[20], i, n, ihead, tot;
  float seek=0, avgs;

  printf("Enter the no of request: ");
  scanf("%d", &n);
  printf("Enter the initial head position: ");
  scanf("%d", &ihead);
  
  ioq[0]=ihead;

  printf("Enter the I/O queue request\n");
  for(i=1; i<=n; i++) {
    scanf("%d", &ioq[i]);
  }
  ioq[n+1]=ioq[n];
  printf("\nThe order of request served is: \n");
  for(i=0; i<=n; i++) {
    printf("%d-->", ioq[i]);
  }

  printf("\n\nstart\tend\tdifference\n");
  for(i=0; i<n; i++) {
    tot=abs(ioq[i+1]-ioq[i]);
    seek+=tot;
    printf("%d\t%d\t%d\n", ioq[i], ioq[i+1], tot);
  }

  avgs=seek/n;
  printf("\nTotal seek time\t: %.2f\n", seek);
  printf("Average seek time\t: %.2f\n", avgs);

  return 0;
}