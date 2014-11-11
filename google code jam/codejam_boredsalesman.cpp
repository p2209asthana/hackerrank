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
#define debug(v){for(int i=0;i<v.size();i++)cout<<v[i]<<" ";cout<<endl;}
using namespace std;
typedef unsigned long long int ull;
typedef long long int sll;
struct edge
{
int v;
bool present;
};
struct p_code
{
int pincode;
int index;
};
bool compare(p_code i,p_code j)
{return i.pincode<j.pincode;
}

struct node
{
int index;
node*next;
node*prev;
};
int get_min_index(vr<bool>&visited,vr<bool>&discovered,vr<int>&pincode_arr)
{
int min=INT_MAX;int min_index=-1;
fi(i,0,pincode_arr.size())if(!visited[i] and discovered[i] and pincode_arr[i]<min){min=pincode_arr[i];min_index=i;}
return min_index;
}
void calc(vr<bool>&visited,vr<vr<edge> >&graph,vr<int>&pincode_arr)
{
int min=INT_MAX;int min_index;
fi(i,0,pincode_arr.size()) if(!visited[i]  and pincode_arr[i]<min){min=pincode_arr[i];min_index=i;}
vr<bool>discovered;discovered.assign(visited.size(),false);
discovered[min_index]=true;
while(1)
{
visited[min_index]=true;
fi(i,0,graph[min_index].size())discovered[graph[min_index][i].v];
min_index=get_min_index(visited,discovered,pincode_arr);
if(min_index==-1)break;
}


}
/*void foo(vr<bool>&visited,vr<vr<edge> >&graph,vr<int>&pincode_arr)
{

int min=INT_MAX;int min_index;
fi(i,0,pincode_arr.size()) if(!visited[i]  and pincode_arr[i]<min){min=pincode_arr[i];min_index=i;}



node*head=new node;
head->next=NULL;
head->prev=NULL;

node*tail=new node;
head->next=tail;tail->prev=head;tail->next=NULL;tail->index=min_index;
int curr_index=min_index;
int start_index=min_index;
while(1)
{
int min=INT_MAX;int min_index;
fi(i,0,graph[curr_index].size())
{
    if((graph[curr_index][i].present)and pincode_arr[graph[curr_index][i].v]<min)
    {
        min=pincode_arr[graph[curr_index][i].v];
        min_index=graph[curr_index][i].v;
    }
}
//delete the ongoinf edge
fi(i,0,graph[curr_index].size())
{
    if(graph[curr_index][i].v==min_index)graph[curr_index][i].present=false;
}


node*curr=new node;
tail->next=curr;curr->prev=tail;curr->next=NULL;curr->index=min_index;
tail=curr;

curr_index=min_index;
if(curr_index==start_index)break;
}

node*curr=head->next;
while(curr!=NULL)
{cout<<curr->index;curr=curr->next;}
}
*/
int main()
{
//ios_base::sync_with_stdio(false);

int T;
cin>>T;
feq(t,1,T)
{
cout<<"Case #"<<t<<": ";
int n,m;cin>>n>>m;
vr<int>pincode_arr;
fi(i,0,n){int temp;cin>>temp;pincode_arr.pb(temp);}
//sort(pincode_arr.begin(),pincode_arr.end(),compare);
debug(pincode_arr);
vr<vr<edge> >graph;graph.resize(n);
fi(i,0,m)
{
int v1,v2;
cin>>v1>>v2;v1--;v2--;
edge e1;e1.v=v2;e1.present=true;
edge e2;e2.v=v1;e2.present=true;
graph[v1].pb(e1);
graph[v2].pb(e2);
}

vr<bool>visited;visited.assign(n,false);



}
return 0;
}
