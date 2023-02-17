import java.util.Scanner;

public class MatrixTranspose {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter row and column of matrix: ");
        int row=sc.nextInt();
        int column=sc.nextInt();
        int[][] matrix=new int[row][column];
        System.out.println("Enter the matrix elements: ");
        for(int i=0; i<row; i++) {
            for(int j=0; j<column; j++) {
                matrix[i][j]=sc.nextInt();
            }
        }
        int[][] transpose=new int[column][row];
        for(int i=0; i<row; i++) {
            for(int j=0; j<column; j++) {
                transpose[j][i]=matrix[i][j];
            }
        }

        System.out.println("Transpose is: ");
        for(int i=0; i<column; i++) {
            for(int j=0; j<row; j++) {
                System.out.print(transpose[i][j]+" ");
            }
            System.out.println();
        }
        sc.close();
    }
}
