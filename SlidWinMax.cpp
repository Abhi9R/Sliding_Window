#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

vector<int> slidingWindowMaximum(vector<int> &arr, int k) {
    deque<int> dq;
    vector<int> ans;
    

    for(int i=0; i<arr.size(); i++) {
    	if(!dq.empty() && dq.front() == i-k) {
    		dq.pop_front();
    	}
    	
    	while(!dq.empty() && arr[dq.back()] < arr[i]) {
    		dq.pop_back();
    	}

    	dq.push_back(i);
    	if(i >=k-1) {
    		ans.push_back(arr[dq.front()]);
    	}
    }

    return ans;
}

int32_t main() {
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> ans = slidingWindowMaximum(arr, k);
    for(auto it : ans) {
    	cout << it << " ";
    } cout << endl;
    return 0;
}