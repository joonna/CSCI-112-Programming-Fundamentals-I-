#define _CRT_SECURE_NO_WARNINGS
// Jonathan Kohler ID:011165333
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define SIZE 75
#define TOTALEMPLOYEES 14

FILE *fpIn, *fpOut;

typedef enum { false, true } bool;
typedef struct Employee {
	char first[8];
	char initial[2];
	char last[10];
	char street[17];
	char city[12];
	char state[3];
	char zip[6];
	int age;
	char sex[2];
	int tenure;
	double salary;
} Employee;

void processFile(char buf[], Employee allEmployees[]);
void clearString(char stringToClear[], int maxSize);
void strsub(char buf[], char subString[], int start, int end);
void outputMen(Employee allEmployees[]);
void topWoman(Employee allEmployees[]);
void lowestMan(Employee allEmployees[]);
double avgSalary(Employee allEmployees[]);
void underpaidWomen(Employee allEmployees[], double avgSal);
void ratioMen(Employee allEmployees[], double avgSal);
void veteranEarners(Employee allEmployees[]);
void promoteEmployees(Employee allEmployees[]);
void sortStruct(Employee allEmployees[]);
int compareStructElement(const void *s1, const void *s2);
int main(void)
{
	char buf[SIZE];
	double avgSal;
	Employee allEmployees[TOTALEMPLOYEES];

	{ 
		if (!(fpOut = fopen("csis.txt", "w")))
		{
			printf("Error... closing");
			exit(1);
		}
	}
	processFile(buf, allEmployees);
	outputMen(allEmployees);
	topWoman(allEmployees);
	lowestMan(allEmployees);
	avgSal = avgSalary(allEmployees);
	underpaidWomen(allEmployees, avgSal);
	ratioMen(allEmployees, avgSal);
	veteranEarners(allEmployees);
	promoteEmployees(allEmployees);

	sortStruct(allEmployees);

	fclose(fpOut);
	getchar();
	return 0;
}
void clearString(char stringToClear[], int maxSize) {
	for (int i = 0; i < maxSize; i++) {
		stringToClear[i] = '\0';
	}
}
void strsub(char buf[], char subString[], int start, int end) {
	int i, j;

	for (j = 0, i = start; i <= end; i++, j++) {
		subString[j] = buf[i];

	}
	subString[j] = '\0';
}

