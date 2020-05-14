#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

//#define int int64_t
//#define FILE 10

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using orset = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename K>
using ormap = tree <T, K, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
    int a, b;
    cin >> a >> b;
}

int32_t main()
{
    srand(time(NULL));
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    #ifdef FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--)
        solve();
}