#include <string>
#include <vector>

using namespace std;

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, 
                     vector<string> seller, vector<int> amount) {
    
    unordered_map<string, int> idx;
    vector<int> result(enroll.size(), 0);
    
    // O(N)
    for (int i = 0; i < enroll.size(); i++) {
        idx[enroll[i]] = i;
    }
    
    // O(M × log(금액))
    for (int i = 0; i < seller.size(); i++) {
        int money = amount[i] * 100;
        string cur = seller[i];
        
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