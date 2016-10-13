package abcd;

import java.util.Scanner;

public class MaxHeapSort
{
   static void max_heapify(int arr[],int n,int num){
	if(n<0)
	return;
	int parent_index=(n/2)-1;
	while(parent_index<num){
	int greater_child_index=2*parent_index+1;
	if(greater_child_index<n && arr[greater_child_index]<arr[greater_child_index+1])
	greater_child_index++;
	if(arr[greater_child_index]>arr[parent_index]){
		int temp=arr[greater_child_index];
		arr[greater_child_index]=arr[parent_index];
		arr[parent_index]=temp;
		parent_index=2*parent_index+1;
	}
}
	max_heapify(arr,n-2,num);	
}
static void heapsort(int arr[],int n,int num){
	int x=n-1;
	while(x>0){
	int temp=arr[0];
	arr[0]=arr[x];
	arr[x]=temp;
	max_heapify(arr,n,num);
}
}
public static void main(String args[]){
	 int n;
         Scanner sc=new Scanner(System.in);
	System.out.println("Enter the number of numbers you want to sort : ");
	n=sc.nextInt();
	int arr[]=new int[n];
	System.out.println("Enter the numbers which you want to sort : ");
		for(int i=0;i<n;i++)
		arr[i]=sc.nextInt();
		heapsort(arr,n,n);
		System.out.println("The sorted numbers are : ");
		for(int i=0;i<n;i++)
		arr[i]=sc.nextInt();
}
}