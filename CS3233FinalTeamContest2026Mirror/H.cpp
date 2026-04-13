#include <bits/stdc++.h> //WA13
using namespace std;
using  ll = long long;
using ld = long double;
ld pi = 3.141592653589793238462643383279L;
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

ld topolar(ll x, ll y){
	return (atan2l(x,y) + pi) / pi / 2;
}

void tc(){
	ll n,q;
	cin >> n >> q;
	vector<ld> polar(n);
	bool AAAAAAAAAH = false;
	for(ll i = 0; i < n; ++i){
		ll x,y;
		cin >> x >> y;
		if(x == 0 && y == 0){
			AAAAAAAAAH = true;
		}
		polar[i] = topolar(x,y);
	}
	if(AAAAAAAAAH){
		while(q--){
			ll jkher, gyjef;
			cin >> jkher >> gyjef;
			cout << "1\n";
		}
		return;
	}
	vector<pair<ld, ll>> v(n + 2);
	for(ll i = 1; i <= n; ++i){
		v[i] = {polar[i - 1], i - 1};
	}
	sort(v.begin() + 1, v.end() - 1);
	v[0] = {v[v.size() - 2].first - 1, v[v.size() - 2].second};
	v[v.size() - 1] = {v[1].first + 1, v[1].second};
	vector<ld> polar2(n + 2);
	for(ll i = 0; i < n + 2; ++i){
		polar2[i] = v[i].first;
		//cout << "coord: " << polar2[i] << endl;
		//cout << "index: " << v[i].second << endl;
	}
	while(q--){
		ll x,y;
		cin >> x >> y;
		if(x == 0 && y == 0){
			cout << "1\n";
			continue;
		}
		ld pol = topolar(x,y);
		//cout << "pol = " << pol << endl;
		auto it = lower_bound(polar2.begin(), polar2.end(), pol);
		ll r = it - polar2.begin();
		ll l = r - 1;
		//cout << l << " = l, r = " << r <<endl;
		if(abs((polar2[r] - pol) - (pol - polar2[l])) <= 1e-12){
			if(v[l].second < v[r].second){
				cout << v[l].second + 1 << '\n';
			}else{
				cout << v[r].second + 1 << '\n';
			}
		}else if(polar2[r] - pol > pol - polar2[l]){
			//cout << "l closer\n";
			cout << v[l].second + 1 << '\n';
		}else if(polar2[r] - pol < pol - polar2[l]){
			//cout << "r closer\n";
			cout << v[r].second + 1 << '\n';
		}else{
			cerr << "nothing should go here...i think...\n";
		}
	}
	cout << flush;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll t = 1;
	//cin >> t;
	while(t--){
		tc();
	}
}
