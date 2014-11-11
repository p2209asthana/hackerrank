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
#define vr vector
#define PRIME 1000000007
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define endl "\n"
#define fi(i,a,b) for(sll i=a;i<b;i++)
#define feq(i,a,b) for(sll i=a;i<=b;i++)
#define debug(v){for(sll DontUseThisVaraibleInOuterLoop=0;DontUseThisVaraibleInOuterLoop<v.size();DontUseThisVaraibleInOuterLoop++)cout<<v[DontUseThisVaraibleInOuterLoop]<<" ";cout<<endl;}
using namespace std;
typedef unsigned long long int ull;
typedef long long int sll;

sll calc(sll pos,vr<sll>&memoize,vr<bool>&a,vr<bool>&b,vr<bool>&k,bool flaga,bool flagb,bool flagk)
{
//cout<<"pos="<<pos<<" flaga="<<flaga<<" flagb="<<flagb<<" flagk="<<flagk<<endl;
if (pos==32)return (sll)(flaga and flagb and flagk);

sll index=(flaga<<7)|(flagb<<6)|(flagk<<5)|pos;
//cout<<index<<endl;
if(memoize[index]!=-1)return memoize[index];
bool dig_a=flaga or a[pos];
bool dig_b=flagb or b[pos];
bool dig_k=flagk or k[pos];
sll total=0;
feq(i,0,dig_a)
{
feq(j,0,dig_b)
{
bool res=i&j;
if(res>dig_k)continue;


total+=calc(pos+1,memoize,a,b,k,flaga or i<a[pos],flagb or j<b[pos],flagk or res<k[pos] );
}


}
memoize[index]=total;
return total;
}

int main()
{
//ios_base::sync_with_stdio(false);
sll T;cin>>T;
feq(t,1,T)
{
cout<<"Case #"<<t<<": ";
 sll a,b,k;
cin>>a>>b>>k;
if(a>b)a^=b^=a^=b;
vr<bool>a_digit,b_digit,k_digit;
sll i_size=32;
a_digit.resize(i_size);
b_digit.resize(i_size);
k_digit.resize(i_size);
fi(i,0,i_size)
{
a_digit[i_size-1-i]=(((1<<i)&a)>>i);
b_digit[i_size-1-i]=(((1<<i)&b)>>i);
k_digit[i_size-1-i]=(((1<<i)&k)>>i);
}

vector<sll>memoize;memoize.assign(256,-1);
cout<<calc(0,memoize,a_digit,b_digit,k_digit,false,false,false)<<endl;
}
return 0;
}
