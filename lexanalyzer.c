
#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *fp;
    int ch;

    fp = fopen("input.txt", "r");

    if (fp == NULL)
    {
        printf("File not found");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == ' ' || ch == '\t' || ch == '\n')
            continue;

        if (isalpha(ch) || ch == '_')
        {
            printf("Identifier starts with : %c\n", ch);

            while ((ch = fgetc(fp)) != EOF &&
                   (isalnum(ch) || ch == '_'));

            if (ch != EOF)
                fseek(fp, -1, SEEK_CUR);
        }
        else if (isdigit(ch))
        {
            printf("Number starts with : %c\n", ch);

            while ((ch = fgetc(fp)) != EOF && isdigit(ch));

            if (ch != EOF)
                fseek(fp, -1, SEEK_CUR);
        }
        else
        {
            printf("Operator/Special Symbol : %c\n", ch);
        }
    }

    fclose(fp);
    return 0;
}

