#include<iostream>
using namespace std;
void selsort(int *arr,int n){
	int min;
	for(int i=0;i<n-1;i++){
		min=i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[min])
				min=j;
		}
		int temp=arr[min];
		arr[min]=arr[i];
		arr[i]=temp;
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
	selsort(arr,n);
	cout<<"The sorted array is : ";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	return 0;
}

