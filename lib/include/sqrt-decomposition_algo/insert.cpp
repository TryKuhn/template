void insert(int where, int what)
{
    b [where / len] -= a [where];
    b [where / len] += what; 
    a [where] = what;
}