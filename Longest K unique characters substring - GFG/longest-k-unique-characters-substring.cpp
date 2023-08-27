//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int front = 0;
        int rear = 0;
        int maxLength = 0;
        unordered_map<char, int> m = {};
        
        while(front < s.size()) {
            char front_letter = s[front];
            
            if(m.find(front_letter) == m.end()) {
                m[front_letter] = 0;
            }
            
            m[front_letter]++;
            
            while(m.size() > k) {
                char rear_letter = s[rear];
                
                if(m.find(rear_letter) != m.end()) {
                    m[rear_letter]--;
                }
                
                if(m[rear_letter] == 0) {
                    m.erase(rear_letter);
                }
                
                rear++;
            }
            
            int tempLength = 0;
            for(auto i : m) {
                tempLength += i.second;
            }
            maxLength = max(maxLength, tempLength);
            
            front++;
        }
        
        return m.size() < k ? -1 : maxLength;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends