#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char STACK_[100000] = {0,};
int local_index = -1;

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
bool solution(const char* s) {
    const int length = strlen(s);
    if(length <= 0 || length%2 != 0 || s[0] == ')' || s[length-1] == '(')
        return 0;
    
    for(int i =0; i<length; ++i) {
        if (local_index > -1 && s[i] != STACK_[local_index])
        {
            STACK_[local_index] = 0;
            local_index--;
        } else {
            if(local_index == -1 && s[i] == ')') {
                return 0;
            }
            local_index++;
            STACK_[local_index] = s[i];
        }
    }    
    
    return local_index == -1;
}