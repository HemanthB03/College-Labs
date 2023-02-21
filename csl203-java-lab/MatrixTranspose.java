import java.util.Scanner;

public class MatrixTranspose {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter row and column of matrix: ");
        int r=sc.nextInt();
        int c=sc.nextInt();
        int[][] mat=new int[r][c];
        System.out.println("Enter the matrix");
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                mat[i][j]=sc.nextInt();
            }
        }
        System.out.println("Transpose is");
        for(int i=0; i<c; i++) {
            for(int j=0; j<r; j++) {
                System.out.print(mat[j][i]+" ");
            }
            System.out.println();
        }
        sc.close();
    }
}
