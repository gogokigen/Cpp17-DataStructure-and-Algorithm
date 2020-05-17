#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

// constraint, global definition


void solve() {
	
	int N = 0, K = 0;
	cin >> N >> K;

	vector <int> arr(N,0);
	for(int i = 0; i < N; i++){
	    cin >> arr[i];
	}

    int ret = 0;
    for(int i = 0; i < N - K + 1; i++){
        if(arr[i] == K){
            bool tmp = true;
            for(int j = i; j < i + K - 1; j++){
                if(arr[j + 1] != arr[j] - 1){
                    tmp = false;
                    break;
                }
            }
            if(tmp == true){
                ret++;
            }
        }
    }

    // the output of # i 
	cout << ret << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int testNumbers, i=1;
    
    // 1st line: test number
	cin >> testNumbers;
	while(testNumbers--) {
		cout << "Case #" << i << ": ";
		solve();
		++i;
	}
}