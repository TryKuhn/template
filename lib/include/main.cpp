void solve()
{
    
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