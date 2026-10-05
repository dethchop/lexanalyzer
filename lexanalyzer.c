#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main()
{

char str[100];
int i = 0;
printf("Enter Expression: ");
fgets(str, sizeof(str), stdin);


while(str[i] != '\0')
{
	if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
	{
		i++;
		continue;
	}
	
	if(isalpha(str[i]) || str[i] == '_')
	{	
		char identifier[50];
		int j = 0;
		while(isalnum(str[i]) || str[i] == '_')
		{
			identifier[j++] = str[i++];
		}
		identifier[j] = '\0';
		printf("%s : Identifier\n", identifier);
	}
	
	else if(isdigit(str[i]))
	{
		char number[50];
		int j = 0;
		
		while(isdigit(str[i]))
		{
			number[j++] = str[i++];
		}
		number[j] = '\0';
		printf("%s : Number\n", number);
	}
	else
	{
		printf("%c : Operator\n", str[i]);
		i++;
	}
}
return 0;
}
