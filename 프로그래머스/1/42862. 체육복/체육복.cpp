#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
     std::sort(lost.begin(),lost.end());
    std::sort(reserve.begin(),reserve.end());

    for(auto it = lost.begin(); it !=lost.end();)
    {
        auto delete_it = std::find_if(reserve.begin(), reserve.end(), [=](int i) { return i == *it;  });
         if(delete_it != reserve.end()) {
             reserve.erase(delete_it);
            it = lost.erase(it);
         } else {
             ++it;
         }
    }

    std::unordered_map<int, int> delMap;
    for(auto r_it = reserve.begin(); r_it !=reserve.end();)
    {
        auto delete_it = std::find_if(lost.begin(), lost.end(), [=](int i) { return ((i + 1) == *r_it) || ((i - 1) == *r_it);  });
         if(delete_it != lost.end()) {
           // std::cout << "found : " << *delete_it << std::endl;           
            auto it = delMap.find(*delete_it); 
            if(it!=delMap.end())
                delMap.erase(it);

            lost.erase(delete_it);
            r_it = reserve.erase(r_it);
         } else {
            //std::cout << "not found : " << *r_it << std::endl;
            delMap[*r_it] = 1;
            ++r_it;
         }
    }
    
    for(auto it : delMap)
    {
        //std::cout << "delMap found : " << it.first << std::endl;
        auto del_it = std::find_if(reserve.begin(), reserve.end(), [=](auto i) { return i == it.first; });
        if(del_it != reserve.end())
        {
           //std::cout << "erase : " << *del_it << std::endl;
           reserve.erase(del_it);
        }
    }

    int const lostCnt = lost.size();
    int const reserveCnt = reserve.size();
    //std::cout << "lost : " << lostCnt << std::endl;
    //std::cout << "reserveCnt : " << reserveCnt << std::endl;
    if(lostCnt > reserveCnt) return n - (lostCnt - reserveCnt);    
    return n;
}