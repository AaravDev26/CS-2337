// Aarav Dev
// axd220001

#include "Beetle.h" // includes beetle header file
using namespace std; // used to avoid using "std::" in many instances, shortens code

int Beetle::move(int a, int b, int c, int d) const // beetle move method
{
   int arr[] = {a, b, c, d};
    //Intialize the value of min and index
    int min = arr[0];
    int max = arr[0];
    int minInd = -1;
    // Iterate the array
    for(unsigned int i=0; i < 4; i++)
    {
        if(arr[i] < min)
        {
            //If current value is less than min value
            // then replace it with min value
            min = arr[i];
            minInd = i;
        }
        if(arr[i] > max)
        {
            //If current value is greater than max value
            // then replace it with max value
            max = arr[i];
        }
    }
    int numMin = 0;
    for(unsigned int i=0; i < 4; i++)
    {
        if (arr[i] == min) {
            numMin++;
        }
    }
    
    if (min >= 10)
    {
        int array[] = {a%10, b%10, c%10, d%10};
        //Intialize the value of min and index
        int m = array[0];
        int mi = -1;
        // Iterate the array
        for(unsigned int i=0; i < 4; i++)
        {
            if(array[i] > m)
            {
                //If current value is greater than max value
                // then replace it with max value
                m = array[i];
                mi = i;
            }
        }
        if (mi == 0) {
            return 1;
        }
        if (mi == 1) {
            return 2;
        }
        if (mi == 2) {
            return 3;
        }
        if (mi == 3) {
            return 4;
        }
    }
    
    if (numMin == 1)
    {
        if (minInd == 0) {
            return 1;
        }
        if (minInd == 1) {
            return 2;
        }
        if (minInd == 2) {
            return 3;
        }
        if (minInd == 3) {
            return 4;
        }
    }
    
    if (numMin > 1) //come back here
    {
        if (minInd == 0) {
            return 1;
        }
        if (minInd == 1) {
            return 2;
        }
        if (minInd == 2) {
            return 3;
        }
        if (minInd == 3) {
            return 4;
        }
    }
    return 0;
}

int Beetle::breed(int a, int b, int c, int d) const
{
   if (a > 0) {
       return 1;
   }
   else if (b > 0) {
       return 2;
   }
   else if (c > 0) {
       return 3;
   }
   else if (d > 0) {
       return 4;
   }
   else {
       return 0;
   }
}

int Beetle::starve() const {return 0;}
