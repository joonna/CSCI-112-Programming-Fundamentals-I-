#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

FILE *fp, *csis;

char *processFile();
void cipher(char *values, int shift);
void outputCode(char *inp);

int main(void)
{
	char *input;

	csis = fopen("csis.txt", "w");

	input = processFile();
	cipher(input, 13);
	outputCode(input);

	fclose(csis);
	fclose(fp);

	return 0;
}

char *processFile()
{
	static char temp[300];
	int i = 0;
	char input;

	if (!(fp = fopen("congress.txt", "r"))) {
		printf("congress.txt could not be opened for input.");
		exit(1);
	}
	while (!feof(fp)) {
		fscanf(fp, "%c\n", &input);
		if (isalpha(input)) {
			temp[i] = toupper(input);
			i++;
		}
	}
	return temp;
}

void cipher(char *values, int shift)
{
	while (*values) {
		*values = (*values - 'A' + shift) % 26 + 'A';
		values++;
	}
	*values = '\0';
}

void outputCode(char *inp)
{
	for (int i = 0; *inp != '\0'; inp++, i++) {
		if ((i % 5) == 0) {
			printf(" ");
			fprintf(csis, " ");
		}
		if ((i % 50) == 0) {
			printf("\n");
			fprintf(csis, "\n");
		}
		printf("%c", *inp);
		fprintf(csis, "%c", *inp);
	}
}