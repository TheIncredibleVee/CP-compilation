#include<bits/stdc++.h>    
#define ll long long
using namespace std;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, k, x,sum = 0;
        cin>>n>>k>>x;
        if(x < 0){
            k = n - k;
            x *= -1;
        }
        vector<ll> a(n);
        for(ll i = 0 ; i < n; ++i){
            cin>>a[i];
            sum += a[i];
        }
        ll curr = 0;
        ll res = 0;
        for(ll i = 0 ; i < k; ++i){
            curr += a[i];
        }
        res = curr;
        for(ll i = k ; i < n; ++i){
            curr += a[i];
            curr -= a[i-k];
            res = max(res, curr);
        }
        res = max(0ll, res + (k * x));
        res = max(res, sum + (k*x) - ((n-k)*x));
        cout<<res<<endl;
    }
}
