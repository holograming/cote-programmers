#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
//자카드J(A,B) : 교집합/합집합
//A,B 모두 공집합 : J(A,B) = 1

// A = {1,1,1}, B {1,1,1,1,1} 교집합 : {1,1,1} min(A,B),  합집합 {1,1,1,1,1} max(A,B) >> J(A,B) = 3/5

using namespace std;



bool _isChar(std::string str) {
    auto is_char = [](char ch) -> bool {
        return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
    };
    for(auto ch : str) {
        if(!is_char(ch))
            return false;
    }
    //std::cout << "str: " << str << std::endl;
    return true;
}

int solution(string str1, string str2) {
    if(str1.size() < 2 || str2.size() < 2)
        return 0;
    
    std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    std::transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
    
    auto split_word = [](std::string const in) -> std::vector<std::string> {
        std::string word;
        std::vector<std::string> group;
        std::string prev;
        for(auto it=in.begin(); it!=in.end(); ++it)
        {           
            word += *it;
            prev = *it;
           // std::cout << "word : " << word << "\t it :" << *it << std::endl;
            if(word.size() == 2)
            {
                if(_isChar(word))
                {
                    group.push_back(word);
                   // std::cout << "unique_word : " << word << std::endl;
                }   
                word=prev;
            }      
        }
        
        return group;
    };
    
    auto a_group = split_word(str1);    
    auto b_group = split_word(str2);
     if(a_group.empty() && b_group.empty())
        return 65536;
    
    std::sort(a_group.begin(), a_group.end());
    std::sort(b_group.begin(), b_group.end());
    
    std::vector<std::string> intersection_result;
    std::vector<std::string> union_result;
    
    std::set_intersection(a_group.begin(), a_group.end(),
                          b_group.begin(), b_group.end(),
                          std::back_inserter(intersection_result));
    
    std::cout << "----------" << std::endl;
    for(auto it:intersection_result)
        std::cout << it << std::endl;
    
    std::set_union(a_group.begin(), a_group.end(),
                   b_group.begin(), b_group.end(),
                   std::back_inserter(union_result));
    std::cout << "----------" << std::endl;
    for(auto it:union_result)
        std::cout << it << std::endl;
    
    int A = intersection_result.size();
    int B = union_result.size();
    
    if(B == 0)
        return 65536;
    
    return (int)(65536.0 * A / B);
}