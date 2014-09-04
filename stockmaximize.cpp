#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
typedef unsigned long long int ull;

vector<int> find_peaks(vector<int> &arr,vector<int>index)
{
vector<int> temp;
for(int i=0;i<index.size()-1;i++)
    if(arr[index[i]]>arr[index[i+1]])
        temp.push_back(index[i]);
temp.push_back(index[index.size()-1]);
if(temp.size()<index.size())
    return find_peaks(arr,temp);
else
    return temp;
}
int main()
{
int t,n;
cin>>t;
while(t--)
{
cin>>n;
vector<int> arr(n);
vector<int> index(n);
for(int i=0;i<n;i++)cin>>arr[i];
for(int i=0;i<n;i++)index[i]=i;
index=find_peaks(arr,index);

//for(int i=0;i<arr.size();i++)cout<<arr[i]<<" ";cout<<endl<<endl;
//for(int i=0;i<index.size();i++)cout<<index[i]<<" ";cout<<endl<<endl;
int curr_index=-1;
ull profit=0;
for(int i=0;i<index.size();i++)
{
    ull length=index[i]-curr_index;
    if(length>1)
    {
        ull sum=0;
        for(int j=curr_index+1;j<index[i];j++)
        sum+=arr[j];
        profit+=(length-1)*arr[index[i]]-sum;
    }
    curr_index=index[i];


}


cout<<profit<<endl;
}

}
