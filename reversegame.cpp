#include<iostream>
using namespace std;
/**https://www.hackerrank.com/contests/infinitum-aug14/challenges/reverse-game*/

 int main()
{
int t,n,count,k;
cin>>t;
while(t--)
{
cin>>n;
n--;
cin>>k;
//cout<<"k="<<k<<endl;
if(n%2)
{
  //  cout<<"n is odd"<<endl;
    if(k>n/2)count=1+2*(n-k);
    else count=2+2*k;
}
else
{
    //cout<<"n is even"<<endl;

    if(k>=n/2)count=1+2*(n-k);
    else count=2+2*k;
}

if(count%2){//cout<<"count is odd"<<endl;
    cout<<n-k+count/2<<endl;}
else{//cout<<"count is even"<<endl;
    cout<<k+count/2<<endl;}


}
}
