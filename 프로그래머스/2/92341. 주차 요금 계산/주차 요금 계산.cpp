#include <bits/stdc++.h>


using namespace std;

struct ParkingFeeTable {
    int dMin = 0;
    int dWon = 0;
    int uMin = 0;
    int uWon = 0;
};

struct CarList {
    CarList(vector<string> const records) {
        for(auto record : records)
        {
            int hh = stoi(record.substr(0, 2));
            int mm = stoi(record.substr(3, 2));
            std::string number = record.substr(6, 4);
            int type = record.substr(11, 2) == "IN" ? 0 : 1;
            int hhmm = hh*100+mm;
            carRecords[number].insert(std::make_pair(hhmm, type));
        }
        
    };
   
    std::map<std::string, std::map<int, int>> carRecords;
};

int _totTime(int outTime, int inTime)
{
    int diff = outTime - inTime;
    int out_hh = outTime / 100;
    int out_mm = outTime % 100;
    int in_hh = inTime / 100;
    int in_mm = inTime % 100;
    diff = (out_hh - in_hh) * 60 + out_mm - in_mm;
    std::cout << outTime << " - " << inTime << " : " << diff << std::endl;
    return diff;
}

int calcFee(std::map<int, int> const record, ParkingFeeTable const table) {
    int totTime =0 , inTime = 0, outTime = 0;
    for(auto it: record)
    {
        if(it.second == 1)
        { 
            outTime = it.first;
            totTime += _totTime(outTime, inTime);
            inTime = 0, outTime = 0;
        }
        else 
            inTime = it.first;        
    }
    if(record.size() % 2 != 0)
    {
        outTime = 2359;
        totTime += _totTime(outTime, inTime);
    }   

    //std::cout << "SUM : " << totTime << std::endl;
    if(totTime <= table.dMin) 
        return table.dWon;
    
    int extra = std::ceil((totTime - table.dMin)/(table.uMin * 1.0));
    //std::cout << "extra : " << extra << std::endl;
    //std::cout << "table.dWon : " << table.dWon << std::endl;
    //std::cout << "table.dMin : " << table.dMin << std::endl;
    //std::cout << "table.uMin : " << table.uMin << std::endl;
    //std::cout << "val : " << std::ceil(extra) << std::endl;
    
    return table.dWon + extra * table.uWon;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    ParkingFeeTable FEE_TABLE;
    FEE_TABLE.dMin = fees[0];
    FEE_TABLE.dWon = fees[1];
    FEE_TABLE.uMin = fees[2];
    FEE_TABLE.uWon = fees[3];
    
    CarList cars(records);
    
    for(auto it : cars.carRecords)
    {
        std::cout << it.first << " --------" << std::endl;
        int parked = calcFee(it.second, FEE_TABLE);
        answer.push_back(parked);
        std::cout << "paid : " << parked << std::endl;
        //for(auto nn : it.second)
        //{ 
        //    std::cout << "\t " << nn.first << " , " << nn.second << std::endl;
        //}
    }
    
    
    
    return answer;
}