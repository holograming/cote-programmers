#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <set>

using namespace std;

// 
// 당첨에 제제 아이디 목록의 경우의 수.
// ban_id 는 하나에만 무조건 해당 -> 하나에 두개일수 없음. 
// ban_id 루프돌면서 하나씩 빼면서 재귀식으로 찾기.

/* case1
    [frodo, abc1123
    [crodo, abc1123
*/

/* case2
    [frodo, crodo, abc123
    [frodo, crodo, frodoc
*/

/* case3
    [frodo, crodo, abc123, frodoc,
    [fradi, frodo, abc123, frodoc,
    [fradi, crodo, abc123, frodoc,
*/

bool _CompareChar(std::string const uid, std::string const bid) {
    if(uid.size() != bid.size()) return false;
    
    
    for(auto i = 0; i<uid.size(); ++i)
        if(bid[i] != '*' && uid[i] != bid[i])
            return false;
    
    return true;
}


int solution(std::vector<std::string> user_id, std::vector<std::string> banned_id) {
    int answer = 0;
    
    int cnt =0;
    std::map<std::string, int> u_map;
    std::vector<std::string> ru_map(user_id.size());
    for(auto u:user_id)
    {    
        u_map[u] = cnt; // 0~size()-1
        ru_map[cnt++] = u;
    }
    
    std::vector<std::vector<int>> groups;
    for(auto bid : banned_id)
    {
        std::vector<int> locals;
        for(auto u:user_id)
            if(_CompareChar(u, bid))
                locals.push_back(u_map[u]);
        groups.push_back(locals);
    } 
    
    std::set<std::set<int>> results;
    
    int const n = groups.size();
    vector<int> indices(n, 0);
    
    while (true) {
        // 현재 조합 생성
        std::set<int> combo;
        bool valid = true;
        
        for (int i = 0; i < n; i++) {
            int num = groups[i][indices[i]];
            if (combo.count(num)) {  // 중복 체크
                valid = false;
                break;
            }
            combo.insert(num);
        }
        
        if (valid) {
            results.insert(combo);
        }
        
        // 다음 조합으로 이동 (오도미터 방식)
        int pos = n - 1;
        while (pos >= 0) {
            indices[pos]++;
            if (indices[pos] < groups[pos].size()) break;
            indices[pos] = 0;
            pos--;
        }
        if (pos < 0) break;  // 모든 조합 완료
    }
    
    
    
    for(auto group : groups)
    {
        std::cout << "[ ";
        for(auto id : group)
            std::cout << ru_map[id] << ", ";
        std::cout << " ]\n";
    }
    answer = results.size();
    
    
    
    
    
    
    
    return answer;
}