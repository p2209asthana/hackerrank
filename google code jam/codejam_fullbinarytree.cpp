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
#define pb push_back
#define PRIME 1000000007
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define endl "\n"
#define fi(i,a,b) for(int i=a;i<b;i++)
#define feq(i,a,b) for(int i=a;i<=b;i++)
#define debug(v){for(int i=0;i<v.size();i++)cout<<v[i]<<" ";cout<<endl;}
using namespace std;
typedef unsigned long long int ull;
typedef long long int sll;

int how_many(vector<vector<int> >&arr,vector<int>&parent,vector<int>&size,int n)
{
if(arr[n].size()==1 and parent[n]==-1)return size[arr[n][0]] ;
else if(arr[n].size()==1 and parent[n]!=-1) return 0;
else if(arr[n].size()==2 and parent[n]!=-1)return size[n]-1;

vector<int>min;min.assign(arr[n].size(),INT_MAX);

fi(i,0,arr[n].size())
{
if(arr[n][i]==parent[n])continue;
min[i]=how_many(arr,parent,size,arr[n][i]);
}

vector<int>min_s;min_s.assign(arr[n].size(),INT_MAX);
fi(i,0,arr[n].size())
{
if(arr[n][i]==parent[n])continue;
min_s[i]=size[arr[n][i]];
}
int sum=0;
fi(i,0,arr[n].size())
{
if(arr[n][i]==parent[n])continue;
sum+=min_s[i];
}
fi(i,0,arr[n].size())
{
if(arr[n][i]==parent[n])continue;
min[i]-=min_s[i];
}
int min0,min1;min0=min1=INT_MAX;int min0p,min1p;
fi(i,0,arr[n].size())
{
if(arr[n][i]==parent[n])continue;
if(min[i]<min0){min0=min[i];min0p=i;}
}
fi(i,0,arr[n].size())
{
if(arr[n][i]==parent[n] or i==min0p)continue;
if(min[i]<min1){min1=min[i];min1p=i;}
}
return sum+min0+min1;
}
void construct(vector<vector<int> >&arr,vector<int>&parent,int n)
{
fi(i,0,arr[n].size())
{
if(parent[arr[n][i]]!=-2)continue;
parent[arr[n][i]]=n;
construct(arr,parent,arr[n][i]);
}
}
int get_size(vector<vector<int> >&arr,vector<int>&parent,vector<int>&size,int n)
{
int count=0;
fi(i,0,arr[n].size())
{
if(arr[n][i]==parent[n])continue;
count+=get_size(arr,parent,size,arr[n][i]);
}
size[n]=count+1;
}
int calculate(vector<vector<int> >&arr,int n)
{
vector<int>parent;parent.assign(arr.size(),-2);
parent[n]=-1;
vector<int>size;size.assign(arr.size(),0);
construct(arr,parent,n);
//return 0;
get_size(arr,parent,size,n);

return how_many(arr,parent,size,n);
}
int main()
{
//ios_base::sync_with_stdio(false);
int T;cin>>T;
feq(t,1,T)
{
cout<<"Case #"<<t<<": ";
int n;cin>>n;
vector<vector<int> >arr;arr.resize(n);
fi(i,0,n-1)
{
int a,b;cin>>a>>b;a--;b--;
arr[a].pb(b);arr[b].pb(a);
}


bool flag=true;
int min=INT_MAX;
fi(i,0,n)
{
int m=calculate(arr,i);
if(m<min)min=m;
}
cout<<min<<endl;
}
return 0;
}
