package p;
import java.util.Scanner;
public class QuickSort {
    static int arr[];
    static int n;
    public static void main(String s[]){
        Scanner scan=new Scanner(System.in);
        System.out.print("Enter the number of elements in the array:");
        n=scan.nextInt();
        System.out.println("Enter the array elements:");
        arr=new int[n];
        for(int i=0;i<n;i++)
            arr[i]=scan.nextInt();
        quick(0,n-1);
        for(int i=0;i<n;i++)
            System.out.println(arr[i]);
    }
    static void quick(int low,int high){
        if(low>high)
            return;
        int pivot=arr[low],temp;
        int i=low+1;
        int j=high;
        while(i<=j){
            while(arr[i]<=pivot && i<=high){
                i++;
            }
            while(arr[j]>pivot && j>=low){
                j--;
            }
            if(i<j){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        if(low<j){
            temp=arr[j];
            arr[j]=arr[low];
            arr[low]=temp;
        }
        quick(low,j-1);
        quick(j+1,high);
    }
}
