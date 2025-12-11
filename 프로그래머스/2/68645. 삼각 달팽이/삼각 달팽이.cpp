#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    
     
    std::vector<std::vector<int>> res;    
    for(int c=0; c< n; ++c)
    {
        std::vector<int> locals;
        for(auto cc =0; cc < c+1; ++cc)
        {
            locals.push_back(0);
        }
        res.push_back(locals);
    }
    
    int nth = 0; //몇번 탐색하면 되나. nth == n
    int count = 1;
    if(res.size() == 1) {
        res[0][0] = 1;
    }
    else {
        while(nth < n)
        {
            // 1. 왼쪽 값이 (빈) 첫번째 인덱스 탐색
            for(int r = nth; r < n-nth; r++)
            {
                if(res[r][nth] == 0)
                    res[r][nth] = count++;
            }

            // 2. 밑변의 (빈) 탐색 
            // [0] 차있다. 
            for(int c = nth + 1; c < (n-nth); c++)
            {
               if(res[n-1-nth][c] == 0)
                    res[n-1-nth][c] = count++; 
            }  

            // 밑변이 이미 다 찻으므로 시작은 밑변의 위쪽
            // 3. 오른쪽 값이 (빈) 윗방향 탐색 == 마지막
            for(int r = n-1-1-nth; r > nth; r--)
            {
               if(res[r][r-nth] == 0)
                    res[r][r-nth] = count++; 
            }
            nth++;
        }
    }
       
    vector<int> answer;
    for(auto vec : res)
        for(auto it: vec)
            answer.push_back(it);
    return answer;
}