#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using orset = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename K>
using ormap = tree <T, K, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
