#include<iostream>
using namespace std;
void ins_sort(int *arr,int n){
	for(int i=1;i<n;i++){
		int var=arr[i];
		int j=i-1;
		while(j>=0 && arr[j]>var){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=var;
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
	ins_sort(arr,n);
	cout<<"The sorted array is : ";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	return 0;
}

