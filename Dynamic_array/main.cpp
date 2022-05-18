#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

template<class T>
class Array
{
    T *arr;
    int size_of_array;
    int capacity;
public:
    Array();
    ~Array();

    T& operator [] (int);
    void set_size_of_array(int);
    int get_size_of_array();
    void push_back(const T&);
    void Delete_an_element(int);
    int get_index_of_element(int, int, T);
    void remove_if(int, int, T);
    void Delete_array();
};


template <class T>
Array<T>::Array()
{
    size_of_array = 0;
    capacity = 4;
    arr = (T*)malloc(capacity*sizeof(T));
    for (int i = 0; i < capacity; i++)
    {
        arr[i] = NULL;
    }

    if (arr == NULL)
        cout<<"The array is empty"<<endl;
}


template <class T>
Array<T>::~Array()
{
    if (arr)
    {
        free(arr);
        arr = NULL;
    }
}

template <class T>
void Array<T>::set_size_of_array( int new_size)
{


    if (new_size < 0)
        cout<<"Size Cannot be 0"<<endl;
    else
    {
        size_of_array = new_size;
        if ((size_of_array > capacity) || (size_of_array < capacity/2))
        {
            capacity = size_of_array;
            arr = (T *)realloc(arr, sizeof(T)*size_of_array);

            if (arr == NULL)
            {
                cout<<"The array is empty"<<endl;
                exit(1);
            }
        }
    }

}

template <class T>
int Array<T>::get_size_of_array()
{
    return size_of_array;
}

template <typename T>
void display_array(Array<T> &arr)
{
    for( int i=0; i<arr.get_size_of_array(); i++)
        cout << arr[i] << " ";

    cout << endl;
}

template <class T>
void Array<T>::push_back(const T &element)
{
    size_of_array++;

    if (size_of_array > capacity)
    {
        capacity *= 2;

        arr = (T *)realloc(arr, sizeof(T)*capacity);

        if (arr == NULL)
        {
            cout<<"The array is empty"<<endl;
            exit(1);
        }
    }

    arr[size_of_array-1] = element;
}

template <class T>
T& Array<T>::operator [] (int index)
{
    if (index < 0 || index >= size_of_array)
        throw invalid_argument( "Out of Bounds!" );
    return arr[index];
}

template <class T>
void Array<T>::Delete_array()
{
    size_of_array = 0;
    arr = (T *)realloc(arr, sizeof(T)*0);
    capacity = 0;
}

template <class T>
void Array<T>::Delete_an_element(int index)
{
    if (size_of_array == 1)
        Delete_array();
    else
    {
        for( int i=index; i<size_of_array-1; i++)
            arr[i] = arr[i+1];

        size_of_array--;
    }
}
/*
template <class T>
int bin_search(T arr[], int left, int right, T target)
{

    int mid = left + (right - left) / 2;
    while(left <= right)
    {
        if (arr[mid] == target)
            return mid;
        else if(target < arr[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
        mid = left + (right - left) / 2;
    }
    return -1;
}
*/
template <class T>
int search_in_array(T arr[], int left, int right, T condition)
{
    for (int i = left + 1; i < right; i++)
    {
        if (arr[i] == condition)
            return i;
    }
    return -1;
}

template <class T>
int Array<T>::get_index_of_element(int left, int right, T condition)
{
    return search_in_array(arr, left, right, condition);
}


template <class T>
void Array<T>::remove_if(int start, int endd, T condition)
{
    if ((endd - start) <= 0)
        cout<<"Range is not available...\n";
    else if (start < 0 || endd > size_of_array)
        cout<<"This Range is Out Of Bounds!!";
    else
    {
        int index = get_index_of_element(start, endd, condition);
        if ( index < start || index > endd)
            cout<<"The Condition is Not Found in this range...\n";
        else
        {
            while(index != -1)
            {
                Delete_an_element(index);
                endd--;
                index = get_index_of_element(start, endd, condition);
            }
        }
    }
}



int main(void)
{
    int size_of_array;
    Array<int> arr1;
    cout <<"Enter the size of the array: ";
    cin>> size_of_array;
    cout<<endl;
    arr1.set_size_of_array(size_of_array);

    cout<<"Now you need to push_back elements to the array....."<<endl;
    for (int i = 0; i < size_of_array; i++)
    {
        cin>>arr1[i];
    }
    display_array(arr1);
    arr1.push_back(6);
    arr1.push_back(11);
    arr1.push_back(8);
    arr1.push_back(9);
    arr1.push_back(10);
    arr1.push_back(11);
    arr1.push_back(11);
    arr1.push_back(11);
    arr1.push_back(11);
    arr1.push_back(11);
    arr1.push_back(14);
    cout<<"Array Before Removing.... with range 3 and 9\n";
    display_array(arr1);
    arr1.remove_if(3,9,11);
    cout<<"Array After Removing....\n";
    display_array(arr1);

/////////////////////////////////////////////
    Array<char> arr2;
    arr2.push_back('a');
    arr2.push_back('b');
    arr2.push_back('c');
    arr2.push_back('d');
    arr2.push_back('e');
    arr2.push_back('f');
    arr2.push_back('g');
    arr2.push_back('h');
    arr2.push_back('t');
    cout<<"Array Before Removing.... with range 0 and 5\n";
    display_array(arr2);
    arr2.remove_if(0,5,'a');
    cout<<"Array After Removing....\n";
    display_array(arr2);


    /////////////////////////////////////////////
    Array<float> arr3;
    arr3.push_back(1.1);
    arr3.push_back(1.2);
    arr3.push_back(1.3);
    arr3.push_back(1.4);
    arr3.push_back(1.5);
    arr3.push_back(1.6);
    arr3.push_back(1.7);

    cout<<"Array Before Removing.... with range 0 and 6\n";
    display_array(arr3);
    arr3.remove_if(0,6,1.2);
    cout<<"Array After Removing....\n";
    display_array(arr3);
    arr1.~Array();
    arr2.~Array();
    arr3.~Array();
    return 0;
}


