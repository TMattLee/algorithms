/**********************************************
***********************************************
Sort the list of trips based on ascending start
times. Use a priority queue that holds both 
capacity and end_location. The priority queue
will be a min heap that holds these two values
as a pair. Alternatively, you can modify the
priority queue to hold the entire trips[x] array
instead of just the pair.

Push the first item into the priority queue.

Iterate through the rest of the items using the
following logic:

Pop the queue while the start location is 
greater than or equal to the front's end 
location.

Then push the new item and increase
capacity based on the new item. Compare
that the currentCapacity does not exceed 
the maximum capacity. If it does return false.

Finally return true;

**********************************************/


class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int maxCapacity) {
        if(trips.size() == 1){
            if(trips[0][0] > maxCapacity) return false;
            return true;
        }
        
        int currentCapacity = 0;

        auto compare = [](const pair<int,int> & a, const pair<int,int> & b) -> bool {
            return a.second > b.second;
        };

        priority_queue< pair<int,int>, vector< pair<int,int> >, decltype(compare)> pq(compare);               
        
        sort(trips.begin(), trips.end(), [](const vector<int> & a, const vector<int> & b) -> bool {
            if(a[1] == b[1]) return a[2] < b[2];
            return a[1] < b[1]; 
        });
        
        currentCapacity += trips[0][0];
                
        pq.push({trips[0][0], trips[0][2]});
        
        vector< vector<int> >::iterator it = trips.begin();
        
        it++;
                 
        for(; it != trips.end(); it++){
            
            while(!pq.empty() && (*it)[1] >= pq.top().second){
                currentCapacity -= pq.top().first;
                pq.pop();
            }
            
            currentCapacity += (*it)[0];
            
            pq.push({(*it)[0], (*it)[2]});
            
            if(currentCapacity > maxCapacity) return false;
            
        }
        return true;             
        
    }
};
