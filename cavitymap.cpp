#include<iostream>
using namespace std;
bool iscavity(string*arr,int i, int j)
    {
    if(arr[i+1][j]<arr[i][j] and arr[i-1][j]<arr[i][j] and arr[i][j+1]<arr[i][j] and arr[i][j-1]<arr[i][j]) return true;
    return false;



}

int main()
    {
    int n;
    cin>>n;
    string *arr=new string[n];
    for(int i=0;i<n;i++)
           cin>>arr[i];
    string *copy=new string[n];
    for(int i=0;i<n;i++)
        copy[i]=arr[i];
    for(int i=1;i<n-1;i++)
        for(int j=1;j<n-1;j++)
            if(iscavity(copy,i,j))arr[i][j]='X';
    for(int i=0;i<n;i++)
        cout<<arr[i]<<endl;
   return 0;
}
