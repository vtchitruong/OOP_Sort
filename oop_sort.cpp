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

class SelectionSort : public SortBase
{
public:
    virtual void Sort(int *aa, int n);
};

class QuickSort : public SortBase
{
private:
    void qsort(int l, int r);
public:
    virtual void Sort(int *aa, int n);
};

class HeapSort : public SortBase
{
private:
    void Shift(int i, int n);
public:
    virtual void Sort(int *aa, int n);
};

int main()
{


    return 0;
}