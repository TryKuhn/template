class segment_tree{
private:
    template <typename T>
    static T merge_sort(T a1, T a2)
    {
        deque <int> a3 (a1.size() + a2.size());
        int i = 0, j = 0;
        int len = a3.size();
        for (int k = 0; k < len; k++)
        {
            if (i >= a1.size())
            {
                int a = a2[j];
                a3[k] = a;
                j++;
            }
            else if (j >= a2.size())
            {
                int a = a1[i];
                a3[k] = a;
                i++;
            }
            else if (a1[i] < a2[j])
            {
                int a = a1[i];
                a3[k] = a;
                i++;
            }
            else
            {
                int b = a2[j];
                a3[k] = b;
                j++;
            }
        }
        return a3;
    }
    static int binsearch(deque <int> a, int what){
        int count;
        int l = 0, r = a.size() - 1, m = (l + r) / 2;
        while(l < r){
            if (a [m] > what)
                r = m - 1;
            else if (a [m] < what)
                l = m + 1;
            else if (a [m] == what)
                l = r = m;
        }
        count = max(0LL, a.size() - l - 1);
        if (a [m] == what)
            count++;
        return count;
    }
    struct vertex{
    public:
        bool init = false;
        deque <int> a;
        vertex(){
            init = false;
            a.clear();
        }
        vertex* son_left{};
        vertex* son_right{};
    protected:
        void build (int left, int right, vertex* now, deque <int> * in){
            if (left == right){
                (now->a).push_back((*in) [left]);
                return;
            }
            now->init = true;
            int mid = (left + right) / 2;
            now->son_left = new vertex();
            now->son_right = new vertex();
            build(left, mid, now->son_left, in);
            build(mid + 1, right, now->son_right, in);
            now->a = merge_sort(now->son_left->a, now->son_right->a);
        }
    public:
        void init_f(deque <int> in, int left, int right, vertex* now){
            if (in.size() == 1){
                this->a = in;
                return;
            }
            else{
                now->init = true;
                int mid = (left + right) / 2;
                son_left = new vertex;
                son_right = new vertex;
                son_left->a.clear();
                build(left, mid, son_left, &in);
                son_right->a.clear();
                build(mid + 1, right, son_right, &in);
                now->a = merge_sort(son_left->a, son_right->a);
            }
        }
        void print(vertex* now){
            if (init){
                println_container(now->son_left->a);
                if(now->son_left->init)
                    this->print(now->son_left);
                println_container(now->son_right->a);
                if (now->son_right->init)
                    this->print(now->son_right);
            }
            else
                return;
        }
        int get (vertex* v, int tl, int tr, int l, int r, int what) {
            if (l > r)
                return 0;
            if (l == tl && r == tr)
                return binsearch(v->a, what);
            int tm = (tl + tr) / 2;
            return get (v->son_left, tl, tm, l, min(r,tm), what) + get (v->son_right, tm+1, tr, max(l,tm+1), r, what);
        }
        void set(int left, int right, int what, int where, vertex* now){
            if (left == right){
                now->a.clear();
                now->a.push_back(what);
                return;
            }
            int mid = (left + right) / 2;
            if (where <= mid)
                set(left, mid, what, where, now->son_left);
            else
                set(mid + 1, right, what, where, now->son_right);
            now->a = merge_sort(now->son_left->a, now->son_right->a);
        }
    };
    vertex* start = new vertex{};
public:
    void build(const deque <int>& a){
        this->start->init_f(a, 0, a.size() - 1, start);
    }
    int get(int left, int right, int what){
        return start->get(start, 0LL, start->a.size() - 1, left, right, what);
    }
    void set(int what, int where){
        start->set(0, start->a.size() - 1, what, where, start);
    }
    void print(){
        println_container(start->a);
        start->print(start);
    }
};
