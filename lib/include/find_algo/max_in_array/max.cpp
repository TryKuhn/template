template <typename T>
long long max_in_array(int n, T a)
{
    long long mx = LLONG_MIN;
    for (int i = 0; i < n; i++)
        mx = max(mx, a [i]);
    return mx;
}
