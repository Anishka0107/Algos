
import java.util.Random;
import java.util.Scanner;
public class RandomisedQuickSort {
    static int arr[];
    static int n;
    public static void main(String s[]){
        Scanner scan=new Scanner(System.in);
        System.out.print("Enter the number of elements in the array : ");
        n=scan.nextInt();
        System.out.println("Enter the array elements : ");
        arr=new int[n];
        for(int i=0;i<n;i++)
            arr[i]=scan.nextInt();
        quick(0,n-1);
        for(int i=0;i<n;i++)
            System.out.println(arr[i]);
    }
    static void quick(int low,int high){
    	if(low<high){
            Random r=new Random();
	    int pivotindex=low+r.nextInt(high-low+1);  //taking random element as pivot  
	    	int temp=arr[high];
		arr[high]=arr[pivotindex];
    		arr[pivotindex]=temp;
	    int pivot=arr[pivotindex];
            for(int i=low;i<high;i++){
		    if(arr[i]<=pivot){
		    	temp=arr[i];
  		        arr[i]=arr[pivotindex];
		        arr[pivotindex]=temp;
		        pivotindex++;
			}
		}
    		quick(low,pivotindex-1);
	    	quick(pivotindex+1,high);
	}
}
}
