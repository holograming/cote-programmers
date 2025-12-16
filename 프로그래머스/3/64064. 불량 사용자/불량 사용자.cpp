#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

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

void solve(std::vector<std::vector<int>> const groups, int idx, std::vector<int> current, std::vector<std::vector<int>>& results) {
    
    if (idx == groups.size()) {
        std::vector<int> sorted = current;
        std::sort(sorted.begin(), sorted.end());
        
        if (std::find(results.begin(), results.end(), sorted) == results.end()) {
            results.push_back(sorted);
        }
        return;
    }
    
    // 현재 그룹에서 하나씩 선택
    //{ 0, 1}, { 1, 2}, { 4, 5}, { 4, 5 }
    for (int num : groups[idx]) {
        // 중복 체크
        if (std::find(current.begin(), current.end(), num) == current.end()) {
            current.push_back(num);
            solve(groups, idx + 1, current, results); // 다음 그룹에서 하나 찾기, 
            current.pop_back(); // 이전 값이 남아있음!
        } 
    }
}

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
    
    std::vector<std::vector<int>> results;
    solve(groups, 0, {}, results);
    
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