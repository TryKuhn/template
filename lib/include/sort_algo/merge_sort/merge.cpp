deque <int> merge_sort(deque <int> a1, deque <int> a2)
{
    deque <int> a3 (a1.size() + a2.size());
    int i = 0, j = 0;
    for (int k = 0; k < a3.size(); k++) 
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
}