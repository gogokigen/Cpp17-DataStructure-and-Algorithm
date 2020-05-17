//https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff43/0000000000337b4d
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int calculate(vector<int>& arr, int start, int end){
    int ret = 0;
    int sign = -1;
    int count = 1;
    for(int i = start - 1; i < end; i++){
        sign *= -1;
        ret += count * sign * arr[i];
        count++;
    }
    return ret;
}

void solve() {
	
	int N = 0, Op = 0;
	cin >> N >> Op;
    if(N==0) cout << 0;

	vector <int> arr(N,0);
	for(int i = 0; i < N; i++){
	    cin >> arr[i];
	}

	int ret = 0;
	for(int i = 0; i < Op; i++){
	    char s;
	    cin >> s;
	    if(s == 'Q'){
	        int start = 0, end = 0;
	        cin >> start >> end;
	        ret += calculate(arr, start, end);
	    }
	    
	    if(s == 'U'){
	        int ops = 0, num = 0;
	        cin >> ops >> num;
	        arr[ops - 1] = num;
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