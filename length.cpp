#include <assert.h>
#include <stdio.h>

int myLength(const char *line)
{
    assert(line != NULL);

    int i = 0;
    while (line[i] != '\0')
        i++;
    return i;
}

char *myStrcpy(char *dest, const char *src)
{
    assert(src != NULL);
    assert(dest != NULL);

    int i = 0;
    for (i; src[i]; i++)
    {
        *(dest + i) = *(src + i);
    }
    dest[i] = '\0';
    return dest;
}

int myPuts(char *line)
{
    assert(line != NULL);

    int i = 0;
    while (line[i] != '\0')
    {
        if (line[i] == EOF)
        {
            return EOF;
        }
        printf("%c", line[i]);
        i++;
    }
    printf("\n");
    return 0;
}

int main()
{
    char src[] = "xaxa";
    char dest[] = "dljfaldk";
    myPuts(src);
    printf("dfdf");
    // myStrcpy(dest, src);
    // int len = myLength(dest);
    // printf("%s %d\n", dest, len);
}

// strncpy strcat strncat fgets strdub