package game;

import java.util.Scanner;

public class Heapsort {
    static int arr[];
    static void heapify(int n){
       int i=(n/2)-1;
       int j,temp;
       while(i>=0){
           j=2*i+1;
           while(j<n){
               if(arr[j+1]>arr[j]){
                   j++;
               }
               if(arr[j]>arr[(j-1)/2]){
                   temp=arr[j];
                   arr[j]=arr[(j-1)/2];
                   arr[(j-1)/2]=temp;
                   j=2*j+1;
               }
               else
                   break;
           }
           i--;
       }
   }
    static void heapSort(int n){
       int temp,k=n-1;
       while(k>0){
           heapify(k);           
           temp=arr[0];
           arr[0]=arr[k];
           arr[k]=temp;
           k--;
       }
   }
   public static void main(String args[]){
       Scanner sc=new Scanner(System.in);
       System.out.println("Enter the number of elements of your array : ");
       int n=sc.nextInt();
       System.out.println("Enter your array");
       int i=0;
       arr=new int[n];
       while(i<n){
           arr[i]=sc.nextInt();
           i++;
       }
       heapSort(n);
       for(int x:arr){
           System.out.print(x+" ");
       }
   }
}