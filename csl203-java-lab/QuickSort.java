import java.util.Scanner;

public class QuickSort {
    static int n;
    public static void quickSort(String[] arr, int low, int high) {
        if(low<high) {
            int mid=partition(arr, low, high);
            quickSort(arr, low, mid-1);
            quickSort(arr, mid+1, high);
        }
    }

    public static int partition(String[] arr, int low, int high) {
        int i=low-1;
        String x=arr[high];

        for(int j=low; j<=high-1; j++) {
            if(arr[j].compareTo(x)<=0) {
                i++;
                String temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        String temp=arr[i+1];
        arr[i+1]=arr[high];
        arr[high]=temp;

        return i+1;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the limit: ");
        n=sc.nextInt();
        String[] names=new String[n];
        System.out.println("Enter the names: ");
        for(int i=0; i<n; i++) {
            names[i]=sc.next();
        }

        quickSort(names, 0, n-1);

        System.out.println("Sorted names are: ");
        for(int i=0; i<n; i++) {
            System.out.print(names[i]+", ");
        }
        System.out.println();
        sc.close();

    }
}
