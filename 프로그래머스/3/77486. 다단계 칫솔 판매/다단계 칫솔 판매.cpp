#include <string>
#include <vector>
#include <unordered_map>


std::vector<int> solution(std::vector<string> enroll, std::vector<string> referral, 
                     std::vector<string> seller, std::vector<int> amount) {
    
    std::unordered_map<std::string, int> idx;
    std::vector<int> result(enroll.size(), 0);
    
    // O(N)
    for (int i = 0; i < enroll.size(); i++) {
        idx[enroll[i]] = i;
    }
    
    // O(M × log(금액))
    for (int i = 0; i < seller.size(); i++) {
        int const money = amount[i] * 100;
        std::string cur = seller[i];
        
        while (cur != "-" && money > 0) {
            int id = idx[cur];
            int fee = money / 10;
            
            result[id] += money - fee;
            
            if (fee == 0) break;  // ⭐ 핵심 최적화
            
            cur = referral[id];
            money = fee;
        }
    }
    
    return result;
}
