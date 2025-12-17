#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    std::unordered_map<std::string, int> map_p;
    for(auto p : participant)
        map_p[p] += 1;
    
    for(auto p : completion)
        map_p[p] -= 1;
    
    for(auto it : map_p)
    {
        //std::cout << it.first << " : " << it.second << std::endl;
        if(it.second > 0)
            answer = it.first;
    }
    
    return answer;
}