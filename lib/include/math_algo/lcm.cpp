int lcm(int x, int y)
{
    return(x * y / __gcd(x, y));
}