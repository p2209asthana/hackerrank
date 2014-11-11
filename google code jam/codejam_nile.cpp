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
#define debug(v){for(int DNUTVIOL=0;DNUTVIOL<v.size();DNUTVIOL++)cout<<v[DNUTVIOL]<<" ";cout<<endl;}
using namespace std;
typedef unsigned long long int ull;
typedef long long int sll;
struct node
{
int index;
node*next;
};
void delete_node(node*curr)
{if(curr!=NULL){delete_node(curr->next);delete curr;}}
void delete_ll(node*curr)
{
if(curr!=NULL)
delete_node(curr);
}
void severe_ties(vector<node*>&arr,ull index,ull w,ull h)
{
delete_ll(arr[index]->next);
arr[index]->next=NULL;

if(index%w!=0)
{//delete from left one's list
node*parent=arr[index-1];
node*curr=parent->next;
while(1)
{
    if(curr->index==index)
    {
        parent->next=curr->next;
        delete curr;
        break;
    }
    parent=curr;
    curr=curr->next;
}
}
if(index%w!=w-1)
{//delete from righft one's list

node*parent=arr[index+1];
node*curr=parent->next;
while(1)
{
    if(curr->index==index)
    {
        parent->next=curr->next;
        delete curr;
        break;
    }
    parent=curr;
    curr=curr->next;
}
}
if(index/w!=0)
{//delete from below one's list
node*parent=arr[index-w];
node*curr=parent->next;
while(1)
{
    if(curr->index==index)
    {
        parent->next=curr->next;
        delete curr;
        break;
    }
    parent=curr;
    curr=curr->next;
}

}
}
ull calc(vr<node*>&arr,ull w,ull h)
{
for(ull i =0 ;i<w;i++)
{




}



}
int main()
{
//ios_base::sync_with_stdio(false);
int T;cin>>T;
feq(t,1,T)
{
cout<<"Case #"<<t<<": ";
ull w,h,b;
cin>>w>>h>>b;
vector<int> temp;
fi(i,0,b)fi(j,0,4){int x;cin>>x;temp.pb(x);}

vector<node*>arr;
for(ull i=0;i<w*h;i++)
{
    node*head=new node;
    head->index=-1;
    head->next=NULL;
    ull temp=i%w;

    if(temp!=0)
    {
    node*curr=new node;
    curr->index=i-1;
    curr->next=head->next;
    head->next=curr;
    }
    if(temp!=w-1)
    {
    node*curr=new node;
    curr->index=i+1;
    curr->next=head->next;
    head->next=curr;
    }
    if(i/w<h-1)
    {
    node*curr=new node;
    curr->index=i+w;
    curr->next=head->next;
    head->next=curr;
    }
    arr.pb(head);
}

for(ull i=0;i<temp.size();)
{
    ull x1=temp[i++];
    ull y1=temp[i++];
    ull x2=temp[i++];
    ull y2=temp[i++];

    ull y, x;
    y=y1;
    for(x=x1;x<x2;x++)
    {
    ull index=y*w+x;
    severe_ties(arr,index,w,h);
    }
    y=y2;
    for(x=x1+1;x<=x2;x++)
    {
    ull index=y*w+x;
    severe_ties(arr,index,w,h);
    }
    x=x1;
    for(y=y1+1;y<=y2;y++)
    {
    ull index=y*w+x;
    severe_ties(arr,index,w,h);
    }
    x=x2;
    for(y=y1;y<y2;y++)
    {
    ull index=y*w+x;
    severe_ties(arr,index,w,h);
    }

}


ull num=calc(arr,w,h);


}


return 0;
}
