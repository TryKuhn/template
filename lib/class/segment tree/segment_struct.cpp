class segment{
    short type = 1;//Type of operation
    int left = 0, right = 0;
    long long act(long long f, long long s){ // An operation, which we are going to count in segment tree
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
    struct vertex{
        long long val = 0;
        vertex* left_son{};
        vertex* right_son{};
    };
public:
    vertex* node = new vertex;
    template<typename T>
    void tree_build(T &a, vertex* v, int tl, int tr){
        if (tl == tr){
            v->val = a[tl];
            return;
        }
        v->left_son = new vertex();
        v->right_son = new vertex();
        int tm = (tl + tr) / 2;
        tree_build(a, v->left_son, tl, tm);
        tree_build(a, v->right_son, tm + 1, tr);
        v->val = act((v->left_son)->val, (v->right_son)->val);
    }
    void update(vertex* v, int tl, int tr, int idx, int new_val){
        if (tl == tr){
            v->val = new_val;
            return;
        }
        int tm = (tl + tr) / 2;
        if (tm >= idx)
            update(v->left_son, tl, tm, idx, new_val);
        else
            update(v->right_son, tm + 1, tr, idx, new_val);
        v->val = act((v->left_son)->val, (v->right_son)->val);
    }
    long long request(vertex* v, int tl, int tr, int l, int r){
        if (l > r)
            return -1;
        if (l == tl && r == tr)
            return v->val;
        long long ans = LLONG_MAX;
        int tm = (tl + tr) / 2;
        int nl = l, nr = min(r, tm);
        if (nl <= nr)
            ans = request(v->left_son, tl, tm, nl, nr);
        nl = max(l, tm + 1), nr = r;
        if (nl <= nr){
            if (ans != LLONG_MAX)
                ans = act(ans, request(v->right_son, tm + 1, tr, nl, nr));
            else
                ans = request(v->right_son, tm + 1, tr, nl, nr);
        }
        return ans;
    }
public:
#define SEG_MAX 100000
    explicit segment(short tp){
        type = tp;
    }
    template<typename T>
    void build(T &in){
        right = in.size() - 1;
        tree_build(in, node, left, right);
    }
    void set(int idx, int new_val){
        update(node, left, right, idx, new_val);
    }
    long long get(int l, int r){
        return request(node, left, right, l, r);
    }
};
