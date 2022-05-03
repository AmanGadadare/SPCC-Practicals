#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char opcode[10], mnemonic[10], operand[10], label[10], code[10], address[10], sizeAddress[10], Motlabel[10];
    int locctr = 0, start, length, flag = 0;
    FILE *fp1, *fp2, *fp3, *fp4, *fp5, *fp6, *fp411;
    fp1 = fopen("INPUT.txt", "r");
    fp2 = fopen("MNT.txt", "w");
    fp3 = fopen("MDT.txt", "w");

    fscanf(fp1, "%s %s %s", label, opcode, operand);

    while (strcmp(opcode, "END") != 0)
    {
        if (strcmp(label, "Macro") == 0)
        {
            while (strcmp(label, "MEND") != 0)
            {
                fscanf(fp1, "%s %s %s", label, opcode, operand);
                if (strcmp(opcode, "**") == 0 && strcmp(label, "MEND") != 0)
                {
                    fprintf(fp2, "%s\n", label);
                }
                printf("%s\n", label);
                fprintf(fp3, "%s %s\n", label, opcode);
            }
        }
        fscanf(fp1, "%s %s %s", label, opcode, operand);
    }
    return 0;
}