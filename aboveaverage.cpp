/**
Author: Prakhar Asthana
prakharast@gmail.com
*/
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

int t;
cin>>t;
int n;
while(t--)
{
cin>>n;
vector<int>arr;
for(int i=0;i<n;i++){int temp;cin>>temp;arr.push_back(temp);}

double sum=0;
for(int i=0;i<n;i++){sum+=arr[i];}
sum=sum/n;

int count=0;
for(int i=0;i<arr.size();i++)if(arr[i]>sum)count++;
cout<<count<<endl;




}


return 0;
}
