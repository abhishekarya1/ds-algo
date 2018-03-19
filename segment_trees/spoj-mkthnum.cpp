//TODO http://www.spoj.com/problems/MKTHNUM/

#include <bits/stdc++.h>
using namespace std;
/*ONLY FOR GNU*/
#include <ext/pb_ds/assoc_container.hpp>    // Common file
#include <ext/pb_ds/tree_policy.hpp>        // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
/* tree.find_by_order(i) == gives element at ith position in tree
 tree.order_by_key(val)== gives iterator to upper_bound(x)*/
/* GNU SPECIFIC ENDS*/

const int inf           = 1<<28;
const int D             = (int)1e6+5;
typedef long long       lli;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<vi>      vvi;
typedef vector<bool>    vb;
#define sc              scanf               /*remember that %c %n %[] does NOT consume whitespaces*/
#define scd(a)          scanf("%d", &a)
#define scs(a)          scanf("%s", a)
#define prd(a)           printf("%d\n", a)
#define freq            first
#define val             second
#define pb(a)           push_back(a)
#define all(a)          a.begin(),a.end()
void inputVec(vi&v)     {for (auto&i : v)scd(i);}
void printVec(vi&v)     {for (auto&i : v)prd(i);}
void printMat(vvi& mat) {for (auto&v : mat) {for (auto&x : v)cout << x << " ";} cout << endl;}
int left(int i)         {return i << 1;}
int right(int i)        {return (i << 1) + 1;}
int mid(int a, int b)   {return (a + b) >> 1;}
int mid1(int a, int b)  {return ((a+b)>>1)+1;}
void iofile()           {freopen(R"(../in)", "r", stdin);freopen(R"(../out)", "w", stdout);}
int n,q;
/*************************/
vi v, klone, t[4*D];

void build(int root, int be, int en){
    if (be > en){
        return;
    }
    if (be == en){
        t[root].push_back(v[be]);
        return;
    }
    build(left(root), be, mid(be, en));
    build(right(root), mid1(be, en), en);
    merge(all(t[left(root)]), all(t[right(root)]), back_inserter(t[root]));
}

int query(int root, int be, int en, int i, int j, int k){
    // no of elements smaller than k
    if (be > en or i > en or j < be) return 0;
    if (i <= be && j >= en){
        return t[root].end() - lower_bound(all(t[root]), k);
    }
    int q1 = query(left(root), be, mid(be, en), i, j, k);
    int q2 = query(right(root), mid1(be, en), en, i, j, k);
    return q1 + q2;
}

int query(int i, int j, int k){
    while(i <= j){
        int m = mid(i, j);
        int no_of_smaller_elements = query(1, 0, n-1, i, j,klone[m]);
        if (no_of_smaller_elements == k) {
            return klone[m];
        }
        else if (no_of_smaller_elements < k){
            i = m + 1;
        }
        else {
            j = m - 1;
        }
    }
    return -1;
}


int main(){
    iofile();
    scd(n);
    scd(q);
    v.resize(n);
    inputVec(v);
    copy(all(v), back_inserter(klone));
    sort(all(klone));
    int l,r,k;
    build(1, 0, n-1);
    for(int i = 0; i < q; ++i){
        sc("%d %d %d", &l, &r, &k);
        prd(query(l-1, r-1, k));
    }
    return 0;
}