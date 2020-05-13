di pref_sum(di v)
{
    di rezult (v.size());
    if (v.empty())
        return rezult;
    rezult [0] = v [0];
    For(v.size())
    {
        if (!i)
            continue;
        rezult [i] = rezult [i - 1] + v [i];
    }
    return rezult;
}