#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
//#include "abc.cpp"

#define MaxLen 1000


char func_puts(char s[]);
int len_of_str(char s[]);
int func_sctrchr(char s[], int ch);
char func_strcpy(char b[], char a[]);
char func_strcpyn(char b[], char a[], int n);
char func_srtcat(char destination[], char append[]);
char * my_strcat(char *dest, const char *src);
char * my_strncat(char *dest, const char *src, int num);
char * my_fgets(FILE *fp, char str[]);


int main ()
{
    char a[] = {"a b c d n c \n"};
    char b[] = {" "};

    int n = 5;

    /*int i = 0;
    while (a[i] != '\n')
    {
        scanf("%c", &a[i]);
        i++;
    }  */

    /*//--------------------- strlen

    printf("lenth of string is %d\n", len_of_str(a));

    //---------------------

    printf("\n");

    //---------------------- puts
    func_puts(a);
    //----------------------

    printf("\n");

    //---------------------- strch
    int num = 0;
    num =  func_sctrchr( a, 'g');
    if (num == 0)
        printf("there is no this ch\n");
    else
        printf("func_sctrchr says that sequence number is %d\n", num);
    //-----------------------

    printf("\n");

    //---------------------- strcpy

    func_strcpy(b,a);

    for (int m = 0; m < len_of_str(a); m++)
        printf("%c", b[m]);

    //----------------------

    printf("\n");

    //-----------------------strcpyn

    func_strcpyn(b, a, n);
    for (int m = 0; m < n; m++)
        //printf("%c", b[m]);
    return *b;*/

    //-----------------------

    printf("\n");

    //---------------------- func_srtcat

    char destination[100] = {"1 2 3 "};
    const char append[] = {"a b c"};

    //my_strcat(destination, append);
   // printf("%s", my_strcat(destination, append));
   int num = 3;

    //my_strncat(destination, append, num);
    //printf("%s", my_strncat(destination, append, num));

    //func_srtcat(destination, append);

    FILE *fp;
   // FILE *fopen(char *name, char *mode);
    fp = fopen ("tester.txt", "r");
    char str[MaxLen] = "\0";
    my_fgets(fp, str);
    fclose(fp);





    return 0;
}

char func_puts(char s[])
{
    for (int i = 0; i < len_of_str(s); i++)
    {
        printf("%c", s[i]);
    }
    return '\n';
}

int len_of_str(char s[])
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}
int func_sctrchr(char s[], int ch)
{
    int k = 0;
    for (int i = 0; i < len_of_str(s); i++)
    {
      if (s[i] == ch)
        k = i + 1;
    }
    if (k == 0)
        return 0;
    else
        return k;
}
char func_strcpy(char b[], char a[])
{
    for (int i = 0; i < len_of_str(a); i++)
    {
        b[i] = a[i];
        printf("%c", b[i]);
    }

    return *b;
}
char func_strcpyn(char b[], char a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }

    return *b;
}
char func_srtcat(char destination[], char append[])
{
    int dest = 0;
    while (destination[dest] != '\0')
    {
        dest ++;
    }
    int i = dest;
    int app = len_of_str(append);
    printf ("%d", app);
    while ( i < (dest + app+1))
        {
            int k = 0;
            printf("%d",i);
            destination[i] = append[k];
            printf("%c", destination[i]);
            k++;
            i++;
        }

    return *destination;
}
char * my_strcat(char *dest, const char *src)
{
    char *rdest = dest;

    while (*dest != '\0')
        dest++;
    while (*dest++ = *src++)
        ;
    return rdest;
//printf("%s", rdest);
}
char * my_strncat(char *dest, const char *src, int num)
{
    char *rdest = dest;

    int i = 0;

    while (i < num)
    {
        dest++;
        i++;
    }
    while (*dest++ = *src++)
        ;
    return rdest;
}
char * my_fgets(FILE *fp, char str[])
{
    int i = 0;

    while((str[i] = getc(fp)) != EOF)
    {
        i++;
    }

    printf("%s", str);

    return str;
}
