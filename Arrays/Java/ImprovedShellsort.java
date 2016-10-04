package p;

import java.util.Scanner;

public class ImprovedShellSort {
    public static void main(String str[]){
        int n;
        Scanner scan=new Scanner(System.in);
        System.out.print("Enter the number of elements in the array:");
        n=scan.nextInt();
        System.out.println("Enter the array elements:");
        int arr[]=new int[n];
        for(int i=0;i<n;i++)
            arr[i]=scan.nextInt();
        ImprovedShellSort s=new ImprovedShellSort();
        arr=s.shells(arr,n);
        for(int i=0;i<n;i++)
            System.out.println(arr[i]);
    }
    int[] shells(int a[],int n){
        int increment,x;
        //increment should preferably have a prime number value
        //as same elements are not compared again in subsequent passes
        increment=(int)Math.sqrt(n);
        while(increment>0){
            x=0;
            while(x<=increment){
                for(int i=x+increment;i<n;i=i+increment){
                int temp=a[i];
                int j=i-increment;
                while(j>=0 && a[j]>temp){
                    a[j+increment]=a[j];
                    j=j-increment;
                }
                a[j+increment]=temp;
            }
            x++;
            }
            increment--;
        }
        return a;
    }
}
