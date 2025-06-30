#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll N;
    cin >> N;
    ll A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    if(N == 1){
        ll faces[6] = {A, B, C, D, E, F};
        ll sum = A + B + C + D + E + F;
        ll maxi = 0;
        for (int i = 0; i < 6; i++){
            maxi = max(maxi, faces[i]);
        }
        cout << sum - maxi;
        return 0;
    }
    ll m1 = min({A, B, C, D, E, F});
    ll m2 = min({ A+B, A+E, F+B, F+E, A+C, A+D, F+C, F+D, B+C, B+D, E+C, E+D });
    ll m3 = min( { A+B+C, A+B+D, A+C+E, A+D+E, F+B+C, F+B+D, F+C+E, F+D+E } );

    ll ans = 4*m3 + (8*N-12)*m2 + (4*(N-2)*(N-1)+(N-2)*(N-2))*m1;
    cout << ans;
}
