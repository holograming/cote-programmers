#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

// 1.문자열에서 같은 알파벳이 2개 붙어 있는 짝을 찾기
// 2.그 둘을 제거한 뒤, 앞뒤로 문자열을 이어 붙입니다
// 3.반복 후, 종료

int solution(string s)
{
    if(s.empty() || s.length() <= 1 || s.length() > 1,000,000)
        return 0;

    std::stack<char> s_tack;
    for(auto it=s.begin(); it!=s.end(); std::advance(it, 1))
    {
        if(!s_tack.empty() && *it == s_tack.top())
            s_tack.pop();
        else 
            s_tack.push(*it);
    }  
    return s_tack.empty();
}