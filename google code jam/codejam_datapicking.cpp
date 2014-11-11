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
int n,x;cin>>n>>x;
vr<int>arr;fi(i,0,n){int temp;cin>>temp;arr.pb(temp);}
sort(arr.begin(),arr.end());
int start=0;int finish=arr.size()-1;
int count=0;
while(start<finish)
{
if(arr[start]+arr[finish]<=x){start++;finish--;}
else finish--;
count++;
}
if(start==finish)count++;
cout<<count<<endl;

}
return 0;
}
