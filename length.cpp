#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

size_t myStrlen(const char *line)
{
    assert(line != NULL);

    size_t i = 0;
    while (line[i] != '\0')
        i++;
    return i;
}

char *myStrcpy(char *dest, const char *src)
{
    assert(src != NULL);
    assert(dest != NULL);

    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

int myPuts(const char *line)
{
    assert(line != NULL);

    int i = 0;
    while (line[i] != '\0')
    {
        putchar(line[i]);
        i++;
    }
    putchar('\n');
    return 0;
}

char *myStrncpy(char *dest, const char *src, size_t n)
{
    size_t i = 0;
    while ((i < n) && (src[i] != '\0'))
    {
        dest[i] = src[i];
        i++;
    }
    for (size_t j = i; j < n; j++)
        dest[j] = '\0';
    return dest;
}

char *myStrcat(char *dest, const char *src)
{
    assert(dest != NULL);
    assert(src != NULL);

    int destlen = myStrlen(dest);
    myStrcpy(&dest[destlen], src);
    return dest;
}

char *myStrncat(char *dest, const char *src, size_t n)
{
    assert(dest != NULL);
    assert(src != NULL);

    size_t destlen = myStrlen(dest);
    size_t i = 0;
    while ((i < n) && (src[i] != '\0'))
    {   
        dest[destlen] = src[i];
        i++;
        destlen++;
    }
    dest[destlen] = '\0';
    return dest;
}

const char *myStrchr(const char *line, char c)
{
    assert(line != NULL);

    int i = 0;
    char *ptr = NULL;
    while (line[i] != c)
    {
        if (line[i] == '\0')
        {
            return ptr;
        }
        i++;
    }
    return &(line[i]);
}

char *myStrdup(const char *line)
{
    assert (line != NULL);

    char *dup_line = (char *)calloc(sizeof(char), sizeof(line));
    if(dup_line == NULL)
    {
        return NULL;
    }
    return myStrcpy(dup_line, line);
}

ssize_t getline(char **line, size_t *n, FILE *stream)
{
    if(*line == NULL)
    {
        *line = (char *)calloc(*n, sizeof(char));
    }

    ssize_t i = 0;
    char c = fgetc(stream);
    const int multiplayer = 2;
    while(c != EOF)
    {
        (*line)[i] = c;
        if(c == '\n')
        {
            break;
        }
        i++;

        if(i > *n)
        {
            *n *= multiplayer;
            *line = (char *)realloc(*line, *n);
        }
        c = fgetc(stream);
    }
    if(c == EOF)
    {
        return -1;
    }

    return i;
    
}

char *myFgets(char *line, int n, FILE *stream)
{
    int i = 0;
    while(i < n)
    {
        char c = fgetc(stream);
        if(c == EOF){
            return NULL;
        }
        line[i] = c;
        if(c == '\n'){
            break;
        }
        i++;
    }
    return line;
}

// string substring
const char *myStrstr(const char *lineB, const char *lineA)
{
    int suma = 0;
    int sumb = 0;
    int first = (int)(lineB[0]);
    int x = 2;
    const int bign = 1e9 + 7;
    size_t lena = myStrlen(lineA);
    size_t lenb = myStrlen(lineB);
    if(lena > lenb) 
        return NULL;
    size_t j = 0;
    for(; j < lena; j++)
    {
        first *= x;
        suma = (suma + (int)(lineA[j]))*x;
        sumb = (sumb + (int)(lineB[j]))*x;
    }

    if(suma == sumb)
    {
        return &(lineB[j-lena]);
    }

    while (j < lenb)
    {
        sumb = ((sumb + (int)(lineB[j]) - first) * x) % bign; //size_t kek = first << 1;
        if(sumb == suma)
        {
            return &(lineB[j-lena + 1]);
        }
        first = (((int)(first / (int)lineB[j-lena])) * ((int)lineB[j - lena + 1])) % bign;
        j++;
    }
    return NULL;
}//рабина карпа хеширование

// в функции битовые
// polynom_hash()


int main()
{
    char src[] = "xaxaabcd";
    char dest[10] = "yyyy";
    size_t n = 2;
    // printf("%s\n", myStrncat(dest, src, 2));
    const char *p = myStrstr(src, "abcd");
    if(p !=NULL)
    {
        printf("%c\n", *p);
        printf("yes\n");
    }
    else{printf("no\n");}

    // printf("dfdf\n");
    // char *ptr = myStrchr(src, 'x');
    // printf("%p\n", ptr);
    // myStrcpy(dest, src);
    // int len = myLength(dest);
    // printf("%s %d\n", dest, len);
}

// *strchr *strncpy *strcat *strncat *fgets *strdup *getline strstr