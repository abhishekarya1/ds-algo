// TODO http://www.spoj.com/problems/POSTERS/
#include <bits/stdc++.h>
using namespace std;
const int inf           = 1<<28;
const int D             = (int)1e6+5;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<vi>      vvi;
typedef vector<bool>    vb;
typedef long long       lli;
void inputVec(vi&v)     {for (auto&i : v)cin >> i;}
void printVec(vi&v)     {for (auto&i : v)cout << i << " "; cout << endl;}
void printMat(vvi& mat) {for (auto&v : mat) {for (auto&x : v)cout << x << " ";} cout << endl;}
int left(int i)         {return i << 1;}
int right(int i)        {return (i << 1) + 1;}
int mid(int a, int b)   {return (a + b) >> 1;}
int mid1(int a, int b)  {return ((a+b)>>1)+1;}
void iofile()           {freopen(R"(../in)", "r", stdin);};
#define sc              scanf
#define scd(a)          scanf("%d", &a)
#define scs(a)          scanf("%s", a)
#define pr(a)           printf("%d\n", a)
#define freq            first
#define val             second
#define pb(a)           push_back(a)
#define all(a)          a.begin(),a.end()
/*************************/

int main(){

}