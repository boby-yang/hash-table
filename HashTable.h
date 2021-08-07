#include <string>

class HashTable
{
private:
	string *data;
	int capacity;
	int p2;
	int cur_size;
	bool is_prime(int num);
	int next_prime(int num);

public:
	HashTable();
	HashTable(int n);
	HashTable(const HashTable &src);
	~HashTable();
	HashTable operator=(const HashTable &src);
	void insert(string data);
	bool find(string target);
	int size();
	int maxSize();
	double loadFactor();
}