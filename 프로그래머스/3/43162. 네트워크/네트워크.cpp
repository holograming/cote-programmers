#include <string>
#include <vector>
#include <functional>

using namespace std;



int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    std::vector<int> visited(n, 0);
    
    std::function<void(int)> dfs = [&](int idx){
        
        visited[idx] = true;
        for(int i=0; i<n; ++i)
            if(computers[idx][i] == 1 && visited[i] == 0)
            {
                dfs(i);
            }
    };
    
    
    for(int i=0; i<n; ++i)
        if(visited.at(i) == 0)
        {
            dfs(i);
            answer++;
        }
    return answer;
}