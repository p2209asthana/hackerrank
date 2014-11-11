#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#define vr vector
#include<limits.h>
using namespace std;

/**https://code.google.com/codejam/contest/842485/dashboard*/


struct node
{
double n;
int round;
};




bool comp1(node i, node j)
{
if(i.round!=j.round)
return i.round<j.round;
else return i.n<j.n;
}


int main()
{
int t,n;
cin>>t;
for(int x=1;x<=t;x++)
{
cin>>n;
vector<node> arr(n);
cout<<"Case #"<<x<<": "<<endl;

for(int i=0;i<n;i++)
cin>>arr[i].n;

double l=1.0/3,r=2.0/3;
for(int i=0;i<n;i++)
{
int count=0;
double k=arr[i].n;
for(count=0;count<30;count++)
{
    if(k==0.0 or k==1.0){arr[i].round=INT_MAX;break;}
    else
    {
        if(l<=k and k<=r){arr[i].round=count;break;}
        else if(k<l)k=k*3;
        else k=(k-r)*3;
    }
}
if(count==30)arr[i].round=INT_MAX;
}

sort(arr.begin(),arr.end(),comp1);

for(int i=0;i<n;i++)
{
char str[50];
sprintf(str,"%.14f",arr[i].n);
char*p=str;
while((*p)!='\0')
    p++;
p--;
if((*p)=='0')
    while((*p)=='0')
        {*p='\0';p--;}

printf("%s\n",str);
}
}
return 0;
}
