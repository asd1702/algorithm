#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll n;

struct Matrix{
    ll m[2][2];
};

Matrix multiply(const Matrix &a, const Matrix &b){
    Matrix res = {0, 0, 0, 0};
    for (int i = 0; i < 2; i++){
        for (int k = 0; k < 2; k++){
            for (int j = 0; j < 2; j++){
                res.m[i][j] = (res.m[i][j] + a.m[i][k] * b.m[k][j]) % mod;    
            }
        }
    }
    return res;
}

Matrix power(Matrix base, ll exp){
    Matrix res = {{{1, 0}, {0, 1}}};
    while(exp){
        if(exp & 1) res = multiply(res, base);
        base = multiply(base, base);
        exp >>= 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    if(n%2==1){
        cout << 0;
        return 0;
    }
    ll k = n/2;

    if(k == 0){
        cout << 1;
        return 0;
    }
    if(k == 1){
        cout << 3;
        return 0;
    }

    Matrix a = {{{4, mod-1}, {1, 0}}};
    Matrix a_exp = power(a, k-1);
    Matrix b = {{{3, 0}, {1, 0}}};
    Matrix ans = multiply(a_exp, b);

    cout << ans.m[0][0] % mod;
}