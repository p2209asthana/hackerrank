#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
/**https://www.hackerrank.com/contests/w9/challenges/pmix*/

int mut_arr[4][4]={{0,1,2,3},{1,0,3,2},{2,3,0,1},{3,2,1,0}};
typedef struct node
{
int i1,i2;
};

node** mutate_arr(int k,int size)
{
int l=log(k)/log(2);
node **arr=new node*[l+1];
for(int i=0;i<=l;i++)
arr[i]= new node[size];

for(int i=0;i<size;i++)
{arr[0][i].i1=i;arr[0][i].i2=(i+1)%size;}

for(int i=1;i<=l;i++)
{
    node*temp=new node[size];
    for(int j=0;j<size;j++)
    temp[j]=arr[i-1][j];

    for(int j=0;j<size;j++)
    {
        int index_i1=temp[j].i1;
        int index_i2=temp[j].i2;
        arr[i][j].i1=temp[index_i1].i1;
        arr[i][j].i2=temp[index_i2].i2;
    }
}
return arr;
}

void print_mutate_arr(node**arr,int k, int size)
{
int l=log(k)/log(2);

for(int i=0;i<=l;i++)
{for(int j=0;j<size;j++)cout<<"("<<arr[i][j].i1<<","<<arr[i][j].i2<<") ";cout<<endl;}
}
int main()
{
int n,k;
string s;
cin>>n>>k>>s;
for(int i=0;i<s.size();i++)s[i]-='A';
node**arr=mutate_arr(k,s.size());
//print_mutate_arr(arr,k,s.size());
while(k!=0)
{
int curr_exp=log(k)/log(2);
string temp=s;
for(int i=0;i<s.size();i++)
{
int alpha1_index=arr[curr_exp][i].i1;
int alpha2_index=arr[curr_exp][i].i2;
s[i]=mut_arr[temp[alpha1_index]][temp[alpha2_index]];
}
k=k-(int)pow((double)2,(double)curr_exp);
}
for(int i=0;i<s.size();i++)s[i]+='A';
cout<<s<<endl;
return 0;
}
