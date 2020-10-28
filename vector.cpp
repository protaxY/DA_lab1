#include "vector.h"

template <class T>
TVector<T>::TVector(){
    TVectorSize = 0;
    TVectorCapacity = 0;
    Data = nullptr;
}
template <class T>
 long long TVector<T>::Size(){
    return TVectorSize;
}
template <class T>
void TVector<T>::PushBack(const T &elem){
    if (TVectorCapacity == 0){
        TVectorCapacity = 1;
        TVectorSize = 0;
        Data = new T[TVectorCapacity];
    }
    else if (TVectorCapacity == TVectorSize){
        TVectorCapacity *= 2;
        T* newData = new T[TVectorCapacity];
        for (long long i = 0; i < TVectorSize; ++i){
            newData[i] = Data[i];
        }
        delete [] Data;
        Data = newData;
    }
    TVectorSize += 1;
    Data[TVectorSize - 1] = elem;
}
template <class T>
T& TVector<T>::operator[] (const long long iterator){
    return Data[iterator];
}
template <class T>
TVector<T>::~TVector(){
    delete [] Data;
}