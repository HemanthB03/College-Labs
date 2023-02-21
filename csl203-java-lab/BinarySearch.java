import java.util.Scanner;

public class BinarySearch {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the limit: ");
        int n=sc.nextInt();
        int[] arr=new int[n];
        System.out.println("Enter the numbers in ascending order");
        for(int i=0; i<n; i++) {
            arr[i]=sc.nextInt();
        }

        System.out.print("Enter the key: ");
        int key=sc.nextInt();

        int first=0, last=n-1; 
        while(first<last) {
            int mid=(first+last)/2;
            if(arr[mid]==key) {
                System.out.println("Key found at index "+mid);
                break;
            }
            else if(arr[mid]<key) {
                first=mid+1;
            }
            else {
                last=mid-1;
            }
        }
        System.out.println("Key not found");
    }
}