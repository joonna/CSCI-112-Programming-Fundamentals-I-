#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//This is Jonathan Kohler's Character Constant Lab
FILE *poo;
int main()
{
	poo = fopen("poo.txt", "w");
	
	printf("%15s%20s%25s\n","Char Constant" , "Description" , "Value");

	fprintf(poo, "%15s%20s%25s\n", "Char Constant", "Description", "Value");

	printf("%15s%20s%25d\n","\'\\n\'", "newline",'\n');

	fprintf(poo, "%15s%20s%25d\n", "\'\\n\'", "newline", '\n');

	printf("%15s%20s%25d","\'\\t'" ,"horizontal tab",'\t');
	
	fprintf(poo, "%15s%20s%25d", "\'\\t'", "horizontal tab", '\t');

	printf("%35s%20s%25d","\'\\v'","vertical tab",'\v');

	fprintf(poo, "%35s%20s%25d", "\'\\v'", "vertical tab", '\v');

	printf("%35s%20s%25d","\'\\b'","backspace",'\b');

	fprintf(poo, "%35s%20s%25d", "\'\\b'", "backspace", '\b');

	printf("%35s%20s%25d","\'\\r'","carriage return",'\r');

	fprintf(poo, "%35s%20s%25d", "\'\\r'", "carriage return", '\r');

	printf("%35s%20s%25d","\'\\'f","form feed", '\f');

	fprintf(poo, "%35s%20s%25d", "\'\\'f", "form feed", '\f');

	printf("%35s%20s%25d","\'\\\\'","backslash", '\\');

	fprintf(poo, "%35s%20s%25d", "\'\\\\'", "backslash", '\\');

	printf("%35s%20s%25d","\'\\''","single quote", '\'');
	
	fprintf(poo, "%35s%20s%25d", "\'\\''", "single quote", '\'');

	printf("%35s%20s%25d","\'\\\"\'","double quote", '\"');

	fprintf(poo, "%35s%20s%25d", "\'\\\"\'", "double quote", '\"');

	printf("%35s%20s%25d","\'\\0'","null", '\0');
	
	fprintf(poo, "%35s%20s%25d", "\'\\0'", "null", '\0');
	
	fclose(poo);
	
	getchar();
	
	return 0;
}