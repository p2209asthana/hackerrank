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
#define min(a,b)((a<b)?a:b)
using namespace std;
typedef unsigned long long int ull;
typedef  long long int sll;



int calculate(vector<vector<int> >&arr,int m,int n)
{
if(arr[m][n]!=-1)return arr[m][n];
if(m==n){arr[m][n]=1;return arr[m][n];}
if(m>n){arr[m][n]=calculate(arr,n,m);return arr[m][n];}

int minm=INT_MAX;
for(int i=1;i<=m;i++)
{
    int a=calculate(arr,m-i,i);
    int b=calculate(arr,m,n-i);

    int c=calculate(arr,m-i,n);
    int d=calculate(arr,i,n-i);

    int s1=1+a+b;
    int s2=1+c+d;

    if(minm>min(s1,s2))minm=min(s1,s2);
}


arr[m][n]=minm;

return arr[m][n];
}


int main()
{

int t;cin>>t;
int m,n;
while(t--)
{
cin>>m>>n;
if(m>n)m^=n^=m^=n;

vector<vector<int> >arr(m+1);
for(int i=0;i<m+1;i++)arr[i].assign(n+1,-1);
for(int i=0;i<=n;i++)arr[0][i]=0;
for(int i=0;i<=m;i++)arr[i][0]=0;

cout<<calculate(arr,m,n)<<endl;

}


return 0;
}
