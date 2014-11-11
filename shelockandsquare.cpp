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
#define PRIME 1000000007
using namespace std;
typedef unsigned long long int ull;
typedef  long long int sll;

int main()
{
int t;
cin>>t;
ull n;

while(t--)
{
cin>>n;
ull perimeter=4;
ull pow=1;
for(ull i=1;i<=n;i++)
{
pow*=2;
pow%=PRIME;
perimeter+=pow;
perimeter%+PRIME;
}
cout<<perimeter<<endl;
}

return 0;
}
