#include <iostream>

using namespace std;

class SortBase
{
protected:
    int *a;
    void Swap(int i, int j)
    {
        int t = a[i];
        a[i] = a[j];
        a[j] = a[i];
    }

public:
    virtual void Sort(int *aa, int n)
    {
        a = aa;
    }
};

int main()
{


    return 0;
}