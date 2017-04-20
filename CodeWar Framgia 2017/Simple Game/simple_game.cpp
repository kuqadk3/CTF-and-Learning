logo
Home
How to
Scoreboard
Submissions
  Đào Tuấn Linh  
 
VN 

Submission Detail
Home Submissions Submission Detail
By Đào Tuấn Linh, contest: Code War 2017 - Online Round, problem: Simple Game, last passed test case: 60

Accepted

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<set>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<stack>
#define INF 2100000000
#define ll long long
#define clr(x)  memset(x,0,sizeof(x))
#define clrmax(x)  memset(x,127,sizeof(x))

using namespace std;

inline int read()
{
    char c;
    int ret=0;
    while(!(c>='0'&&c<='9'))
        c=getchar();
    while(c>='0'&&c<='9')
    {
        ret=(c-'0')+(ret<<1)+(ret<<3);
        c=getchar();
    }
    return ret;
}

#define M 200005

int n,k,x;
ll a[M],lg2[40],t=1,ans;

int main()
{
    n=read();k=read();x=read();
    for(int i=1;i<=n;i++)
        a[i]=read();
    for(int i=1;i<=k;i++)
        t*=x;
    for(int i=1;i<=n;i++)
        for(int j=a[i];j;j-=j&(-j))
        {
            int temp=j&(-j);
            temp=log((double)temp+0.5)/log(2.0);
            lg2[temp]++;
        }
    for(int i=1;i<=n;i++)
    {
        ll num=a[i]*t;
        for(int j=a[i];j;j-=j&(-j))
        {
            int temp=j&(-j);
            temp=log((double)temp+0.5)/log(2.0);
            lg2[temp]--;
        }
        ll x=0;
        for(int j=0;j<=32;j++)
            if(lg2[j])x+=1<<j;
        x|=num;
        ans=max(ans,x);
        for(int j=a[i];j;j-=j&(-j))
        {
            int temp=j&(-j);
            temp=log((double)temp+0.5)/log(2.0);
            lg2[temp]++;
        }
    }
    cout<<ans;
    return 0;
}
© 2017 Framgia Vietnam. All rights reserved.
Follow Life at Framgia on
