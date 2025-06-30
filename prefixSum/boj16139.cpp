#include<bits/stdc++.h>
using namespace std;

string s;
int q, a[27][200001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> s >> q;
    a[s[0]-'a'][0]++;
    for (int i = 0; i < 27; i++){
        for (int j = 1; j < s.size(); j++){
            a[i][j] += a[i][j-1] + ((i == s[j]-'a') ? 1 : 0);
        }
    }
    for (int i = 0; i < q; i++){
        char x;
        int l, r, ans;
        cin >> x >> l >> r;
        ans = (l == 0) ? a[x-'a'][r] : a[x-'a'][r] - a[x-'a'][l-1];
        cout << ans << '\n';
    }
}