#include<iostream>
using namespace std;
void quicksort(int *arr,int low,int high){
	if(low<high){
		int pivot=arr[high];  //taking last element as pivot always
		int pivotindex=low;
		for(int i=low;i<high;i++){
			if(arr[i]<=pivot){
				int temp=arr[i];
				arr[i]=arr[pivotindex];
				arr[pivotindex]=temp;
				pivotindex++;
			}
		}
		int temp=arr[high];
		arr[high]=arr[pivotindex];
		arr[pivotindex]=temp;
		quicksort(arr,low,pivotindex-1);
		quicksort(arr,pivotindex+1,high);
	}
}

int main(){
	int n;
	cout<<"Enter the size of your array : ";
	cin>>n;
	int arr[n];
	cout<<"Enter the elements of your array : ";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	quicksort(arr,0,n-1);
	cout<<"The array after sorting is : ";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	return 0;
}
