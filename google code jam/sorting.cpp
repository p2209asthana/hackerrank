#include<iostream>
#include<algorithm>
using namespace std;
/**https://code.google.com/codejam/contest/2924486/dashboard#s=p2*/

int *arr,n;

bool comp1(int i,int j)
{
return i<=j;
}

bool comp2(int i,int j)
{
return i>=j;
}


int main()
{
int t;
cin>>t;
for(int x=1;x<=t;x++)
{
cout<<"Case #"<<x<<": ";
cin>>n;
arr=new int[n];
for(int i=0;i<n;i++)
cin>>arr[i];

int *odd=new int[n];
int *even = new int[n];
int odd_count=0;
for(int i=0;i<n;i++)
if(arr[i]%2)odd[odd_count++]=arr[i];
int even_count=0;
for(int i=0;i<n;i++)
if(!(arr[i]%2))even[even_count++]=arr[i];

sort(odd,odd+odd_count,comp1);
sort(even,even+even_count,comp2);

odd_count=0;even_count=0;
for(int i=0;i<n;i++)
{
if(!(arr[i]%2))cout<<even[even_count++]<<" ";
else cout<<odd[odd_count++]<<" ";
}
cout<<endl;
}
}


