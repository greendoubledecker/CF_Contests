#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#define lli long long

using namespace std;

struct Elf{
	lli a;
	lli h;
	lli index;
};

bool cmp(Elf a, Elf b){
	return a.a < b.a;
}

void tc(){
	lli n, m;
	cin >> n >> m;
	vector<Elf> elves(n);
	for(lli i = 0; i < n; ++i){
		elves[i].index = i;
		cin >> elves[i].a;
		elves[i].h  = elves[i].a;
	}
	if(m > n / 2){
		cout << -1 << endl;
		return;
	}
	sort(elves.begin(), elves.end(), cmp);
	if(m == 0){
		lli sum = 0;
		for(lli i = 0; i < n - 1; ++i){
			sum += elves[i].a;
		}
		if(sum < elves[n - 1].a){
			cout << -1 << endl;
			return;
		}
		sum = 0;
		for(int i = n - 2; i >= 0; --i){
			sum += elves[i].a;
			if(sum >= elves[n - 1].h){
				cout << n - 1 << endl;
				for(int j = 0; j < i; ++j){
					cout << elves[j].index + 1 << " " << elves[j + 1].index + 1 << endl;
				}
				for(int j = i; j < n - 1; ++j){
					cout << elves[j].index + 1 << " " << elves[n - 1].index + 1 << endl;
				}
				return;
			}
		}
	}else{
		lli num = m - 1;
		num += n - 1 - (2 * (m - 1));
		cout << num << endl;
		for(lli i = 0; i < m - 1; ++i){
			cout << elves[2 * i + 1].index + 1 << " " << elves[2 * i].index + 1 << endl;
		}
		for(lli i = 2 * (m - 1); i < n - 1; ++i){
			cout << elves[i + 1].index + 1 << " " << elves[i].index + 1 << endl;
		}
	}
	return;
}

int main(){
	lli t;
	cin >> t;
	for(lli i = 0; i < t; ++i){
		tc();
	}
	return 0;
}
