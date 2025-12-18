#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
using namespace std;

vector<int> solution(vector<int> answers) {
    
    vector<int> counts(3, 0);
    const std::vector<int> A{1,2,3,4,5};
    const std::vector<int> B{2,1,2,3,2,4,2,5};
    const std::vector<int> C{3,3,1,1,2,2,4,4,5,5};
    
    const int ASize = A.size();
    const int BSize = B.size();
    const int CSize = C.size();
    for(int idx =0; idx < answers.size(); ++idx) {
        int const aIdx = idx % ASize;
        int const bIdx = idx % BSize;
        int const cIdx = idx % CSize;
        if(A[aIdx] == answers[idx]) counts[0]++;
        if(B[bIdx] == answers[idx]) counts[1]++;
        if(C[cIdx] == answers[idx]) counts[2]++;
    }
    
    std::cout << counts[0] << ", " << counts[1] << " , " << counts[2] << std::endl;
    
    if((counts[0] == counts[1]) && (counts[1] == counts[2]) && (counts[0] == counts[2]) )
    {
        if(counts[0] == 0) return {};
        return { 1, 2, 3 };
    }
    
    // 최댓값 찾기
    int maxScore = std::max({counts[0], counts[1], counts[2]});
    
    // 최댓값과 같은 사람만 answer에 추가 (자동으로 오름차순)
    std::vector<int> answer;
    for(int i = 0; i < 3; ++i) {
        if(counts[i] == maxScore) {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
    
    return answer;
}