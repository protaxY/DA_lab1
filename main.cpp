#include <string>
#include <iostream>
#include <iomanip>
#include <cstring>
#include "vector.h"
#include "vector.cpp"

const unsigned int KEY_SIZE = 8;
const unsigned int KEY_RADIX_SIZE = 4;
const unsigned int VALUE_SIZE = 2050;
const unsigned int MAX_KEY_VALUE = 0xffff;

struct item{
    int Key[KEY_SIZE];
    char** Value;
};

int main(){
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    char strKey[33];
    TVector<item> sortArray;
    TVector<char*> valueData;
    char currentValue[VALUE_SIZE];
    item currentPair;
    while (std::cin >> strKey >> currentValue){
        for (int & i : currentPair.Key){
            i = 0;
        }
        for (int i = KEY_SIZE - 1; i >= 0; --i){
            int radixMultiply = 1;
            for (int j = KEY_RADIX_SIZE - 1; j >= 0; --j){
                if (strKey[i * KEY_RADIX_SIZE + j] >= '0' && strKey[i * KEY_RADIX_SIZE + j] <= '9'){
                    currentPair.Key[i] += (strKey[i * KEY_RADIX_SIZE + j] - '0') * radixMultiply;
                }
                else if (strKey[i * KEY_RADIX_SIZE + j] >= 'a' && strKey[i * KEY_RADIX_SIZE + j] <= 'f'){
                    currentPair.Key[i] += (strKey[i * KEY_RADIX_SIZE + j] - 'a' + 10) * radixMultiply;
                }
                radixMultiply *= 16;
            }
        }
        char* newValue = new char[VALUE_SIZE];
        std::memcpy(newValue, currentValue, sizeof(char)*VALUE_SIZE);
        valueData.PushBack(newValue);
        sortArray.PushBack(currentPair);
    }
    for (long long i = 0; i < sortArray.Size(); ++i){
        sortArray[i].Value = &valueData[i];
    }

    for (int radixNumber= KEY_SIZE - 1; radixNumber >= 0; --radixNumber){
        long long countingArray[MAX_KEY_VALUE + 1];
        for (unsigned int i = 0; i <= MAX_KEY_VALUE; ++i){
            countingArray[i] = 0;
        }
        for (long long i = 0; i < sortArray.Size(); ++i){
            countingArray[sortArray[i].Key[radixNumber]] += 1;
        }
        for (unsigned int i = 1; i <= MAX_KEY_VALUE; ++i){
            countingArray[i] += countingArray[i - 1];
        }
        item* result = new item[sortArray.Size()];
        for (long long i = sortArray.Size() - 1; i >= 0; --i){
            result[countingArray[sortArray[i].Key[radixNumber]] - 1] = sortArray[i];
            countingArray[sortArray[i].Key[radixNumber]] = countingArray[sortArray[i].Key[radixNumber]] - 1;
        }
        for (long long i = 0; i < sortArray.Size(); ++i){
            sortArray[i] = result[i];
        }
        delete [] result;
    }

    for (long long i = 0; i < sortArray.Size(); ++i){
        for (int j : sortArray[i].Key){
            std::cout << std::hex << std::setw(4) << std::setfill('0') << j;
        }
        std::cout << " " << *sortArray[i].Value << "\n";
    }
    for (long long i = 0; i < valueData.Size(); ++i){
        delete [] valueData[i];
    }
    return 0;
}
