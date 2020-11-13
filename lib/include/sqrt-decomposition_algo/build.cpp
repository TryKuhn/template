template<typename T>
decomposition(int sz, T inp){//Builder
    len = (int)sqrt(sz) + 1;
    for(int it = 0; it < sz; it++)
        main_ar[it] = inp[it];
    for (int i = 0; i < sz; ++i)
        dec[i / len] += inp[i];
}
