#include<iostream>
using namespace std;
//better than binarysearch, we get an idea of a better mid to choose,complexity O(log(logn)) for uniform distribution
//needs sorted array
int intersearch(int *arr,int item,int n){
	int beg=0, end=n-1, mid;
	while(beg<=end){
		mid=beg+(end-beg)*((item-arr[beg])/(arr[end]-arr[beg]));
		if(arr[mid]==item)
			return mid;    //Element found at index mid
		if(arr[mid]<item)
			beg=mid+1;
		else if(arr[mid]>item)
			end=mid-1;
	}
	return -1;
}
int main(){
	int n;
	cout<<"Enter the size of your array : ";
	cin>>n;
	int arr[n];
	cout<<"Enter the elements of your array : ";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int item;	
	cout<<"Enter the element you want to search for : ";
	cin>>item;
	int res=intersearch(arr,item,n);	
	if(res!=-1)
		cout<<"Element found at index : "<<res+1;
	else 
		cout<<"Sorry! Element not found";	
	return 0;
}
