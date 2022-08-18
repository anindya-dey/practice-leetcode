class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int size = arr.size();
        int n = size;
        int count = 0;
        unordered_map<int, int> m;
        multimap<int, int, greater<int>> c;
        
        for(auto a : arr) {
            m[a] += 1;
        }
        
        for(auto i : m) {
            c.insert({i.second, i.first});
        }
        
        for(auto j : c) {
            size -= j.first;
            count += 1;
            if(size <= (n/2)) break;
        }
        
        return count;
    }
};