class segment
{
private:
    static const int N = 1e5; //MAX_SIZE of segment tree
    short type = 1;//Type of operation
    array <long long, 4 * N + 4> tree{};//Segment tree
    int left = 0, right = N - 1;//left and right border of input array
    long long act(long long f, long long s){ // An operation, which we are going count in segment tree
        switch (type){
            case 1:
                return max(f, s);
            case 2:
                return min(f, s);
            case 3:
                return f + s;
            case 4:
                return (unsigned)f ^ (unsigned)s;
            case 5:
                return (unsigned)f | (unsigned)s;
            case 6:
                return (unsigned)f & (unsigned)s;
            case 7:
                return __gcd(f, s);
            case 8:
                return f * s;
            default:
                return -1;
        }
    }
    void update(int v, int tl, int tr, int idx, int new_val){//updates value (new_val) on index (idx)
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
    long long request(int v, int tl, int tr, int l, int r){//finds type (sum, min, max...) on segment from l to r
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
    template<typename T>
    void tree_build(T &in, int v, int tl, int tr){//builds segment tree
        if (tl == tr)
        {
            tree [v] = in [tl];
            return;
        }
        int tm = (tl + tr) / 2;
        tree_build(in, v * 2, tl, tm);
        tree_build(in, v * 2 + 1, tm + 1, tr);
        tree [v] = act(tree [v * 2], tree [v * 2 + 1]);
    }
public:
#define N SEG_MAX_SIZE
    explicit segment(short tp){
        type = tp;
    }
    template<typename T>
    void build(T &in){
        right = in.size() - 1;
        tree_build(in, 1, left, right);
    }
    void set(int idx, int new_val){
        update(1, left, right, idx, new_val);
    }
    long long get(int l, int r){
        return request(1, left, right, l, r);
    }
};
