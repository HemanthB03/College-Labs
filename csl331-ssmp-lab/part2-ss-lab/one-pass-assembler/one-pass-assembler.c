#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  FILE *inFile, *optabFile, *symtabFile, *symtab1File, *outFile;
  int locctr, startAddr, i = 0, j = 0, m[10], pgmlen, len, k, len1, l = 0;
  char name[10], operand[10], label[10], mnemonic[10], s1[10], mnemonic1[10], operand1[10];
  char lcs[10], ms[10];
  char sym[10], symaddr[10], obj1[10], obj2[10], s2[10], q[10], s3[10];

  inFile = fopen("input.txt", "r");
  optabFile = fopen("optab.txt", "r");
  symtabFile = fopen("symtab.txt", "w+");
  symtab1File = fopen("symtab1.txt", "w+");
  outFile = fopen("output.txt", "w+");

  fscanf(inFile, "%s%s%s", label, mnemonic, operand);

  if (strcmp(mnemonic, "START") == 0) {
    startAddr = atoi(operand);
    strcpy(name, label);
    locctr = startAddr;
  }

  strcpy(s1, "*");
  fscanf(inFile, "%s%s%s", label, mnemonic, operand);

  while (strcmp(mnemonic, "END") != 0) {
    if (strcmp(label, "-") == 0) {
      fscanf(optabFile, "%s%s", mnemonic1, operand1);

      while (!feof(optabFile)) {
        if (strcmp(mnemonic1, mnemonic) == 0) {
          m[i] = locctr + 1;
          fprintf(symtabFile, "%s\t%s\n", operand, s1);
          fprintf(outFile, "%s\t0000\n", operand1);
          locctr = locctr + 3;
          i = i + 1;
          break;
        } else {
          fscanf(optabFile, "%s%s", mnemonic1, operand1);
        }
      }
    } else {
      fseek(symtabFile, SEEK_SET, 0);
      fscanf(symtabFile, "%s%s", sym, symaddr);

      while (!feof(symtabFile)) {
        if (strcmp(sym, label) == 0) {
          sprintf(lcs, "%d", locctr);
          fprintf(symtab1File, "%s\t%s\n", label, lcs);
          sprintf(ms, "%d", m[j]);
          j = j + 1;
          fprintf(outFile, "%s\t%s\n", ms, lcs);
          i = i + 1;
          break;
        } else {
          fscanf(symtabFile, "%s%s", sym, symaddr);
        }
      }

      if (strcmp(mnemonic, "RESW") == 0)
        locctr = locctr + 3 * atoi(operand);
      else if (strcmp(mnemonic, "BYTE") == 0) {
        strcpy(s2, "-");
        len = strlen(operand);
        locctr = locctr + len - 2;

        for (k = 2; k < len; k++) {
          q[l] = operand[k];
          l = l + 1;
        }

        fprintf(outFile, "%s\t%s\n", q, s2);
        break;
      } else if (strcmp(mnemonic, "RESB") == 0)
        locctr = locctr + atoi(operand);
      else if (strcmp(mnemonic, "WORD") == 0) {
        strcpy(s3, "#");
        locctr = locctr + 3;
        fprintf(outFile, "%s\t%s\n", operand, s3);
        break;
      }
    }

    fseek(optabFile, SEEK_SET, 0);
    fscanf(inFile, "%s%s%s", label, mnemonic, operand);
  }

  fseek(outFile, SEEK_SET, 0);
  pgmlen = locctr - startAddr;
  printf("H^%s^%d^0%x\n", name, startAddr, pgmlen);
  printf("T^");
  printf("00%d^0%x", startAddr, pgmlen);
  fscanf(outFile, "%s%s", obj1, obj2);

  while (!feof(outFile)) {
    if (strcmp(obj2, "0000") == 0)
      printf("^%s%s", obj1, obj2);
    else if (strcmp(obj2, "-") == 0) {
      printf("^");
      len1 = strlen(obj1);

      for (k = 0; k < len1; k++) printf("%d", obj1[k]);
    } else if (strcmp(obj2, "#") == 0) {
      printf("^");
      printf("%s", obj1);
    }

    fscanf(outFile, "%s%s", obj1, obj2);
  }

  fseek(outFile, SEEK_SET, 0);
  fscanf(outFile, "%s%s", obj1, obj2);

  while (!feof(outFile)) {
    if (strcmp(obj2, "0000") != 0) {
      if (strcmp(obj2, "-") != 0) {
        if (strcmp(obj2, "#") != 0) {
          printf("\n");
          printf("T^%s^02^%s", obj1, obj2);
        }
      }
    }

    fscanf(outFile, "%s%s", obj1, obj2);
  }

  printf("\nE^00%d", startAddr);
  return 0;
}
