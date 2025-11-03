
/*
  name:         Owuor Zephania Ulare
  reg:          PA106/G/29218/25
  description:   CAT_Q3
*/



#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void writeInputFile();
void calculateSumAndAverage();
void displayFiles();

int main() {
    writeInputFile();          // Step 1: Get 10 integers from user
    calculateSumAndAverage();  // Step 2: Process integers and write sum/average
    displayFiles();            // Step 3: Display contents of input.txt and output.txt
    
    return 0;
}

// Function to prompt user for 10 integers and save to input.txt
void writeInputFile() {
    FILE *fp = fopen("input.txt", "w");
    if (fp == NULL) {
        perror("Error opening input.txt for writing");
        exit(1);
    }

    int num;
    printf("Enter 10 integers:\n");
    for(int i = 0; i < 10; i++) {
        printf("Integer %d: ", i + 1);
        scanf("%d", &num);
        fprintf(fp, "%d\n", num); // Write each integer on a new line
    }

    fclose(fp);
    printf("Input successfully written to input.txt\n\n");
}

// Function to read integers from input.txt, calculate sum and average, and write to output.txt
void calculateSumAndAverage() {
    FILE *fpIn = fopen("input.txt", "r");
    if (fpIn == NULL) {
        perror("Error opening input.txt for reading");
        exit(1);
    }

    int num, sum = 0, count = 0;
    while(fscanf(fpIn, "%d", &num) == 1) {
        sum += num;
        count++;
    }

    if(count == 0) {
        printf("No integers found in input.txt\n");
        fclose(fpIn);
        return;
    }

    float average = (float)sum / count;

    fclose(fpIn);

    FILE *fpOut = fopen("output.txt", "w");
    if (fpOut == NULL) {
        perror("Error opening output.txt for writing");
        exit(1);
    }

    fprintf(fpOut, "Sum: %d\n", sum);
    fprintf(fpOut, "Average: %.2f\n", average);

    fclose(fpOut);
    printf("Sum and average successfully written to output.txt\n\n");
}

// Function to read and display the contents of input.txt and output.txt
void displayFiles() {
    FILE *fpIn = fopen("input.txt", "r");
    if (fpIn == NULL) {
        perror("Error opening input.txt for reading");
        exit(1);
    }

    printf("Contents of input.txt:\n");
    printf("----------------------\n");
    int num;
    int line = 1;
    while(fscanf(fpIn, "%d", &num) == 1) {
        printf("Integer %d: %d\n", line++, num);
    }
    fclose(fpIn);

    FILE *fpOut = fopen("output.txt", "r");
    if (fpOut == NULL) {
        perror("Error opening output.txt for reading");
        exit(1);
    }

    printf("\nContents of output.txt:\n");
    printf("-----------------------\n");
    char ch;
    while((ch = fgetc(fpOut)) != EOF) {
        putchar(ch);
    }
    fclose(fpOut);
}
