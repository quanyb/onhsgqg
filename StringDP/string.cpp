#include <bits/stdc++.h>
#define Vani "biendoixau"
#define FOR(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i) 
#define FOD(i, a, b) for(int i = (int)(a); i >= (int)(b); --i)

using namespace std;

int minDistance(string s, string t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> f(n + 1, vector<int>(m + 1));
    FOR(i, 0, n) f[i][0] = i;
    FOR(j, 0, m) f[0][j] = j;

    FOR(i, 1, n) FOR(j, 1, m) {
        if(s[i - 1] == t[j - 1]) f[i][j] = f[i - 1][j - 1];
        else f[i][j] = min({f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]}) + 1;
    }
    return f[n][m];
}

void solve() {
    string s, t;
    getline(cin, s);
    getline(cin, t);
    // cout << s << '\n' << t << '\n';
    cout << minDistance(s, t) << '\n';
}

int32_t main() {
    if(fopen(Vani".inp", "r")) {
        freopen(Vani".inp", "r", stdin);
        freopen(Vani".out", "w", stdout);
    }
    int test = 1;
    cin >> test;
    cin.ignore();
    while(test--) {
        solve();
    }
    return 0;
}
