#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int mod = 1e9 + 7;
const int p = 73;
const int N = 1e5 + 9;
int power[N];

void precalc(){
	power[0] = p;
	for(int i = 1 ; i < N;i++){
		power[i] = (1ll * power[i-1] * p) % mod;
		power[i] %= mod;
	}
}

int get_hash(string s){
	int hash_val = 0;
	for(int i = 0 ; i < s.size();i++){
		hash_val += (1ll * power[i] * (int)s[i] - 137) % mod;
		hash_val %= mod;
	}
	return hash_val;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precalc();

    string s; cin >> s;
    cout<<get_hash(s)<<endl;

    return 0;
}