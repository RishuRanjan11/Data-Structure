#include <stdio.h>

int main()
{
    int i, deg1, deg2;
    int poly1[50], poly2[50], poly3[50]={0};

    // Input first polynomial
    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &deg1);

    printf("Enter the coefficients of the first polynomial (from highest degree to lowest): ");
    for (i = deg1; i >= 0; i--)
    {
        scanf("%d", &poly1[i]);
    }

    // Input second polynomial
    printf("Enter the degree of the second polynomial: ");
    scanf("%d", &deg2);

    printf("Enter the coefficients of the second polynomial (from highest degree to lowest): ");
    for (i = deg2; i >= 0; i--)
    {
        scanf("%d", &poly2[i]);
    }

    // Performing polynomial addition
    int maxDeg = (deg1 > deg2) ? deg1 : deg2;

    for (i = 0; i <= maxDeg; i++)
    if (i<=deg1&&i<=deg2){
        poly3[i]=poly1[i]+poly2[i];
    }
    else if(i>=deg1){
        poly3[i]=poly1[i];
    }
    else if(i>=deg2){
        poly3[i]=poly2[i];
    }
    // Displaying result
    printf("Maximum degree of the resultant polynomial: %d\n", maxDeg);
    printf("Resultant polynomial after addition:\n");
    for (i = maxDeg; i >= 0; i--)
    {

        printf("%dx^%d ", poly3[i], i);
        if (poly3[i] >= 0 && i >= 0)
        {
            printf("+ ");
        }
    }

    return 0;
}
