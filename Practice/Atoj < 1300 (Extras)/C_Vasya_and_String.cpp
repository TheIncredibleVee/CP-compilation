#pragma GCC optimize("O3")  //https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html  (0fast alternative, but more aggressive)
#include <bits/stdc++.h>    
#include<ext/pb_ds/assoc_container.hpp> //Policy based Data Structrues containter
#include<ext/pb_ds/tree_policy.hpp> //Ordered set
#define gcj "Case #"    //For Kickstart 
#define adj_list vector<vi> // Adjacency list
#define endl "\n"
#define spc " "
#define INF_INT 2e9
#define INF_LL 2e18
#define matmax 25
#define mod 1000000007
#define PI 3.14159265
#define mp make_pair
#define pb push_back
#define pi pair<int, int>
#define pip pair<int,pi>
#define pl pair<ll,ll>
#define plp pair<ll,pl>
#define vi vector<int>
#define vl vector<ll>
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define ins insert
#define lb lower_bound  // First element NOT LESS than val
#define ub upper_bound  // First element GREATER than val
#define sz(q) (int)(q.size())
#define ook order_of_key  // Number of elements STRICTLY smaller than X
#define fbo find_by_order  //  *ITERATOR* pointing to the kth element (0 order)
#define VEC_INP ll n; cin>>n; vl a(n);fo(0, n){cin>>a[i];};

#define fo(a,b) for(auto i=a;i<b;++i)
#define nfo(a,b) for(auto i=a;i>=b;--i)
#define jfo(a,b) for(auto j=a;j<b;++j)
#define njfo(a,b) for(auto j=a;j>=b;--j)
#define tt ll t; cin>>t; while(t--)

using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;
typedef long int li;
 
string to_string(bool b) { return b ? "1" : "0"; }
string to_string(char c) { return string(1, c); }
string to_string(string s) { return s; }


template<typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

template<typename T>
ostream& operator<<(ostream& os, vector<T>& intermediate_array) { for (auto& a : intermediate_array) cout << a << ' '; return os; }
template<typename T>
istream& operator>>(istream& is, vector<T>& intermediate_array) { for (auto& a : intermediate_array) cin >> a; return is; }
template<typename T>
void print(T a) { cout << a << endl; }
template<typename T, typename... Args>
void print(T a, Args... b) { cout << a << " "; print(b...); } 
template<typename T>
void _debug(T a) {
    if (typeid(a) == typeid(char)) cout << '\'';
    if (typeid(a) == typeid(string)) cout << '\"';
    cout << a;
    if (typeid(a) == typeid(char)) cout << '\'';
    if (typeid(a) == typeid(string)) cout << '\"';
    cout << "]" << endl;
}
template<typename T, typename... Args>
void _debug(T a, Args... b) {
    if (typeid(a) == typeid(char)) cout << '\'';
    if (typeid(a) == typeid(string)) cout << '\"';
    cout << a;
    if (typeid(a) == typeid(char)) cout << '\'';
    if (typeid(a) == typeid(string)) cout << '\"';
    cout << ",\t";
    _debug(b...);
}
template<typename... Args>
void debug(Args... b) { cout << '['; _debug(b...); }

void swap(ll &x,ll &y){
	ll temp = y;
	y = x;
	x = temp;
}

ll powa(ll a, ll b, ll m = mod){
	if (b == 0)
		return 1ll;
	else if (b == 1)
		return a;
	else
	{
		ll x = powa(a, b/2, m);
		x *= x;
		// x %= m;
		if (b%2)
		{
			x *= a;
			// x %= m;
		}
		return x;
	}
}

bool check_prime(ll n){
    if(n==1)
        return false;
    if(n==2 || n==3 || n==5 || n==7)
        return true;
    for(ll i=2; i*i<=n; i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

string dectobin(ll n)
{
    string s = bitset<64> (n).to_string();
    const auto loc1 = s.find('1');
    if(loc1 != string::npos)
        return s.substr(loc1);
    return "0";
}

string replaceall(string s, string &from, string to){
	ll idx = 0;
	while((idx = s.find(from,idx)) != string::npos){
		s.replace(idx, from.length(), to);
		idx += to.length();				// Incase to is a substring of from, so that the there is no infinite loop
	}
	return s;
}

ll ans(vl&a, ll n, ll k){
    ll start = 0;
    vl pre_sum(n + 1);
    ll sum = 0;
    fo(1,n + 1){
        sum += a[i - 1];
        pre_sum[i] = sum;
    }    
    ll res = 0;
    fo(0, n + 1){
        if(i == pre_sum[i]){
            res = i;
            continue;
        }
        ll curr_sum = pre_sum[i] - pre_sum[start];
        ll cnt = i - start;
        if(curr_sum + k >= cnt){
            res = max(res, cnt);
            continue;
        }
        while(start <= i && curr_sum + k < cnt){
            start++;
            curr_sum = pre_sum[i] - pre_sum[start];
            cnt = i - start;
        }
        res = max(res, cnt);
    }
    return res;
}

void solve(){
    ll n, k;
    cin>>n>>k;
    vl a(n), b(n);
    char c;
    fo(0, n){
        cin>>c;
        if(c == 'b'){
            a[i] = 1;
        }else{
            b[i] = 1;
        }
    }
    
    print(max(ans(a,n,k), ans(b,n,k)));
    return;
}

int main(){
	fastio
	solve();
}
