#include <string>
#include <vector>
#include <stack>

using namespace std;


int count_result = 0;

void dfs(vector<int> numbers, int target, int index, int current_sum) {
    
    if (index == numbers.size()) {
        if (current_sum == target) {
            count_result++;
        }
        return;
    }
    
    // 두 가지 선택
    dfs(numbers, target, index + 1, current_sum + numbers[index]);  // 현재 숫자를 더하는 경우
    dfs(numbers, target, index + 1, current_sum - numbers[index]);  // 현재 숫자를 빼는 경우
}

using IDX = int;
using SUM = int;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    //dfs(numbers, target, 0, 0);
    std::stack<std::pair<IDX, SUM>> S;
    S.push({0, 0});
    
    while(!S.empty()) {
        
        auto const data = S.top(); S.pop();
        auto const index = data.first;
        auto const sum = data.second;
        
        if (index == numbers.size()) {
            if (sum == target) {
                answer++;
            }
            continue;
        }
        
        
        S.push({index + 1, sum + numbers[index]});
        S.push({index + 1, sum - numbers[index]});
    }
        
    
    
    return answer;
}