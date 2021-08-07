#include <string>

class HashTable
{
private:
	string *data;
	int capacity;
	int h2_param;
	int cur_size;

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