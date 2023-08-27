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
            int front_fruit = fruits[front];
            
            if(m.find(front_fruit) == m.end()) {
                m[front_fruit] = 0;
            }
            
            m[front_fruit]++;
            
            while(m.size() > numberOfBaskets) {
                int rear_fruit = fruits[rear];
                
                if(m.find(rear_fruit) != m.end()) {
                    m[fruits[rear]]--;
                }
                
                if(m[rear_fruit] == 0) {
                    m.erase(rear_fruit);
                }
                
                rear++;
            }
            
            int tempTotal = 0;
            for(auto i : m) {
                tempTotal += i.second;
            }
            total = max(total, tempTotal);
            
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