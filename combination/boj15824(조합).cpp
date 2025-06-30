#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int n, a[300001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);

    vector<ll> pow2(n+1, 1);
    for (int i = 1; i <= n; i++){
        pow2[i] = (pow2[i-1]*2)%mod;
    }
    
    ll ans = 0;
    for (int i = 0; i < n; i++){
        ll Max = (a[i]*pow2[i])%mod;
        ll Min = (a[i]*pow2[n-1-i])%mod;
        ans = (ans+Max-Min+mod)%mod;
    }
    cout << ans;
}
