#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, l;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> l;

    vector<pair<int,int>>a(n);
    for (int i = 0; i < n; i++){
        int st, en;
        cin >> st >> en;
        a[i] = {st, en};
    }
    sort(a.begin(), a.end());
    
    int ans = 0, covered = 0;
    for (int i = 0; i < n; i++){
        int st = a[i].first;
        int en = a[i].second;

        if(covered < st){
            covered = st;
        }
        if(covered < en){
            int remain = en - covered;
            int cnt = (remain+l-1)/l;
            ans += cnt;
            covered += cnt*l;
        }
    }
    
    cout << ans;
}