// Pass two of Two Pass Assembler for SIC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char opcode[20], operand[20], symbol[20], label[20], code[20];
  char mnemonic[25], character, add[20], objectcode[20];
  int flag, flag1, locctr, loc;
  int startAddress=0, pgmLen=0, textRecLen=0;
  char pgmName[20], textRecord[100], temp1[20], temp2[100];

  memset(pgmName, 0, sizeof(pgmName));
  memset(textRecord, 0, sizeof(textRecord));
  memset(temp2, 0, sizeof(temp2));

  FILE *passOneOut, *optabFile, *symtabFile, *assemblyListing, *objPgmFile;
  passOneOut = fopen("out1.txt", "r");
  optabFile = fopen("opcode.txt", "r");
  symtabFile = fopen("sym1.txt", "r");
  assemblyListing = fopen("assemblyListing.txt", "w");
  objPgmFile = fopen("objectcode.txt", "w");

  fscanf(passOneOut, "%s\t%s\t%s", label, opcode, operand);
  if (strcmp(opcode, "START") == 0) {
    fprintf(assemblyListing, "%s\t%s\t%s\n", label, opcode, operand);
    startAddress=atoi(operand);
    sprintf(textRecord, "T^%6d", startAddress);

    fscanf(passOneOut, "%d\t%s\t%s\t%s", &locctr, label, opcode, operand);
  }

  while (strcmp(opcode, "END") != 0) {
    flag = 0;
    rewind(optabFile);
    while (fscanf(optabFile, "%s\t%s", code, mnemonic) != EOF) {
      if ((strcmp(opcode, code) == 0) && (strcmp(mnemonic, "**") != 0)) {
        flag = 1;
        break;
      }
    }

    if (flag == 1) {
      flag1 = 0;
      rewind(symtabFile);
      while (fscanf(symtabFile, "%d\t%s", &loc, symbol) != EOF) {
        if (strcmp(symbol, operand) == 0) {
          flag1 = 1;
          break;
        }
      }
      if (flag1 == 1) {
        sprintf(add, "%d", loc);
        strcpy(objectcode, strcat(mnemonic, add));
      }
    } 
    else if (strcmp(opcode, "BYTE") == 0 || strcmp(opcode, "WORD") == 0) {
      if ((operand[0] == 'C') || (operand[0] == 'X')) {
        character = operand[2];
        sprintf(add, "%d", character);
        strcpy(objectcode, add);
      }
      else {
        strcpy(objectcode, add);
      }
    } 
    else {
      strcpy(objectcode, "\0");
    }

    if (strcmp(label, "**") == 0) {
      fprintf(assemblyListing, "%d\t%s\t%s\t%s\t%s\n", locctr, label, opcode, operand, objectcode);
      textRecLen+=strlen(objectcode);
      strcat(temp2, "^");
      strcat(temp2, objectcode);
    }
    fscanf(passOneOut, "%d\t%s\t%s\t%s", &locctr, label, opcode, operand);
  }

  pgmLen=locctr-startAddress;
  sprintf(temp1, "^%2d", textRecLen/2);
  strcat(textRecord, temp1);
  strcat(textRecord, temp2);
  
  fprintf(objPgmFile, "H^%6s^%6d^%6d\n", pgmName, startAddress, pgmLen);
  fprintf(objPgmFile, "%s\n", textRecord);
  fprintf(objPgmFile, "E^%6d\n", startAddress);

  fclose(passOneOut);
  fclose(optabFile);
  fclose(symtabFile);
  fclose(assemblyListing);
  fclose(objPgmFile);

  return 0;
}
