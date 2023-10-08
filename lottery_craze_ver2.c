#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayHome(void);

void writeSixWinners(FILE*, char*, size_t, int*);

void writeFiveWinners(FILE*, char*, size_t, int*);

void writeFourWinners(FILE*, char*, size_t, int*);

void writeThreeWinners(FILE*, char*, size_t, int*);

int main(void) {

    // File pointer declarations for the files to be read and written
    FILE* dataset,
        * sixCombinations,
        * fiveCombinations,
        * fourCombinations,
        * threeCombinations;

    // prizes for each winning combinations
    double prizeSix,
           prizeFive,
           prizeFour,
           prizeThree;


    // tally of winners in each number of combination
    long int sixCombiWinners = 0,
             fiveCombiWinners = 0,
             fourCombiWinners = 0,
             threeCombiWinners = 0;

    int match;

    // Variables in the dataset file
    char date[10];
    int numbers[6];    // winning numbers in the dataset

    // lotto entry inputted by the user
    int entries[6];

    // Open dataset file and check if it exists
    dataset = fopen("lottery_NY_lotto_winning_numbers_formatted.csv", "r");
    if (dataset == NULL) {
        perror("Error in reading the file");
        exit(1);
    }

    // Open files for appending
    sixCombinations = fopen("six_combi.csv", "a");
    fiveCombinations = fopen("five_combi.csv", "a");
    fourCombinations = fopen("four_combi.csv", "a");
    threeCombinations = fopen("three_combi.csv", "a");

    displayHome();

    printf("\n  Enter a number combination: ");
    for (unsigned int i = 0; i < 6; ++i) {
        scanf("%d", &entries[i]);
    }

    // Check if entered entry is within 1-59
    for (unsigned int i = 0; i < 6; ++i) {
        if (!(entries[i] >= 1 && entries[i] <= 59)) {
            printf("Invalid range of number combination. Enter numbers between 1-59\n");
            exit(1);
        }
    }


    // Read the dataset
    char line[50];
    char* stringPtr;

    while (fgets(line, 50, dataset) != NULL) {
        match = 0;

        // Handle the date in the dataset
        stringPtr = strtok(line, ",");
        strcpy(date, stringPtr);

        // Handle the winning numbers
        int i = 0;
        while (stringPtr = strtok(NULL, " ")) {
            numbers[i] = atoi(stringPtr);
            ++i;
        }

        // Compare each number in the entry to the winning numbers in the dataset
        for (unsigned int a = 0; a < 6; ++a) {
            for (unsigned int b = 0; b < 6; ++b) {
                if (entries[a] == numbers[b]) {
                    ++match;
                    break;
                }
            }
        }

        // Write to file
        switch (match) {
            case 6:
                ++sixCombiWinners;
                writeSixWinners(sixCombinations, date, 6, numbers);
                break;
            case 5:
                ++fiveCombiWinners;
                writeFiveWinners(fiveCombinations, date, 6, numbers);
                break;
            case 4:
                ++fourCombiWinners;
                writeFourWinners(fourCombinations, date, 6, numbers);
                break;
            case 3:
                ++threeCombiWinners;
                writeThreeWinners(threeCombinations, date, 6, numbers);
                break;
        }
    }

    fclose(dataset);
    fclose(sixCombinations);
    fclose(fiveCombinations);
    fclose(fourCombinations);
    fclose(threeCombinations);

    printf("\n**************************************************\n\n");
    printf("  Six-combination winners: %d\n", sixCombiWinners);
    printf("  Five-combination winners: %d\n", fiveCombiWinners);
    printf("  Four-combination winners: %d\n", fourCombiWinners);
    printf("  Three-combination winners: %d\n\n", threeCombiWinners);
    printf("**************************************************");

    return 0;
}

void displayHome(void) {
    printf("**************************************************\n"
           "                LOTTERY CRAZE                      \n"
           "**************************************************\n");
}

void writeSixWinners(FILE* fptr, char* drawDate, size_t numArr, int* numToWrite) {
    fprintf(fptr, "%s,", drawDate);

    for (int i = 0; i < numArr; ++i) {
        fprintf(fptr, "%d ", numToWrite[i]);
    }
    fprintf(fptr, "\n");
}

void writeFiveWinners(FILE* fptr, char* drawDate, size_t numArr, int* numToWrite) {
    fprintf(fptr, "%s,", drawDate);

    for (int i = 0; i < numArr; ++i) {
        fprintf(fptr, "%d ", numToWrite[i]);
    }
    fprintf(fptr, "\n");
}

void writeFourWinners(FILE* fptr, char* drawDate, size_t numArr, int* numToWrite) {
    fprintf(fptr, "%s,", drawDate);

    for (int i = 0; i < numArr; ++i) {
        fprintf(fptr, "%d ", numToWrite[i]);
    }
    fprintf(fptr, "\n");
}

void writeThreeWinners(FILE* fptr, char* drawDate, size_t numArr, int* numToWrite) {
    fprintf(fptr, "%s,", drawDate);

    for (int i = 0; i < numArr; ++i) {
        fprintf(fptr, "%d ", numToWrite[i]);
    }
    fprintf(fptr, "\n");
}
