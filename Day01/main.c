#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char firstNumberOfString(char *buffer);
char lastNumberOfString(char *buffer);
char *replaceNumberNamesWithDigits(char *buffer);

int main() {
    // Create pointer to the input file
    FILE *inputPointer = fopen("input.txt", "r");

    // Stop execution if the file wasn't found
    if (inputPointer == NULL) {
        return 1;
    }

    int calibrationValueSum = 0;
    char workingCharacter, *bufferLine, *processedLine;

    bufferLine = (char *)malloc(256);

    while (fgets(bufferLine, 255, inputPointer) != NULL) {
        processedLine = replaceNumberNamesWithDigits(bufferLine);

        workingCharacter = firstNumberOfString(processedLine);
        if (workingCharacter == '\0') {
            continue;
        }

        char calibrationValue[3];
        calibrationValue[0] = workingCharacter;

        workingCharacter = lastNumberOfString(processedLine);
        if (workingCharacter == '\0') {
            continue;
        }

        calibrationValue[1] = workingCharacter;
        calibrationValue[2] = '\0';
        calibrationValueSum += strtol(calibrationValue, NULL, 10);
    }

    fclose(inputPointer);
    free(bufferLine);

    printf("%i\n", calibrationValueSum);
    return 0;
}

char firstNumberOfString(char *buffer) {
    while (*buffer) {
        if (isdigit(*buffer)) {
            return *buffer;
        }
        buffer++;
    }
    return '\0';
}

char lastNumberOfString(char *buffer) {
    buffer += strlen(buffer) - 1;
    while (*buffer) {
        if (isdigit(*buffer)) {
            return *buffer;
        }
        buffer--;
    }
    return '\0';
}

char *replaceNumberNamesWithDigits(char *buffer) {
    char *output = (char *)malloc(strlen(buffer) + 1);
    char *outputStart = output;

    while (*buffer) {
        switch (*buffer) {
        case 'o':
            buffer++;
            if (*buffer == 'n') {
                buffer++;
                if (*buffer == 'e') {
                    *output = '1';
                    output++;
                } else {
                    buffer--;
                }
            }
            break;
        case 't':
            buffer++;
            if (*buffer == 'w') {
                buffer++;
                if (*buffer == 'o') {
                    *output = '2';
                    output++;
                }
            } else if (*buffer == 'h') {
                buffer++;
                if (*buffer == 'r') {
                    buffer++;
                    if (*buffer == 'e') {
                        buffer++;
                        if (*buffer == 'e') {
                            *output = '3';
                            output++;
                        } else {
                            buffer--;
                        }
                    }
                }
            }
            break;
        case 'f':
            buffer++;
            if (*buffer == 'o') {
                buffer++;
                if (*buffer == 'u') {
                    buffer++;
                    if (*buffer == 'r') {
                        *output = '4';
                        output++;
                        buffer++;
                    }
                } else {
                    buffer--;
                }
            } else if (*buffer == 'i') {
                buffer++;
                if (*buffer == 'v') {
                    buffer++;
                    if (*buffer == 'e') {
                        *output = '5';
                        output++;
                    }
                }
            }
            break;
        case 's':
            buffer++;
            if (*buffer == 'i') {
                buffer++;
                if (*buffer == 'x') {
                    *output = '6';
                    output++;
                    buffer++;
                }
            } else if (*buffer == 'e') {
                buffer++;
                if (*buffer == 'v') {
                    buffer++;
                    if (*buffer == 'e') {
                        buffer++;
                        if (*buffer == 'n') {
                            *output = '7';
                            output++;
                            buffer++;
                        } else {
                            buffer--;
                        }
                    }
                } else {
                    buffer--;
                }
            }
            break;
        case 'e':
            buffer++;
            if (*buffer == 'i') {
                buffer++;
                if (*buffer == 'g') {
                    buffer++;
                    if (*buffer == 'h') {
                        buffer++;
                        if (*buffer == 't') {
                            *output = '8';
                            output++;
                        }
                    }
                }
            }
            break;
        case 'n':
            buffer++;
            if (*buffer == 'i') {
                buffer++;
                if (*buffer == 'n') {
                    buffer++;
                    if (*buffer == 'e') {
                        *output = '9';
                        output++;
                    }
                }
            }
            break;
        default:
            *output = *buffer;
            output++;
            buffer++;
            break;
        }
    }

    *output = '\0';
    return outputStart;
}
