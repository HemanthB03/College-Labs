#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  FILE *inputFile, *namTab, *defTab, *argTab, *opMacro;
  int len, i, pos = 1;
  char arg[20], mnemonic[20], operand[20], label[20], name[20];
  char mnemonic1[20], operand1[20], pos1[10], pos2[10];

  inputFile = fopen("inputmacro.txt", "r");
  namTab = fopen("namtab.txt", "w+");
  defTab = fopen("deftab.txt", "w+");
  argTab = fopen("argtab.txt", "w+");
  opMacro = fopen("opmacro.txt", "w+");

  fscanf(inputFile, "%s%s%s", label, mnemonic, operand);
  while (strcmp(mnemonic, "END") != 0) {
    if (strcmp(mnemonic, "MACRO") == 0) {
      fprintf(namTab, "%s\n", label);
      fseek(namTab, SEEK_SET, 0);
      fprintf(defTab, "%s\t%s\n", label, operand);
      fscanf(inputFile, "%s%s%s", label, mnemonic, operand);
      while (strcmp(mnemonic, "MEND") != 0) {
        if (operand[0] == '&') {
          snprintf(pos1, sizeof pos1, "%d", pos);
          strcpy(pos2, "?");
          strcpy(operand, strcat(pos2, pos1));
          pos = pos + 1;
        }
        fprintf(defTab, "%s\t%s\n", mnemonic, operand);
        fscanf(inputFile, "%s%s%s", label, mnemonic, operand);
      }
      fprintf(defTab, "%s", mnemonic);
    } else {
      fscanf(namTab, "%s", name);
      if (strcmp(mnemonic, name) == 0) {
        len = strlen(operand);
        for (i = 0; i < len; i++) {
          if (operand[i] != ',')
            fprintf(argTab, "%c", operand[i]);
          else
            fprintf(argTab, "\n");
        }
        fseek(defTab, SEEK_SET, 0);
        fseek(argTab, SEEK_SET, 0);
        fscanf(defTab, "%s%s", mnemonic1, operand1);
        fprintf(opMacro, ".\t%s\t%s\n", mnemonic1, operand);
        fscanf(defTab, "%s%s", mnemonic1, operand1);
        while (strcmp(mnemonic1, "MEND") != 0) {
          if ((operand[0] == '?')) {
            fscanf(argTab, "%s", arg);
            fprintf(opMacro, "-\t%s\t%s\n", mnemonic1, arg);
          } else
            fprintf(opMacro, "-\t%s\t%s\n", mnemonic1, operand1);
          fscanf(defTab, "%s%s", mnemonic1, operand1);
        }
      } else
        fprintf(opMacro, "%s\t%s\t%s\n", label, mnemonic, operand);
    }
    fscanf(inputFile, "%s%s%s", label, mnemonic, operand);
  }
  fprintf(opMacro, "%s\t%s\t%s", label, mnemonic, operand);
  fclose(inputFile);
  fclose(namTab);
  fclose(defTab);
  fclose(argTab);
  fclose(opMacro);

  return 0;
}