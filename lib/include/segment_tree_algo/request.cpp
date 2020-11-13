long long get(int v, int l, int r, int tl, int tr)
{
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return tree [v];
    int mid = (l + r) / 2;
    return get(v * 2, l, min(r, tm), tl, tm) + get(v * 2 + 1, max(l, tm + 1), tm + 1, tr);
}
