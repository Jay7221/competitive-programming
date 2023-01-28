#include<bits/stdc++.h>
using namespace std;
int cnt(int num)
{
    int c=0;
    while(num)
    {
        num=num>>1;
        c++;
    }
    return c;
}
void sol(int n)
{
    int num;
    const int N=22;
    int a[N][N]={0};
    int a_z[N][N]={0};
    for(int i=0;i<n;i++)
    {
        cin>>num;
        if(num==0)
        {
            a_z[0][0]++;
            continue;
        }
        int index=cnt(num);
        for(int i=0;i<N;i++)
        {
            if(num & (1<<i))
            a[index][i]++;
            else
            a_z[index][i]++;
        }
    }
    int b[N][N]={0};
    int b_z[N][N]={0};
    for(int i=0;i<n;i++)
    {
        cin>>num;
        if(num==0)
        {
            b_z[0][0]++;
            continue;
        }
        int index=cnt(num);
        for(int i=0;i<N;i++)
        {
            if(num & (1<<i))
            b[index][i]++;
            else
            b_z[index][i]++;
        }
    }
    int zero=a_z[0][0];
    long long sum=0;
    for(int i=1;i<N;i++)
    {
        for(int j=0;j<=i;j++)
        {
            sum+=1LL*zero*(b[i][j])*(1<<j);
        }
    }
    zero=b_z[0][0];
    for(int i=1;i<N;i++)
    {
        for(int j=0;j<=i;j++)
        {
            sum+=1LL*zero*(a[i][j])*(1<<j);
        }
    }
    long long l;
    for(int i_a=1;i_a<N;i_a++)
    {
        for(int j_a=0;j_a<N;j_a++)
        {
            l=1LL*a[i_a][j_a]*(b[i_a][j_a])*(1<<j_a);
            if(l>0)
            sum+=l;
            for(int i_b=1;i_b<N;i_b++)
            {
                if(i_a==i_b)
                {
                    continue;
                }
                l=1LL*a[i_a][j_a]*(b_z[i_b][j_a])*(1<<j_a);
                if(l>0)
                    sum+=l;
                l=1LL*a_z[i_a][j_a]*(b[i_b][j_a])*(1<<j_a);
                if(l>0)
                    sum+=l;
            }
        }
    }
    cout<<sum<<'\n';
}
void sol2(int n)
{
    vector<int>a(n);
    vector<int>b(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int j=0;j<n;j++)
    cin>>b[j];
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            sum+=max(a[i]^b[j],a[i]&b[j]);
        }
    }
    cout<<sum<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n<10)
        {
            sol2(n);
        }
        else
        sol(n);
    }
 return 0;
}