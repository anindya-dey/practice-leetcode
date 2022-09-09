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
            if(prop[1] < maxDefense) {
                count++;
            }
            
            if(prop[1] > maxDefense) {
                maxDefense = prop[1];
            }
        }
        
        return count;
    }
};