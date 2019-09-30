// Author: πα

#include <bits/stdc++.h>
using namespace std;
#define long int64_t

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    map<string, int> m;
    for(int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        m[s]++;
    }
    long ans = 0;
    for(auto it : m)
        ans += 1LL * it.second * (it.second - 1);
        cout << ans << endl;
    cout << ans/2;
    return 0;
}

