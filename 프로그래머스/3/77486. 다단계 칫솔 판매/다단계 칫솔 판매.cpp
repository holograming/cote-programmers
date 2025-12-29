#include <string>
#include <vector>

using namespace std;

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, 
                     vector<string> seller, vector<int> amount) {
    int const n = enroll.size();
    
    std::unordered_map<std::string, int> nameToIndex;
    for (int i = 0; i < n; i++) {
        nameToIndex[enroll[i]] = i;
    }
    
    // 누적 이익금
    std::vector<int> answer(n, 0);
    
    
    for (int i = 0; i < seller.size(); i++) {
        string currentSeller = seller[i];
        int profit = amount[i] * 100; // 칫솔 1개당 100원
        
    
        while (currentSeller != "-" && profit > 0) {
            int idx = nameToIndex[currentSeller];
            int const toReferral = profit / 10;
            int const toKeep = profit - toReferral;
            answer[idx] += toKeep;
            
            // 버림
            if (toReferral < 1) {
                break;
            }
            
            // 끝까지 탐색
            currentSeller = referral[idx];
            profit = toReferral;
        }
    }
    
    return answer;
}
