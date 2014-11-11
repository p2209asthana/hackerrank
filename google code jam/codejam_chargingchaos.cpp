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

int cal(vector<string>&avail,vector<string>&need)
{
fi(i,0,avail[0].size())
{
int n=0;
fi(j,0,avail.size())
{
if(avail[j][i]=='0')n=n<<1;
else n=
}



}


}
int main()
{
int T;cin>>T;
feq(t,1,T)
{
cout<<"Case #"<<t<<": ";
int n,l;
cin>>n>>l;
vector<string> avail,need;
avail.resize(n);
need.resize(n);
fi(i,0,avail.size())cin>>avail[i];
fi(i,0,need.size())cin>>need[i];
int m=cal(avail,need);
}

return 0;
}
