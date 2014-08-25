#include<iostream>
/**https://www.hackerrank.com/contests/csindia-practice/challenges/john-and-gcd-list*/
using namespace std;
int gcd(int a,int b)
    {
    if(a<b)return gcd(b,a);
    if(b==0)return a;
    return gcd(b,a%b);
}
int lcm(int a,int b)
    {
    //cout<<gcd(a,b);
    return(a*b)/gcd(a,b);
}
int main()
    {
    int t,n;
    cin>>t;
    while(t--)
        {
        cin>>n;
        int *arr=new int[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<arr[0]<<" ";
        for(int i=0;i<n-1;i++)
            cout<<lcm(arr[i],arr[i+1])<<" ";
        cout<<arr[n-1]<<endl;
    }


    return 0;
}
