/**
Author: Prakhar Asthana
prakharast@gmail.com
*/
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<limits>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef unsigned long long int ull;
typedef  long long int sll;



struct trie_node
{
bool leaf;
trie_node* next;
};

class note
{
private:
string guid;
string created;
vector<string>tag;
string content;
trie_node* trie_root;

trie_node* get_trie_node_arr()
{
trie_node *new_node_arr=new trie_node[37];
for(int i=0;i<37;i++)
{new_node_arr[i].leaf=false;new_node_arr[i].next=NULL;}
return new_node_arr;
}

void trim_front(string &haystack)
{
bool flag=true;
for(int i=0;i<haystack.size();i++)if(haystack[i]!=' '){flag=false;haystack=haystack.substr(i);break;}//trim from front;
if(flag)haystack="";
}
bool search_trie(string key,bool prefix_match)
{
    trie_node*curr=trie_root,*parent;

    for(int i=0;i<key.size();i++)
    {
        int pos;
        if(isdigit(key[i]))pos=key[i]-'0';
        else if(key[i]=='\'')pos=36;
        else pos=key[i]-'a'+10;
        if(curr[pos].next==NULL)return false;
        parent=curr;
        curr=curr[pos].next;
    }

    if(prefix_match or parent->leaf)return true;

return false;
}
void insert_trie(string key)
{
    //cout<<"insert function"<<endl;
    trie_node *curr=trie_root,*parent;
    if(key.size())
    {
        for(int i=0;i<key.size();i++)
        {
            int pos;
            if(isdigit(key[i]))pos=key[i]-'0';
            else if(key[i]=='\'')pos=36;
            else
            pos=key[i]-'a'+10;
            if(curr[pos].next==NULL)
            curr[pos].next=get_trie_node_arr();
            parent=curr;
            curr=curr[pos].next;
        }
    parent->leaf=true;
    }
}
void make_trie()
{
    string haystack=content;
    int pos;
    for(int i=0;i<haystack.size();i++)haystack[i]=tolower(haystack[i]);//coonvert to lower case
    while((pos=haystack.find_first_of(".*,?!\"(){}[];:-`\t\n"))!=string::npos)//remove punctuation marks
        haystack[pos]=' ';

    trie_root=get_trie_node_arr();

    while(1)
    {
        trim_front(haystack);
       // cout<<haystack<<endl;
        int pos=haystack.find(' ');
        string key=haystack.substr(0,pos);
       // cout<<key<<"!"<<endl;
        insert_trie(key);
        if(pos==string::npos)break;
        haystack=haystack.substr(pos+1);
    }
}

public:
note()
{
char ch;
cin.ignore(std::numeric_limits<std::streamsize>::max(), '>');

cin.ignore(std::numeric_limits<std::streamsize>::max(), '>');
while((ch=getchar())!='<')
guid.push_back(ch);
cin.ignore(std::numeric_limits<std::streamsize>::max(), '>');

cin.ignore(std::numeric_limits<std::streamsize>::max(), '>');
while((ch=getchar())!='<')
created.push_back(ch);
cin.ignore(std::numeric_limits<std::streamsize>::max(), '>');
while(1)
{
    string s;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '<');
    while((ch=getchar())!='>')
        s.push_back(ch);

    if(s=="content")
    {
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        break;
    }
    string temp;
    while((ch=getchar())!='<')
        temp.push_back(ch);

    tag.push_back(temp);
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '>');
}
while(1)
{
    string temp;
    getline(cin,temp);

    if(temp.find("</content>")!=string::npos)
        break;
    if(content.size()==0)
    content=temp;
    else
    content=content+"\n"+temp;
    //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
cin.ignore(std::numeric_limits<std::streamsize>::max(), '>');
cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//cout<<(char)getchar();
//print();
make_trie();
}
string get_guid()
{
return guid;
}
string get_content()
{
return content;}
string get_datentime()
{
return created;}
vector<string> get_tags()
{
return tag;}
void print()
{
cout<<"GUID=>"<<guid<<endl;
cout<<"CREATED=>"<<created<<endl;
for(int i=0;i<tag.size();i++)
cout<<"TAG=>"<<tag[i]<<endl;
cout<<"CONTENT=>"<<endl<<content<<endl;
}
bool isdategeq(string testdate)
{
string date=created.substr(0,4)+created.substr(5,2)+created.substr(8,2);
if(date.compare(testdate)>=0)return true;
else return false;
}
bool iscontentmatch(string needle)
{
for(int i=0;i<needle.size();i++)needle[i]=tolower(needle[i]);
//cout<<needle<<endl;
if(needle[needle.size()-1]=='*')
{
    needle=needle.substr(0,needle.size()-1);
    return search_trie(needle,true);
}
else return search_trie(needle,false);
}
};

int find(vector<note*>& note_arr,string datentime,string guid)
{
int l=-1;int r=note_arr.size()-1;
int m;

    while( r - l > 1 )//get leftmost occurence of date
    {
        m = l + (r - l)/2;

        if( note_arr[m]->get_datentime() >= datentime )
            r = m;
        else
            l = m;
    }
int pos=r;
for(;pos<note_arr.size();pos++)
    if(note_arr[pos]->get_guid()==guid)break;
return pos;
}

