di counting_sort(int n, int k, di v)
{
    int a [k + 1] = {};
    for (int i = 0; i < n; i++)
        a [v [i]]++;
    di rezult;
    for (int i = 0; i <= k; i++)
    {
        while (a [i]--)
            rezult.pb(i);
    }
    return rezult;
}
