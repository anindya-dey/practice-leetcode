//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

bool decode (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << decode (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


bool decode (string s)
{
    string m = "hello";
    
    if (s.size() < m.size()) return false;
    
    // set pointers to the beginning of each strings
    int m_p = 0;
    int s_p = 0;
    
    while(s_p < s.size()) {
        if(m[m_p] == s[s_p]) {
            m_p += 1;
            s_p += 1;
        } else {
            s_p += 1;
        }
        
        if(m_p >= m.size()) return true;
    }
    
    return false;
}