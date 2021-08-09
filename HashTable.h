#pragma once
#include <string>

using namespace std;


///// for testing purpose
#include <iostream>
/////

class HashTable
{
private:
	string *data;
	int capacity;
	int sec_hash_const;
	int cur_size;
	bool is_prime(int num);
	int next_prime(int num);
	int get_hash_index(string str, int mod_val)const;

public:
	HashTable();
	HashTable(int n);
	HashTable(const HashTable &src);
	~HashTable();
	HashTable operator=(const HashTable &src);
	void insert(string strs);
	bool find (string target)const;
	int size();
	int maxSize();
	double loadFactor();

	///// for testing purpose
	void print_table_stats();
	/////
};