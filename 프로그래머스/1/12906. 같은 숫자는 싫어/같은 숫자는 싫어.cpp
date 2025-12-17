#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    answer.push_back(arr[0]);
    for(auto val : arr)
        if(answer.back() != val)
        {
            answer.push_back(val);
        }
       

    return answer;
}