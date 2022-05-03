#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char opcode[10], mnemonic[10], operand[10], label[10], normal[10];
    FILE *fp1, *fp2, *fp3, *fp4;
    fp1 = fopen("INPUT.txt", "r");
    fp2 = fopen("Expanded Source.txt", "w");
    fp3 = fopen("MNT.txt", "r");
    fp4 = fopen("MDT.txt", "r");

    fscanf(fp1, "%s %s %s", label, opcode, operand);

    while (strcmp(opcode, "END") != 0)
    {
        if (strcmp(label, "Macro") == 0)
        {
            while (strcmp(label, "MEND") != 0)
            {
                fscanf(fp1, "%s %s %s", label, opcode, operand);
            }
        }
        else if (strcmp(opcode, "START") == 0)
        {
            fprintf(fp2, "%s\t %s\t %s\n", label, opcode, operand);
            printf("%s\t %s\t %s\n", label, opcode, operand);

            fscanf(fp1, "%s %s %s", label, opcode, operand);
            // printf("print 1");
        }
        // fscanf(fp3, "%s", mnemonic);
        // printf("%s", mnemonic);
        else
        {
            if (strcmp(label, "**") == 0 && strcmp(operand, "**") == 0)
            {
                fscanf(fp4, "%s %s", mnemonic, normal);
                fprintf(fp4, "%s\n", mnemonic);
                printf("%s\n", mnemonic);
                // printf("print 12");
                while (strcmp(opcode, mnemonic) != 0)
                {
                    fscanf(fp4, "%s %s", mnemonic, normal);
                    printf("%s %s\n", mnemonic, opcode);
                    if(strcmp(mnemonic, "MEND") == 0||strcmp(opcode, "MEND") == 0)
                    {
                        break;
                    }
                }
                if (strcmp(opcode, mnemonic) == 0)
                {

                    while (strcmp(label, "MEND") != 0)
                    {
                        fscanf(fp4, "%s %s", label, opcode);
                        if (strcmp(opcode, mnemonic) == 0 || strcmp(label, "MEND") == 0)
                        {
                            continue;
                        }
                        // printf("%s\n", label);
                        fprintf(fp2, "%s %s\n", label, opcode);
                        printf("%s %s\n", label, opcode);
                        // printf("print 2");
                    }
                    rewind(fp4);
                }
            }
            else
            {
                fprintf(fp2, "%s\t %s\t %s\n", label, opcode, operand);
                printf("%s\t %s\t %s\n", label, opcode, operand);
                // printf("print 3");
            }
            // printf("print 6");
        }
        // printf("print 7");
        rewind(fp3);
        // printf("print 8");
        fscanf(fp1, "%s %s %s", label, opcode, operand);
        // printf("print 9");
    }
    // printf("print 10");
    fprintf(fp2, "%s\t %s\t %s\n", label, opcode, operand);
    // printf("print 11");
    printf("%s\t %s\t %s\n", label, opcode, operand);
    // printf("print 4");
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    return 0;
}