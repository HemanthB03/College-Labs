import java.util.Scanner;

public class MatrixMultiplication {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter row and column of first matrix: ");
        int r1=sc.nextInt();
        int c1=sc.nextInt();

        System.out.print("Enter row and column of second matrix: ");
        int r2=sc.nextInt();
        int c2=sc.nextInt();

        if(c1!=r2) {
            System.out.println("Can't multiply. Column of first must be equal tp Row of second");
        }
        else {
            int[][] matA=new int[r1][c1];
            int[][] matB=new int[r2][c2];
            int[][] matC=new int[r1][c2];
            System.out.println("Enter first matrix");
            for(int i=0; i<r1; i++) {
                for(int j=0; j<c1; j++) {
                    matA[i][j]=sc.nextInt();
                }
            }
            System.out.println("Enter second matrix");
            for(int i=0; i<r2; i++) {
                for(int j=0; j<c2; j++) {
                    matB[i][j]=sc.nextInt();
                }
            }

            for(int i=0; i<r1; i++) {
                for(int j=0; j<c2; j++) {
                    matC[i][j]=0;
                    for(int k=0; k<r2; k++) {
                        matC[i][j]+=matA[i][k]*matB[k][j];
                    }
                }
            }
            System.out.println("Resultant matrix is: ");
            for(int i=0; i<r1; i++) {
                for(int j=0; j<c2; j++) {
                    System.out.print(matC[i][j]+" ");
                }
                System.out.println();
            }
        }

        sc.close();
    }
}
