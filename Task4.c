#include <stdio.h>

int main() {
    int marks[4][2];   // 4 students, 2 columns (Mid, Final)
    int i, j;
    int total[4];
    int maxMid, maxFinal, maxOverall;
    int minMid, minFinal, minOverall;
    float avgMid = 0, avgFinal = 0;

    // Input
    printf("Enter Mid and Final marks for 4 students:\n");
    for(i = 0; i < 4; i++) {
        printf("Student %d:\n", i + 1);
        for(j = 0; j < 2; j++) {
            if(j == 0)
                printf("  Mid marks: ");
            else
                printf("  Final marks: ");
            scanf("%d", &marks[i][j]);
        }
    }

    // Initialize max/min
    maxMid = minMid = marks[0][0];
    maxFinal = minFinal = marks[0][1];
    maxOverall = minOverall = marks[0][0];

    // Calculations
    for(i = 0; i < 4; i++) {
        total[i] = marks[i][0] + marks[i][1];

        // Mid
        if(marks[i][0] > maxMid) maxMid = marks[i][0];
        if(marks[i][0] < minMid) minMid = marks[i][0];

        // Final
        if(marks[i][1] > maxFinal) maxFinal = marks[i][1];
        if(marks[i][1] < minFinal) minFinal = marks[i][1];

        // Overall
        if(marks[i][0] > maxOverall) maxOverall = marks[i][0];
        if(marks[i][1] > maxOverall) maxOverall = marks[i][1];
        if(marks[i][0] < minOverall) minOverall = marks[i][0];
        if(marks[i][1] < minOverall) minOverall = marks[i][1];

        avgMid += marks[i][0];
        avgFinal += marks[i][1];
    }

    avgMid /= 4.0;
    avgFinal /= 4.0;

    // Display
    printf("\n--- Results ---\n");
    printf("1. Total marks of each student:\n");
    for(i = 0; i < 4; i++) {
        printf("   Student %d: %d\n", i + 1, total[i]);
    }

    printf("\n2. Highest marks:\n");
    printf("   Highest Mid   : %d\n", maxMid);
    printf("   Highest Final : %d\n", maxFinal);
    printf("   Highest Overall: %d\n", maxOverall);

    printf("\n3. Lowest marks:\n");
    printf("   Lowest Mid    : %d\n", minMid);
    printf("   Lowest Final  : %d\n", minFinal);
    printf("   Lowest Overall: %d\n", minOverall);

    printf("\n4. Averages:\n");
    printf("   Average Mid marks  : %.2f\n", avgMid);
    printf("   Average Final marks: %.2f\n", avgFinal);

    return 0;
}
