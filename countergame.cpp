#include<iostream>
#include<cmath>
using namespace std;
/**https://www.hackerrank.com/contests/csindia-practice/challenges/counter-game*/

int main()
{
int t;
unsigned long long n;
cin>>t;
while(t--)
{
bool flag=true;
cin>>n;
int k=63;
while(n!=1)
{
for(int i=k;i>0;i--)
if(n & (1ll<<i)){k=i;break;}
n=((n & (n-1))!=0)?(n-(1ll<<k)):(n>>1);
flag=!flag;
}
printf((flag?"Richard":"Louise"));
printf("\n");
}
return 0;
}
