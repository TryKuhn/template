void set(int v, int tl, int tr, int idx, int val)
{
    if (tl == tr)
    {
        tree [v] = val;
        return;
    }
    int tm = (tl + tr) / 2;
    if (tm >= where)
        set(v * 2, l, tm, idx, val);
    else
        set(v * 2 + 1, tm + 1, r, idx, val);
    tree [v] = tree [v * 2] + tree [v * 2 + 1];
}
