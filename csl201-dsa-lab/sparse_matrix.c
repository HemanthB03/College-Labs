#include <stdio.h>

int main() {

    int mat[20][20], sparse[20][20], i, j, k, row, col;
    printf("Enter the row and column: ");
    scanf("%d%d", &row, &col);

    printf("Enter the elements\n");
    for(i=0; i<row; i++) {
        for(j=0; j<col; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    printf("the triplet representation is(index starts at zero)\n");

    sparse[0][0] = row;
    sparse[0][1] = col;

    k=1;
    for(i=0; i<row; i++) {
        for(j=0; j<col; j++) {
            if(mat[i][j]!=0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = mat[i][j];
                k++;
            }
        }
    }

    sparse[0][2] = k-1;

    printf("Rows\tColumns\tValue\n");

    for(i=0; i<=sparse[0][2]; i++) {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }


    return 0;
}