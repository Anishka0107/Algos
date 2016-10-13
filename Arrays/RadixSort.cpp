#include<iostream>
using namespace std;

//function to return the largest element in array
int big(int *arr,int n){
	int temp=arr[0];
	for(int i=0;i<n;i++){
		if(arr[i]>temp)
			temp=arr[i];
	}
	return temp;
}

void countingSort(int *arr,int n,int i){	
	int count[10]={0};   //initializes all array elements to 0
	for(int j=0;j<n;j++)
		count[(arr[j]/i)%10]++;
	for(int j=1;j<10;j++)
		count[j]+=count[j-1];
	int output[n];
	for(int j=n-1;j>=0;j--){
		output[count[(arr[j]/i)%10]-1]=arr[j];
		count[(arr[j]/i)%10]--;
	}
	for(int j=0;j<n;j++)
		arr[j]=output[j];
}

void radixsort(int *arr,int n){
	int len=big(arr,n);
	for(int i=1;len/i>0;i*=10){
		countingSort(arr,n,i);   //After digit selection, counting sort is performed
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
	radixsort(arr,n);
	cout<<"The array after sorting is : ";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	return 0;
}
