#include <bits/stdc++.h> //AC
using namespace std;
using  ll = long long;
//DSU
vector<ll> parent;
vector<ll> sz;
ll find(ll ind){
	if(parent[ind] == ind){
		return ind;
	}else{
		parent[ind] = find(parent[ind]);
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
	//ll dist = 1'000'000'000'000'000'000LL;
	vector<Node*> connections;
	//bool finalised = false;
	ll comp = -1;
};
void bidirConnect(Node* a, Node* b){
	a -> connections.push_back(b);
	b -> connections.push_back(a);
}
/*
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
*/
void dfs(Node* start){
	for(Node* n : start -> connections){
		if(n -> comp != -1) continue;
		n -> comp = start -> comp;
		dfs(n);
	}
}
//END

void tc(){
	ll n,m;
	cin >> n >> m;
	vector<ll> weight(n);
	vector<ll> buyer(n);
	for(ll i = 0; i < n; ++i){
		cin >> weight[i];
	}
	for(ll i = 0; i < n; ++i){
		cin >> buyer[i];
	}
	vector<Node*> nodes(n);
	for(ll i = 0; i < n; ++i){
		nodes[i] = new Node;
		nodes[i] -> index = i;
	}
	for(ll i = 0; i < m; ++i){
		ll a,b;
		cin >> a >> b;
		bidirConnect(nodes[a-1], nodes[b-1]);
	}
	for(ll i = 0; i < n; ++i){
		if(nodes[i] -> comp == -1){
			nodes[i] -> comp = nodes[i] -> index;
			dfs(nodes[i]);
		}
	}
	vector<vector<Node*>> components(n);
	for(ll i = 0; i < n; ++i){
		components[nodes[i] -> comp].push_back(nodes[i]);
	}
	ll sum = 0;
	for(ll i = 0; i < n; ++i){
		vector<ll> costs;
		for(ll j = 0; j < components[i].size(); ++j){
			costs.push_back(buyer[components[i][j] -> index]);
		}
		vector<ll> bars;
		for(ll j = 0; j < components[i].size(); ++j){
			bars.push_back(weight[components[i][j] -> index]);
		}
		sort(costs.begin(), costs.end());
		sort(bars.begin(), bars.end());
		for(ll j = 0; j < components[i].size(); ++j){
			sum += costs[j] * bars[j];
		}
	}
	cout << sum << endl;
}

int main(){
	ll t = 1;
	//cin >> t;
	while(t--){
		tc();
	}
}
