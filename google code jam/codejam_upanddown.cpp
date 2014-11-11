/**
Author: Prakhar Asthana
prakharast@gmail.com
*/
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<limits.h>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
#define vr vector
#define pb push_back
#define PRIME 1000000007
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define endl "\n"
#define fi(i,a,b) for(int i=a;i<b;i++)
#define feq(i,a,b) for(int i=a;i<=b;i++)
#define fdeq(i,a,b) for(int i=a;i>=b;i--)
#define debug(v){for(int DNUTVIOL=0;DNUTVIOL<v.size();DNUTVIOL++)cout<<v[DNUTVIOL]<<" ";cout<<endl;}
using namespace std;
typedef unsigned long long int ull;
typedef long long int sll;

int main()
{
//ios_base::sync_with_stdio(false);
int T;cin>>T;
feq(t,1,T)
{
cout<<"Case #"<<t<<": ";
int n;cin>>n;
//cout<<"n="<<n<<endl;
vr<int>arr;fi(i,0,n){int temp;cin>>temp;arr.pb(temp);}
int steps=0;int l=0;int r=arr.size()-1;

while(r>l)
{
//debug(arr);
int min=INT_MAX;int min_pos;
feq(i,l,r)if(arr[i]<min){min=arr[i];min_pos=i;}

//cout<<"minpos="<<min_pos<<endl;
int d1=min_pos-l;
int d2=r-min_pos;
if(d1<d2)
{
fdeq(j,min_pos,l+1)
{steps++;arr[j]=arr[j-1];}

arr[l]=min;
l++;
}
else
{

feq(j,min_pos,r-1)
{steps++;arr[j]=arr[j+1];}
arr[r]=min;
r--;
}//cout<<steps<<endl;
}


cout<<steps<<endl;
}

return 0;
}
