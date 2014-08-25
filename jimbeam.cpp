
#include<iostream>
#include<cmath>
#define min(a,b) ((a>b)?b:a)

/**https://www.hackerrank.com/contests/infinitum-aug14/challenges/jim_beam*/
using namespace std;
int main()
{
long long int t,x1,x2,y1,y2,xm,ym;
cin>>t;double lambda1, lambda2,temp,temp1;
bool flag;
while(t--)
{
cin>>x1>>y1>>x2>>y2>>xm>>ym;
if(xm==0 and ym==0){cout<<"YES"<<endl; continue;}
if(y1*y1+x1*x1>y2*y2+x2*x2){y1^=y2^=y1^=y2;x1^=x2^=x1^=x2;}

temp=(x1-x2)*ym+xm*(y2-y1);
temp1=ym*x1-xm*y1;
//cout<<"temp="<<temp<<"  temp1="<<temp1<<endl;
if(temp==0)
{
    if(temp1!=0)cout<<"YES"<<endl;
    else
    {
        if(x2-x1!=0)temp=((xm-x1)*1.0)/(x2-x1);
        else temp =((ym-y1)*1.0)/(y2-y1);
        if(0<=temp)
                cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    continue;
}
lambda1=temp1/temp;
if(xm!=0)
lambda2=(x1+lambda1*(x2-x1))/xm;
else
lambda2=(y1+lambda1*(y2-y1))/ym;
//cout<<lambda1<<" "<<lambda2;
if(0<=lambda1 and lambda1<=1 and 0<=lambda2 and lambda2<=1)cout<<"NO"<<endl;
else cout<<"YES"<<endl;

}
return 0;
}
