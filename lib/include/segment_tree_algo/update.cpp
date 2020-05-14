void tree_update(int v, int l, int r, int where, int what)
{
    if (l == r)
    {
        tree [v] = what;
        return;
    }
    int mid = (l + r) / 2;
    if (mid >= where)
        tree_update(v * 2, l, mid, where, what);
    else
        tree_update(v * 2 + 1, mid + 1, r, where, what);
    tree [v] = tree [v * 2] + tree [v * 2 + 1];
}