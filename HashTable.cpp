#include "HashTable.h"

/*
 * Default constructor of the HashTable
 * Param: None
 * Post: creates a hash table of size 101;
 * sets all array elements to the empty string ("");
 * sets cur_size to 0
 * sets P2, the value used by h2
 */
HashTable()
{
	capacity = 101;
	cur_size = 0;
	p2 = next_prime(capacity);
	data = new string(capacity);
	for (int i = 0; i < capacity; ++i)
	{
		data[i] = "";
	}
}

HashTable(int n)
{

}

HashTable(const HashTable &src)
{

}

~HashTable()
{

}


HashTable operator=(const HashTable &src)
{
	return *this;
}

void insert(string data)
{

}

bool find(string target)
{
	return false;
}

/*
 * Pre: HashTable obj need to be created
 * Param: none
 * Post: returns number of strings in the HashTable
 */
int size()
{
	return cur_size;
}

/*
 * Pre: HashTable obj need to be created
 * Param: none
 * Post: returns capacity of the HashTable
 */
int maxSize()
{
	return capacity;
}

/*
 * Pre: capacity cannot be 0
 * Param: none
 * Post: returns load factor of the HashTable
 */
double loadFactor()
{
	return (double)cur_size / capacity;
}

/** Helper Functions **/

/*
 * Pre: none
 * Param: integer to check if number is prime
 * Post: returns true if param is prime
 * false otherwise
 */
bool is_prime(int num)
{
	for (int i = 2; i * i <= num; ++i)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

/*
 * Pre: none
 * Param: integer
 * Post: returns the smallest prime number
 * greater than the parameter
 */
int next_prime(int num)
{
	for (int i = num + 1; ;++i)
	{
		if (is_prime(i))
		{
			return i;
		}		
	}
	return -1; // should never reach here
}