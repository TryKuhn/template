int64_t upd(int type, int a, int b){
    switch (type){
        case 1:
            return max(a, b);
            break;
        case 2:
            return min(a, b);
            break;
        case 3:
            return a + b;
            break;
        case 4:
            return a ^ b;
            break;
        case 5:
            return a | b;
            break;
        case 6:
            return a & b;
            break;
        case 7:
            return __gcd(a, b);
            break;
        case 8: 
            return a * b;
            break;
    }
}

class SegmentTree
{
private:
    static const int N = 1e5;
public:
    int type;
    SegmentTree(int type){
        this->type = type;
    }
    int n;
    int64_t tree [4 * N + 1] = {};
    void tree_build(deque <int> a, int v, int l, int r)
    {
        if (l == r)
        {
            tree [v] = a [l];
            return;
        }
        int mid = (l + r) / 2;
        tree_build(a, v * 2, l, mid);
        tree_build(a, v * 2 + 1, mid + 1, r);
        tree [v] = upd(type, tree [v * 2], tree [v * 2 + 1]);
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
        tree [v] = upd(type, tree [v * 2], tree [v * 2 + 1]);
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
        tree [v] = upd(type, tree [v * 2], tree [v * 2 + 1]);
    }
    int tree_request(int v, int l, int r, int rl, int rr)
    {
        if (rl > rr) {
            if (type == 8)
                return 1;
            return 0;
        }
        if (l == rl && r == rr)
            return tree [v];
        int mid = (l + r) / 2;
        return upd(type, tree_request(v * 2, l, mid, rl, min(mid, rr)), tree_request(v * 2 + 1, mid + 1, r, max(mid + 1, rl), rr));
    }
};
