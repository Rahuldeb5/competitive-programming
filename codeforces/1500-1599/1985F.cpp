/**
* @problem: F. Final Boss
* @link: https://codeforces.com/problemset/problem/1985/F
* @author: Rahul Deb
* @date: 2024-06-21 18:14
**/

#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
using ll = long long;

#define F first
#define S second
#define all(x) x.begin(), x.end()
#define pb push_back
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define FORE(i,a,b) for(int i = (a); i <= (b); ++i)
#define ROF(i,a,b) for(int i = (a); i >= (b); --i)
#define R0F(i,a) ROF(i,a,0)
#define trav(a,x) for(auto& a: x)
#define sz(x) (int)x.size()

using str = string;
template<class T> using V = vector<T>;
using vi = V<int>;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(0); cin.tie(nullptr);
        
    int t; cin >> t;

    while(t-- > 0) {
        ll h, n; cin >> h >> n; // health and attacks
        V<ll> attack(n), cool(n);
        F0R(i, n) {
            cin >> attack[i];
        } F0R(i, n) {
            cin >> cool[i];
        }

        ll low = 1, high = 1e12;

        while(low <= high) {
            ll mid = ((high-low)/2)+low;

            ll init {};
            F0R(i, sz(attack)) {
                init += attack[i];
            } if(init >= h) {
                break;
            }

            ll damage {};
            F0R(i, sz(cool)) {
                damage += (((mid-1)/cool[i])+1)*attack[i];
            }

            if(damage >= h) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        cout << low << "\n";
    }

    return 0;
}
