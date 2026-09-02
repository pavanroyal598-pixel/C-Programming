#include <stdio.h>

/* Function declarations */
int my_atoi(char *);
double my_atof(char *);

int main()
{
    char s[100];
    int choice;

    printf("1. atoi()\n");
    printf("2. atof()\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    /* Remove newline left by scanf */
    getchar();

    printf("Enter input: ");
    fgets(s, sizeof(s), stdin);

    switch(choice)
    {
        case 1:
            printf("Integer value = %d\n", my_atoi(s));
            break;

        case 2:
            printf("Floating value = %lf\n", my_atof(s));
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}


/* Own atoi() function */
int my_atoi(char *p)
{
    int i = 0;
    int sign = 1;
    int num = 0;

    /* Handle leading spaces and tabs */
    while(p[i] == ' ' || p[i] == '\t')
        i++;

    /* Handle + and - signs */
    if(p[i] == '+')
    {
        sign = 1;
        i++;
    }
    else if(p[i] == '-')
    {
        sign = -1;
        i++;
    }

    /* Convert digits into integer */
    while(p[i] >= '0' && p[i] <= '9')
    {
        num = num * 10 + (p[i] - '0');
        i++;
    }

    return num * sign;
}


/* Own atof() function */
double my_atof(char *p)
{
    int i = 0;
    int sign = 1;
    double num = 0;
    double fraction = 0.1;

    /* Handle leading spaces and tabs */
    while(p[i] == ' ' || p[i] == '\t')
        i++;

    /* Handle + and - signs */
    if(p[i] == '+')
    {
        sign = 1;
        i++;
    }
    else if(p[i] == '-')
    {
        sign = -1;
        i++;
    }

    /* Convert integer part */
    while(p[i] >= '0' && p[i] <= '9')
    {
        num = num * 10 + (p[i] - '0');
        i++;
    }

    /* Handle decimal point */
    if(p[i] == '.')
    {
        i++;

        /* Convert fractional part */
        while(p[i] >= '0' && p[i] <= '9')
        {
            num = num + (p[i] - '0') * fraction;
            fraction = fraction / 10;
            i++;
        }
    }

    return num * sign;
}
