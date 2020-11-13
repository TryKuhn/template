long long bin_pow(long long x, long long y)
{
    if (y == 0)
        return 1;
    if (y & 1)
        return x * bin_pow(x, y - 1);
    else
    {
        long long z = bin_pow(x, y / 2);
        return z * z;
    }
}

double binpow (double x, double y, bool d)
{
    return exp(y * log(x));
}

int sqr(int x)
{
    return x * x;
}
