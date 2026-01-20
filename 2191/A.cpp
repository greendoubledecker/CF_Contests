#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Card{
	int n;
	bool red;
};

bool cmp(Card a, Card b){
	return a.n < b.n;
}

int main(){
	int t;
	cin >> t;
	while(t--){	
		int n;
		cin >> n;
		vector<Card> v(n);
		for(int i = 0; i < n; ++i){
			cin >> v[i].n;
			v[i].red = i % 2 == 0;
		}
		sort(v.begin(), v.end(), cmp);
		bool works = true;
		for(int i = 1; i < n; ++i){
			if(v[i].red == v[i-1].red){
				works = false;
				break;
			}
		}
		if(works){
			cout << "yes" << endl;
		}else{
			cout << "no" << endl;
		}
	}
}
