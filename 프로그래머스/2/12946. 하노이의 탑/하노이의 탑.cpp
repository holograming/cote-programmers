#include <string>
#include <vector>

using namespace std;


std::vector<std::vector<int>> hanoitop(int const N, int start, int end, int mid) {
    
    std::vector<std::vector<int>> answer;
    if(N == 1) {
        answer.push_back({start, end});
        return answer;
    }
    
    for(auto vec : hanoitop(N-1, start, mid, end))
        answer.push_back(vec);

    answer.push_back({start, end});

    for(auto vec : hanoitop(N-1, mid, end, start))
        answer.push_back(vec);

    return answer;
}


vector<vector<int>> solution(int n) {
    
    return  hanoitop(n, 1, 3, 2);
}