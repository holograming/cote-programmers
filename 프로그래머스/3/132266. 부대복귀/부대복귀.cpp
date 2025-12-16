#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
#include <algorithm>

using RoadMap = std::map<int, std::vector<int>>;

int findPath(RoadMap const roadMap, int const key, int const destination) {
    if(key == destination) return 0;
    
    std::map<int, int> dist;  
    std::queue<int> q;
    
    q.push(key);
    dist[key] = 0;
    
    while(!q.empty()) {
        int const cur = q.front();
        q.pop();
        
        auto it = roadMap.find(cur);
        if(it == roadMap.end()) continue;
        
        for(int next : it->second) {
            if(dist.find(next) == dist.end()) {  // 미방문
                dist[next] = dist[cur] + 1;
                if(next == destination) return dist[next];
                q.push(next);
            }
        }
    }
    return -1;
}

std::vector<int> solution(int n, std::vector<std::vector<int>> roads, std::vector<int> sources, int destination) {
   std::vector<int> answer;
    
   std::vector<std::vector<int>> roadMap(n+1);
    for(auto& road : roads) {
        roadMap[road[0]].push_back(road[1]);
        roadMap[road[1]].push_back(road[0]);
    }
    
    // destination에서 한 번만 BFS
    std::vector<int> dist(n + 1, -1); ; //초기화 -1
    std::queue<int> Q;
    
    Q.push(destination);
    dist[destination] = 0;
    
    while(!Q.empty()) {
        int const cur = Q.front();
        Q.pop();
        
        for(int next : roadMap[cur]) {
            if(dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                Q.push(next);
            }
        }
    }
    
    // O(1)로 각 source 거리 조회
    for(int src : sources) {
        answer.push_back(dist[src]);
    }

    return answer;

    return answer;
}
