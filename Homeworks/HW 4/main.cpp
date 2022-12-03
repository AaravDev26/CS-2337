// Aarav Dev
// axd220001

#include <iostream> // common import, used for cout and cin

using namespace std; // used to avoid putting std:: in front of every statement which requries the std namespace

const double loadFactor = 0.5; // holds the load factor for the hash table, rehash when load factor is greater than this amount
void insert(int arr[], int size, int item); // function to insert item into hash table
int* rehash(int arr[], int size); // resizes hash table
int nextPrime(int n); // finds next prime number
bool isPrime(int n); // checks if number is prime
double getLoadFactor(int table[], int size); // returns load factor of hash table
void print(int table[], int size); // prints contents of hash table, if empty print underscore

int main() // main method
{
    int size = 11; // size of hash table, initial value is 11
    int numValues; // number of values to be entered
    cout << "How many values will be entered?" << endl; // prompting user
    cin >> numValues;
    int* nums = new int[numValues]; // array to hold input numbers
    int* hashTable = new int[size]; // hash table
    // setting initial values to zero
    for (int i = 0; i < 11; i++)
    {
        hashTable[i] = 0;
    }
    // getting input
    for (int i = 0; i < numValues; i++)
    {
        cin >> nums[i];
    }
    // inserting all numbers into hash table, resizing when necessary
    for (int i = 0; i < numValues; i++)
    {
        if (getLoadFactor(hashTable, size) > loadFactor)
        {
            hashTable = rehash(hashTable, size); // resizing
            size = nextPrime(size * 2);
        }
        insert(hashTable, size, nums[i]);
    }
    print(hashTable, size); // printing hash table
    return 0; // signifies end of main method
}

void insert(int arr[], int size, int item) // insert item into hash table
{
    int i = 0;
    int bucketsProbed = 0;
    int bucket = (item % size) % size;
    while (bucketsProbed < size)
    {
        if (!arr[bucket]) // if empty
        {
            arr[bucket] = item; // update
            return;
        }
        i++;
        bucket = ((item % size) + (i*i)) % size; // calculating new bucket
        bucketsProbed++;
    }
}

int* rehash(int arr[], int size)
{
    int n = nextPrime(size * 2); // finding new size
    int* temp = new int[n]; // creating new array
    // setting initial elements to zero
    for (int i = 0; i < n; i++)
    {
        temp[i] = 0;
    }
    // inserting items into new array
    for (int i = 0; i < size; i++)
    {
        if (arr[i])
        {
            insert(temp, n, arr[i]);
        }
    }
    return temp;
}

int nextPrime(int n)
{
    int ans = n;
    bool found = false;

    //loop continuously until isPrime returns true for a number above n
    while (!found)
    {
        ans++;
        if (isPrime(ans))
        {
            found = true;
        }
    }
    return ans;
}

//given a number n, determine if it is prime
bool isPrime(int n)
{
    //loop from 2 to n/2 to check for factors
    for (int i = 2; i <= n/2; i++)
    {
        if (n % i == 0)     //found a factor that isn't 1 or n, therefore not prime
        {
            return false;
        }
    }

    return true;
}

double getLoadFactor(int table[], int size) // returns laod factor of hash table array
{
    double ans = 0.0; // holds answer
    for (int i = 0; i < size; i++)
    {
        if (table[i]) // if not empty
        {
            ans++;
        }
    }
    return ans/size;
}

void print(int table[], int size) // prints contents of hash table, if empty print underscore
{
    // looping through hash table
    for (int i = 0; i < size; i++)
    {
        if (table[i])
        {
            cout << table[i] << " ";
        }
        else
        {
            cout << "_ ";
        }
    }
    cout << endl;
}
