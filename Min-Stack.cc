#include <iostream>
#include <vector>
using namespace std;

class MinStack 
{
    int s[10000];
    int topIndex;
    int minIndex;
    
public:
    MinStack() 
    {
        topIndex = -1;
        minIndex = -1;
    }
    
    void push(int x) 
    {
        if(topIndex == N-1)
        {
            cout << "invalid push" << endl;
            return;
        }
        
        topIndex++;
        s[topIndex] = x;
        
        if(minIndex == -1)
            minIndex = 0;
        else if(s[minIndex] > x)
            minIndex = topIndex;
    }
    
    void pop() 
    {
        if(topIndex == -1)
        {
            cout << "invalid pop" << endl;
            return;
        }
        
        if(minIndex == topIndex)
        {
            minIndex = 0;
            for(int i = 1; i < topIndex; i++)
                if(s[minIndex] > s[i])
                    minIndex = i;
        }
        
        topIndex--;
        return;
    }
    
    int top() 
    {
        if(topIndex == -1)
        {
            cout << "invalid top" << endl;
            return -1;
        }
        
        return s[topIndex];
    }
    
    int getMin() 
    {
        if(minIndex == -1)
        {
            cout << "invalid getMin" << endl;
            return -1;
        }
        return s[minIndex];
    }
};

int main()
{
    MinStack obj;
    obj.push(-2);
    obj.push(0);
    obj.push(-3);
    cout << obj.top() << endl;
    cout << obj.getMin() << endl;
    obj.pop();
    cout << obj.getMin() << endl;
    return 0;
}