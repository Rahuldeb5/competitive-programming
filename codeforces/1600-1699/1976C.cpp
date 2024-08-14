/**
 * @problem: 
 * @link: 
 * @author: Rahuldeb5
 * @date: 2024-
 **/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

#define F first
#define S second
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define FORE(i,a,b) for(int i = (a); i <= (b); ++i)
#define ROF(i,a,b) for(int i = (a); i >= (b); --i)
#define R0F(i,a) ROF(i,a,0)
#define trav(a,x) for(auto& a: x)
#define sz(x) (int)x.size()
#define rsz resize
#define cl clear

using str = string;
template<class T> using V = vector<T>;
using vi = V<int>;
using pii = pair<int, int>;

typedef tree<int,null_type,less<int>,rb_tree_tag,
            tree_order_statistics_node_update> indexed_set;

void setIO(string name = "") {  // name is nonempty for USACO file I/O
	cin.tie(0)->sync_with_stdio(0);
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin);  // see Input & Output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

signed main() {
    setIO();
    
    int t; cin >> t;
    while(t-- > 0) {
        int n, m; cin >> n >> m;
        V<vi> arr(2);
        F0R(i, n+m+1) {
            int x; cin >> x; arr[0].pb(x);
        } F0R(i, n+m+1) {
            int x; cin >> x; arr[1].pb(x);
        }
        
        vi bounds = {n, m};
        int bad = -1, badType = -1;
        ll ans = 0;
        vi types(n+m+1), curr(2);

        F0R(i, n+m) {
            int currType = 0;
            if(arr[0][i] < arr[1][i]) {
                currType = 1;
            } if(curr[currType] == bounds[currType]) {
                currType = 1 - currType;
                if(bad == -1) {
                    bad = i;
                    badType = 1 - currType;
                }
            }
            types[i] = currType;
            ans += arr[currType][i];
            curr[currType]++;
        }

        V<ll> sol;
        F0R(i, n+m) {
            ll val = ans - arr[types[i]][i];
            if(bad != -1 && bad > i && types[i] == badType) {
                val += arr[badType][bad] - arr[1-badType][bad] + arr[1-badType][n+m];
            } else {
                val += arr[types[i]][n+m]; 
            }
            sol.pb(val);
        } sol.pb(ans);
        F0R(i, sz(sol)) {
            cout << sol[i] << " ";
        } cout << "\n";
    }
    
    return 0;
}

