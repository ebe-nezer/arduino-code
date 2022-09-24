#include <stdio.h>
#include <string.h>
 
#define ROW 10
#define COL  5

char ArrayOfString[ROW][COL];

size_t vSeparateSringByComma (char* string)
{
    const char *delims = ",\n";
    char *s = string;
    size_t n = 0, len;

    for (s = strtok (s, delims); s && n < ROW; s = strtok (NULL, delims))
        if ((len = strlen (s)) < COL)
            strcpy (ArrayOfString[n++], s);
        else
            fprintf (stderr, "error: '%s' exceeds COL - 1 chars.\n", s);

    return n;
}

int main(void) {
    char a[] = "1234,456,789";
    char dest[10] = "";
    size_t n = vSeparateSringByComma (a);
    for (size_t i = 0; i < n; i++){
        printf ("%s \t", ArrayOfString[i]);
    }
    return 0;
}
