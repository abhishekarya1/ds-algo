// https://blog.anudeep2011.com/mos-algorithm/
/*Given an array of size N. All elements of array <= N. You need to answer M queries. Each query is of the form L, R. You need to answer the count of values in range [L, R] which are repeated at least 3 times.
Example: Let the array be {1, 2, 3, 1, 1, 2, 1, 2, 3, 1} (zero indexed)
Query: L = 0, R = 4. Answer = 1. Values in the range [L, R] = {1, 2, 3, 1, 1} only 1 is repeated at least 3 times.
Query: L = 1, R = 8. Answer = 2. Values in the range [L, R] = {2, 3, 1, 1, 2, 1, 2, 3} 1 is repeated 3 times and 2 is repeated 3 times. Number of elements repeated at least 3 times = Answer = 2.*/

#include <bits/stdc++.h>
using namespace std;
/*ONLY FOR GNU*/
#include <ext/pb_ds/assoc_container.hpp>    // Common file
#include <ext/pb_ds/tree_policy.hpp>        // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
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
#define sc              scanf           /*remember that %c %n %[] does NOT consume whitespaces*/
#define scd(a)			scanf("%d", &a)
#define scs(a)          scanf("%s", a)
#define prd(a)          printf("%d\n", a)
#define fr              first
#define sec             second
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
/*************************/
int n, q;
vi v, freq;
vector<ii> queries;

struct Compare{
	int rootn;
	Compare(int n){
		rootn = ceil(sqrt(n));
	}
	bool operator()(const ii&a, const ii& b){
		int b1 = a.fr/rootn;
		int b2 = b.fr/rootn;
		if (b1 == b2){
			return a.sec < b.sec;
		}
		return  b1 < b2;
	}
};

vi cntLessThree(){
	int i = 0, j = 0;
	int freq[D] = {};    	// TODO : what if I cant create an array
	int ans = 0;
	vi qans;

	for (int k = 0; k < queries.size(); ++k) {
		int l = queries[k].fr;
		int r = queries[k].sec;

		// handling l pointer
		while(i < l){
			--freq[v[i]];
			if (freq[v[i]] == 2) --ans;
			++i;
		}
		while(i > l){
			++freq[v[i]];
			if (freq[v[i]] == 3) ++ans;
			--i;
		}

		// handling r pointer
		while(j < r){
			++freq[v[j]];
			if (freq[v[j]] == 3) --ans;
			++j;
		}
		while(j > r){
			--freq[v[j]];
			if (freq[v[j]] == 2) --ans;
			--j;
		}
		qans.push_back(ans);
	}
}

int main(){
	scd(n);
	scd(q);
	v.resize(n);
	queries.resize(q);
	inputVec(v);
	vi pos;
	for (int i = 0; i < q; ++i) {
		sc("%d,%d", &queries[i].fr, &queries[i].sec);   // TODO : queries order has to be maintained
	}
	sort(all(queries), Compare(n));
	vi ans = cntLessThree();
	printVec(ans);
}