#define FILE
#define LONG
#define MATH
#define FASTER

#define all(a) (a).begin(), (a).end()
#define F first
#define S second
#define pb push_back
#define pf push_front
#define ppb pop_back();
#define ppf pop_front();
#define For(r) for(int i = 0; i < r; i++)
#define FOR(l, r) for(int i = l; i <= r; i++)
#define YES cout << "YES\n";
#define NO cout << "NO\n";

#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))

#ifdef LONG
    #define int long long
#endif

#ifdef MATH
    #define INFD 1.0 / 0
    #define pi acos(-1)
    #define MOD (int)(1e9 + 7)
    #define sinDegrees(x) sin((x) * PI / 180.0)
    #define cosDegrees(x) cos((x) * PI / 180.0)
    #define tanDegrees(x) tan((x) * PI / 180.0)
    #define atanDegrees(x) atan(x)* 180.0 / PI
#endif
