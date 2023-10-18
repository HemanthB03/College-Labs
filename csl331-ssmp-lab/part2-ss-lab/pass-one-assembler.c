// Pass one of Two Pass Assembler for SIC and SIC/XE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
  FILE *inFile, *optabFile, *outFile, *symFile;
  char label[30], opcode[30], operand[30], opcode1[30], operand1[30];
  int locctr, flag = 0;

  memset(label, 0, sizeof(label));
  memset(opcode, 0, sizeof(opcode));
  memset(operand, 0, sizeof(operand));

  inFile = fopen("input.txt", "r");
  optabFile = fopen("opcode.txt", "r");
  outFile = fopen("out1.txt", "w");
  symFile = fopen("sym1.txt", "w");

  while (fscanf(inFile, "%s%s%s", label, opcode, operand) != EOF) {
    if (strcmp(label, "**") == 0) {
      if (strcmp(opcode, "START") == 0) {
        fprintf(outFile, "%s %s %s", label, opcode, operand);
        locctr = atoi(operand);
      }
      else {
        rewind(optabFile);
        flag = 0;
        while (fscanf(optabFile, "%s%s", opcode1, operand1) != EOF) {
          if (strcmp(opcode, opcode1) == 0) {
            flag = 1;
          }
        }
        if (flag == 1) {
          fprintf(outFile, "\n%d %s %s %s", locctr, label, opcode, operand);
          locctr += 3;
        }
      }
    }
    else {
      if (strcmp(opcode, "RESW") == 0) {
        fprintf(outFile, "\n%d %s %s %s", locctr, label, opcode, operand);
        fprintf(symFile, "\n%d %s", locctr, label);
        locctr += (3 * (atoi(operand)));
      }
      else if (strcmp(opcode, "WORD") == 0) {
        fprintf(outFile, "\n%d %s %s %s", locctr, label, opcode, operand);
        fprintf(symFile, "\n%d %s", locctr, label);
        locctr += 3;
      }
      else if (strcmp(opcode, "BYTE") == 0) {
        fprintf(outFile, "\n%d %s %s %s", locctr, label, opcode, operand);
        fprintf(symFile, "\n%d %s", locctr, label);
        locctr += 1;
      }
      else if (strcmp(opcode, "RESB") == 0) {
        fprintf(outFile, "\n%d %s %s %s", locctr, label, opcode, operand);
        fprintf(symFile, "\n%d %s", locctr, label);
        locctr += 1;
      }
      else {
        fprintf(outFile, "\n%d %s %s %s", locctr, label, opcode, operand);
        fprintf(symFile, "\n%d %s", locctr, label);
        locctr += atoi(operand);
      }
    }
  }

  fclose(inFile);
  fclose(optabFile);
  fclose(outFile);
  fclose(symFile);

  return 0;
}
