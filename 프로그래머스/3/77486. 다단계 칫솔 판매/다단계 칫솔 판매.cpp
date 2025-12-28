#include <string>
#include <vector>

using namespace std;

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, 
                     vector<string> seller, vector<int> amount) {
    int n = enroll.size();
    
    // 판매원 이름 -> 인덱스 매핑
    unordered_map<string, int> nameToIndex;
    for (int i = 0; i < n; i++) {
        nameToIndex[enroll[i]] = i;
    }
    
    // 각 판매원의 누적 이익금
    vector<int> answer(n, 0);
    
    // 각 판매 건에 대해 이익 배분
    for (int i = 0; i < seller.size(); i++) {
        string currentSeller = seller[i];
        int profit = amount[i] * 100; // 칫솔 1개당 100원
        
        // 현재 판매원부터 상위 추천인까지 이익 배분
        while (currentSeller != "-" && profit > 0) {
            int idx = nameToIndex[currentSeller];
            
            // 상위에 배분할 금액 (10%)
            int toReferral = profit / 10;
            
            // 현재 판매원이 가질 금액 (90% 또는 전체)
            int toKeep = profit - toReferral;
            answer[idx] += toKeep;
            
            // 배분할 금액이 1원 미만이면 종료 (절사로 인해 0원)
            if (toReferral < 1) {
                break;
            }
            
            // 다음 추천인으로 이동
            currentSeller = referral[idx];
            profit = toReferral;
        }
    }
    
    return answer;
}