// Aarav Dev
// axd220001

#include "Ant.h"
using namespace std; // used to avoid using "std::" in many instances, shortens code

int Ant::move(int a, int b, int c, int d) const
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
            //If current value is less than min value
            // then replace it with min value
            max = arr[i];
        }
    }
    int firstNeg = -1;
    for(unsigned int i=0; i < 4; i++)
    {
        if (arr[i] >= 10) {
            firstNeg = i;
            break;
        }
    }
    int numMin;
    for(unsigned int i=0; i < 4; i++)
    {
        if (arr[i] == min) {
            numMin++;
        }
    }
    
    
    if (min >= 10) {
        return 0;
    }
    
    if (max < 10) {
        if (minInd == 0) {
            return 3;
        }
        if (minInd == 1) {
            return 4;
        }
        if (minInd == 2) {
            return 1;
        }
        if (minInd == 3) {
            return 2;
        }
    }
    
    if (firstNeg != -1 && min < 10 && numMin > 1) {
        if (firstNeg == 0) {
            return 1;
        }
        if (firstNeg == 1) {
            return 2;
        }
        if (firstNeg == 2) {
            return 3;
        }
        if (firstNeg == 3) {
            return 4;
        }
    }
    
    return 5;
}

int Ant::breed(int a, int b, int c, int d) const
{
   if (a > 0) {
       return 1;
   }
   if (b > 0) {
       return 2;
   }
   if (c > 0) {
       return 3;
   }
   if (d > 0) {
       return 4;
   }
   return 0;
}
