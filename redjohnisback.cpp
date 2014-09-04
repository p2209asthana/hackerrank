#include<iostream>
#include<vector>
#include<cstring>
#define NUM 217286
using namespace std;

typedef unsigned long long int ull;

ull arr[21];

ull recurse(int n)
{
if(n==0 or n==1 or n==2 or n==3)return 1;
if(arr[n]!=0)return arr[n];

ull i=recurse(n-1);
ull j=recurse(n-4);
arr[n]=i+j;
return arr[n];
}
int main()
{
memset(arr,0,21*sizeof(int));

bool sieve[NUM];
memset(sieve,true,NUM*sizeof(bool));

for(int i=2;i<NUM;i++)
{
if(sieve[i])
for(int j=2*i;j<NUM;j+=i)
sieve[j]=false;
}
vector<int>prime;
for(int i=2;i<NUM;i++)
if(sieve[i])prime.push_back(i);

int t,n;
cin>>t;
while(t--)
{
cin>>n;
ull sum=recurse(n);
int i;
for( i=0;i<prime.size();i++)
if(prime[i]>sum){cout<<i<<endl;break;}
if(i==prime.size())cout<<prime.size()<<endl;
}

return 0;
}
