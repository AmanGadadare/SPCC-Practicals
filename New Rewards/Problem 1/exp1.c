#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct table
{
    char symbol;
    struct table *address;
    // 1 is identifier 0 is operator 2 is constant
    int type;
};

void create_table(char str[], struct table *ptr, int len);
void view_table(struct table *ptr, int len);
void insert_symbol(char ch, struct table *ptr, int len);
void remove_symbol(char ch, struct table *ptr, int len);
void search_symbol(char ch, struct table *ptr, int len);

int main()
{
    int num;
    int length = 0;
    char str[20];
    char ch;
    struct table ptr[20];
    while (1)
    {
        printf("1. Create table 2. Search table 3. Enter symbol 4. Remove symbol 5. View table 6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &num);
        while ((getchar()) != '\n')
            ;
        switch (num)
        {
        case 1:
            printf("Enter expression: ");
            gets(str);
            create_table(str, ptr, length);
            length = length + strlen(str);
            break;
        case 2:
            printf("Enter the symbol to be searched: ");
            ch = getchar();
            search_symbol(ch, ptr, length);
            break;
        case 3:
            printf("Enter the symbol to be inserted: ");
            ch = getchar();
            insert_symbol(ch, ptr, length);
            length++;
            break;
        case 4:
            printf("Enter the symbol to be removed: ");
            ch = getchar();
            remove_symbol(ch, ptr, length);
            break;
        case 5:
            view_table(ptr, length);
            break;
        case 6:
            exit(0);
        }
    }
}

void create_table(char str[], struct table *ptr, int len)
{

    for (int i = len; i < strlen(str) + len; i++)
    {
        if (isalpha(str[i - len]))
        {
            (ptr + i)->symbol = str[i - len];
            (ptr + i)->address = (ptr + i);
            (ptr + i)->type = 1;
        }
        else if (isdigit(str[i - len]))
        {
            (ptr + i)->symbol = str[i - len];
            (ptr + i)->address = (ptr + i);
            (ptr + i)->type = 2;
        }
        else
        {
            (ptr + i)->symbol = str[i - len];
            (ptr + i)->address = (ptr + i);
            (ptr + i)->type = 0;
        }
    }
}

void view_table(struct table *ptr, int len)
{
    if (len == 0)
    {
        printf("NO table is created\n");
        return;
    }
    for (int i = 0; i < len; i++)
    {
        if ((ptr + i)->type == 1)
        {
            printf("Symbol : %c | Address: %p | Type: Identifier\n", (ptr + i)->symbol, (ptr + i)->address);
        }
        else if ((ptr + i)->type == 2)
        {
            printf("Symbol : %c | Address: %p | Type: Constant\n", (ptr + i)->symbol, (ptr + i)->address);
        }
        else if ((ptr + i)->type == 0)
        {
            printf("Symbol : %c | Address: %p | Type: Operator\n", (ptr + i)->symbol, (ptr + i)->address);
        }
    }
}

void insert_symbol(char ch, struct table *ptr, int len)
{
    if (isalpha(ch))
    {
        (ptr + len)->symbol = ch;
        (ptr + len)->address = (ptr + len);
        (ptr + len)->type = 1;
    }
    else if (isdigit(ch))
    {
        (ptr + len)->symbol = ch;
        (ptr + len)->address = (ptr + len);
        (ptr + len)->type = 2;
    }
    else
    {
        (ptr + len)->symbol = ch;
        (ptr + len)->address = (ptr + len);
        (ptr + len)->type = 0;
    }
}

void search_symbol(char ch, struct table *ptr, int len)
{
    for (int i = 0; i < len; i++)
    {
        if ((ptr + i)->symbol == ch)
        {
            if ((ptr + i)->type == 10)
            {
                break;
            }
            printf("Symbol is Present\n");
            if ((ptr + i)->type == 1)
            {
                printf("Symbol : %c | Address: %p | Type: Identifier\n", (ptr + i)->symbol, (ptr + i)->address);
            }
            else if ((ptr + i)->type == 2)
            {
                printf("Symbol : %c | Address: %p | Type: Constant\n", (ptr + i)->symbol, (ptr + i)->address);
            }
            else if ((ptr + i)->type == 0)
            {
                printf("Symbol : %c | Address: %p | Type: Operator\n", (ptr + i)->symbol, (ptr + i)->address);
            }
            return;
        }
    }
    printf("Symbol Not Found\n");
}

void remove_symbol(char ch, struct table *ptr, int len)
{
    for (int i = 0; i < len; i++)
    {
        if ((ptr + i)->symbol == ch)
        {
            (ptr + i)->type = 10;
            printf("Symbol is Removed\n");
            return;
        }
    }
    printf("Symbol Not Found\n");
}
