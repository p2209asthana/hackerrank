#include<iostream>
#include<cmath>
using namespace std;
/**https://www.hackerrank.com/contests/csindia-practice/challenges/little-gaurav-and-sequence*/

typedef long long ll;
int main()
{
int t;
ll n;
cin>>t;
while(t--)
{
cin>>n;
int i_upper=log(n)/log(2);

if(n&1)//n is odd
cout<<0<<endl;
else if(i_upper==0)cout<<2<<endl;
else cout<<(6*i_upper)%10<<endl;

}



return 0;
}
