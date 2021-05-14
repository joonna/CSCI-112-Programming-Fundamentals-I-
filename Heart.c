#define _CRT_SECURE_NO_WARNINGS
//My name is Jonathan Kohler, this is my lab.
#include <stdio.h>
#define bpm  60
#define bph (bpm * 60)
#define bpd (bph * 24)
#define bpy (bpd * 365)
#define totalbeats_50years (bpy * 50) 
FILE *hbs;
int main() {

	hbs = fopen("heartlab.txt", "w");

	printf("How many beats will your heart make in 50 years?\n");

	fprintf(hbs, "How many beats will your heart make in 50 years?\n");

	printf("It will make %i beats.\n", totalbeats_50years);

	fprintf(hbs, "It will make %i beats.\n", totalbeats_50years);

	fclose(hbs);

	getchar();

	return 0;
}