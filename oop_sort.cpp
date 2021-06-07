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
    void qsort(int left, int right);
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

//-----------------------------------------
void QuickSort::qsort(int left, int right)
{
    int x, l, r;
    if (left < right)
    {
        x = a[left];
        l = left;
        r = right + 1;

        do
        {
            ++l;
            --r;

            while (l < right && a[l] < x) ++l;
            while (a[r] > x) --r;
            
            if (l < r) swap(l, r);
        } while (l < r);

        swap(left, r);
        qsort(left, r - 1);
        qsort(r + 1, right);
    }
}

void QuickSort::Sort(int *aa, int n)
{
    SortBase::Sort(aa, n);
    qsort(0, n - 1);
}

int main()
{


    return 0;
}