int get(int l, int r){//Getter
    int sum = 0;
    int l_block = l / len,   r_block = r / len;
    if (l_block == r_block)
    {
        for (int i = l; i <= r; ++i)
            sum += main_ar[i];
    }
    else
    {
        for (int it=l, end=(l_block+1)*len-1; it<=end; ++it)
            sum += main_ar[it];
        for (int it=l_block+1; it<=r_block-1; ++it)
            sum += dec[it];
        for (int it=r_block*len; it<=r; ++it)
            sum += main_ar[it];
    }
    return sum;
}
