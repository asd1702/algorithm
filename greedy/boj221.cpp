#include<bits/stdc++.h>
using namespace std;

int n, k;

bool cmp(int a, int b){
    return a > b;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    vector<int>a(n), g;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if(k >= n){
        cout << 0;
        return 0;
    }
    for (int i = 1; i < n; i++){
        g.push_back(a[i]-a[i-1]);
    }
    sort(g.begin(), g.end(), cmp);
    int ans = a[n-1]-a[0];
    for (int i = 0; i < k-1; i++){
        ans -= g[i];
    }
    cout << ans;
}