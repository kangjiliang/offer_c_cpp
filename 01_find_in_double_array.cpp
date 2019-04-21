#include "public.h"


// 暴力求解 逐行搜索
bool find_one_by_one(int target, vector<vector<int> >& array){
    for(unsigned int i = 0; i < array.size(); ++i){
        for(unsigned int j = 0; j < array[0].size(); ++j){
            if(target == array[i][j]){
                return true;
            }
        }
    }
    return false;
}
// 每行都是递增 针对每一行 使用二分查找
bool find_binary(int target, vector<vector<int> >& array){
    for(unsigned int i = 0; i < array.size(); i++){
        int l = 0;
        int r = array[i].size()-1;
        while(l <= r){
            int mid = (l + r)/2;
            if(target == array[i][mid]){
                return true;
            }
            else if(target < array[i][mid]){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
    }
    return false;
}
/*
    从右上角 或左下角， 下面以右上角开始为例：
    如果target大于当前值，array[i][j] 是当前行的最大值，则target可能在下一行 即j++
    如果target小于当前值，array[i][j] 是当前列的最小值，则target可能在左一列 即i--
    相等则返回true
*/
bool find_from_right_top(int target, vector<vector<int> >& array){
    int rows = array.size();
    if(0 == rows){
        return false;
    }
    int cols = array[0].size();
    int i = 0;
    int j = cols - 1;
    while(i < rows && j >= 0){
        if(target == array[i][j]){
            return true;
        }
        else if(target < array[i][j]){
            j--;
        }
        else{
            i++;
        }
    }
    return false;
}

void test_01_find_in_double_array()
{

}
