#include <bits/stdc++.h>
using namespace std;
 
 
 
 
int main()
{
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    
 int t,i;
 cin>>t;
 
 
 for(i=0;i<t;i++)
 {
    int n;
    cin>>n;
    int a[n],j,l=0,m=0;
    cin>>a[0];
    for(j=1;j<n;j++)
    {
        cin>>a[j];
        if(a[j]-a[j-1]==1 || a[j]-a[j-1]==(-1*(n-1)) ) l++;
        
        else if(a[j-1]-a[j]==1 || a[j-1]-a[j]==(-1*(n-1))) m++;
    }
    
    if(l==n-1 || m==n-1) cout<<"YES\n";
    else cout<<"NO\n";
    
    
    
    
 }
 
return 0;
}
