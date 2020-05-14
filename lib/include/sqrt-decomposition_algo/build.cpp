void build(int n, deque <int> a)
{
    int len = (int) sqrt (n + .0) + 1;
    deque <int> b (len);
    for (int i = 0; i < n; ++i)
        b[i / len] += a[i];
}