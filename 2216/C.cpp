#include <bits/stdc++.h>
using namespace std;
using  ll = long long;
//DSU
vector<ll> parent;
vector<ll> sz;
ll find(ll ind){
	if(parent[ind] == ind){
		return ind;
	}else{
		return find(parent[ind]);
	}
}
bool merge(ll a, ll b){
	ll rootA = find(a), rootB = find(b);
	if(rootA == rootB){
		return false;
	}
	if(sz[rootA] > sz[rootB]){
		sz[rootA] += sz[rootB];
		parent[rootB] = rootA;
	}else{
		sz[rootB] += sz[rootA];
		parent[rootA] = rootB;
	}
	return true;
}
//FACTORS
vector<ll> factors(ll n){
	vector<ll> ans;
	for(ll i = 1; i < sqrt(n); ++i){ //O(sqrt(n))
		if(n % i == 0){
			ans.push_back(i);
			ans.push_back(n / i);
		}
	}
	if((ll)sqrt(n) * (ll)sqrt(n) == n){
		ans.push_back(sqrt(n));
	}
	return ans;
}
map<ll, ll> primeFactorize(ll n){
	map<ll, ll> ans;
	while(n % 2 == 0){
		++ans[2];
		n /= 2;
	}
	for(ll i = 3; i * i <= n; i += 2){
		while(n % i == 0){
			++ans[i];
			n /= i;
		}
	}
	if(n == 1) return ans;
	++ans[n];
	return ans;
}
//GRAPH
struct Node{
	ll index = 0;
	ll dist = 1'000'000'000'000'000'000LL;
	vector<pair<Node*, ll>> connections;
	bool finalised = false;
};
void connect(Node* a, Node* b, ll cost){
	a -> connections.push_back({b, cost});
}
void bidirConnect(Node* a, Node* b, ll cost){
	a -> connections.push_back({b, cost});
	b -> connections.push_back({a, cost});
}
struct Compare{
	bool operator()(const Node* n1, const Node* n2){
		return n1 -> dist > n2 -> dist;
	}
};
void dijkstra(Node* start){
	priority_queue<Node*, vector<Node*>, Compare> pq;
	start -> dist = 0;
	pq.push(start);
	while(!pq.empty()){
		Node* cur = pq.top();
		pq.pop();
		if(cur -> finalised){
			continue;
		}else{
			cur -> finalised = true;
			for(pair<Node*, ll> &edge : cur -> connections){
				Node* next = edge.first;
				if(!next -> finalised && cur -> dist + edge.second < next -> dist){
					next -> dist = cur -> dist + edge.second;
					pq.push(next);
				}
			}
		}
	}
}
//END

void tc(){
	ll n, k, p, q;
	cin >> n >> k >> p >> q;
	vector<ll> pqval(n), qpval(n);
	ll minn = 0;
	for(ll i = 0; i < n; ++i){
		ll x;
		cin >> x;
		pqval[i] = (x % p) % q;
		qpval[i] = (x % q) % p;
		minn += min(pqval[i], qpval[i]);
	}
	vector<ll> ps_pq(n + 1);
	ps_pq[0] = 0;
	for(ll i =1; i <= n; ++i){
		ps_pq[i] = ps_pq[i - 1] + pqval[i - 1];
		//cout << "ps_pq: " << ps_pq[i] << endl;
	}
	vector<ll> ps_qp(n + 1);
	ps_qp[0] = 0;
	for(ll i =1; i <= n; ++i){
		ps_qp[i] = ps_qp[i - 1] + qpval[i - 1];
		//cout << "ps_qp: " << ps_qp[i] << endl;
	}
	vector<ll> minps(n + 1);
	minps[0] = 0;
	for(ll i = 1; i <= n; ++i){
		minps[i] = minps[i - 1] + min(qpval[i - 1], pqval[i - 1]);
		//cout << "minps: " << minps[i] << endl;
	}
	ll ans = 1e15;
	for(ll i = 0; i + k <= n; ++i){
		ll minval = minps[i + k] - minps[ i];
		ll qpsum = ps_qp[i + k] - ps_qp[i];
		ll pqsum = ps_pq[i + k] - ps_pq[i];
		ans = min(ans, minn - minval + min(qpsum,pqsum));
	}
	cout << ans << endl;
}

int main(){
	ll t = 1;
	cin >> t;
	while(t--){
		tc();
	}
}
