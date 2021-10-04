#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define MaxLen 1000

char func_puts(char s[]);
int len_of_str(char s[]);
int func_sctrchr(char s[], int ch);
char func_strcpy(char b[], char a[]);
char func_strcpyn(char b[], char a[], int n);
char func_srtcat(char destination[], char append[]);
char* my_strcat(char *dest, const char *src);
char* my_strncat(char *dest, const char *src, int num);
char* my_fgets(FILE *fp, char str[]);
char* my_strdup(char src[]);

int main ()
{
    char a[] = {"a b c d n c d \n"};
    char b[len_of_str(a)];
    char ch;
    int num = 0, n = 0;
    char destination[MaxLen] = {"1 2 3 "};
    const char append[] = {"a b c"};
    char str[MaxLen] = "\0";
    char src[] = {"a b c d"};



    printf("Choose function and input it's number\n\n"
           "1 - puts\n2 - strlen\n3 - strchr\n4 - strcpy\n5 - strcpyn\n"
           "6 - strcat\n7 - strncat\n8 - fgets\n9 - strdup\n");

    int func = 0;
    scanf("%d", &func);

    switch (func)
    {
        case 1:
            func_puts(a);
            break;
        case 2:
            printf("len_of_str is %d",len_of_str(a));
            break;
        case 3:
            scanf("Input char %c", &ch);
            num = func_sctrchr(a, ch);
            if (num == 0)
                printf("there is no this ch\n");
            else
            printf("func_sctrchr says that sequence number is %d\n", num);
            break;
        case 4:
            func_strcpy(b, a);

            printf("Result:\n");
            for (int m = 0; m < len_of_str(a); m++)
                printf("%c", b[m]);
            break;
        case 5:
            printf("Input n");
            scanf("%d", &n);
            func_strcpyn(b, a, n);

            for (int m = 0; m < n; m++)
                printf("%c", b[m]);
            break;
        case 6:
            printf("%s\n", my_strcat(destination, append));
            break;
        case 7:
            printf("Input n");
            scanf("%d", &n);
            printf("%s\n", my_strncat(destination, append, n));
            break;
        case 8:
            FILE *fp;
            fp = fopen ("tester.txt", "r");
            my_fgets(fp, str);
            fclose(fp);
            break;
        case 9:
            printf("%s", my_strdup(src));
            break;
        //case 10:
        default:
            printf("You input smth wrong");
            break;
    }

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
char* my_strcat(char *dest, const char *src)
{
    char *rdest = dest;

    while (*dest != '\0')
        dest++;
    while (*dest++ == *src++)
        ;
    return rdest;
}
char* my_strncat(char *dest, const char *src, int num)
{
    char *rdest = dest;

    int i = 0;

    while (i < num)
    {
        dest++;
        i++;
    }
    while (*dest++ == *src++)
        ;
    return rdest;
}
char* my_fgets(FILE *fp, char str[MaxLen])
{
    int i = 0;

    while((str[i] = (char)getc(fp)) != EOF)
    {
        i++;
    }

    printf("%s", str);

    return str;
}
char* my_strdup(char src[])
{
    char *s;
    int len = 0;

    while (src[len])
        len++;

    s = (char*)calloc(len + 1, sizeof(*src));

    func_strcpy(s,src);

    return s;
}


