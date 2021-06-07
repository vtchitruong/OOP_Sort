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

//----------------------------------------
void SelectionSort::Sort(int *aa, int n)
{
    SortBase::Sort(aa, n);
    
    int k;
    for (int i = 0; i < n - 1; ++i)
    {
        k = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (a[j] < a[k]) k = j;
            if (k != j) swap(i, k);
        }
    }
}

int main()
{


    return 0;
}