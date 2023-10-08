#include <stdio.h>

void winnerSix (FILE*, long int, int, int, int, int, int, int); //tempGate, serialNum, taya1, taya2, taya3, taya4, taya5, taya6
void winnerFive (FILE*, long int, int, int, int, int, int, int);
void winnerFour (FILE*, long int, int, int, int, int, int, int);
void winnerThree (FILE*, long int, int, int, int, int, int, int);
void totalWinners(int, int, int, int);
void totalPrizes(int, int, int, int, double, double, double, double);

int main() {

    FILE *testData, *combiSix, *combiFive, *combiFour, *combiThree;
    long int serialNum;
    double jackpot, prizeFive, prizeFour, prizeThree;
    int slot1, slot2, slot3, slot4, slot5, slot6;
    int taya1, taya2, taya3, taya4, taya5, taya6;
    int tempGate, winCombiNum, winSix = 0, winFive = 0, winFour = 0, winThree = 0;


    testData = fopen("lotto.txt.in", "r");
    combiSix = fopen("six_combi.out", "a");
    combiFive = fopen("five_combi.out", "a");
    combiFour = fopen("four_combi.out", "a");
    combiThree = fopen("three_combi.out", "a");

    printf("6/58 ULTRA LOTTO CRAZE\n\n\n");
    printf("Enter today's winning combination: \t");
    scanf("%d %d %d %d %d %d", &slot1, &slot2, &slot3, &slot4, &slot5, &slot6);

    printf("\nEnter today's winning prizes:\n");
    printf("\tJackpot prize: \t\t\t");
    scanf("%lf", &jackpot);
    printf("\t5-number Winning Combination: \t");
    scanf("%lf", &prizeFive);
    printf("\t4-number Winning Combination: \t");
    scanf("%lf", &prizeFour);
    printf("\t3-number Winning Combination: \t");
    scanf("%lf", &prizeThree);

    if (testData == NULL) {
        printf("An error has occurred while opening the file!\n");
    } else {
        while(!feof(testData)) {
            winCombiNum = 0;
                fscanf(testData, "%ld %d %d %d %d %d %d", &serialNum, &taya1, &taya2, &taya3, &taya4, &taya5, &taya6);

                if (slot1 == taya1 || slot1 == taya2 || slot1 == taya3 || slot1 == taya4 || slot1 == taya5 || slot1 == taya6) {
                    winCombiNum++;
                }
                if (slot2 == taya1 || slot2 == taya2 || slot2 == taya3 || slot2 == taya4 || slot2 == taya5 || slot2 == taya6) {
                    winCombiNum++;
                }
                if (slot3 == taya1 || slot3 == taya2 || slot3 == taya3 || slot3 == taya4 || slot3 == taya5 || slot3 == taya6) {
                    winCombiNum++;
                }
                if (slot4 == taya1 || slot4 == taya2 || slot4 == taya3 || slot4 == taya4 || slot4 == taya5 || slot4 == taya6) {
                    winCombiNum++;
                }
                if (slot5 == taya1 || slot5 == taya2 || slot5 == taya3 || slot5 == taya4 || slot5 == taya5 || slot5 == taya6) {
                    winCombiNum++;
                }
                if (slot6 == taya1 || slot6 == taya2 || slot6 == taya3 || slot6 == taya4 || slot6 == taya5 || slot6 == taya6) {
                    winCombiNum++;
                }

                switch (winCombiNum) {
                case 6:
                    winSix++;
                    winnerSix(combiSix, serialNum, taya1, taya2, taya3, taya4, taya5, taya6);
                    break;
                case 5:
                    winFive++;
                    winnerFive(combiFive, serialNum, taya1, taya2, taya3, taya4, taya5, taya6);
                    break;
                case 4:
                    winFour++;
                    winnerFour(combiFour, serialNum, taya1, taya2, taya3, taya4, taya5, taya6);
                    break;
                case 3:
                    winThree++;
                    winnerSix(combiThree, serialNum, taya1, taya2, taya3, taya4, taya5, taya6);
                    break;
                }
        }
        totalWinners(winSix, winFive, winFour, winThree);
        totalPrizes(winSix, winFive, winFour, winThree, jackpot, prizeFive, prizeFour, prizeThree);
    }
    fclose(testData);
    fclose(combiSix);
    fclose(combiFive);
    fclose(combiFour);
    fclose(combiThree);

    return 0;
}

