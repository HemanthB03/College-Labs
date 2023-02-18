import java.util.Scanner;

public class QuickSort {
    public static void quick(String A[], int low, int high) {
        if(low<high) {
            int mid=partition(A, low, high);
            quick(A, low, mid-1);
            quick(A, mid+1, high);
        }
    }
    
    public static int partition(String A[], int low, int high) {
        String x=A[high];
        int i=low-1;

        for(int j=low; j<=high-1; j++) {
            if(A[j].compareTo(x) <= 0) {
                i=i+1;
                String temp=A[i];
                A[i]=A[j];
                A[j]=temp;
            }
        }
        String temp=A[i+1];
        A[i+1]=A[high];
        A[high]=temp;
        
        return i+1;
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        
        System.out.print("Enter the limit: ");
        int n=sc.nextInt();
        System.out.print("Enter the names: ");
        String A[] = new String[n];
        for(int i=0; i<n; i++) {
            A[i]=sc.next();
        }
        
        quick(A, 0, n-1);
        
        System.out.println("Sorted names are: ");
        for(int i=0; i<n; i++) {
            System.out.print(A[i]+", ");
        }
        System.out.println();
    }
    
}

