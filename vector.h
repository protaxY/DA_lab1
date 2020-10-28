#ifndef LAB1_TVector_H
#define LAB1_TVector_H
template <class T>
class TVector{
    private:
        long long TVectorSize;
        long long TVectorCapacity;
        T* Data;
    public:
        TVector();
        long long Size();
        void PushBack(const T &elem);
        T& operator[] (const long long iterator);
        ~TVector();
};
#endif
