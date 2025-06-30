#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

struct Matrix{
    ll m[2][2];
};

Matrix multiply(const Matrix &A, const Matrix &B) {
    Matrix C;
    C.m[0][0] = (A.m[0][0] * B.m[0][0] + A.m[0][1] * B.m[1][0]) % mod;
    C.m[0][1] = (A.m[0][0] * B.m[0][1] + A.m[0][1] * B.m[1][1]) % mod;
    C.m[1][0] = (A.m[1][0] * B.m[0][0] + A.m[1][1] * B.m[1][0]) % mod;
    C.m[1][1] = (A.m[1][0] * B.m[0][1] + A.m[1][1] * B.m[1][1]) % mod;
    return C;
}

Matrix power(Matrix A, ll exp){
    if(exp == 1) return A;
    Matrix half = power(A, exp/2);
    Matrix result = multiply(half, half);
    if(exp % 2 == 1) result = multiply(result, A);
    return result;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin >> n;

    Matrix T = {{{1, 1}, {1, 0}}};
    Matrix ans = power(T, n);

    cout << ans.m[1][0] % mod;
}