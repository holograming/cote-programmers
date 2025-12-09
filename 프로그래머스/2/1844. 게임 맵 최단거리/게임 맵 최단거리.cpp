
#include<vector>
#include<queue>
#include<iostream>

int solution(std::vector<std::vector<int> > maps)
{
    if(maps.empty())
        return -1;
    
    int const N = maps.size();
    int const M = maps[0].size();
    
    if(N == 0 || M == 0)
        return -1;
    
    if( maps[0][0] == 0 
     || maps[N-1][M-1] == 0)
        return -1;
    
    std::vector<int> distance(N*M, 0);  
    struct POS {
        int X;
        int Y;
    };
    
    std::queue<POS> pos_queue;
    pos_queue.push({0, 0});
    distance[0] = 1;
    
    std::vector<POS> boundary = { {1,0}, {0,1}, {-1,0}, {0,-1} };   
    while(!pos_queue.empty())
    {
       auto pos = pos_queue.front();
       pos_queue.pop();
       
       for(int i=0; i<4; ++i)
       {
           int nn = pos.X + boundary[i].X;
           int mm = pos.Y + boundary[i].Y;

           if(nn >= 0 && nn < N && mm >= 0 && mm < M)
           {
               int idx = mm * N + nn;
               if(maps[nn][mm] == 1 && distance[idx] == 0)
               {
                   int cidx = pos.Y * N + pos.X;
                   distance[idx] = distance[cidx] + 1;                   
                   pos_queue.push({nn, mm});
               }
           }
       }
    }    
        
    if(auto res = distance[N*M-1]; res > 0)
        return res;
    return -1;
    
}