//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{
    
    public:
    int maxCandy(int height[], int n) 
    { 
        // Your code goes here
        if(n <= 2) return 0; // No space between two or less books
        
        int maxHeight = INT_MIN;
        
        int l = 0, r = n - 1;
        
        while(l < r) {
            maxHeight = max(maxHeight, min(height[l], height[r]) * (r - l - 1));
            if(height[l] == height[r]) {
                l++;
                r--;
            } else if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        
        return maxHeight;
    }   
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int height[n];
    	for (int i = 0; i < n; ++i)
    	{
    		cin>>height[i];
    	}
    	
    	Solution obj;
    	
    	cout << obj.maxCandy(height,n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends