#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

long long failed(int n, vector<int> works) {
    
    int leavedTime = n;   
    if(std::accumulate(works.cbegin(), works.cend(), 0) < leavedTime)
        return 0;

    int workIn1Hour=0;    
    auto f = [&works, &workIn1Hour](int id) -> void {
        
        if(id == -1)
        {//0이 있을 수 있음. 
            std::vector<int> temp;
            std::copy_if(works.begin(), works.end(), 
                std::back_inserter(temp),
                [](int n) { return n != 0; }
            );
            std::sort(temp.begin(), temp.end(), std::greater<int>());
            works = temp;
            workIn1Hour = works.size();
        } else {
            if(works[id] == 0) {
                works.erase(works.begin() + id);
                works.shrink_to_fit();
                workIn1Hour--;
            } else {
                if(id < works.size()) {
                    if(works[id] < works[id+1])
                        std::sort(works.begin(), works.end(), std::greater<int>());
                }
                
            } 
        }
    };
    
    auto showWorks = [&works]() -> void {
          std::cout << "[ " ;
            for(auto it: works)
                std::cout << it << " , ";
            std::cout << " ]\n" ;
    };
    
    f(-1);
    
    int id =0;
    while(leavedTime > 0) {
        if(works[id] > 0)
        {
            works[id] -= 1;
            --leavedTime;    
            f(id);
        }
    }
    
     std::transform(works.cbegin(), works.cend(), works.begin(), [](int i) { return i*i;});
    ;
    
    return std::accumulate(works.cbegin(), works.cend(), 0);
}


long long solution(int n, vector<int> works) {
    int leavedTime = n;   
    if(std::accumulate(works.cbegin(), works.cend(), 0) < leavedTime)
        return 0;
    
    // 혹시 0이 있을수도?
    std::vector<int> temp;
    std::copy_if(works.begin(), works.end(), 
        std::back_inserter(temp),
        [](int n) { return n != 0; }
    );
    works = temp;
    
    std::priority_queue<int> pq(works.begin(), works.end());    
    while(leavedTime > 0 && !pq.empty()) {
        auto val = pq.top(); pq.pop();
        if(--val > 0)
        {
            pq.push(val);
        }
        --leavedTime;    
    }
    
    long long sum =0;
    while(!pq.empty()) {
        sum += pq.top() * pq.top(); pq.pop();
    }
    return sum;
    
}
