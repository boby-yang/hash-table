#include "HashTable.h"
#include "spellcheck.h"
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

void print_vector(vector<string> v)
{
	for (auto i = v.begin(); i != v.end(); ++i)
	{
		cout << *i << ",";
	}

	cout << endl;
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
	// test_long_str();


	//// pt 2 table
	// All ex strings in table
	HashTable ht = HashTable(3);
	vector<string> que = {"chate", "atr", "rateat", "poe", "thed"};
	vector<string> ans = {"chat", "hate", "art", "tar", "rat", "eat", "rate","at", "poet", "poke", "pole", "pope", "pose", "shed", "thee", "them", "they", "thud", "toed"};
	vector<string> not_ans = {"hat", "cat", "rat", "poetry", "shad", "thus"};

	for (auto it = que.begin(); it != que.end(); ++it)
	{
		ht.insert(*it);
	}


	vector<string> extra_fd = extraLetter(ht, "chate");
	print_vector(extra_fd);

	vector<string> trans_fd = transposition(ht, "atr");
	print_vector(trans_fd);

	vector<string> missing_sp_fd = missingSpace(ht, "rateat");
	print_vector(missing_sp_fd);

	vector<string> missing_lt_fd = missingLetter(ht, "poe");
	print_vector(missing_lt_fd);

	vector<string> incorrect_fd = incorrectLetter(ht, "thed");
	print_vector(incorrect_fd);


	// All not in
	HashTable ht2 = HashTable(3);
	for (auto it = ans.begin(); it != ans.end(); ++it)
	{
		ht2.insert(*it);
	}

	for (auto it = not_ans.begin(); it != not_ans.end(); ++it)
	{
		ht2.insert(*it);
	}
	extra_fd = extraLetter(ht2, "chate");
	print_vector(extra_fd);

	trans_fd = transposition(ht2, "atr");
	print_vector(trans_fd);

	missing_sp_fd = missingSpace(ht2, "rateat");
	print_vector(missing_sp_fd);

	missing_lt_fd = missingLetter(ht2, "poe");
	print_vector(missing_lt_fd);

	incorrect_fd = incorrectLetter(ht2, "thed");
	print_vector(incorrect_fd);

	return 0;
}