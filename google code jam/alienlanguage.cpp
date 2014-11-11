#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;
/**https://code.google.com/codejam/contest/90101/dashboard#s=p0*/

typedef long long ll;
vector<string> m;
ll l, d,n;;
int matches;
int get_perm(string*arr, vector<string>& rem, int length)
{
    //cout<<"string="<<s<<endl;
    if(length==l)
    {
        return rem.size();
    }
    if(rem.size()==0)return 0;
    vector<string> next;
    for(int i=0;i<rem.size();i++)
    {
  //      cout<<"i="<<i;
        if(arr[length].find(rem[i][length])!=string::npos)
            next.push_back(rem[i]);
    }
    return get_perm(arr,next,length+1);
}
int main()
{
cin>>l>>d>>n;
string s,s1;
string* arr=new string[l];

while(d--){cin>>s;m.push_back(s);}
sort(m.begin(),m.end());
//for(vector<string>::iterator it=m.begin();it!=m.end();it++)
  //  cout<<*it<<endl;

int count;
for(int i=0;i<n;i++)
{
count=0;
cin>>s1;
int pos1=0,pos2=0,start=0;
for(;count<l;)
{
    pos1=s1.find('(',start);
    pos2=s1.find(')',start);
    if(pos1!=start)
    {
        if(pos1==string::npos)
            for(int i=start;i<s1.size();i++)
                {
                    arr[count]=s1.substr(i,1);
                    count++;
                }
        else
            for(int i=start;i<pos1;i++)
                {
                    arr[count]=s1.substr(i,1);
                    count++;
                }
    start=pos1;
    }
    else
    {
        arr[count]=s1.substr(pos1+1,pos2-pos1-1);
        count++;
        start=pos2+1;
    }
}

//for(int i=0;i<count;i++)
  // cout<<arr[i]<<endl;

cout<<"Case #"<<i+1<<": "<<get_perm(arr,m,0)<<endl;
}

return 0;
}

