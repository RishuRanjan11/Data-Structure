#include<stdio.h>

struct polyterm {
    int coeff;
    int exp;
};

int main() {
    struct polyterm poly1[50], poly2[50], poly3[50];
    int term1, term2, term3; // Added term3 to store the result
    int i, j, k;

    printf("Enter number of terms for polynomial 1: ");
    scanf("%d", &term1);

    printf("Enter coefficients and expnents for polymnomial 1:\n");
    for (i = 0; i < term1; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &poly1[i].coeff, &poly1[i].exp);
    }

    printf("Enter number of terms for polynomial 2: ");
    scanf("%d", &term2);

    printf("Enter coefficients and expnents for polynomial 2:\n");
    for (j = 0; j < term2; j++) {
        printf("Term %d: ", j + 1);
        scanf("%d %d", &poly2[j].coeff, &poly2[j].exp);
    }

    // Add two polynomials and store the result in poly3
    k = 0;
    for (i = 0; i < term1; i++) {
        for (j = 0; j < term2; j++) {
            if (poly1[i].exp == poly2[j].exp) {
                poly3[k].coeff = poly1[i].coeff + poly2[j].coeff;
                poly3[k].exp = poly1[i].exp;
                k++;
                break; // Break added to exit inner loop when a match is found
            }
        }
    }

    // Add remaining terms from poly1
    for (i = 0; i < term1; i++) {
        int found = 0;
        for (j = 0; j < k; j++) {
            if (poly1[i].exp == poly3[j].exp) {
                found = 1;
                break;
            }
        }
        if (!found) {
            poly3[k].coeff = poly1[i].coeff;
            poly3[k].exp = poly1[i].exp;
            k++;
        }
    }

    // Add remaining terms from poly2
    for (j = 0; j < term2; j++) {
        int found = 0;
        for (i = 0; i < k; i++) {
            if (poly2[j].exp == poly3[i].exp) {
                found = 1;
                break;
            }
        }
        if (!found) {
            poly3[k].coeff = poly2[j].coeff;
            poly3[k].exp = poly2[j].exp;
            k++;
        }
    }

    term3 = k; // Number of terms in the resultant polynomial

    // Display the result
    printf("\nResultant polynomial after addition: ");
    for (i = 0; i < term3 - 1; i++) {
        printf("%dx^%d + ", poly3[i].coeff, poly3[i].exp);
    }
    printf("%dx^%d\n", poly3[term3 - 1].coeff, poly3[term3 - 1].exp);

    return 0;
}
