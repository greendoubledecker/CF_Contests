#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void tc(){
	int n;
	cin >> n;
	vector<int> children(n);
	for(int i = 0; i < n; ++i){
		cin >> children[i];
	}
	long long score1 = 0; //0 - - - - -
	for(int i = 1; i < n; ++i){
		score1 -= children[i];
	}
	long long score2 = children[0];  //+ 0 - - - - -
	for(int i = 2; i < n; ++i){
		score2 -= children[i];
	}
	long long maxx = score2;
	for(int i = 2; i < n; ++i){
		score2 += children[i];
		score2 += abs(children[i - 1]);
		if(score2 > maxx){
			maxx = score2;
		}
	}
	if(score1 > maxx){
		maxx = score1;
	}
	cout << maxx << endl;
}

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		tc();
	}
}
