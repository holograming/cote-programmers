#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

bool changable(std::string str1, std::string str2) {
  
    if(!str1.empty() && !str2.empty() && str1.size() != str2.size())
        return false;
    
    int notMatched = 0;
    for(int i=0; i<str1.size(); ++i)
    {
        if(str1[i] != str2[i]) notMatched++;

        if(notMatched > 1) return false;
    }

    return notMatched == 1;
}
 

int solution(string begin, string target, vector<string> words) {
     // target이 words에 없으면 불가능
    bool hasTarget = false;
    for(const auto& w : words) {
        if(w == target) {
            hasTarget = true;
            break;
        }
    }
    if(!hasTarget) return 0;
    
    std::cout <<"words"<<std::endl;
   
    std::map<std::string, int> map_;
    for(auto w : words)
      map_[w] = -1;
    
    std::queue<std::string> que;
    que.push(begin);
    map_[begin] = 0;
    
    bool isFind = false;
    while(!que.empty())
    {
        auto key = que.front();
        que.pop();
        
        for(auto word : words)
        {
            if(map_[word] == -1 && changable(key, word)) 
            {
                map_[word] = map_[key] + 1;
                if(word == target)
                {
                   return map_[word] ;
                }
                que.push(word);
            }
        }
    }
    return 0;
}