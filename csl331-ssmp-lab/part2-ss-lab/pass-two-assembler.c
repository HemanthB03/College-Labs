// Pass two of Two Pass Assembler for SIC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char opcode[20], operand[20], symbol[20], label[20], code[20];
    char mnemonic[25], character, add[20], objectcode[20];
    int flag, flag1, locctr, loc;
    int startingAddress, pgmLen;

    memset(label, 0, sizeof(label));
    memset(opcode, 0, sizeof(opcode));
    memset(operand, 0, sizeof(operand));
    memset(add, 0, sizeof(add));

    FILE *passOneOut, *passTwoOut, *optabFile, *symtabFile;
    passOneOut = fopen("out1.txt", "r");
    passTwoOut = fopen("twoOut.txt", "w");
    optabFile = fopen("opcode.txt", "r");
    symtabFile = fopen("sym1.txt", "r");

    fscanf(passOneOut, "%s %s %s", label, opcode, operand);
    startingAddress=atoi(operand);
    if (strcmp(opcode, "START") == 0) {
        fprintf(passTwoOut, "%s %s %s\n", label, opcode, operand);
        fscanf(passOneOut, "%d %s %s %s", &locctr, label, opcode, operand);
    }

    while (strcmp(opcode, "END") != 0) {
        flag = 0;
        rewind(optabFile);
        while (fscanf(optabFile, "%s %s", code, mnemonic) != EOF) {
            if ((strcmp(opcode, code) == 0) && (strcmp(mnemonic, "*") != 0)) {
                flag = 1;
                break;
            }
        }

        if (flag == 1) {
            flag1 = 0;
            rewind(symtabFile);
            while (fscanf(symtabFile, "%s %d", symbol, &loc) != EOF) {
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
            } else {
                strcpy(objectcode, add);
            }
        } 
        else {
            strcpy(objectcode, "\0");
        }

        if (strcmp(label, "**") == 0) {
            fprintf(passTwoOut, "%s %s %s %d %s\n", label, opcode, operand, locctr, objectcode);
        }
        fscanf(passOneOut, "%d %s %s %s", &locctr, label, opcode, operand);
    }

    pgmLen=locctr-startingAddress;

    fclose(passOneOut);
    fclose(passTwoOut);
    fclose(optabFile);
    fclose(symtabFile);

    return 0;
}
