#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/**
 * C BrainF-ck Interpreter
 * Antoine LANDRIEUX
 * 
 * <https://github.com/AntoineLandrieux/BrainF-ck>
**/

/**
 * @brief 512000 bits
 *
 */
int8_t MEMORY[64 * 1000];

#define MAX_USER_INPUT 1000

typedef struct brainf_ck
{
    char _Code[MAX_USER_INPUT];

    uint64_t _Position;

    uint8_t _Condition;
    uint64_t _Condition_Address;
} BrainF_ck;

/**
 * 
 * @param _BrainF_ckLine 
 * @return uint32_t 
 */
uint32_t RunBrainF_ckLine(BrainF_ck _BrainF_ckLine)
{
    static uint32_t POINTER = 0x00;
    uint32_t _Start = _BrainF_ckLine._Position;

    while (_BrainF_ckLine._Code[_BrainF_ckLine._Position])
    {
        BrainF_ck new;
        const char c = _BrainF_ckLine._Code[_BrainF_ckLine._Position];

        _BrainF_ckLine._Position++;

        switch (c)
        {
        case '>':

            POINTER++;
            break;

        case '<':

            POINTER--;
            break;

        case '+':

            ++MEMORY[POINTER];
            break;

        case '-':

            --MEMORY[POINTER];
            break;

        case '.':

            putchar(MEMORY[POINTER]);
            break;

        case ',':

            MEMORY[POINTER] = getchar();
            break;

        case '[':

            strcpy(new._Code, _BrainF_ckLine._Code);
            new._Position = _BrainF_ckLine._Position;
            new._Condition = 1;
            new._Condition_Address = POINTER;

            _BrainF_ckLine._Position = RunBrainF_ckLine(new);
            break;

        case ']':

            if (!_BrainF_ckLine._Condition)
                fprintf(stderr, "\n[ERROR] THE LOOP IS ENDING WITHOUT HAVING STARTED\n");

            else if (MEMORY[_BrainF_ckLine._Condition_Address])
            {
                strcpy(new._Code, _BrainF_ckLine._Code);
                new._Position = _Start;
                new._Condition = 1;
                new._Condition_Address = _BrainF_ckLine._Condition_Address;
                return RunBrainF_ckLine(new);
            }

            return _BrainF_ckLine._Position;

        default:

            break;
        }
    }
    return 0;
}

/**
 * 
 * @param _Filename 
 */
void ExecuteFile(const char *_Filename)
{
    FILE *file = fopen(_Filename, "r+");

    if (file == NULL)
    {
        fprintf(stderr, "\n[ERROR] CAN'T READ FILE '%s'\n", _Filename);
        return;
    }

    BrainF_ck bf;
    bf._Position = 0;
    bf._Condition = 0;
    bf._Condition_Address = 0;

    while (fgets(bf._Code, MAX_USER_INPUT, file) != NULL)
        RunBrainF_ckLine(bf);

    fclose(file);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "\nUSE: brainf_ck <filename>\n");
        return EXIT_FAILURE;
    }

    ExecuteFile(argv[1]);
    return EXIT_SUCCESS;
}
