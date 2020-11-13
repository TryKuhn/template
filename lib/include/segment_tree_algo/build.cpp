template<typename T>
void tree_build(T& a, int v, int tl, int tr)
{
    if (tl == tr)
    {
        tree [v] = a [tl];
        return;
    }
    int tm = (tl + tr) / 2;
    tree_build(a, v * 2, tl, tm);
    tree_build(a, v * 2 + 1, tm + 1, tr);
    tree [v] = tree [v * 2] + tree [v * 2 + 1];
}
