#include<iostream>
#include<string>
using namespace std;
unsigned long long int arr[21];

int n,m;
unsigned long long int calculate(int i,int j)
{
unsigned long long int f=arr[i+j];
unsigned long long int f1=arr[i];
unsigned long long int f2=arr[j];
//cout<<f<<" "<<f1<<" "<<f2;
return (f/(f1*f2));
}


void print(string &str,int num_h,int num_v,unsigned long long int k)
{
//cout<<num_h<<" "<<num_v<<" "<<k<<endl;
int pos=n+m-num_h-num_v;
if(num_h==0)
{for(int i=0;i<num_v;i++)str[pos+i]='V';cout<<str<<endl;return;}
if(num_v==0)
{for(int i=0;i<num_h;i++)str[pos+i]='H';cout<<str<<endl;return;}

unsigned long long int temp=calculate(num_h-1,num_v);
if(k<=temp)
{
str[pos]='H';
print(str,num_h-1,num_v,k);
}
else
{
k=k-temp;
str[pos]='V';
print(str,num_h,num_v-1,k);
}

}
int main()
{
arr[0]=1;
for(int i=1;i<21;i++)
arr[i]=i*arr[i-1];
string str;
int t;
unsigned long long int k;
cin>>t;
while(t--)
{
cin>>n>>m;
str.resize(n+m);
cin>>k;
print(str,n,m,k+1);
}


return 0;
}
