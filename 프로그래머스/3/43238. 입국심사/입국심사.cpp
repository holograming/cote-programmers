#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

using ll = long long;

long long solution(int n, vector<int> times) {
    ll answer = 0;
    
   //풀서치로, 검사관의 검사여부를 탐색하면 너무 느림. 
    ll min_time = 1; // 1분 이상 1,000,000,000분 이하하
    ll max_time = static_cast<ll>(*std::max_element(times.begin(), times.end())) * n; // 최대 시간 x N명 안에는 무조건 존재한다. 

    while(min_time < max_time) {
        
        const ll avr = (min_time + max_time)/2;
        const ll sum = static_cast<ll>(std::accumulate(times.begin(), times.end(), 0LL, [avr](ll acc, int b) {
            return acc + (avr / b);
        }));
        
        if(sum < n) min_time = avr + 1; // N보다 적으니, 더 많은 시간 필요. 
        else max_time = avr; // N보다 많은 인원 검사 가능
        
    }
    answer = min_time;
    return answer;
}