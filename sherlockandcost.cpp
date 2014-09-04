#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#define MAX(i,j) ((i>j)?i:j)
using namespace std;
typedef struct choice
{
int i,j;
};


int main()
{
int t,n,temp;
cin>>t;
while(t--)
{
cin>>n;
vector<int>b;
for(int i=0;i<n;i++){cin>>temp;b.push_back(temp);}

vector<choice> a;

choice temp;
temp.i=0;
temp.j=0;
a.push_back(temp);
for(int i=1;i<b.size();i++)
{
choice temp;
temp.i=MAX(a[i-1].i,a[i-1].j+abs(b[i-1]-1));
temp.j=MAX(a[i-1].i+abs(b[i]-1),a[i-1].j+abs(b[i]-b[i-1]));
a.push_back(temp);
}

cout<<max(a[a.size()-1].i,a[a.size()-1].j)<<endl;
}


return 0;}

