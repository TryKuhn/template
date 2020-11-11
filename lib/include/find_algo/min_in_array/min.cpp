template <typename T>
long long min_in_array(int n, T a)
{
    long long mn = LLONG_MAX;
    for (int i = 0; i < n; i++)
        mn = min(mn, a [i]);
    return mn;
}
