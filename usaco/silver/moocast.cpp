/**
 * @problem: Moocast - 2016 December Silver 
 * @link: 
 * @author: Rahuldeb5
 * @date: 2024-06-28
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

int n;
V<vi> arr;
V<pii> visited;

double dist(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

int dfs(int x, int y, int power) {
    trav(oof, visited) {
        if(oof.F == x && oof.S == y) {
            return 0;
        }
    }

    int count = 1;
    visited.pb(make_pair(x,y));

    trav(sub, arr) {
        if(dist(x, y, sub[0], sub[1]) <= power) {
            count += dfs(sub[0], sub[1], sub[2]);
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(nullptr);
    freopen("moocast.in", "r", stdin);
  	freopen("moocast.out", "w", stdout);

    cin >> n; arr.resize(n);
    F0R(i, n) {
        int x, y, power; cin >> x >> y >> power;
        arr[i] = {x, y, power};
    }

    int ans {};
        
    F0R(i, n) {
        visited.clear();
        ans = max(ans, dfs(arr[i][0], arr[i][1], arr[i][2]));
    }

    cout << ans;
    
    return 0;
}

