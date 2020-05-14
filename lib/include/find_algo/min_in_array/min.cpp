int min_in_array(int n, di a)
{
    int mn = MAX;
    for (int i = 0; i < n; i++)
        mn = min(mn, a [i]);
    return mn;
}