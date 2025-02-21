#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,mmx,abm,avx,avx2,fma")
#define en '\n'
#define int int64_t
#define ll long long
#define pb push_back
#define F first
#define S second
#define m_k make_pair
using namespace std;
/*
const int MAXN = 1005 ;
int p[MAXN][MAXN],a[MAXN][MAXN] ;
int get(int x2, int y2, int x1, int y1) {
    return p[x2][y2]-p[x2][y1-1]-p[x1-1][y2]+p[x1-1][y1-1];
}
*/
int sx,sy,ex,ey ;
bool mar[8][8],f ;
queue<int>X,Y,SN ;
void start(){
string s,s1;
getline(cin,s) ;
getline(cin,s1) ;
sx = int(s[0])-int('a') ;
sy = int(s[1])-int('1') ;
ex = int(s1[0])-int('a') ;
ey = int(s1[1])-int('1') ;
for(int i = 0 ; i < 8 ; ++i){
    for(int j = 0 ; j < 8 ; ++j){
        mar[i][j] = false ;
    }
}
X.push(sx); Y.push(sy); SN.push(0) ;
}
void BFS(int x, int y, int sn, bool &f){
    int st[8][2] = {{1,1},{-1,-1},{-1,1},{1,-1},{-2,0},{2,0},{0,2},{0,-2}} ;
    f = false ;
    for(int i = 0 ; i < 8 && !f ; ++i){
        int cx = x+st[i][0] ;
        int cy = y+st[i][1] ;
        f = (ex == cx) && (ey == cy) ;
        if((cx >= 0) && (cx < 8) && (cy >= 0) && (cy < 8) && (!mar[cx][cy])){
        X.push(cx); Y.push(cy); SN.push(sn) ;
        mar[cx][cy] = true ;
        }
    }
}
void solve(){
start();
f = (sx == ex) && (sy == ey) ;
while(!f && !X.empty()){
    int x = X.front(); X.pop();
    int y = Y.front(); Y.pop();
    int sn = SN.front(); SN.pop();
    ++sn ;
    BFS(x,y,sn,f);
}
if(f){
    cout << "YES" ;
}
else{
    cout << "NO" ;
}
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
     freopen("CHESS.in","r",stdin);
     freopen("CHESS.out","w",stdout);
// int t ; cin >> t ;
 //   for(int i = 0 ; i < t ; ++i){
     solve();
 //   }
}


