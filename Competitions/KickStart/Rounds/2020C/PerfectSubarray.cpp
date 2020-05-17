#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

    bool isPerfectSquare(int num) {
        if(num <2) return true;
        long ret = (long)num/2.0;
        while (ret*ret > num){
            ret = (ret + (((long)num)/(long)ret))/2.0;
        }
        return ret * ret == (long)num;
    }

void solve() {
	
	int N = 0;
	cin >> N;
    if(N==0) cout << 0;

	vector <int> arr(N,0);
	for(int i = 0; i < N; i++){
	    cin >> arr[i];
	}

    int ret = 0;
    int currSum = 0;
    for(int i = 0; i < N; ++i) {
        currSum = 0;
        for(int j = 0; j < N - i; j++ ){
            currSum += arr[i+j];
            if(isPerfectSquare(currSum) && currSum >= 0){
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