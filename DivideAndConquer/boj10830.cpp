#include<bits/stdc++.h>
#define ll long long
#define mod 1000
using namespace std;

typedef vector<vector<ll>> Matrix;

Matrix multiply(const Matrix& A, const Matrix& B){
    int n = A.size();
    Matrix C(n, vector<ll>(n,0));
    for (int i = 0; i < n; i++){
        for (int k = 0; k < n; k++){
            for (int j = 0; j < n; j++){
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;   
            }
        }
    }
    return C;
}

Matrix power(Matrix A, ll exp){
    int n = A.size();
    if(exp == 1){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                A[i][j] %= mod;
            }
        }
        return A;
    }

    Matrix half = power(A, exp/2);
    Matrix result = multiply(half, half);

    if(exp % 2 == 1){
        result = multiply(result, A); 
    }
    return result;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    ll b;
    cin >> n >> b;

    Matrix A(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> A[i][j];
        }
    }
    
    Matrix ans = power(A, b);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << ans[i][j] % mod << ' ';
        }
        cout << '\n';
    }
}