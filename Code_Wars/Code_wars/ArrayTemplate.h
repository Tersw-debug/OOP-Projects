#ifndef ARRAYTEMPLATE_H_INCLUDED
#define ARRAYTEMPLATE_H_INCLUDED

template< class T >
class Array
{
    friend std::ostream &operator<<(std::ostream &output, const Array &);
    friend std::istream &operator>>(std::istream &input, Array &);
public:
    explicit Array(int = 10);
    Array(T arr[], const Array &);
    ~Array();
    size_t getSize() const;

    const Array &operator=(const Array &);
    bool operator==(const Array &) const;
    bool operator!=(const Array &arr) const
    {
        return !(*this == arr);
    }
    int &operator[](int);
    int operator[](int) const;

private:
    size_t size;
    T *ptr;
};
/*

template< class T > Array<T>::Array(int arraySize)
    :   size((arraySize > 0)? arraySize : throw invalid_argument("array size must be > 0")), ptr(new int[size])
{
    for(size_t i = 0;i < size;++i)
        ptr[i] = 0;
}


template<class T > Array<T>::Array(T arr[],const Array &arrCopy)
    :   size(arrCopy.size), ptr(new T[size])
{
    for(size_t i = 0;i < size;++i)
        ptr[i] = arrCopy.ptr[i];

}

template<class T > Array<T>::~Array()
{
    delete [] ptr;
}

template<class T >
size_t Array<T>::getSize() const
{
    return size;
}

template<class T>
const Array<T> &Array<T>::operator=(const Array &arr)
{
    if( &arr != this)
    {
        if(arr.size != size)
        {
            delete [] ptr;
            size = arr.size;
            ptr = new T[size];
        }
        for(size_t i = 0; i < size;++i)
            ptr[i] = arr.ptr[i];
    }


    return *this;
}




template<class T>
bool Array<T>::operator==(const Array &arr) const
{
    if(size != arr.size)
        return false;
    for(size_t i = 0;i < size;i++)
        if(ptr[i] != arr.ptr[i])
            return false;
    return true;
}

template<class T>
int &Array<T>::operator[](int arraysize)
{
    if(arraysize < 0 || arraysize > size)
        throw invalid_argument("Invalid: out of range");
    return ptr[arraysize];
}


template<class T>
int Array<T>::operator[](int arraysize) const
{
    if(arraysize < 0 || arraysize > size)
        throw invalid_argument("Invalid: out of range");
    return ptr[arraysize];
}

template<class T>
istream &operator>>(istream &input, Array<T> &a)
{
    for(size_t i = 0; i <a.size;++i)
        input >> a.ptr[i];
    return input;
}

template<class T>
ostream &operator<<(ostream &output, const Array<T> &a)
{
    for(size_t i = 0; i < a.size;++i)
    {
        output << setw( 12 ) << a.ptr[i];
        if((i+1) % 4 == 0)
            output << endl;
    }
    if(a.size % 4 != 0)
        output<<endl;
    return output;
}
*/


#endif // ARRAYTEMPLATE_H_INCLUDED
