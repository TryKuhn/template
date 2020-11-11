void start(){

}

int32_t main(){
#ifdef FASTREADWRITE
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
#endif
#ifdef FILE
    ifstream fin("input.txt");
    ofstream fout("output.txt");
#endif
    int test = 1;
    //cin >> test;
    while (test--)
        start();
#ifdef FILE
    fin.close();
    fout.close();
#endif
}
