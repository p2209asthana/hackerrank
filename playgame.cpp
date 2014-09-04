#include<iostream>
#include<stdio.h>
#include<limits>
#include<stdlib.h>
#include<cmath>
#include<algorithm>
#include<vector>
#define MAX(i,j,k) ((i>j)?((i>k)?i:k):((j>k)?j:k))


using namespace std;
typedef unsigned long long int ull;

void fill_optimal(vector<ull>& opt,vector<ull>& sum,vector<ull>&brick)
{
opt[1]=1;opt[2]=2;opt[3]=3;
sum[0]=0;
sum[1]=brick[1];
sum[2]=brick[1]+brick[2];
sum[3]=brick[1]+brick[2]+brick[3];

ull first,second,third,rem;
for(ull i=4;i<opt.size();i++)
{
    first=brick[i];
    first+=sum[i-1-opt[i-1]];

    second=brick[i]+brick[i-1];
    second+=sum[i-2-opt[i-2]];

    third=brick[i]+brick[i-1]+brick[i-2];
    third+=sum[i-3-opt[i-3]];

    sum[i]=MAX(first,second,third);
    opt[i]=((sum[i]==first)?1:((sum[i]==second)?2:3));
}




}

int main()
{
ull t,n;
cin>>t;
while(t--)
{
cin>>n;
vector<ull>brick(n+1);
for(ull i=n;i>0;i--)cin>>brick[i];

vector<ull>opt(n+1);
vector<ull>sum(n+1);
fill_optimal(opt,sum,brick);

cout<<sum[n]<<endl;
}
}
