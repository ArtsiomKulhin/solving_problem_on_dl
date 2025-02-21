#include <bits/stdc++.h>
#define en '\n'
#define int int64_t
#define F first
#define S second
#define pb push_back
//typedef long long int  lli;
using namespace std;
int32_t main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
int n ;
cin >> n ;
int a[n] ;
for(int i = 0 ; i < n; ++i){
    cin >> a[i] ;
}
int k = 1  ;
for(int i = 1 ; i < n ; ++i){
    if(a[0] == a[i]){
        ++k ;
    }
}
cout << n-k ;
}
