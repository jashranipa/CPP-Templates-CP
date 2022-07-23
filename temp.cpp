#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
typedef unsigned long long ull;
typedef long double lld;
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
#define endl  '\n'
#define MOD1 998244353
#define setbits(x)      __builtin_popcountll(x)
#define leadzerobits(x)      __builtin_clzll(x)
#define trailzerobits(x)      __builtin_ctzll(x)
#define INF 1e18
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932384626
#define sz(x) ((int)(x).size())
#define vs vector<string>
#define token(str,ch)	(std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;)
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}

#ifndef ONLINE_JUDGE
#define debug(x) cout << #x <<" "; _print(x); cout << endl;
#define debugarr(x,n) cout << #x <<" "; _print(x,n); cout << endl;
#else
#define debug(x)
#define debugarr(x,n)
#endif
void _print(ll t) {cout << t;}
//void _print(int t) {cout << t;}
void _print(string t) {cout << t;}
void _print(bool t) {cout << (t ? "True" : "False");}
void _print(char t) {cout << t;}
void _print(lld t) {cout << t;}
void _print(double t) {cout << t;}
void _print(ull t) {cout << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T,class V> void _print(T v[],V n);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(multiset <T> v);
template <class T> void _print(unordered_set <T> v);
template <class T> void _print(unordered_multiset <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(multimap <T, V> v);
template <class T, class V> void _print(unordered_map <T, V> v);
template <class T, class V> void _print(unordered_multimap <T, V> v);
template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.first); cout << ","; _print(p.second); cout << "}";}
template <class T,class V> void _print(T v[],V n) {cout << "[ "; for (V i=0;i<n;i++) {_print(v[i]); cout << " ";} cout << "]";}
template <class T> void _print(vector <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(unordered_set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(unordered_multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(multimap <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(unordered_multimap <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {x += 0x9e3779b97f4a7c15;x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;x = (x ^ (x >> 27)) * 0x94d049bb133111eb;return x ^ (x >> 31);}    
    size_t operator()(uint64_t x) const {static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x + FIXED_RANDOM);}
};
/*------------------------------------------------------------------------------------------------------------------------------------------*/
ll mod(ll x,ll y,ll m);
ll gcd(ll a, ll b) { a = abs(a); b = abs(b);if (b > a) {return __gcd(b, a);} if (b == 0) {return a;} return __gcd(b, a % b);}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return mod(a, b - 2, b);}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (ll i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (ll j = i * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
string to_binary(int n) {string r; while (n != 0) {r = (n % 2 == 0 ? "0" : "1") + r; n /= 2;} return r;}
int ceil(int a, int b) {return (a + b - 1) / b;}
vector<int> getdigits(int n){vector<int>v; while(n){v.push_back(n%10);n/=10;} reverse(all(v)); return v;} //if you do not want zero then add a check
int getsum(vector<int>v){int sum=0;for(int i=0;i<v.size();i++){sum+=v[i];}return sum;}
void basic_sieveOfEra(int n);// Make global array prime[n+1];//gets you all prime numbers upto n
bool isprime_all_of_factors(int x); // change return type as required
vector<pair<int,int>> PrimeFactorization(int x);
int lcm(int a, int b);
int highestPowerOf2(int n);
int count_digit(int number);
void findDivisors(int n);
// int ncr(int n,int r,int m); void InverseofNumber(ll p) ; void factorial(ll p) ; ll Binomial(ll N, ll R, ll p); void InverseofFactorial(ll p);
int MaxSubarraySum(vector<int>v); // can be used if array has negative elements.(KADANE'S Algo.)

/*------------------------------------------------------------------------------------------------------------------------------------------*/
//all global variables
const int N = 100000; // see constraints
// ll factorialNumInverse[N + 1];   //(used in ncr%MOD)
// ll naturalNumInverse[N + 1];
// ll fact[N + 1];



/*-----------------------------------------------------------------------------------------------------------------*/
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}



void solve()
{
    
    
    return;
}



/*-----------------------------------------------------------------------------------------------------------------*/


int32_t main()
{
    fast_io();
    ll testcases=1;ll cse = 0;
    cin >> testcases;
    // InverseofNumber(MOD);InverseofFactorial(MOD);factorial(MOD); 
    while (testcases--)
    {
        //cse++;
        //cout<<"Case #"<<cse<<": ";
        //cout<<fixed<<setprecision(10)<< <<endl;
        solve();
    }
    return 0;
}
/*---------------------------------------------------------------------------------------------------------------*/

ll mod(ll x,ll y,ll m)   //returns (x^y)%m =>it is superset =>if m=inf;we get x^y-->Binary Exponentiation(O(log(y)))
{
    if(y==0) return 1; //base condition
    
    ll temp  = mod(x,y/2,m);

    temp=(temp*temp)%m;

    if(y%2==1) temp=(temp*x)%m;

    return temp;
}
void basic_sieveOfEra(int n)  //gets you all prime numbers upto n  //O(N*log(log(N)))
{
    bool prime[N]; // make it global // Make global array prime[n+1]; // also can use bitset 
    prime[0]=0;
    prime[1]=0;
    for(int i=2;i<=n;i++)
    {
        prime[i]=1;
    }
    for(int i=2;i<=n;i++)
    {
        if(prime[i]==1)
        {
            for(int j=2*i;j<=n;j+=i)
            {
                prime[j]=0;
            }
        }
    }
    //to print 
    // for(int i=0;i<n;i++)
    // {
    //     if(prime[i]==1)
    //     {
    //         cout<<i<<" ";
    //     }
    // }cout<<endl;
}
bool isprime_all_of_factors(int x) // same to get 1)number of factors and 2)print all factors //(see details in Prime_TEST.cpp)
{
    //for checking prime we may break loop if cnt==2;(change return type as required)
    int cnt=0;vector<int>v;
    for(int i=1;i*i<=x;i++)
    {
        if(x%i==0){cnt+=2; /*v.push_back(i);*/}
        // if(i*i==x){cnt--;}
        // if(i*i!=x){v.push_back(x/i);}
        if(cnt>2)
        {
            return false;
        }
    }
    return true; //to check prime

    // return cnt; // returns no. of factors
    // return v; (all factors of x) 
}
vector<pair<int,int>> PrimeFactorization(int x) // we can modify all functions and use them as required
{
    vector<pair<int,int>>v;
    for(int i=2;i*i<=x;i++)
    {
        int count=0;
        while(x%i==0)
        {
            count++;
            x/=i;
        }
        v.push_back({i,count});
    }
    if(x!=1)
    {
        v.push_back({x,1});
    }
    return v;
}
int lcm(int a, int b)
{
    return ((a*b)/gcd(a,b));
}    
int highestPowerOf2(int n)
{
    return (n & (~(n - 1)));
}    
int count_digit(int number)
{
    return int32_t(log10(number) + 1);
}
void findDivisors(int n)
{
    int div[N];        //make array global
    memset(div, 0, sizeof(div));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j * i <= n; j++)
            div[i * j]++;
    }
}
// void InverseofNumber(ll p)
// {
//     naturalNumInverse[0] = naturalNumInverse[1] = 1;
//     for (int i = 2; i <= N; i++)
//         naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
// }
// void InverseofFactorial(ll p)
// {
//     factorialNumInverse[0] = factorialNumInverse[1] = 1;
//     for (int i = 2; i <= N; i++)
//         factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
// }
// void factorial(ll p)
// {
//     fact[0] = 1;
//     for (int i = 1; i <= N; i++) {
//         fact[i] = (fact[i - 1] * i) % p;
//     }
// }
// ll Binomial(ll N, ll R, ll p)
// {
//     // n C r = n!*inverse(r!)*inverse((n-r)!)
//     ll ans = ((fact[N] * factorialNumInverse[R])% p * factorialNumInverse[N - R])% p;
//     return ans;
// }
// int ncr(int n,int r,int m)
// {
//     return Binomial(n,r,m);
// }

int MaxSubarraySum(vector<int>v)
{
    int max_sum = LLONG_MIN;
    int cur_sum=0;
    for(int i=0;i<v.size();i++)
    {
        cur_sum = cur_sum + v[i];
        if(cur_sum>max_sum)
        {
            max_sum = cur_sum;
        }  
        if(cur_sum<0)
        {
            cur_sum=0;
        }  
    }
    return max_sum;
}

// int nCr1(int n, int r) // use if it's given overflow will not happen(and modulo not needed) and N<=10^5 --> O(min(r,n-r)*Q).
// {
//     int ans=1;
//     for(int i=1;i<=min(r,n-r);i++)
//     {
//         ans = ((ans * (n-i+1))/i);
//     }
//     return ans;
// }

// int nCr2(int n, int r) // use if it's given overflow will not happen(and modulo not needed) and N is small --> O(n+Q).
// {
//     // int ans=1;
//     // vector<int> fact(n+1,1); // --> make it global 

//     /*  call precompute() function before all T.C.
//     void precompute()
//     {
//         for(int i=1;i<=n;i++)
//         {
//             fact[i] = fact[i-1]*i;
//         }
//     }
//     */
//     ans = fact[n]/(fact[r]*fact[n-r]);
//     return ans;
// }


// int nCr3(int n, int r,int p) // use when %mod and N is big --> O(n+Q). (slight more optimised than striver, see ug)
// {
//     // vector<int>fact(N+1);
//     // vector<int>factorialNumInverse(N+1);   
//     // vector<int>naturalNumInverse(N+1);  // --> make it global
    
//     /* call precompute() function before all T.C.
//     void precompute(int p) // n -> max. value of n in constraints , p = MOD 
//     {
        
        
//         // step - 1
//         fact[0] = 1;
//         for (int i = 1; i <= N; i++) 
//         {
//             fact[i] = (fact[i - 1] * i) % p;
//         }

//         // step-2
//         naturalNumInverse[0] = 1; naturalNumInverse[1] = 1;
//         for (int i = 2; i <= N; i++)
//         {
//             naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
//         }

//         // step-3
//         factorialNumInverse[0] = 1; factorialNumInverse[1] = 1;
//         for (int i = 2; i <= N; i++)
//         {
//             factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
//         }
//     }
//     */

//     // nCr = n!*inverse(r!)*inverse((n-r)!)
//     ll ans = (((fact[n] * factorialNumInverse[r])% p) * factorialNumInverse[n - r])% p;
//     return ans;
// }