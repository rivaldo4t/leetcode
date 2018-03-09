#include <iostream>
#include <vector>
#include <climits>
#include <stack>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
 
class MinHeap
{
public:
    
    int *harr;
    int capacity;
    int heap_size;

    MinHeap(int cap)
    {
        harr = new int[cap];
        heap_size = 0;
        capacity = cap;
    }
 
    int parent(int i) { return (i-1)/2; }
 
    int left(int i) { return (2*i + 1); }
 
    int right(int i) { return (2*i + 2); }
 
    int getMin() { return harr[0]; }
 
    void MinHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        
        if(l < heap_size && harr[l] < harr[smallest])
            smallest = l;
        if(r < heap_size && harr[r] < harr[smallest])
            smallest = r;
        if(smallest != i)
        {
            swap(harr[i], harr[smallest]);
            MinHeapify(smallest);
        }
    }
 
    void insertKey(int k)
    {
        if(heap_size == capacity)
        {
            cout << "Nope\n";
            return;
        }
        heap_size++;
        int i = heap_size-1;
        harr[i] = k;
        
        while(i>0 && harr[parent(i)] > harr[i])
        {
            swap(harr[parent(i)], harr[i]);
            i = parent(i);
        }
    }
    
    int extractMin()
    {
        if (heap_size <= 0)
        {
            cout << "asc\n";
            return INT_MAX;
        }
        if (heap_size == 1)
        {
            heap_size--;
            return harr[0];
        }
        
        int root = harr[0];
        harr[0] = harr[heap_size-1];
        heap_size--;
        MinHeapify(0);
        
        return root;
    }
    
    void decreaseKeyAt(int i, int new_val)
    {
        harr[i] = new_val;
        while(i>0 && harr[parent(i)] > harr[i])
        {
            swap(harr[parent(i)], harr[i]);
            i = parent(i);
        }
    }
    
    void deleteKeyAt(int i)
    {
        decreaseKeyAt(i, INT_MIN);
        for(int i = 0; i < heap_size; i++)
        cout << harr[i] << " ";
    cout << endl;
        extractMin();
    }
};

int main()
{
    MinHeap h(50);
    
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKeyAt(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(36);
    
    for(int i = 0; i < h.heap_size; i++)
        cout << h.harr[i] << " ";
    cout << endl;
    
    h.deleteKeyAt(2);
    
    for(int i = 0; i < h.heap_size; i++)
        cout << h.harr[i] << " ";
    cout << endl;
    
    //cout << h.extractMin() << endl;
    
    // cout << h.getMin() << endl;
    // h.decreaseKeyAt(2, 1);
    // cout << h.getMin() << endl;
    return 0;
}