template <typename T>
int bin_search(T in, int val)
{
    int l = 0, r = in.size() - 1;
    while (l < r)
    {
        int m = (l + r) / 2;
        if (in [m] < val)
            l = m + 1;
        else if (in [m] > val)
            r = m - 1;
        else
            l = m, r = m;
    }
    if (in[l] == val)
        return l;
    else
        return -1;
}
