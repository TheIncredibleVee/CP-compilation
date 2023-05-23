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

void solve(){
    ll t;
    ll x1, x2, y1, y2;
    cin>>t>>x1>>y1>>x2>>y2;
    vector<char> a(t);
    fo(0,t){
        cin>>a[i];
    }    
    ll n = 0, s= 0, e = 0, w =0;
    ll dx = x2 - x1;
    ll dy = y2 - y1;
    if(dx< 0){
        w+= abs(dx);
    }else{
        e += abs(dx);
    }
    if(dy < 0){
        s += abs(dy);
    }else{
        n += abs(dy);
    }
    if(dx == 0 && dy == 0){
        print(0);
        return;
    }
    fo(0, t){
        if(a[i] == 'N' && n){
            n--;
        }
        if(a[i] == 'S' && s) s--;
        if(a[i] == 'E' && e) e--;
        if(a[i] == 'W' && w) w--;
        if(!(w + e + s + n)){
            print(i + 1);
            return;
        }
    }
    if(!(n + s + e + w)){
        print(t + 1);
        return;
    }
    print(-1);
    return;
}

int main(){
	fastio
	solve();
}