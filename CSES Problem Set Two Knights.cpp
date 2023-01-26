#include<bits/stdc++.h>
 using namespace std;
using ll = long long int ; // 
#define hi cout << "test\n" ;
const ll inf = 1e9 + 7  ;
#define f first  
#define s second 
#define files freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout),freopen("error.txt","w",stderr) 
#define FastIO ios_base::sync_with_stdio(false) , cin.tie(0) , cout.tie(0)
#ifndef ONLINE_JUDGE
#define dbg(x) cerr << #x <<" = "; _print(x); cerr << endl;
#else
#define dbg(x)
#endif    
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll gcd(ll a, ll b) { return((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a, ll b) { return (b / gcd(a, b)) * a; }
void _print(auto t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
//----------------------------------------------------------------------------------------------------------------------------------
#define int long long
void solve() { 
     int x , y ; 
     cin >> x >> y; 
      if ( x <= y ) {
        int ans = y * y - y + 1;
        if ( y % 2 == 0 )
           ans -= y - x ; 
         else
          ans += y - x  ;
        cout << ans ;
        return ;
      }  
      int ans = x * x - x + 1 ; 
      if ( x % 2 == 0 ) 
         ans += x - y ; 
       else 
        ans -=  x - y;
      cout << ans ; 
      
}//--------- -----------------------------------------------------------------------------------------------------------------
int32_t main(){
 #ifndef ONLINE_JUDGE
     files;
  #endif 
     FastIO;
 int test = 1;
  cin>>test; 
    while(test--){
  //cout << " test case " <<++i<<endl;
     solve(); 
     if(test>0)
       cout << endl; 
}
 
 }  
