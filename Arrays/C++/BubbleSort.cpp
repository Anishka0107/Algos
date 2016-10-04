#include<iostream>
using namespace std;
void bubblesort(int *arr,int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
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
	bubblesort(arr,n);
	cout<<"The sorted array is : ";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	return 0;
}

