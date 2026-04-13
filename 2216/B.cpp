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
	ll t,h,u;
	cin >> t >> h >> u;
	ll ans = 0;
	ll minn = min(t, u);
	ans += 4 * minn;
	t -= minn;
	u -= minn;
	if(t == 0){
		cout << ans + 3*h + 3*u << endl;
	}else{
		ll tht = min(t/2, h);
		ans += 7 * tht;
		t -= 2*tht;
		h -= tht;
		//cout << "ans " << ans << endl;
		ll th = min(t, h);
		ans += 5 * th;
		t -= th;
		h -= th;
		if(t){
			ans += 2 * t + 1;
		}
		cout << ans + 3*h << endl;
	}
}

int main(){
	ll t = 1;
	cin >> t;
	while(t--){
		tc();
	}
}
