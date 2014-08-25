#include<iostream>
#include<cmath>
/** https://www.hackerrank.com/contests/infinitum-aug14/challenges/stepping-stones-game*/
using namespace std;
typedef long long ll;
int main()
{
int t;
ll n,s;
cin>>t;
bool flag;
while(t--)
{
cin>>n;
n=n*8+1;
s=sqrt(n);
if(n==s*s)cout<<"Go On Bob "<<(s-1)/2<<endl;
else cout<<"Better Luck Next Time"<<endl;

}


return 0;
}
