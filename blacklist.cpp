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
using namespace std;
typedef unsigned long long int ull;
typedef  long long int sll;




int n;
int **arr;
map<ull,int>m;


ull get_hash(int left, vector<int> merc)
{
ull sum=0;
for(int i=0;i<merc.size();i++)
{
int num=merc[i];
sum+=(1ull<<num);
}

sum+=(1ull<<(12+left));


return sum;
}

int calculate(int left, vector<int> merc)
{
if(left==n)return 0;
if(merc.size()==0)return (1<<20);


ull hash=get_hash(left,merc);

if(m.count(hash)>0)return m[hash];


int minm=INT_MAX;
int ming=-1;
for(int i=0;i<merc.size();i++)
{
    int merc_num=merc[i];
    //cout<<"merc-num="<<merc_num<<endl;
    for(int j=left;j<n;j++)
    {
       // cout<<"j="<<j<<endl;
        int cost=0;
        for(int k=left;k<=j;k++)cost+=arr[merc_num][k];
        //cout<<"co="<<cost<<endl;
        vector<int>new_merc=merc;
        new_merc.erase(new_merc.begin()+i);
        cost+=calculate(j+1,new_merc);
        if(cost<minm)minm=cost;
    }

}


//cout<<minm<<endl;

m[hash]=minm;
return minm;
}



int main()
{
int k;
cin>>n>>k;
arr=new int*[k];
for(int i=0;i<k;i++)arr[i]=new int[n];
for(int i=0;i<k;i++)for(int j=0;j<n;j++)cin>>arr[i][j];

vector<int> merc;
for(int i=0;i<k;i++)merc.push_back(i);

cout<<calculate(0,merc);
return 0;
}
