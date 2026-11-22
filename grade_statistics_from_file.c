#include <stdio.h>
#include <stdlib.h>

void Enter(void);
void showstatistics(void);
void readfile(void);

float* grades= NULL;
int gradecount = 0;

int main() {
    int choice;
    printf("HELLO TO THE GRADE MANAGEMENT\n");
    while (1) {
        printf("1. Load a file\n");
        printf("2. Enter Grade\n");
        printf("3. View Statistics\n");
        printf("4. Quit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                readfile();
                break;
            case 2:
                Enter();
                break;
            case 3:
                showstatistics();
                break;
            case 4:
                free(grades);
                return 0;
        }
    }


}
void Enter(void) {
    int numberofgrades;
    printf("How many grades do you want to Enter?\n");
    scanf("%d", &numberofgrades);

    float* temp =realloc (grades, (gradecount + numberofgrades)*sizeof(float));
    if (temp == NULL) {
        printf("Not enough memory");
        return;
    }
    grades = temp;


    for (int i=0; i<numberofgrades; i++) {
        float g=0;
        printf("Enter Grade:");
        scanf("%f", &g);
        if (g>=1.0 && g<=5.0) {
            grades[gradecount] = g;
            gradecount++;
        }else {
            printf("Grade must be between 1.0 and 5.0\n");
            i--;
        }
    }
    printf("The Grades have been saved\n");
    printf("\n");
}

void showstatistics(void) {
    if (gradecount == 0) {
        printf("The number of grades have not been saved yet\n");
        printf("Please Enter grades using Option 2\n");
        printf("Or\n");
        printf("Load the data\n");
        return;
    }else {
        float averagesum=0;

        for (int i=0; i<gradecount; i++) {
            averagesum = averagesum + grades[i];
        }
        float average = averagesum/gradecount;
        printf("The average of the grades is %.2f\n", average);

        float bestgrade= grades[0];
        for (int i=0; i<gradecount; i++) {
            if (grades[i] < bestgrade) {
                bestgrade = grades[i];
            }
        }
        printf("The best grade is %.2f\n", bestgrade);

        float worstgrade= grades[0];
        for (int i=0; i<gradecount; i++) {
            if (grades[i] > worstgrade) {
                worstgrade = grades[i];
            }
        }
        printf("The worst grade is %.2f\n", worstgrade);

        int fails=0;
        for (int i=0; i<gradecount; i++) {
            if (grades[i] > 4.0) {
                fails++;
            }
        }
        printf("The number of failures is %d\n", fails);

    }
}

void readfile(void) {
    FILE* file = fopen("examgrades1.txt", "r");
    if (file == NULL) {
        printf("Not able to open file\n");
        return;
    }
    char line[100];

    while (fgets(line, sizeof(line), file) != NULL) {
        gradecount++;
    }

    rewind(file);
    float* temp =realloc (grades, (gradecount + 1)*sizeof(float));
    if (temp == NULL) {
        printf("Not enough memory");
        return;
    }
    grades = temp;

    for (int i=0; i<gradecount; i++) {
       fgets(line, sizeof(line), file);
        grades[i] = atof(line);
        printf(" Grade:%.2f\n", grades[i]);
    }
    printf("\n");
    fclose(file);
}