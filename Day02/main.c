#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syslimits.h>

int MAX_RED_CUBES = 12;
int MAX_GREEN_CUBES = 13;
int MAX_BLUE_CUBES = 14;

struct Game {
    int gameNumber;
    int redCount;
    int greenCount;
    int blueCount;
};

int partOne(struct Game currentGame);
int partTwo(struct Game currentGame);
void inputParser(FILE *pInput);

int main() {
    FILE *pInput = fopen("input.txt", "r");
    FILE *pInputStart = pInput;

    if (pInput == NULL) {
        printf("Input file not found\n");
        return 1;
    }
    inputParser(pInput);

    pInput = pInputStart;

    fclose(pInput);
    return 0;
}

int partOne(struct Game currentGame) {
    if (currentGame.redCount <= MAX_RED_CUBES &&
        currentGame.greenCount <= MAX_GREEN_CUBES &&
        currentGame.blueCount <= MAX_BLUE_CUBES) {
        return currentGame.gameNumber;
    }

    return 0;
}
int partTwo(struct Game currentGame) {
    return currentGame.redCount * currentGame.greenCount *
           currentGame.blueCount;
}

void inputParser(FILE *pInput) {
    char *pLineBuffer = (char *)malloc(1024);
    char *pLineBufferStartingAddres = pLineBuffer;

    int cubeAmount = 0;
    int setRedCubes = 0;
    int setGreenCubes = 0;
    int setBlueCubes = 0;

    int partOneSum = 0;
    int partTwoSum = 0;

    struct Game game = {0, 0, 0, 0};

    while (fgets(pLineBuffer, 1024, pInput)) {
        sscanf(pLineBuffer, "Game %d:", &game.gameNumber);
        pLineBuffer = strchr(pLineBuffer, ':') + 2;

        while (*pLineBuffer) {
            // Get amount of cubes of current color
            if (isdigit(*pLineBuffer)) {
                sscanf(pLineBuffer, "%d", &cubeAmount);
                pLineBuffer = strchr(pLineBuffer, ' ') + 1;
            }

            // Assing the amount of cubes to the respective color
            switch (*pLineBuffer) {
            case 'r':
                setRedCubes += cubeAmount;
                cubeAmount = 0;
                pLineBuffer = strchr(pLineBuffer, 'd');
                break;
            case 'g':
                setGreenCubes += cubeAmount;
                cubeAmount = 0;
                pLineBuffer = strchr(pLineBuffer, 'n');
                break;
            case 'b':
                setBlueCubes += cubeAmount;
                cubeAmount = 0;
                pLineBuffer = strchr(pLineBuffer, 'e');
                break;
            default:
                pLineBuffer++;
                if (*pLineBuffer == ';') {
                    game.redCount = game.redCount > setRedCubes ? game.redCount
                                                                : setRedCubes;
                    game.greenCount = game.greenCount > setGreenCubes
                                          ? game.greenCount
                                          : setGreenCubes;
                    game.blueCount = game.blueCount > setBlueCubes
                                         ? game.blueCount
                                         : setBlueCubes;
                    setRedCubes = 0;
                    setGreenCubes = 0;
                    setBlueCubes = 0;
                    pLineBuffer++;
                } else if (*pLineBuffer == '\0') {
                    game.redCount = game.redCount > setRedCubes ? game.redCount
                                                                : setRedCubes;
                    game.greenCount = game.greenCount > setGreenCubes
                                          ? game.greenCount
                                          : setGreenCubes;
                    game.blueCount = game.blueCount > setBlueCubes
                                         ? game.blueCount
                                         : setBlueCubes;
                    setRedCubes = 0;
                    setGreenCubes = 0;
                    setBlueCubes = 0;
                }
            }
        }

        partOneSum += partOne(game);
        partTwoSum += partTwo(game);
        game.redCount = 0;
        game.greenCount = 0;
        game.blueCount = 0;
        pLineBuffer = pLineBufferStartingAddres;
    }
    printf("partOneSum = %d\n", partOneSum);
    printf("partTwoSum = %d\n", partTwoSum);
}
