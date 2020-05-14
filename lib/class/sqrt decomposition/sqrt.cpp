class sqrtdecomp 
{
    public:
        int len;
        deque <int> a, b;
        sqrtdecomp(int n, deque <int> v);
        void insert(int where, int what)
        {
            b [where / len] -= a [where];
            b [where / len] += what; 
            a [where] = what;
        }
        int request(int l, int r)
        {
            int sum = 0;
            int c_l = l / len,   c_r = r / len;
            if (c_l == c_r)
            {
                for (int i = l; i <= r; ++i)
                    sum += a[i];
            }
            else 
            {
                for (int i=l, end=(c_l+1)*len-1; i<=end; ++i)
                    sum += a[i];
                for (int i=c_l+1; i<=c_r-1; ++i)
                    sum += b[i];
                for (int i=c_r*len; i<=r; ++i)
                    sum += a[i];
            }
        }
};

sqrtdecomp::sqrtdecomp(int n, deque <int> v)
{
    a = v;
    len = (int) sqrt (n + .0) + 1;
    b.resize(len);
    for (int i = 0; i < n; ++i)
        b[i / len] += a[i];
}