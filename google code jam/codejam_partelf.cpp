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
#define vr vector
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

struct frac
{ull num,den;};
ull stoi(string s)
{
ull sum=0;
fi(i,0,s.size())
{
ull exp=(ceil)(pow((double)10,(double)(s.size()-1-i)));
sum+=(s[i]-'0')*exp;
}
return sum;
}

ull gcd(ull a ,ull b)
{
if(b==0)return a;
return gcd(b,a%b);
}

int main()
{
//ios_base::sync_with_stdio(false);
int T;
cin>>T;
feq(t,1,T)
{
cout<<"Case #"<<t<<": ";
string s;cin>>s;
int pos=s.find('/');
ull num=stoi(s.substr(0,pos));
ull den=stoi(s.substr(pos+1));
ull count=0;
bool flag=false;
bool fail=false;;
while(1)
{
ull hcf;
do
{
    hcf=gcd(num,den);
    if(hcf!=1)
    {
        num/=hcf;
        den/=hcf;
    }
}while(hcf!=1);
if((den==1)and (num==1 or num==0))break;
if((den==1)and num!=1 and num!=0){fail=true;break;}
if(den%2!=0){fail=true;break;}
den=den/2;
if(!flag)
count++;
if(num>=den){flag=true;num-=den;}

}
if(fail)cout<<"impossible"<<endl;else cout<<count<<endl;
}
return 0;
}
