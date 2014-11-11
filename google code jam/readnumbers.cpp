#include<iostream>
#include<map>
#include<vector>
using namespace std;
/**https://code.google.com/codejam/contest/2924486/dashboard*/

map <int,string> quan;
vector<string> eng(10);
int main()
{
quan[2]="double";quan[3]="triple";quan[4]="quadruple";quan[5]="quintuple";quan[6]="sextuple";quan[7]="septuple";
quan[8]="octuple";quan[9]="nonuple";quan[10]="decuple";

eng[0]="zero";eng[1]="one";eng[2]="two";eng[3]="three";eng[4]="four";eng[5]="five",eng[6]="six";eng[7]="seven";eng[8]="eight";eng[9]="nine";
int t;
string n,temp;
cin>>t;
for(int x=1;x<=t;x++)
{
cout<<"Case #"<<x<<": ";
vector<string> division;
int count=0;
cin>>n>>temp;
int pos;
while((pos=temp.find('-'))!=string::npos)
{
    //cout<<temp.substr(0,pos);
    division.push_back(temp.substr(0,pos));
    //cout<<temp.substr(pos+1);
    temp=temp.substr(pos+1);
}
division.push_back(temp);

//for(int i=0;i<division.size();i++)cout<<division[i]<<endl;
int sum_so_far=0;

for(int i=0;i<division.size();i++)
{
    int sum=0;
    for(int j=0;j<division[i].size();j++)
    {
        //cout<<division[i][j]<<endl;
        sum=sum*10+(division[i][j]-'0');
    }
    //cout<<"sum="<<sum<<" sum_so_far="<<sum_so_far<<endl;
    char curr,prev,next;
    int prev_pos;
    bool flag=true;
    for(int j=sum_so_far;j<sum_so_far+sum;j++)
    {
        curr=n[j];
        if(j==sum_so_far+sum-1)
        {
            if(flag)
            {cout<<eng[curr-'0']<<" ";continue;}
          //  cout<<curr<<" "<<prev<<" "<<prev_pos;
            if(curr==prev)
            {
                    if(j+1-prev_pos>10)
                            for(int i=1;i<=j+1-prev_pos;i++)
                                cout<<eng[prev-'0']<<" ";
                    else
                    {
                        if(j+1-prev_pos==1)cout<<eng[prev-'0']<<" ";
                        else cout<<quan[j+1-prev_pos]<<" "<<eng[prev-'0']<<" ";
                    }
            }
            else
            {
                if(j-prev_pos>10)
                            for(int i=1;i<=j-prev_pos;i++)
                                cout<<eng[prev-'0']<<" "<<endl;
                else
                {
                    if(j-prev_pos==1)cout<<eng[prev-'0']<<" ";
                    else cout<<quan[j-prev_pos]<<" "<<eng[prev-'0']<<" ";
                }
                cout<<eng[curr-'0']<<" ";
            }
        }
        else if(flag)
        {
            //cout<<"flag= true"<<endl;
            prev=n[j];prev_pos=j;flag=false;
        }
        else
        {
            if(curr!=prev)
            {
               if(j-prev_pos>10)
                    for(int i=1;i<=j-prev_pos;i++)
                        cout<<eng[prev-'0']<<" ";
                else
                {
                    //cout<<"mismatch <= 10"<<endl;
                    if(j-prev_pos==1)cout<<eng[prev-'0']<<" ";
                    else cout<<quan[j-prev_pos]<<" "<<eng[prev-'0']<<" ";
                }
                prev=curr;prev_pos=j;
            }
        }



    }
    sum_so_far+=sum;

}
cout<<endl;


}







return 0;
}
