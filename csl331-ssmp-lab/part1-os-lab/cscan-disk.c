#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int i, j, temp, tempInd1, tempInd2;
  int n, ihead, cylinders, diff;
  int ioq[20], ioq1[20], ioq2[20];
  float seek=0, avgs;

  printf("C-SCAN Disk Scheduling\n");
  printf("Enter the number of cylinders in disk: ");
  scanf("%d", &cylinders);

  printf("Enter number of requests: ");
  scanf("%d", &n);

  printf("Enter the initial head position: ");
  scanf("%d", &ihead);

  printf("Enter the I/O queue requests: ");
  for(i=1; i<=n; i++) {
    scanf("%d", &temp);

    if(temp>ihead) {
      ioq1[tempInd1]=temp;
      tempInd1++;
    }
    else {
      ioq2[tempInd2]=temp;
      tempInd2++;
    }
  }

  for(i=0; i<tempInd1-1; i++) {
    for(j=i+1; j<tempInd1; j++) {
      if(ioq1[i]>ioq1[j]) {
        temp=ioq1[i];
        ioq1[i]=ioq1[j];
        ioq1[j]=temp;
      }
    }
  }

  for(i=0; i<tempInd2-1; i++) {
    for(j=i+1; j<tempInd2; j++) {
      if(ioq2[i]<ioq2[j]) {
        temp=ioq2[i];
        ioq2[i]=ioq2[j];
        ioq2[j]=temp;
      }
    }
  }

  for(i=1, j=0; j<tempInd1; i++, j++) {
    ioq[i]=ioq1[j];
  }

  ioq[i]=cylinders-1;
  ioq[i+1]=0;

  for(i=tempInd1+3, j=0; j<tempInd2; i++, j++) {
    ioq[i]=ioq2[j];
  }
  ioq[0]=ihead;

  printf("\nThe order of request served is: \n");
  for(i=0; i<=n; i++) {
    printf("%d-->", ioq[i]);
  }
  
  printf("\nStart\tEnd\tNo: of head movements");
  for(i=0; i<=n; i++) {
    diff=abs(ioq[i+1]-ioq[i]);

    printf("\n%d\t%d\t%d", ioq[i], ioq[i+1], diff);

    seek+=diff;
  }

  avgs=seek/n;
  printf("\nTotal seek time\t: %.2f\n", seek);
  printf("Average seek time\t: %.2f\n", avgs);

  return 0;
}