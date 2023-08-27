//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        int front = 0, rear = 0, total = 0, numberOfBaskets = 2;
        unordered_map<int, int> m = {};
        
        while(front < N) {
            int fruit = fruits[front];
            auto it = m.find(fruit);
            
            if(it == m.end()) {
                m[fruit] = 0;
            }
            
            m[fruit]++;
            
            while(m.size() > numberOfBaskets) {
                auto itr = m.find(fruits[rear]);
                
                if(itr != m.end()) {
                    m[fruits[rear]]--;
                    if(m[fruits[rear]] == 0) m.erase(itr);
                }
                rear++;
            }
            
            int currTotal = 0;
            for(auto i : m) {
                currTotal += i.second;
            }
        
            total = max(total, currTotal);
            front++;
        }
        
        return total;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends