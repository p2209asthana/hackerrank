#include<iostream>
#include<stdio.h>
#include<cstring>
#include<limits>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef unsigned long long int ull;
typedef  long long int sll;

int main()
{
int n;
cin>>n;
vector<int>arr(n);
for(int i=0;i<n;i++)cin>>arr[i];

vector<ull>candy(n);
for(int i=0;i<n;i++)candy[i]=1;

for(int i=1;i<candy.size();i++)
if(arr[i]>arr[i-1] and candy[i]<=candy[i-1])candy[i]=candy[i-1]+1;

for(int i=candy.size()-2;i>=0;i--)
if(arr[i]>arr[i+1] and candy[i]<=candy[i+1])candy[i]=candy[i+1]+1;


ull sum=0;
for(int i=0;i<candy.size();i++)sum+=candy[i];

cout<<sum<<endl;

return 0;
}
