#include<bits/stdc++.h>
using namespace std;

int n, a[1000002], ans;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        int h;
        cin >> h;
        a[h]++;
        if(a[h+1]) a[h+1]--;
        else ans++;
    }
    cout << ans;
}