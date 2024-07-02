#include<bits/stdc++.h>
using namespace std;

vector<int> build_lps(vector<int>&LPS , string p){
    int pre = 0 , suf = 1;
    while(suf < p.size()){
        if(p[pre] == p[suf]){
            LPS[suf++] = ++pre;
        }else{
            pre == 0 ? suf++ : pre = LPS[pre-1];
        }
    }
    return LPS;
}

bool KMP(vector<int>LPS , string t , string p){
    int first = 0 , second = 0;
    while(first < t.size()){
        if(t[first] == p[second]){
            first++ , second++;
        }else{
            second == 0 ? first++ : second = LPS[second-1];
        }
        if(second == p.size()) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    string text , pattern; cin >> text >> pattern;
    vector<int>LPS(pattern.size() , 0);
    LPS = build_lps(LPS , pattern);
    KMP(LPS , text , pattern) ? cout<<"Found" : cout<<"Not Found";

    return 0;
}