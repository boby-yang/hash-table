#include "HashTable.h"

/*
 * Default constructor of the HashTable
 * Param: None
 * Post: creates a hash table of size 101;
 * sets all array elements to the empty string ("");
 * sets cur_size to 0
 * sets P2, the value used by h2
 */
HashTable::HashTable()
{
	capacity = 101;
	cur_size = 0;
	sec_hash_const = next_prime(capacity / 2);
	data = new string[capacity];
	for (int i = 0; i < capacity; ++i)
	{
		data[i] = "";
	}
}

/*
 * Constructor of the HashTable
 * Param: number of strings to store
 * Post: creates a hash table to store n items;
 * capacity should be the smallest prime >= 2n
 * sets all array elements to the empty string ("");
 * sets cur_size to 0
 * sets P2, the value used by h2
 */
HashTable::HashTable(int n)
{
	capacity = next_prime(2 * n - 1);
	cur_size = 0;
	sec_hash_const = next_prime(capacity / 2);
	data = new string[capacity];
	for (int i = 0; i < capacity; ++i)
	{
		data[i] = "";
	}
}

/*
 * Copy constructor of the HashTable
 * Param: constant reference of a HashTable object
 * Post: creates a deep copy of the HashTable parameter;
 */
HashTable::HashTable(const HashTable &src)
{
	capacity = src.capacity;
	cur_size = src.cur_size;
	sec_hash_const = src.sec_hash_const;
	data = new string[capacity];
	for (int i = 0; i < capacity; ++i)
	{
		data[i] = src.data[i];
	}
}

/*
 * Destructor of the QueueT
 * Param: none
 * Post: table of strings will be deleted
 */
HashTable::~HashTable()
{
	delete[] data;
}

/*
 * Overridden assignment operation of the HashTable
 * Param: constant reference of a HashTable object
 * Post:(parameter != this) all strings in the HashTable will deleted;
 * 		cur_size will be set to parameter's cur_size;
 * 		capacity will be set to parameter's capacity;
 * 		all string in parameter will be copied in order
 */
HashTable HashTable::operator=(const HashTable &src)
{
	if (&src != (const HashTable *) this)
	{
		if (nullptr != data)
		{
			delete[] data;
		}		
		capacity = src.capacity;
		cur_size = src.cur_size;
		sec_hash_const = src.sec_hash_const;
		data = new string[capacity];
		for (int i = 0; i < capacity; ++i)
		{
			data[i] = src.data[i];
		}
	}
	return *this;
}


/*
 * Pre: HashTable obj need to be created
 * Param: string to insert to table
 * Post: searches the hashtable for the parameter, 
 * if not found, inserts the param into the hash table;
 * then check load factor, if lf > 0.67 after insertion:
 * (1) create new hashtable of size first prime > 2 * original size
 * (2) inserts the original contents in the new table at the appropriate places
 * (3) sets the value used by h2
 */
void HashTable::insert(string str)
{


	// cout << "Insert "  << str << endl;


	if (false == find(str))
	{
		int cur_index = get_hash_index(str, capacity);
		int h2_gap = sec_hash_const - get_hash_index(str, sec_hash_const);

		// cout << "Initial index:" << to_string(cur_index) << endl;
		// cout << "Gap:" << to_string(h2_gap) << endl;

		while ("" != data[cur_index])
		{


			// cout << "Looking at index:" << to_string(cur_index) << endl;


			cur_index = (cur_index + h2_gap) % capacity;
		}
		data[cur_index] = str;
		cur_size++;


		// cout << "Insert " << str << " at index:" << to_string(cur_index) << endl;
		// print_table_stats();
		// cout << endl;


		if (loadFactor() > 0.67)
		{

			// cout << "Table needs expansion" << endl;

			int new_size = next_prime(2 * capacity);
			int old_size = capacity;
			string *new_data = new string[new_size];
			for (int i = 0; i < new_size; ++i)
			{
				new_data[i] = "";
			}
			string *tmp = data;
			data = new_data;
			capacity = new_size;
			sec_hash_const = next_prime(new_size / 2);
			cur_size = 0;


			// cout << "Before migration:" << endl;
			// print_table_stats();
			// cout << endl;


			for (int i = 0; i < old_size; ++i)
			{
				if ("" != tmp[i])
				{
					insert(tmp[i]);	
				}				
			}



			// cout << "After migration:" << endl;
			// print_table_stats();
			// cout << endl;


			delete[] tmp; // need to test for valgrind
		}
	}
}

/*
 * Pre: HashTable obj need to be created
 * Param: string for target to look for
 * Post: returns true if its string parameter is in the hash table
 * returns false if it is not
 */
bool HashTable::find (string target) const
{
	// cout << "Searching for " << target << endl;
	if ("" == target)
	{
		return false;
	}
	int cur_index = get_hash_index(target, capacity);
	int h2_gap = sec_hash_const - get_hash_index(target, sec_hash_const);

	// cout << "Initial index:" << to_string(cur_index) << endl;
	// cout << "Gap:" << to_string(h2_gap) << endl;

	while ("" != data[cur_index])
	{
		if (target == data[cur_index])
		{
			return true;
		}
		cur_index = (cur_index + h2_gap) % capacity;


		// cout << "Cur index = " << to_string(cur_index) << " Gap:" << to_string(h2_gap) << endl;


	}
	return false;
}

/*
 * Pre: HashTable obj need to be created
 * Param: none
 * Post: returns number of strings in the HashTable
 */
int HashTable::size()
{
	return cur_size;
}

/*
 * Pre: HashTable obj need to be created
 * Param: none
 * Post: returns capacity of the HashTable
 */
int HashTable::maxSize()
{
	return capacity;
}

/*
 * Pre: capacity cannot be 0
 * Param: none
 * Post: returns load factor of the HashTable
 */
double HashTable::loadFactor()
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
bool HashTable::is_prime(int num)
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
 * Param: an integer
 * Post: returns the smallest prime number
 * greater than the parameter
 */
int HashTable::next_prime(int num)
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

/*
 * Pre: none
 * Param: string to calculate the string value
 * Post: returns the index of hash function using the equation:
 * ch0 * 32^n-1 + ch1 * 32^(n-2) + ... + ch(n-2) * 32^1 + ch(n-1) * 32^0
 * and we use honer's method to avoid overflowing
 */
int HashTable::get_hash_index(string str, int mod_val) const
{	
	if (0 == str.size())
	{
		return 0;
	}
	int out = 0;
	for (int i = 0; i < str.size(); ++i)
	{		
		int ascii = str[i] - 96;
		out = (32 * out + ascii) % mod_val;
	}
	return out;
}



///// for testing purpose
void HashTable::print_table_stats()
{
	cout << "Table stats:" << endl;
	cout << "Size:" << to_string(cur_size) << endl;
	cout << "Capacity:" << to_string(capacity) << endl;
	cout << "P2:" << to_string(sec_hash_const) << endl;
	cout << "Load:" << to_string(loadFactor()) << endl;

	int cnt = 0;
	cout << "Data:" << endl;
	for (int i = 0; i < capacity; ++i)
	{
		if ("" != data[i])
		{	
			cout << to_string(i) << ":" << data[i] << " ";
			++cnt;
		}
	}
	cout << endl;
	cout << "Num valid data:" << to_string(cnt) << endl;
	cout << endl;
}
/////
