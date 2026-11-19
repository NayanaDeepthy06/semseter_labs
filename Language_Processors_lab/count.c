//C Program to Count Characters, Words and Lines in a File

/*.  
fopen() ->Opens a file
fgetc()	-> Reads one character at a time
isspace() ->	Checks whitespace
fclose() ->	Closes the file
printf() ->	Displays the result

stdio.h – Provides file handling and input/output functions like fopen(), fgetc(), printf().
ctype.h – Provides the isspace() function to check whitespace

FILE *fp – File pointer used to access the file.  inWord = 0 – Checks whether we are currently inside a word.
inWord = 0 means outside a word; inWord = 1 means inside a word.
fp stores the file reference. EOF means End Of File.


*/


#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *fp;
    int ch;
    int characters = 0, words = 0, lines = 0;
    int inWord = 0;

    fp = fopen("sample.txt", "r");

    if (fp == NULL)
    {
        printf("Unable to open file");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        characters++;

        if (ch == '\n')
            lines++;

        if (isspace(ch))
            inWord = 0;
        else if (inWord == 0)
        {
            words++;
            inWord = 1;
        }
    }

    fclose(fp);

    printf("Number of Characters = %d\n", characters);
    printf("Number of Words = %d\n", words);
    printf("Number of Lines = %d\n", lines);

    return 0;
}
