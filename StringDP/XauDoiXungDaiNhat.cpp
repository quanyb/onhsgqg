#include <bits/stdc++.h>
#define Vani "xaudoixungdainhat"
#define FOR(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i) 
#define FOD(i, a, b) for(int i = (int)(a); i >= (int)(b); --i)

using namespace std;

string findlcs(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
    // build dp
    FOR(i, 1, n) FOR(j, 1, m) {
        if(s1[i - 1] == s2[j - 1]) f[i][j] = f[i - 1][j - 1] + 1;
        else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
    } 
    // truy vết
    string lcs = "";
    int i = n, j = m;
    while(i > 0 && j > 0) {
        if(s1[i - 1] == s2[j - 1]) {
            lcs = s1[i - 1] + lcs;
            --i;
            --j;
        } else {
            if(f[i - 1][j] > f[i][j - 1]) --i;
            else --j;
        }
    }
    return lcs;
}

int32_t main() {
    string s;
    getline(cin, s);
    string res = s;
    reverse(res.begin(), res.end());
    string lcs = findlcs(s, res);
    cout << lcs << '\n';
    return 0;
}
