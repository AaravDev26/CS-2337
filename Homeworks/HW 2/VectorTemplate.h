// Aarav Dev
// axd220001

#ifndef VECTORTEMPLATE_H // if VectorTemplate is not defined
#define VECTORTEMPLATE_H // define VectorTemplate
#include <vector> // imports vector library

template<typename T> // signifies templated class
class VectorTemplate // initializes class
{
private:
    std::vector<T> v; // private instance variable
    
public:
    // constructors
    VectorTemplate(); // default constructor
    VectorTemplate(std::vector<T> vect) {v = vect;} // overloaded constructor
    
    void setVector(T t) {v.push_back(t);} // mutator
    std::vector<T> getVector() {return v;} // accessor
    
    void InsertionSort(); // sorts vector in ascending order using insertion sort
    bool BinarySearch(T t); // returns if the parameter value is found in the sorted vector using binary search
};

template<typename T> // signifies templated method
void VectorTemplate<T>::InsertionSort() // sorts vector in ascending order using insertion sort
{
    for(unsigned int j = 1; j < v.size(); j++) // loops through vector
    {
        T t = v[j]; // temporary variable to hold current item
        int i = j-1; // previous item
        while(i >= 0 && v[i] > t) // checks if index is still within bound and if previous item is greater than the current item
        {
            v[i+1] = v[i]; // assigns next value with current item
            i--; // reduces current index by 1
        }
        v[i+1] = t; // assigns next value with current item
    }
}

template<typename T> // signifies templated method
bool VectorTemplate<T>::BinarySearch(T find) // returns if the parameter value is found in the sorted vector using binary search
{
    size_t middle = 0; // middle of the vector
    size_t left = 0; // left side of the vector
    size_t right = v.size(); // right side of the vector
    while (left < right) // while the left variable is less than the right variable
    {
        middle = left + (right - left) / 2; // finds middle of search space
        if (find > v.at(middle)) // if target is greater than the middle of the search space
        {
            left = middle + 1; // move left side one spot over to the right
        }
        else if (find < v.at(middle)) // if target is less than the middle of the search space
        {                                        
            right = middle; // make the middle the new right side
        }
        else 
        {                                                                  
            return true; // if the current middle varibale holds the target value, return true
        }                                                                                                               
    }
    return false; // return false if loop ends without finding target variable
}
#endif // ends if statement after defining class
