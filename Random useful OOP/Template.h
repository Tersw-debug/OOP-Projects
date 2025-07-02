#ifndef TEMPLATE_H_INCLUDED
#define TEMPLATE_H_INCLUDED
#include <deque>

template<class T>
class SiArray
{
public:
    T& top()
    {
        return stack.front();
    }
    void push(const T& pushvalue)
    {
        stack.push_front(pushvalue);
    }
    void pop()
    {
        stack.pop_front();
    }
    bool isEmpty() const
    {
        return stack.empty();
    }
    size_t size() const
    {
        return stack.size();
    }
private:
    std::deque< T > stack;
};
/*template<class T>
bool operator==(T x, T y)
{
        return (x == y)? true:false;
}

template<class T>
bool isEqualto(
    Simple< T >&ptrFirst,
    Simple< T >&ptrSecond,
    string value1,
    string value2
    )
{

    T pushvalue = value1;
    ptrFirst.push(pushvalue);
    pushvalue = value2;
    ptrSecond.push(pushvalue);
    if(ptrFirst.top() == ptrSecond.top())
        return true;
    else
        return false;
}

template<class T>
bool isEqualto(
    Simple< T >&ptrFirst,
    Simple< T >&ptrSecond,
    T pushvalue,
    T pushvalue1
    )
{

    ptrFirst.push(pushvalue);
    ptrSecond.push(pushvalue1);
    if(ptrFirst.top() == ptrSecond.top())
        return true;
    else
        return false;
}
    Simple< string > stringSimple;
    Simple< string > stringSimpl1;
    cout << isEqualto(stringSimple,stringSimpl1,"Hello","Hello") << endl;
    cout << isEqualto(stringSimpl1,stringSimpl1,"Value","Value") << endl;

*/

#endif // TEMPLATE_H_INCLUDED
