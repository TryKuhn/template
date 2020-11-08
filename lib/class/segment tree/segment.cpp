class segment
{
private:
    static const int N = 1e5;
    short type = 1;
    int len = N;
    array<int, N> a{};
    array <long long, 4 * N + 4> tree{};
    long long act(long long f, long long s){
        switch (type){
            case 1:
                return max(f, s);
                break;
            case 2:
                return min(f, s);
                break;
            case 3:
                return f + s;
                break;
            case 4:
                return f ^ s;
                break;
            case 5:
                return f | s;
                break;
            case 6:
                return f & s;
                break;
            case 7:
                return __gcd(f, s);
                break;
            case 8:
                return f * s;
                break;
            default:
                return -1;
        }
        return 0;
    }
    void do_build(int v, int tl, int tr){
        if (tl == tr)
        {
            tree [v] = a [tl];
            return;
        }
        int tm = (tl + tr) / 2;
        do_build(v * 2, tl, tm);
        do_build(v * 2 + 1, tm + 1, tr);
        tree [v] = act(tree [v * 2], tree [v * 2 + 1]);
    }
public:
    segment(int tp, int ln){
        type = tp;
        len = ln;
    }
    template<typename T>
    void build(T in, int v, int tl, int tr)
    {
        for(int i = tl; i <= tr; i++)
            a[i] = in[i];
        do_build(v, tl, tr);
    }
    void update(int v, int tl, int tr, int idx, int new_val)
    {
        if (tl == tr)
        {
            tree [v] = new_val;
            return;
        }
        int tm = (tl + tr) / 2;
        if (tm >= idx)
            update(v * 2, tl, tm, idx, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, idx, new_val);
        tree [v] = act(tree [v * 2], tree [v * 2 + 1]);
    }
    long long request(int v, int tl, int tr, int l, int r){
        if (l > r)
            return -1;
        if (tl == l && tr == r)
            return tree[v];
        long long ans = LLONG_MAX;
        int tm = (tl + tr) / 2;
        int nl = l, nr = min(r, tm);
        if (nl <= nr)
            ans = request(v * 2, tl, tm, nl, nr);
        nl = max(l, tm + 1), nr = r;
        if (nl <= nr){
            if (ans != LLONG_MAX)
                ans = act(ans, request(v * 2 + 1, tm + 1, tr, nl, nr));
            else
                ans = request(v * 2 + 1, tm + 1, tr, nl, nr);
        }
        return ans;
    }
};
