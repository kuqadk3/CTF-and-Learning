#include<iostream>
#include<algorithm>
using namespace std;
int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
}
int main()
{
	ios::sync_with_stdio(false);
	int q;
	cin>>q;
	while(q--)
	{
		int n,a[1000];
		cin>>n;
		for(int i=1;i<=n;i++)
		cin>>a[i];
		if(n==1)cout<<"YES"<<endl;
		else
		{
			int flag=0;
			if(a[1]==1)
			{
				if(a[2]==2)
				{
					for(int i=3;i<=n;i++)
					{
						if(a[i]<a[i-1])
						{
							flag=1;break;
						}
					}
					if(flag)cout<<"NO"<<endl;
					else cout<<"YES"<<endl;
				}
				else if(a[2]==n)
				{
					for(int i=3;i<=n;i++)
					{
						if(a[i]>a[i-1])
						{
							flag=1;break;
						}
					}
					if(flag)cout<<"NO"<<endl;
					else cout<<"YES"<<endl;
				}
				else cout<<"NO"<<endl;
			}
			else if(a[1]==n)
			{
				if(a[2]==1)
				{
					for(int i=3;i<=n;i++)
					{
						if(a[i]<a[i-1])
						{
							flag=1;break;
						}
					}
					if(flag)cout<<"NO"<<endl;
					else cout<<"YES"<<endl;
				}
				else if(a[2]==n-1)
				{
					for(int i=3;i<=n;i++)
					{
						if(a[i]>a[i-1])
						{
							flag=1;break;
						}
					}
					if(flag)cout<<"NO"<<endl;
					else cout<<"YES"<<endl;
				}
				else cout<<"NO"<<endl; 
			}
			else
			{
				if(a[1]<a[2])
				{
					for(int i=2;i<=n;i++)
					{
						if(a[1]+i-1==a[i])
						{
							continue;
						}
						else if(a[1]+i-1>n&&a[1]+i-1-n==a[i])
						{
							continue;
						}
						else
						{
							flag=1;break;
						}
					}
					if(flag)cout<<"NO"<<endl;
					else cout<<"YES"<<endl;
				}
				else
				{
					for(int i=2;i<=n;i++)
					{
						if(a[1]-i+1==a[i])
						{
							continue;
						}
						else if(a[1]-i+1<=0&&a[1]-i+1+n==a[i])
						{
							continue;
						}
						else
						{
							//cout<<"i="<<i<<" a1="<<a[1]<<" a="<<a[1]-i+1<<" ai="<<a[i]<<endl;
							flag=1;break;
						}
					}
					if(flag)cout<<"NO"<<endl;
					else cout<<"YES"<<endl;
				}
			}
		}
	}
    return 0;
}