void processFile(char buf[], Employee allEmployees[]) {
	char substring[16];
	char convertString[8];
	int field = 1;
	int curEmployee = 0;
	if (!(fpIn = fopen("payfile.txt", "r"))) {
		printf("payfile.txt not found, check project file... \n");
		exit(1);
	}
	while (!feof(fpIn)) {
		fgets(buf, SIZE, fpIn);

		strsub(buf, allEmployees[curEmployee].first, 0, 6);
		strsub(buf, allEmployees[curEmployee].initial, 8, 8);
		strsub(buf, allEmployees[curEmployee].last, 10, 18);
		strsub(buf, allEmployees[curEmployee].street, 20, 35);
		strsub(buf, allEmployees[curEmployee].city, 37, 47);
		strsub(buf, allEmployees[curEmployee].state, 49, 50);
		strsub(buf, allEmployees[curEmployee].zip, 52, 56);
		
		printf("%s ", allEmployees[curEmployee].first);
		printf("%s ", allEmployees[curEmployee].initial);
		printf("%s ", allEmployees[curEmployee].last);
		printf("address: %s ", allEmployees[curEmployee].street);
		printf("%s ", allEmployees[curEmployee].city);
		printf("%s ", allEmployees[curEmployee].state);
		printf("%s ", allEmployees[curEmployee].zip);
		
		fprintf(fpOut, "%s ", allEmployees[curEmployee].first);
		fprintf(fpOut, "%s ", allEmployees[curEmployee].initial);
		fprintf(fpOut, "%s ", allEmployees[curEmployee].last);
		fprintf(fpOut, "address: %s ", allEmployees[curEmployee].street);
		fprintf(fpOut, "%s ", allEmployees[curEmployee].city);
		fprintf(fpOut, "%s ", allEmployees[curEmployee].state);
		fprintf(fpOut, "%s ", allEmployees[curEmployee].zip);

		strsub(buf, convertString, 58, 59);
		
		allEmployees[curEmployee].age = atoi(convertString);
		
		printf("age: %d ", allEmployees[curEmployee].age);
		
		fprintf(fpOut, "age: %d ", allEmployees[curEmployee].age);
		
		clearString(convertString, 8);

		strsub(buf, allEmployees[curEmployee].sex, 61, 61);
		strsub(buf, convertString, 63, 63);
		
		allEmployees[curEmployee].tenure = atoi(convertString);

		printf("sex: %s ", allEmployees[curEmployee].sex);
		printf("tenure: %d ", allEmployees[curEmployee].tenure);
		
		fprintf(fpOut, "sex: %s ", allEmployees[curEmployee].sex);
		fprintf(fpOut, "tenure: %d ", allEmployees[curEmployee].tenure);
	
		clearString(convertString, 8);

		strsub(buf, convertString, 65, 70);
		
		allEmployees[curEmployee].salary = atof(convertString);
		
		printf("salary: %.2lf \n", allEmployees[curEmployee].salary);
		
		fprintf(fpOut, "salary: %.2lf \n", allEmployees[curEmployee].salary);
		
		clearString(convertString, 8);
		
		curEmployee++;
	}

	fclose(fpIn);

}
void outputMen(Employee allEmployees[]) {
	int curEmployee = 0;
	
	printf("\n Male Employees\n");
	printf("----------------------\n");
	
	fprintf(fpOut, "\n Male Employees\n");
	fprintf(fpOut, "----------------------\n");
	
	while (curEmployee < 14) {
		if (strcmp(allEmployees[curEmployee].sex, "M") == 0) {
			printf("%5s %5s\n", allEmployees[curEmployee].first, allEmployees[curEmployee].last);
			
			fprintf(fpOut, "%5s %5s\n", allEmployees[curEmployee].first, allEmployees[curEmployee].last);

		}
		curEmployee++;
	}
}
void topWoman(Employee allEmployees[]) {
	int curEmployee = 0;
	int topEmployee;
	double highestSalary = 0;
	
	printf("\n Highest Paid Woman\n");
	printf("-------------------------\n");
	
	fprintf(fpOut, "\n Highest Paid Woman\n");
	fprintf(fpOut, "-----------------------\n");
	
	while (curEmployee < 14) {
		if (strcmp(allEmployees[curEmployee].sex, "F") == 0) {
			if (allEmployees[curEmployee].salary > highestSalary) {
				highestSalary = allEmployees[curEmployee].salary;
				topEmployee = curEmployee;
			}
		}
		curEmployee++;
	}
	printf("%5s %5s\n", allEmployees[topEmployee].first, allEmployees[topEmployee].last);
	
	fprintf(fpOut, "%5s %5s\n", allEmployees[topEmployee].first, allEmployees[topEmployee].last);
}
void lowestMan(Employee allEmployees[]) {
	int curEmployee = 0;
	int topEmployee, lowEmployee;
	double highestSalary = 0;
	double lowestSalary;

	printf("\n   Lowest Paid Man\n");
	printf("------------------------\n");
	
	fprintf(fpOut, "\n Lowest Paid Man\n");
	fprintf(fpOut, "----------------------\n");

	while (curEmployee < 14) {
		if (strcmp(allEmployees[curEmployee].sex, "M") == 0) {
			if (allEmployees[curEmployee].salary > highestSalary) {
				highestSalary = allEmployees[curEmployee].salary;
				topEmployee = curEmployee;
			}
		}
		curEmployee++;
	}

	lowestSalary = highestSalary;
	curEmployee = 0;
	while (curEmployee < 14) {
		if (strcmp(allEmployees[curEmployee].sex, "M") == 0) {
			if (allEmployees[curEmployee].salary < lowestSalary) {
				lowestSalary = allEmployees[curEmployee].salary;
				lowEmployee = curEmployee;
			}
		}
		curEmployee++;
	}
	printf("%5s %5s\n", allEmployees[lowEmployee].first, allEmployees[lowEmployee].last);
	
	fprintf(fpOut, "%5s %5s\n", allEmployees[lowEmployee].first, allEmployees[lowEmployee].last);
}
double avgSalary(Employee allEmployees[]) {
	int curEmployee = 0;
	double totalSalaries = 0;

	printf("\n   Average Salary \n");
	printf("-----------------------------\n");
	
	fprintf(fpOut, "\n   Average Salary \n");
	fprintf(fpOut, "-----------------------------\n");

	while (curEmployee < 14) {
		totalSalaries += allEmployees[curEmployee].salary;
		curEmployee++;
	}

	totalSalaries /= TOTALEMPLOYEES;

	printf("The average salary is: %.2lf \n", totalSalaries);
	
	fprintf(fpOut, "The average salary is: %.2lf \n", totalSalaries);

	return totalSalaries;
}
void underpaidWomen(Employee allEmployees[], double avgSal) {
	int curEmployee = 0;
	double highestSalary = 0;
	
	printf("\n Women Earning Less than Average Salary\n");
	printf("--------------------------------------------\n");
	
	fprintf(fpOut, "\n Women Earning Less than Average Salary\n");
	fprintf(fpOut, "--------------------------------------------\n");
	
	while (curEmployee < 14) {
		if (strcmp(allEmployees[curEmployee].sex, "F") == 0) {
			if (allEmployees[curEmployee].salary < avgSal) {
				printf("%5s %5s\n", allEmployees[curEmployee].first, allEmployees[curEmployee].last);
				
				fprintf(fpOut, "%5s %5s\n", allEmployees[curEmployee].first, allEmployees[curEmployee].last);
			}
		}
		curEmployee++;
	}

}
void ratioMen(Employee allEmployees[], double avgSal) {
	int curEmployee = 0;
	float above = 0, below = 0, ratio;
	double highestSalary = 0;
	
	printf("\n Ratio of Men Paid Above Average Salary to Men Paid Below\n");
	printf("------------------------------------------------------------\n");
	
	fprintf(fpOut, "\n Ratio of Men Paid Above Average Salary to Men Paid Below\n");
	fprintf(fpOut, "-----------------------------------------------------------\n");
	
	while (curEmployee < 14) {
		if (strcmp(allEmployees[curEmployee].sex, "M") == 0) {
			if (allEmployees[curEmployee].salary < avgSal) {
				below++;
			}
			else {
				above++;
			}
		}
		curEmployee++;
	}
	ratio = above / below;
	
	printf(" %.3lf \n", ratio);

	fprintf(fpOut, " %.3lf \n", ratio);
}
void veteranEarners(Employee allEmployees[]) {
	int curEmployee = 0;
	int ageThreshold = 30, tenureThreshold = 5;
	double highSalaryThreshold = 35000, tempSalary;

	printf("\n Company Veteran Earners\n");
	printf("-----------------------------\n");
	
	fprintf(fpOut, "\n Company Veteran Earners\n");
	fprintf(fpOut, "---------------------------\n");
	
	while (curEmployee < 14) {
		if (allEmployees[curEmployee].age >= ageThreshold && allEmployees[curEmployee].tenure >= tenureThreshold) {
			tempSalary = allEmployees[curEmployee].salary;
			tempSalary *= 52;
			if (tempSalary > highSalaryThreshold) {
				
				printf("%s %s \n", allEmployees[curEmployee].first, allEmployees[curEmployee].last);
				
				fprintf(fpOut, "%s %s \n", allEmployees[curEmployee].first, allEmployees[curEmployee].last);
			}

		}
		curEmployee++;
	}
}
void promoteEmployees(Employee allEmployees[]) {
	int curEmployee = 0;
	int ageThreshold = 30, tenureThreshold = 5;
	double SalaryThreshold = 350.00;

	printf("\n Promote Employees Earning Less than 350.00 per Week\n");
	printf("--------------------------------------------------------\n");
	
	fprintf(fpOut, "\n Promote Employees Earning Less than 350.00 per Week\n");
	fprintf(fpOut, "--------------------------------------------------------\n");
	
	while (curEmployee < 14) {
		if (allEmployees[curEmployee].salary < SalaryThreshold) {
			allEmployees[curEmployee].salary += (allEmployees[curEmployee].salary *.10);
			
			printf("%s %s %.2lf \n", allEmployees[curEmployee].first, allEmployees[curEmployee].last, allEmployees[curEmployee].salary);
			
			fprintf(fpOut, "%s %s %.2lf \n", allEmployees[curEmployee].first, allEmployees[curEmployee].last, allEmployees[curEmployee].salary);

		}
		curEmployee++;
	}
}

int compareStructElement(const void *s1, const void *s2) {
	struct Employee *temp1 = (struct Employee *)s1;
	struct Employee *temp2 = (struct Employee *)s2;

	int zipcompare = strcmp(temp1->zip, temp2->zip);

	return zipcompare;
}

void sortStruct(Employee allEmployees[]) {

	qsort(allEmployees, 14, sizeof(struct Employee), compareStructElement);

	printf("\n Sort Employees by Zip Code\n");
	printf("---------------------------------\n");
	
	fprintf(fpOut, "\n Sort Employees by Zip Code\n");
	fprintf(fpOut, "--------------------------------\n");

	for (int z = 0; z < 14; z++) {
		
		printf("%s %s %s \n", allEmployees[z].first, allEmployees[z].last, allEmployees[z].zip);
		
		fprintf(fpOut, "%s %s %s \n", allEmployees[z].first, allEmployees[z].last, allEmployees[z].zip);
	}
}