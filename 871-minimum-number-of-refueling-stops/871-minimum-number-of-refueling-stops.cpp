class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int stops = 0;
        int distance_covered = startFuel;
        int currentStation = 0, numberOfStations = stations.size();
        priority_queue<int> pq;
        
        while(distance_covered < target) {
            while((currentStation < numberOfStations) && (stations[currentStation][0] <= distance_covered)) {
                pq.push(stations[currentStation][1]);
                currentStation++;
            }
            
            if(pq.empty()) return -1;
            
            distance_covered += pq.top();
            pq.pop();
            stops++;
        }
        
        return stops;
    }
};