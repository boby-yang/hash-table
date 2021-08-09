#include "HashTable.h"
#include <iostream>
#include <fstream>

void test_find_insert_cross()
{
	HashTable ht1 = HashTable(5);
	ht1.insert("a");
	ht1.insert("c");
	ht1.insert("l");
	ht1.insert("w");
	cout << "All inserts done" << endl;
	ht1.print_table_stats();

	cout << "a in table: " << to_string(ht1.find("a")) << endl;
	cout << "c in table: " << to_string(ht1.find("c")) << endl;
	cout << "l in table: " << to_string(ht1.find("l")) << endl;
	cout << "w in table: " << to_string(ht1.find("w")) << endl; 
	cout << "b in table: " << to_string(ht1.find("b")) << endl;
	cout << "d in table: " << to_string(ht1.find("d")) << endl;
	cout << "z in table: " << to_string(ht1.find("z")) << endl;
}

void test_equal_op()
{
	HashTable ht1 = HashTable(5);
	ht1.insert("a");
	ht1.insert("c");
	ht1.insert("l");
	ht1.insert("w");
	
	HashTable ht2 = ht1;

	cout << "Original Table" << endl;
	ht1.print_table_stats();

	cout << "Copied Table" << endl;
	ht2.print_table_stats();
}

void test_long_str()
{
	HashTable ht1 = HashTable(5);
	ht1.insert("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	ht1.insert("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbb");
	cout << "All inserts done" << endl;
	ht1.print_table_stats();

}

void test_cp_const()
{
	HashTable ht1 = HashTable(5);
	ht1.insert("a");
	ht1.insert("c");
	ht1.insert("l");
	ht1.insert("w");
	
	HashTable ht2 = HashTable(ht1);

	cout << "Original Table" << endl;
	ht1.print_table_stats();

	cout << "Copied Table" << endl;
	ht2.print_table_stats();
}

void test_insert_accuracy()
{
	HashTable ht1 = HashTable(5);
	cout << "Before insert" << endl;
	ht1.print_table_stats();

	ht1.insert("a"); // str value 1
	ht1.insert("c"); // str value 3
	ht1.insert("l"); // str value 12 => 1 -> 3-> 5
	ht1.insert("w"); // str value 23 => 1 -> 6
	cout << "All inserts done" << endl;
	ht1.print_table_stats();
}


void test_word_file(int size, string filename)
{
	ifstream infile(filename);
	HashTable ht1;
	if (size > 0)
		ht1 = HashTable(size);

	cout << "Before insert" << endl;
	ht1.print_table_stats();

	string line;
	while (getline(infile, line, '\n'))
	{
		ht1.insert(line);
	}

	cout << "All inserts done" << endl;
	ht1.print_table_stats();
}


int main()
{
	// test_word_file(-1, "wordlist1000.txt");
	// test_word_file(10, "wordlist31.txt");
	// test_word_file(5, "wordlist10.txt");
	// test_insert_accuracy();
	// test_cp_const();
	// test_equal_op();
	// test_find_insert_cross();
	test_long_str();
	return 0;
}