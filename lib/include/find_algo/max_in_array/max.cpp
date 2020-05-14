int max_in_array(int n, di a)
{
    int mx = MIN;
    for (int i = 0; i < n; i++)
        mx = max(mx, a [i]);
    return mx;
}