void totalWinners(int six, int five, int four, int three) {
    FILE *tallyWin = fopen("total_winners.out", "w");

    fprintf(tallyWin, "TALLY OF WINNERS FOR TODAY'S 6/58 ULTRA LOTTO: \n");
    fprintf(tallyWin, "\t6-number Winning Combination: \t %d\n\t5-number Winning Combination: \t %d\n", six, five);
    fprintf(tallyWin, "\t4-number Winning Combination: \t %d\n\t3-number Winning Combination: \t %d\n", four, three);

    fclose(tallyWin);

    printf("\n\nTALLY OF WINNERS FOR TODAY'S 6/58 LOTTO: \n");
    printf("\t6-number Winning Combination: \t %d\n\t5-number Winning Combination: \t %d\n", six, five);
    printf("\t4-number Winning Combination: \t %d\n\t3-number Winning Combination: \t %d\n", four, three);
}

void totalPrizes(int six, int five, int four, int three, double prizeJ, double prize5, double prize4, double prize3) {
    FILE *tallyPrize = fopen("total_prizes.out", "w");
    double totalPrize5, totalPrize4, totalPrize3;

    totalPrize5 = five * prize5;
    totalPrize4 = four * prize4;
    totalPrize3 = three * prize3;

    fprintf(tallyPrize, "TALLY OF PRIZES FOR TODAY'S 6/58 ULTRA LOTTO:\n");
    fprintf(tallyPrize, "\tWinning Combination Number \t\t Winners \t\tPrize \t\t\t\t Total Amount\n");
    fprintf(tallyPrize, "\t\tJackpot \t\t\t\t\t\t %d \t\t\t\t %.2lf \t\t %.2lf\n", six, prizeJ/six, prizeJ);
    fprintf(tallyPrize, "\t\t5 Numbers\t\t\t\t\t\t %d \t\t\t %.2lf \t\t\t %.2lf\n", five, prize5, totalPrize5);
    fprintf(tallyPrize, "\t\t4 Numbers\t\t\t\t\t\t %d \t\t\t %.2lf \t\t\t %.2lf\n", four, prize4, totalPrize4);
    fprintf(tallyPrize, "\t\t3 Numbers\t\t\t\t\t\t %d \t\t %.2lf \t\t\t %.2lf\n", three, prize3, totalPrize3);

    fclose(tallyPrize);

    printf("\n\nTALLY OF PRIZES FOR TODAY'S 6/58 ULTRA LOTTO:\n");
    printf("\tWinning Combination Number \t\t Winners \t\t Prize \t\t\t Total Amount\n");
    printf("\t\tJackpot \t\t\t %d \t\t\t %.2lf \t\t %.2lf\n", six, prizeJ/six, prizeJ);
    printf("\t\t5 Numbers\t\t\t %d \t\t\t %.2lf \t\t %.2lf\n", five, prize5, totalPrize5);
    printf("\t\t4 Numbers\t\t\t %d \t\t\t %.2lf \t\t %.2lf\n", four, prize4, totalPrize4);
    printf("\t\t3 Numbers\t\t\t %d \t\t %.2lf \t\t %.2lf\n", three, prize3, totalPrize3);
}

void winnerSix (FILE *fptr, long int sn, int a, int b, int c, int d, int e, int f) {
        fprintf(fptr, "%ld %d %d %d %d %d %d\n", sn, a, b, c, d, e, f);
}

void winnerFive (FILE *fptr, long int sn, int a, int b, int c, int d, int e, int f) {
        fprintf(fptr, "%ld %d %d %d %d %d %d\n", sn, a, b, c, d, e, f);
}

void winnerFour (FILE *fptr, long int sn, int a, int b, int c, int d, int e, int f) {
        fprintf(fptr, "%ld %d %d %d %d %d %d\n", sn, a, b, c, d, e, f);
}

void winnerThree (FILE *fptr, long int sn, int a, int b, int c, int d, int e, int f) {
        fprintf(fptr, "%ld %d %d %d %d %d %d\n", sn, a, b, c, d, e, f);
}
