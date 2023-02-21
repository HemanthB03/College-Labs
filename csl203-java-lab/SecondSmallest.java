import java.util.Scanner;

public class SecondSmallest {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter limit: ");
        int n=sc.nextInt();
        int[] arr=new int[n];
        System.out.print("Enter array: ");
        for(int i=0; i<n; i++) {
            arr[i]=sc.nextInt();
        }
        //perform bubble sort to sort in ascending order, second element will be second smallest
        int temp;
        for(int i=0; i<n-1; i++) {
            for(int j=0; j<n-i-1; j++) {
                if(arr[j]>arr[j+1]) {
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }

        System.out.println("second smallest is: "+arr[1]);

        sc.close();
    }
}
