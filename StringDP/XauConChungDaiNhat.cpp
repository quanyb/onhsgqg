#include <bits/stdc++.h>
#define Vani "xauconchungdainhat"
#define FOR(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i) 
#define FOD(i, a, b) for(int i = (int)(a); i >= (int)(b); --i)

using namespace std;

string LongestSubsequeue(string s, string t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));

    FOR(i, 1, n) FOR(j, 1, m) {
        if(s[i - 1] == t[j - 1]) f[i][j] = f[i - 1][j - 1] + 1;
        else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
    }
    // FOR(i, 1, n) {
    //     FOR(j, 1, m) {
    //         cout << f[i][j] << " ";
    //     }cout<<'\n';    
    // }

    // truy vet
    int i = n, j = m;
    string lcs = "";
    
    while(i > 0 && j > 0) {
        if(s[i-1] == t[j-1]) {
            lcs = s[i-1] + lcs;
            i--;
            j--;
        } else {
            if (f[i-1][j] == f[i][j-1]) {
                if(s[i-1] < t[j-1]) {
                    j--;
                } else {
                    i--;
                }
            } else if (f[i-1][j] > f[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }
    }
    return lcs;
}

int32_t main() {
    string s, t;
    // cin.ignore();
    getline(cin, s);
    getline(cin, t);
    cout << LongestSubsequeue(s, t);
    return 0;
}
