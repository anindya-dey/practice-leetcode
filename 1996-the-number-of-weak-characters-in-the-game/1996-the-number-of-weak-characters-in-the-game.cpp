class Solution {
private:
    bool static sortByAttack(vector<int> &a, vector<int> &b) {
        if(a[0] == b[0])
            return a[1] < b[1];
        
        return a[0] > b[0];
    }
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), sortByAttack);
        
        int count = 0;
        int maxDefense = INT_MIN;
        
        for(auto prop : properties) {           
            int currDefense = prop[1];
            
            if(currDefense < maxDefense) {
                count++;
            }
            
            maxDefense = max(maxDefense, currDefense);
        }
        
        return count;
    }
};