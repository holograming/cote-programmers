#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <functional>

using PQ = std::priority_queue<int, std::vector<int>, std::greater<int>>;

int solution(std::vector<int> scoville, int K) {
    int answer = 0;
    
    PQ n_scov(scoville.begin(), scoville.end());
        
    if(n_scov.top() >= K)
        return answer;
    
    while(!n_scov.empty()) {
        
        if(n_scov.size() <= 1)
            return -1;
        
        auto const val1 = n_scov.top(); n_scov.pop();
        auto const val2 = n_scov.top(); n_scov.pop();
        auto const newVal = val1 + (val2*2);
        answer++;
        n_scov.push(newVal);
        if(n_scov.top() >= K)
            return answer;
         
        
    }
    
    
    return answer;
}