class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int size = arr.size();
        int half_size = size / 2;
        int count = 0;
        unordered_map<int, int> counts;
        multimap<int, int, greater<int>> frequencies;
        
        for(auto a : arr) {
            counts[a] += 1;
        }
        
        for(auto [i, f] : counts) {
            frequencies.insert({f, i});
        }
        

        for(auto [f, _] : frequencies) {
            size -= f;
            count++;
            if(size <= half_size) break;
        }
        
        return count;
    }
};