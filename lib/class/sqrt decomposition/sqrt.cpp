class decomposition
{
public:
    static const int LEN_ = 1e3;
    static const int MSZ_ = 1e6;
private:
    int len;
    array <int, LEN_> dec{};
    array<int, MSZ_> main_ar{};
public:
    template<typename T>
    decomposition(int sz, T inp){//Builder
        len = (int)sqrt(sz) + 1;
        for(int it = 0; it < sz; it++)
            main_ar[it] = inp[it];
        for (int i = 0; i < sz; ++i)
            dec[i / len] += inp[i];
    }
    void set(int dest, int delta){//Setter
        main_ar[dest] += delta;
        dec [dest / len] += delta;
    }
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
};
