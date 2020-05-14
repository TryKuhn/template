int binsearch(deque <int> where, int what)
{
    int left = 0, right = where.size() - 1;
    int mid = (left + right) / 2;
    while (where [mid] != what)
    {
        mid = (left + right) / 2;
        if (left == right)
        {
            mid = -1;
            break;
        }
        if (where [mid] < what)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return mid;
}