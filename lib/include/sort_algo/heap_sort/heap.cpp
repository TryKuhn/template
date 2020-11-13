template <typename T>
void heapify(T& in, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && in [l] > in [largest])
        largest = l;
    if (r < n && in[r] > in[largest])
        largest = r;
    if (largest != i)
    {
        swap(in[i], in[largest]);
        heapify(in, n, largest);
    }
}

template <typename T>
void heapSort(T& in, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(in, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(in[0], in[i]);
        heapify(in, i, 0);
    }
}
