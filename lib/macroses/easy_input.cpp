#define EASY_INPUT

#ifdef EASY_INPUT
    template <typename... T>
    inline void read(T&... a){
        ((std::cin >> a), ...);
    }
    template <typename T>
    inline void read_container(T& a){
        for(auto i: a)
            cin >> i;
    }
    template <typename... T>
    inline void print(T&... a){
        ((std::cout << a << ' '),  ...);
    }
    template<typename T>
    inline void print_container(T& a){
        for(auto i: a)
            cout << i << ' ';
    }
#endif
