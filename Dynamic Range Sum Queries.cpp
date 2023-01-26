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
#define int long long
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
vector < int > tree ; 
vector < int > arr ; 
void check (  int n  ) {
  if (__builtin_popcount(n) == 1 ) 
    goto here ;
   for ( int i = 31 ; i>= 0 ; i-- ) 
   {
      if ( n & ( 1 << i ) ) {
         n = 1 << ( i + 1 ) ; 
         break; 
      }
   }
   here :
   tree.resize ( n * 2 + 1 ); 
   arr.resize  ( n     + 1 ); 
}
void build ( int v , int left , int right ) {
   if ( left == right ) {
     tree[v] = arr[left] ; 
     return ; 
   }
   build ( v * 2 , left , ( left + right ) / 2 ) ; 
   build ( v*2 + 1 , ( left + right ) /2 + 1 , right ) ;   
   tree[v] = tree[v*2] + tree[v*2+1] ; 
}
int get ( int v , int st , int end , int a  , int b ) {
   if ( end < a or st > b ) 
    return 0  ; 
  if ( a <= st && end <= b ) 
    return tree[v] ; 
  int mid = ( st + end ) / 2; 
  return get ( v * 2 , st , mid , a , b ) + get ( v * 2 + 1 , mid +1 , end , a , b ) ; 
} 
void update ( int v , int st , int end , int a , int b  , int value  ) {
    if ( st == a and end == a )
   {
     tree[v] = value ;
     return ; 
   }
    if ( st > a or end < a ) 
     return   ;  
    int mid = ( st + end ) / 2 ;
    update( v * 2 ,  st , mid , a , b , value ) ;
    update (v * 2 + 1, mid +1 , end , a , b , value ) ; 
    tree[v] = tree[v*2] + tree[v*2+1] ; 
}
void solve() { 
      int n , m; 
      cin >> n >> m ; 
      check ( n ) ; 
       for ( int i = 0 ; i < n ; i++) 
        cin >> arr[i] ; 
       build ( 1, 0 , n - 1) ; 
       while (m-- ) {
         int x ; cin >> x ; 
         if ( x == 1 ) {
            int k , u ; 
            cin >> k >> u ; 
            k-- ; 
            update ( 1 , 0 , n - 1 , k , k , u ) ; 
            dbg ( tree ) ;
            continue ;
         }
         int a , b ; 
         cin >> a >>b ; 
         a-- , b-- ; 
         cout << get ( 1 , 0 , n- 1 , a , b ) << endl;
      }


}//--------- -----------------------------------------------------------------------------------------------------------------
int32_t main(){
 #ifndef ONLINE_JUDGE
     files;
  #endif 
     FastIO;
 int test = 1;
  // cin>>test; 
    while(test--){
  //cout << " test case " <<++i<<endl;
     solve(); 
     if(test>0)
       cout << endl; 
}
 
 }  
