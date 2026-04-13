#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//FACTORS
vector<ll> factors(ll n){
	vector<ll> ans;
	for(ll i = 1; i < sqrt(n); ++i){
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
	for(ll i = 3; i < sqrt(n); i += 2){
		while(n % i == 0){
			++ans[i];
			n /= i;
		}
	}
	if(n == 1) return ans;
	++ans[n];
	return ans;
}
//GRAPHS
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
//DIJKSTRA
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
int main(){
	//ios_base::sync_with_stdio(false); cin.tie(NULL);
	/*
	for(ll i = 9990; i <= 11000; i += 10){
		cout << i << " x val: ";
		string str = to_string(i);
		ll sum = 0;
		for(char c : str){
			sum += c - '0';
		}
		cout << i - sum << " sum = " << sum << endl;
	}
	*/
	ll t = 1;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll ans = 0;
		for(ll i = n + 1; i < n + 100; ++i){
			string str = to_string(i);
			ll sum = 0;
			for(char c : str){
				sum += c - '0';
			}
			if(i - sum == n){
				++ans;
			}
		}
		cout << ans << endl;
	}
}
