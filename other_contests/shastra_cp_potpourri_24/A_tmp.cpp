#include<bits/stdc++.h>
#include <string.h>
using namespace std;
#pragma GCC optimize("Ofast")
int main()
{
ios::sync_with_stdio(0);
cin.tie(NULL);
cout.tie(NULL);
int t;
cin>>t;
while(t>0)
{
    string c;
    cin>>c;
    string d;
    cin>>d;
    int s[26];
    int s1[26];
    if(d.length()!=c.length())
    {
    cout<<"NO"<<'\n';
    break;
    }
    int l=c.length();
    for(int i=0;i<26;i++ )
    {
    s[i]=0;
    s1[i]=0;
    }
    for(int i=0;i<l;i++)
    {
        if(c[i] < 'a'){
            ++s[c[i] - 'A'];
        }
        else{
            ++s[c[i] - 'a'];
        }
        if(d[i] < 'a'){
            ++s1[d[i] - 'A'];
        }
        else{
            ++s1[d[i] - 'a'];
        }
    }
    int flag;
    for(int i=0;i<26;i++)
    {
        if(s1[i]!=s[i])
        {
            flag=1;
            continue;
        }
    }
    if(flag==1)
    {
        cout<<"NO"<<'\n';
    }
    else
    {
        cout<<"YES"<<'\n';
    }
    --t;
}
return 0;
}