void delete_from_note_arr(vector<note*>& note_arr,string datentime,string guid)
{
int pos=find(note_arr,datentime,guid);
if(pos!=note_arr.size())
note_arr.erase(note_arr.begin()+pos);


}

map<string,note*> get_notes(vector<note*>&note_arr,string date)
{
int l=-1;int r=note_arr.size()-1;
int m;

while( r - l > 1 )//get leftmost occurence of date
{
    m = l + (r - l)/2;
    string temp=note_arr[m]->get_datentime();
    string t_date=temp.substr(0,4);
    t_date+=temp.substr(5,2);
    t_date+=temp.substr(8,2);
    if( t_date >= date )
        r = m;
    else
        l = m;
}
map<string,note*> map_m;
for(;r<note_arr.size();r++)
{
map_m[note_arr[r]->get_guid()]=note_arr[r];
}
return map_m;
}
bool compare(note*i,note*j)
{
return i->get_datentime()<=j->get_datentime();
}




int main()
{
string operation;
map<string,note*> note_map;
map<string,map<string,note*> >tag_db;
vector<note*>note_arr;

bool issorted=false;
while(cin>>operation)
{   cin.ignore();
    //cout<<operation<<endl;
    if(operation=="CREATE")
    {
        issorted=false;
        note* a=new note();

        note_arr.push_back(a);

        note_map[a->get_guid()]=a;
        vector<string>tags_arr=a->get_tags();
        for(int i=0;i<tags_arr.size();i++)
            tag_db[tags_arr[i]][a->get_guid()]=a;
    }
    else if(operation=="UPDATE")
    {
        issorted=false;
        note* a=new note();
        string guid=a->get_guid();
        vector<string>tags_arr=note_map[guid]->get_tags();
        for(int i=0;i<tags_arr.size();i++)
            tag_db[tags_arr[i]].erase(guid);

        string datentime=note_map[guid]->get_datentime();

        note_arr[find(note_arr,datentime,guid)]=a;
        note_map[a->get_guid()]=a;
        tags_arr=a->get_tags();
        for(int i=0;i<tags_arr.size();i++)
            tag_db[tags_arr[i]][guid]=a;
    }
    else if(operation=="DELETE")
    {
        if(!issorted)
            {sort(note_arr.begin(),note_arr.end(),compare);
            issorted=true;}
        string guid;
        cin>>guid;

        string datentime=note_map[guid]->get_datentime();
        delete_from_note_arr(note_arr,datentime,guid);

        vector<string>tags_arr=note_map[guid]->get_tags();
        note_map.erase(note_map.find(guid));
        for(int i=0;i<tags_arr.size();i++)
            tag_db[tags_arr[i]].erase(guid);

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else//operation=="SEARCH"
    {
        string query;
        getline(cin,query);
        vector<string>tag_query;
        vector<string>created_query;
        vector<string>content_query;
        int pos;
        while((pos=query.find(" "))!=string::npos)
        {
            string temp=query.substr(0,pos);
            if(temp.find("created:")!=string::npos)
                created_query.push_back(temp);
            else if(temp.find("tag:")!=string::npos)
                tag_query.push_back(temp);
            else content_query.push_back(temp);
            query=query.substr(pos+1);
        }
        if(query.find("created:")!=string::npos)
            created_query.push_back(query);
        else if(query.find("tag:")!=string::npos)
            tag_query.push_back(query);
        else content_query.push_back(query);

        map<string,note*>q_note_map=note_map;
        //search by date
        if(created_query.size()>0)
        {
            string max_date="00000000";
            for(int i=0;i<created_query.size();i++)
            {
                string date=created_query[i].substr(8);
                if(date>max_date)max_date=date;
            }
            if(!issorted)
            {
                sort(note_arr.begin(),note_arr.end(),compare);
                issorted=true;
            }
            q_note_map=get_notes(note_arr,max_date);
        }
        //search by tag
        for(int i=0;i<tag_query.size();i++)
        {
            vector<string>remove_key;
            string tag_q=tag_query[i].substr(4);
            for (std::map<string,note*>::iterator it=q_note_map.begin(); it!=q_note_map.end();it++ )
                if(!tag_db[tag_q].count(it->first))
                    remove_key.push_back(it->first);
            for(int i=0;i<remove_key.size();i++)
                q_note_map.erase(remove_key[i]);
        }
        for(int i=0;i<content_query.size();i++)
        {
            vector<string>remove_key;
            for (std::map<string,note*>::iterator it=q_note_map.begin(); it!=q_note_map.end();it++ )
                {   if(!it->second->iscontentmatch(content_query[i]))
                    remove_key.push_back(it->first);}
            for(int i=0;i<remove_key.size();i++)
                q_note_map.erase(remove_key[i]);

        }
        map<string,string> answer;
        for (std::map<string,note*>::iterator it=q_note_map.begin(); it!=q_note_map.end(); ++it)
        {
            answer[it->second->get_datentime()]=it->first;
        }
        for (std::map<string,string>::iterator it=answer.begin(); it!=answer.end(); ++it)
        {
            if(it!=answer.begin())
            cout<<","<<it->second;
            else
            cout<<it->second;
        }
        cout<<endl;
        fflush(stdout);
    }



}//for (std::map<string,note*>::iterator it=note_map.begin(); it!=note_map.end(); ++it)
   // std::cout << it->first << " => " << it->second->get_content() << '\n';
return 0;
}
