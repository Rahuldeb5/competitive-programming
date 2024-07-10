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

ll count(ll x1,ll  y1, ll z1, ll x2, ll y2, ll z2) { // 2 is the bigger one
    return (x2-x1+1) * (y2-y1+1) * (z2-z1+1);
}

signed main() {
    setIO();
    
    int t; cin >> t;
    while(t-- > 0) {
        ll x, y, z; cin >> x >> y >> z;
        ll k; cin >> k;
        ll ans {};

        for(ll i = x; i >= 1; i--) {
            if(k % i == 0) {
                for(ll j =y; j >= 1; j--) {
                    if((k/i) % j == 0) {
                        if(ans < count(i, j, ((k/j)/i), x, y, z)) {
                            ans = count(i, j, ((k/j)/i), x, y, z);
                        }
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    
    return 0;
}

