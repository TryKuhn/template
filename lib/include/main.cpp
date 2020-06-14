#ifdef TESTS
void new_test(){

}
#endif

int32_t main(){
#ifdef FASTREADWRITE
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
#endif
#ifdef FILE
    ifstream fin("input.txt");
    ofstream fout("output.txt");
#endif
#ifdef TESTS
    int test;
    cin >> test;
    while (test--){
        new_test();
        cout << "\n";
    }
#endif
#ifndef TESTS
    
#endif
#ifdef FILE
    fin.close();
    fout.close();
#endif
}
