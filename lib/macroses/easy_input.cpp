#ifdef KOTLIN
template <typename T>
void read(T &pr){
    cin >> pr;
}

template <typename T>
void read_container(T &pr){
    for (auto &i: pr)
        cin >> i;
}

template <typename T>
void print_container(const T &pr){
    for (auto &i: pr)
        cout << i << " ";
}

template <typename T>
void print(const T &pr){
    cout << pr;
}

template <typename T>
void println(const T &pr){
    print(pr);
    cout << "\n";
}

template <typename T>
void println_container(const T &pr){
    print_container(pr);
    cout << "\n";
}
#endif
