#include <iostream>
#include <time.h>

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
            if (k != j) Swap(i, k);
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
            
            if (l < r) Swap(l, r);
        } while (l < r);

        Swap(left, r);
        qsort(left, r - 1);
        qsort(r + 1, right);
    }
}

void QuickSort::Sort(int *aa, int n)
{
    SortBase::Sort(aa, n);
    qsort(0, n - 1);
}

//---------------------------
void HeapSort::Shift(int i, int n)
{
    int l, r, k;
    l = 2 * i;
    r = l + 1;

    if (l > n) return;

    if (l == n)
    {
        if (a[i] < a[l]) Swap(i, l);
        return;
    }

    if (a[l] > a[r])
    {
        k = l;
    }
    else
    {
        k = r;
    }

    if (a[i] >= a[k])
    {
        return;
    }
    else
    {
        Swap(i, k);
        Shift(k, n);
    }     
}

void HeapSort::Sort(int *aa, int n)
{
    SortBase::Sort(aa, n);

    for (int i = n / 2; i > 0; --i)
    {
        Shift(i, n);
    }

    for (int i = n - 1; i > 1; --i)
    {
        Swap(1, i);
        Shift(1, i - 1);
    }
}

int main()
{
    int n = 10000;
    int *arr;
    arr = (int*) malloc((n+1) * sizeof(int));

    SortBase *sb[3];
    SelectionSort ss;
    QuickSort qs;
    HeapSort hs;

    sb[0] = &ss;
    sb[1] = &qs;
    sb[2] = &hs;

    srand(time(NULL));
    for (int k = 0; k < 3; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            arr[i] = rand() % 10000 + 1;
        }

        
        sb[k]->Sort(arr, n);
    }

    return 0;
}