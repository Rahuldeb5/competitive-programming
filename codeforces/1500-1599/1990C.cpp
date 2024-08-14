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

const int N = 200005;

int n;
int a[N];
bool c[N];

void doIt() {
    FORE(i,1,n) {
        c[i] = false;
    }
    int maxu = 0;
    FORE(i, 1, n) {
        if(c[a[i]]) {
            maxu = max(maxu, a[i]);
        }
        c[a[i]] = true;
        a[i] = maxu;    
    }
}

void solve() {
    cin >> n;
    FORE(i, 1, n) {
        cin >> a[i];
    }

    ll ans = 0;
    FORE(i, 1, n) {
        ans += a[i];
    }
    doIt();
    FORE(i, 1, n) {
        ans += a[i];
    }
    doIt();

    FORE(i, 1, n) {
        ans += a[i] * 1LL * (n - i + 1);
    }
    cout << ans << "\n";
}

signed main() {
    setIO();
    
    int t; cin >> t;
    while(t-- > 0) {
        solve();
    }
       
    return 0;
}

