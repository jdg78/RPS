#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Variable declarations.
    int userEntry;
    char nameBuffer[100];
    char name[100];

    // Seed random number generator
    srand((unsigned int)time(NULL));

    // Greeting and game opening.
    printf("Welcome to Rock-Paper-Scissors!\n");
    printf("Please enter your name: ");
    fgets(nameBuffer, sizeof(nameBuffer), stdin);
    sscanf(nameBuffer, "%s", name);

    printf("\nOkay %s, it's your turn.\n", name);

    int gameIsOver = 0;
    int userWinCount = 0;
    int compWinCount = 0;
    int roundCounter = 0;

    while (gameIsOver == 0) {
        // Increment the round
        roundCounter++;
        // Determine Game Winner best 3 of 5.
        if (userWinCount == 3) {
            gameIsOver = 1;
            printf("You've won the game!\n");
            break;
        }

        if (compWinCount == 3) {
            gameIsOver = 1;
            printf("You've lost the game!\n");
            break;
        }

        printf("\nRound %d\n", roundCounter);
        printf("\nScores:\n%s: %d\nComputer: %d\n", name, userWinCount, compWinCount);

        printf("\nPlease enter an in 1-3.\n1 - Rock\n2 - Paper\n3 - Scissors.\n");
        printf("Your entry: ");

        // Boolean int value.
        int validEntry = 0;

        // Input validation. Can only enter 1, 2, or 3.
        while (validEntry == 0) {
            char numLine[10];
            fgets(numLine, sizeof(numLine), stdin);
            sscanf(numLine, "%d", &userEntry);

            if (userEntry < 1 || userEntry > 3) {
                validEntry = 0;
                printf("Please enter either 1, 2, or 3: ");
                continue;
            }

            validEntry = 1;
        }

        // Switch statemnt to translate entered int to the respective object. (RPS)
        switch (userEntry) {
            case 1:
            printf("You chose Rock!\n");
            break;
            case 2:
            printf("You chose Paper!\n");
            break;
            case 3:
            printf("You chose Scissors!\n");
            break;
            default:
            printf("There was no decision.\n");
        }

        // Randomized computer decision to pick Rock-Paper-Scissors.
        int computerChoice = rand() % 3; // Randomly generates an int 0-2.
        computerChoice += 1; // Adds 1 to the randomly generated int.

        // Switch statement for computer's int decision.
        switch(computerChoice) {
            case 1:
            printf("The computer chose Rock!\n");
            break;
            case 2:
            printf("The computer chose Paper!\n");
            break;
            case 3:
            printf("The computer chose Scissors!\n");
            break;
            default:
            printf("Invalid choice\n");
        }

        // Test if draw. If true then begin loop again.
        if (userEntry == computerChoice) {
            gameIsOver = 0;
            printf("Draw! Keep going!\n");
            continue;
        }

        // Determine win/loss is user chose rock.
        if (userEntry == 1) {
            if (computerChoice == 2) {
                printf("Paper covers Rock! You lose!\n");
                compWinCount++;
                continue;
            }
            printf("You win this round!\n");
            userWinCount++;
            continue;
        }
        // Determine win/loss if user chose paper.
        if (userEntry == 2) {
            if (computerChoice == 3) {
                printf("Scissors cuts Paper! You lose round!\n");
                compWinCount++;
                continue;
            }
            printf("You win!\n");
            userWinCount++;
            continue;
        }

        // Determine win/loss if user chose Scissors.
        if (userEntry == 3) {
            if (computerChoice == 1) {
                printf("Rock crushes Scissors! You lose the round!\n");
                compWinCount++;
                continue;
            }
            printf("You win this round!\n");
            userWinCount++;
            continue;
        }

    }
    return 0;
}
