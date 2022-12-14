import java.util.Scanner;

public class BinarySearch {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);

        int n, first, last, mid=0, key, flag;
        System.out.print("Enter size of array: ");
        n=sc.nextInt();
        int[] arr=new int[n];
        System.out.println("Enter the elements of the array in ascending order: ");
        for(int i=0; i<n; i++) {
            arr[i]=sc.nextInt();
        }

        System.out.print("Enter key to search for: ");
        key=sc.nextInt();

        first=0;
        last=n-1;
        flag=0;

        while(first<=last) {
            mid=(first+last)/2;
            if(arr[mid]==key) {
                flag = 1;
                break;
            }
            else if(arr[mid]<key) {
                first=mid+1;
            }
            else {
                last=mid-1;
            }
        }
        if(flag==1) {
            System.out.println("Element found at index "+mid);
        }
        else {
            System.out.println("Element not found");
        }
        sc.close();
    }
}