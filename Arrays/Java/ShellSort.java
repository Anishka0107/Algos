package p;

import java.util.Scanner;
//horrible shell sort...aunty types
public class ShellSort {
    public static void main(String str[]){
        int n;
        Scanner scan=new Scanner(System.in);
        System.out.print("Enter the number of elements in the array:");
        n=scan.nextInt();
        System.out.println("Enter the array elements:");
        int arr[]=new int[n];
        for(int i=0;i<n;i++)
            arr[i]=scan.nextInt();
        ShellSort s=new ShellSort();
        arr=s.shell(arr,n);
        for(int i=0;i<n;i++)
            System.out.println(arr[i]);
    }
    int[] shell(int a[],int num){
        int increment,x=0,y;
        increment=(int)Math.sqrt(num);
        while(increment>0){
            int b[]=new int[(num/increment)+1];
            y=0;
            for(int j=x;j<num;j=j+increment){
                b[y]=a[j];
                y++;
            }
            b=InsSort(b,y);
            y=0;
            for(int j=x;j<num;j=j+increment){
                a[j]=b[y];
                y++;
            }
            increment--;
            x++;
        }
        return a;
    }
        int[] InsSort(int ar[],int n){
            for(int i=1;i<n;i++){
                int temp=ar[i];
                int j=i-1;
                while(j>=0 && ar[j]>temp){
                    ar[j+1]=ar[j];
                    j--;
                }
                ar[j+1]=temp;
            }
            return ar;
    }
}