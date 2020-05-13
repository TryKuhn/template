int binpow(int x, int y)
{
    if (y == 0)
        return 1;
    if (y & 1)
        return x * binpow(x, y - 1);
    else
    {
        int z = binpow(x, y / 2);
        return sqr(z);
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