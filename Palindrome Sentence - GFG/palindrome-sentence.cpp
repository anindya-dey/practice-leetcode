//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sentencePalindrome(string s) 
	{
	    // if one knows the ASCII code for 'a' and 'z',
	    // we can use those in if condition, else, use "isalpha()"
	    
	    // APPROACH 1: using ASCII values
	    /*
	    int a_ascii = 97;       // ASCII decimal value of 'a'
	    int z_ascii = 122;      // ASCII decimal value of 'z'
	    
	    int l = 0;              // left pointer
	    int r = s.size() - 1;   // right pointer
	    
	    while(l < r) {
	        if(s[l] < a_ascii || s[l] > z_ascii) {
	            // if s[l] is not alpha, increment l
	            l++;
	        } else if(s[r] < a_ascii || s[r] > z_ascii) {
	            // if s[r] is not alpha, decrement r
	            r--;
	        } else if(s[l] == s[r]) {
	            // if s[l] is equal to s[r], increment l and decrement r
	            l++;
	            r--;
	        } else {
	            // else s[l] is NOT equal to s[r], return false
	            return false;
	        }
	    }
	    */
	    
	    // APPROACH 2: using "isalpha()" method
	    int l = 0;              // left pointer
	    int r = s.size() - 1;   // right pointer
	    
	    while(l < r) {
	        if(!isalpha(s[l])) {
	            // if s[l] is not alpha, increment l
	            l++;
	        } else if(!isalpha(s[r])) {
	            // if s[r] is not alpha, decrement r
	            r--;
	        } else if(s[l] == s[r]) {
	            // if s[l] is equal to s[r], increment l and decrement r
	            l++;
	            r--;
	        } else {
	            // else s[l] is NOT equal to s[r], return false
	            return false;
	        }
	    }
	    
	    return true;
	}
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        Solution ob;
        cout<<ob.sentencePalindrome(str)<<endl;
    }
    return 0;
}  


// } Driver Code Ends