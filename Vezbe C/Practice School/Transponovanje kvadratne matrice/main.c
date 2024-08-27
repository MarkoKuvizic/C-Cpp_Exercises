#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j;

    printf("Unesite duzinu kvadratne matrice ");
    scanf("%i", &n);

    int matrix[n][n];

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){

         printf("\nUnesite element %i. %i.: ", i, j);
         scanf("%i", &matrix[i][j]);

        }
    }


    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){

         matrix[i][j] = matrix[j][i];

        }
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){

            printf("%.2i ", matrix[i][j]);
        }
        printf("\n");

    }

    return 0;
}
