class SegmentTree
{
    public:
        int n;
        int32_t tree [4 * N + 1] = {};
        void tree_build(di a, int v, int l, int r)
        {
            if (l == r)
            {
                tree [v] = a [l];
                return;
            }
            int mid = (l + r) / 2;
            tree_build(a, v * 2, l, mid);
            tree_build(a, v * 2 + 1, mid + 1, r);
            tree [v] = tree [v * 2] + tree [v * 2 + 1];
        }
        void tree_build(int a [], int v, int l, int r)
        {
            if (l == r)
            {
                tree[v] = a[l];
                return;
            }
            int mid = (l + r) / 2;
            tree_build (a, v * 2, l, mid);
            tree_build (a, v * 2 + 1, mid + 1, r);
            tree [v] = tree [v * 2] + tree [v * 2 + 1];
        }
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
        int tree_request(int v, int l, int r, int rl, int rr)
        {
            if (rl > rr)
                return 0;
            if (l == rl && r == rr)
                return tree [v];
            int mid = (l + r) / 2;
            return tree_request(v * 2, l, mid, rl, min(mid, rr)) + tree_request(v * 2 + 1, mid + 1, r, max(mid + 1, rl), rr);
        }
};