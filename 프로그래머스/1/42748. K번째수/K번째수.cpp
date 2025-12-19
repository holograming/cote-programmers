#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    //command i - j cut; kth value
    for(auto cmd : commands)
    {
        int i = cmd[0];
        int const j = cmd[1];
        int const k = cmd[2];
        std::vector<int> temp;
        for(i; i<=j; ++i)
        {
            temp.push_back(array.at(i-1));
        }
        std::sort(temp.begin(), temp.end());
        for(int ii=0; ii<temp.size(); ++ii)
        {
            std::cout<< temp[ii] << ", ";
        }
        std::cout<<std::endl;
        answer.push_back(temp[k-1]);
    }
    
    
    return answer;
}