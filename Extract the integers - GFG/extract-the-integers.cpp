//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
vector<string> extractIntegerWords(string s);

int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        vector<string> ans = extractIntegerWords(str);
        if(ans.size() == 0)
            cout<<"No Integers";
        else
            for(auto i: ans) cout<<i<<' ';
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends


vector<string> extractIntegerWords(string s)
{
    vector<string> result = {};
    string temp = "";
    
    for(char ch : s) {
        if(isdigit(ch)) {
            temp.push_back(ch);
        } else {
            if(temp.size() > 0) {
                result.push_back(temp);
                temp = "";
            }
        }
    }
    
    if(temp.size() > 0) {
        result.push_back(temp);
        temp = "";
    }
    
    return result;
}