template<typename T, typename K>
K pref_sum(T v)
{
    if (v.empty())
        return {};
    K ans (v.size());
    ans [0] = v [0];
    for(int i = 1; i < v.size(); i++)
        ans [i] = ans [i - 1] + v [i];
    return ans;
}
