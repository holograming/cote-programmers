#include <string>
#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

int bfs(std::vector<int> const sequence, int const target, int& index, std::vector<int>& out) {
    
    out.push_back(sequence[index]);
    int const sum = std::accumulate(out.begin(), out.end(), 0);
    if (index == sequence.size()-1 || sum >= target) {
        return sum;
    }

    ++index;
    return bfs(sequence, target, index, out);
}

vector<int> failed(std::vector<int> sequence, int k) {
    auto it = std::adjacent_find(sequence.begin(), sequence.end(), [](const int& a, const int& b){
        return !(a == b); // a와 b가 같지 않으면 true를 반환하여 찾도록 유도
    });
    bool const allSameGroup = (it == sequence.end());
    
    int const target = k;
    int startIdx, finalIdx = 0;
    std::vector<int> finals;
    for(auto i=0;i<sequence.size();++i)
    {
        int outIdx = i;
        std::vector<int> out;
        if(bfs(sequence, target, outIdx, out) != target)
        {
            out.clear();
            continue;
        }

        if( (finals.empty())
         || (out.size() < finals.size())
         || (out.size() == finals.size() && finalIdx < i)
        ) {
            finals = out,
            startIdx = i,
            finalIdx = outIdx;
        }
        if(allSameGroup)
            break;
    }
    
    return std::vector<int> { startIdx, finalIdx};
}

vector<int> solution(std::vector<int> sequence, int k) {
    
    int startIdx = 0, finalIdx = 0;
    std::vector<int> finals;
    int sum = sequence[0];
    int length = 0;
    while(finalIdx < sequence.size()) {
        if(sum < k) {
            sum += sequence[++finalIdx];
            //std::cout << sum << " : " << startIdx << " , " << finalIdx << std::endl;
        } else if (sum > k) {
            sum -= sequence[startIdx++];
        } else 
        {
            int const curLength = finalIdx - startIdx;
            if(finals.empty() || length > curLength)
            {
                length = curLength;
                finals = std::vector<int> { startIdx, finalIdx};
            }
             sum -= sequence[startIdx++]; // 무한루프
        }
    }
    
     return finals;
}