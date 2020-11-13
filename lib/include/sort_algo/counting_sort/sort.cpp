template<typename T>
void counting_sort(T& in, int n, int k = 1e5, bool greater = false)
{
    vector<int> a(k + 1);
    for (int i = 0; i < n; i++)
        a [in [i]]++;
    int r = 0;
    if (greater){
        for (int i = k; i >= 0; i--)
        {
            while (a [i]--)
                in[r++] = i;
        }
    }
    else{
        for (int i = 0; i <= k; i++)
        {
            while (a [i]--)
                in[r++] = i;
        }
    }
}
