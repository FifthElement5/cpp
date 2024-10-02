#include <stdio.h>

void trojkat(float a, float b, float c)
{
    if((a+b)>c && (b + c) > a && (a + c) > b)
    {
        printf("trojkat\n");
        if(a != b && a != c && b!= c)
        {
            printf("roznoramienny\n");
        }
        if (a == b && b == c)
        {
            printf("rownoboczny\n");
        }
        if (a == b || b == c || c == a)
        {
            printf("rownoramienny\n");
        }
        if ((a*a + b*b == c*c) || (b*b + c*c ==a*a) || (a*a + c*c == b*b))
        {
            printf("prostokatny\n");
        }
    } else {
        printf("blad\n");
    }
}

int main(void)
{
    float a, b, c;
    printf("podaj dlugosci 3 bokow: ");
    scanf("%f%f%f", &a, &b, &c);
    printf("podane boki to: %f %f %f\n", a, b, c);

    trojkat(a, b, c);
}
