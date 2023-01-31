#include <bits/stdc++.h>    
#define endl "\n"
using namespace std;
typedef long long int ll;
void func(){
    ll a1,a2,a3,a4; cin>>a1>>a2>>a3>>a4;
    ll alice = a1, bob = a1;
    ll ans = a1, curr = 0;
    while((a2 || a3) && (alice || bob)){
        if(alice && a2){
            curr = min(alice, a2);
            ans += curr;
            alice -= curr;
            bob += curr;
            a2 -= curr;
        }else if(bob && a3){
            ll curr = min(bob, a3);
            ans += curr;
            bob -= curr;
            alice += curr;
            a3 -= curr;
        }else{
            break;
        }
    }
    if(min(alice, bob) == 0){
        if( a2 || a3 || a4 ){
            ans++;
            cout<<ans<<endl;
            return;
        }
    }
    if(a4){
        ans += min(a4, (min(alice, bob))+ 1);
    }
    cout<<ans<<endl;
    return;
}

int main(){
	ll t;
    cin>>t;
    while(t--){
        func();
    }
}
