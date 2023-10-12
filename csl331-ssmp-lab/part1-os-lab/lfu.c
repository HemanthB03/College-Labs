#include <stdio.h>

int main(void) {
  int referenceString[50], i, j, k, m, numberOfFrames, usageCount[20], frames[20], min, pageFaults = 0;
  
  printf("Enter length of reference string: ");
  scanf("%d", &m);
  
  printf("Enter the reference string: ");
  for (i = 0; i < m; i++) {
    scanf("%d", &referenceString[i]);
  }
  
  printf("Enter the number of frames: ");
  scanf("%d", &numberOfFrames);
  
  for (i = 0; i < numberOfFrames; i++) {
    usageCount[i] = 0;
    frames[i] = -1;
  }
  
  printf("LFU Page Replacement\n");
  
  for (i = 0; i < m; i++) {
    for (j = 0; j < numberOfFrames; j++) {
      if (referenceString[i] == frames[j]) {
        usageCount[j]++;
        break;
      }
    }
    
    if (j == numberOfFrames) {
      min = 0;
      for (k = 1; k < numberOfFrames; k++) {
        if (usageCount[k] < usageCount[min]) {
          min = k;
        }
      }
      
      frames[min] = referenceString[i];
      usageCount[min] = 1;
      pageFaults++;
    }
    
    printf("\n");
    
    for (j = 0; j < numberOfFrames; j++) {
      printf("\t%d", frames[j]);
    }
    
    if (j == numberOfFrames) {
      printf("\tPF No %d", pageFaults);
    }
  }
  
  printf("\nTotal number of page faults = %d\n", pageFaults);

  return 0;
}
