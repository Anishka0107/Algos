#include<iostream>
using namespace std;

void merge(int *arr,int low,int mid,int high){
	int i=low,j=mid+1,k=low;
	int arrx[high+1];
	for(int l=low;l<=high;l++)
		arrx[l]=arr[l];
	while(i<=mid && j<=high){
		if(arrx[i]<=arrx[j]){
			arr[k]=arrx[i];
			i++;
		}
		else{
			arr[k]=arrx[j];
			j++;
		}
		k++;
	}
	while(i<=mid){
		arr[k]=arrx[i];
		i++;
		k++;
	}
}

void mergesort(int *arr,int low,int high){
	if(low<high){
		int mid=(low+high)/2;
		mergesort(arr,low,mid);
		mergesort(arr,mid+1,high);
		merge(arr,low,mid,high);
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
	mergesort(arr,0,n-1);
	cout<<"The sorted array is : ";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	return 0;
}
