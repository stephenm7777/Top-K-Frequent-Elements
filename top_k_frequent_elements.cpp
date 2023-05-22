#include <vector> 
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result; 
        unordered_map<int, int> map;
        // storing the numbers from the array into the map
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
        }
        // creating a min heap from the map 
        priority_queue<pair<int, int>> min; 
        for(auto element : map){
            min.push(make_pair(element.second, element.first)); // the index and values (keys and values)
        }

        for(int i = 0; i < k; i++){
            result.push_back(min.top().second); 
            min.pop();
        }
        return result; 
               
    }
};