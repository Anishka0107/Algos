#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//useful for linear efficiency O(n) in sorting floating numbers which are uniformly distributed 
void bucketsort(float[],int);
int main(){
	int n;
	cout<<"Enter the number of elements of your array : ";
	cin>>n;
	float arr[n];
	cout<<"Enter the elements of the array : ";
	for(int x=0;x<n;x++)
		cin>>arr[x];
	bucketsort(arr,n);
	cout<<"The sorted array is : ";
	for(int x=0;x<n;x++)
		cout<<arr[x]<<" ";
	return 0;
}
void bucketsort(float arr[],int n){
	vector<float> use[n];
	for(int i=0;i<n;i++)
		use[(int)(n*arr[i])].push_back(arr[i]);
	for(int i=0;i<n;i++)
		sort(use[i].begin(),use[i].end());
	int index=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<use[i].size();j++)
			arr[index++]=use[i][j];
	}
}
