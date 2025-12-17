#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;

bool Compare_(std::string const src, std::string const trg) {
    if(trg.empty() || src.size() < trg.size()) return false;
    
    //std::cout << src << ", " << trg << std::endl;
    auto pos = src.find(trg);
    if(pos == string::npos || pos != 0)
    {
        //std::cout << "false" << std::endl;
        return false;
    }
    
    //std::cout << "same!" << std::endl;
    return true;
}

bool findPb(std::vector<std::string> const pb, int idx, int next) {
    //std::cout << idx << ", " << next << std::endl;
    if(next == pb.size())
        return true;
    else if(Compare_(pb[next], pb[idx]))
    {
        //std::cout << pb[idx] << ", " << pb[next] << std::endl;
        return false;
    }
    
    return findPb(pb, idx, next+1);
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    // 오름차순정렬이므로, 앞으로 검색할 필요 없다. 
    std::sort(phone_book.begin(), phone_book.end());
    
    for(int i=0; i<phone_book.size() - 1; ++i)
        if(Compare_(phone_book[i+1], phone_book[i]))
            return false;
    
    return answer;
}