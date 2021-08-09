#include "HashTable.h"
#include <vector>

/*
 * Function to find word or strings in HashTable with one extra letter
 * Param: constant reference to hashtable and string to look for
 * Post: if word is not in dict returns all strings in dict
 * that can be made by deleting a single letter from word
 */ 
vector<string> extraLetter(const HashTable & dict, string word)
{
	vector<string> out;

	if (true == dict.find(word))
	{
		out.push_back(word);
	}
	else
	{
		for (int i = 0; i < word.size(); ++i)
		{
			string tmp = word;
			tmp.erase(i, 1);
			if (true == dict.find(tmp))
			{
				out.push_back(tmp);
			}
		}
	}
	return out;
}

/*
 * Function to find word or strings in HashTable that can become word by swapping
 * two adjacent letters
 * Param: constant reference to hashtable and string to look for
 * Post: if word is not in dict returns all strings in dict
 * that can be made swapping any two adjacent letters in word
 */
vector<string> transposition(const HashTable & dict, string word)
{
	vector<string> out;

	if (true == dict.find(word))
	{
		out.push_back(word);
	}
	else
	{
		for (int i = 0; i < word.size() - 1; ++i)
		{
			string tmp = word;
			swap(tmp[i], tmp[i + 1]);
			if (true == dict.find(tmp))
			{
				out.push_back(tmp);
			}
		}
	}
	return out;
}

/*
 * Function to find word or pairs of strings in HashTable that can be made by
 * inserting a space in word
 * Param: constant reference to hashtable and string to look for
 * Post: if word is not in dict returns all pairs of strings in dict 
 * that can be made by inserting a single space in word; 
 * each string in the result should consist of the two strings from dict 
 * separated by a space
 */
vector<string> missingSpace(const HashTable & dict, string word)
{
	vector<string> out;

	if (true == dict.find(word))
	{
		out.push_back(word);
	}
	else
	{
		for (int i = 1; i < word.size(); ++i)
		{
			string tmp1 = word.substr(0,i);
			string tmp2 = word.substr(i);

			if (true == (dict.find(tmp1) && dict.find(tmp2)))
			{
				out.push_back(tmp1 + " " + tmp2);
			}
		}
	}
	return out;
}

/*
 * Function to find word or strings in HashTable with one missing letter
 * Param: constant reference to hashtable and string to look for
 * Post: if word is not in dict returns all pairs of strings in dict 
 * that can be made by inserting any single letter of the alphabet
 * at any position in word
 */
vector<string> missingLetter(const HashTable & dict, string word)
{
	vector<string> out;

	if (true == dict.find(word))
	{
		out.push_back(word);
	}
	else
	{
		vector<string> candidates;
		for (int i = 0; i <= word.size(); ++i)
		{
			for (int c = 'a'; c <= 'z'; ++c)
			{
				string tmp = word;
				tmp.insert(i, 1, c);
				candidates.push_back(tmp);
			}			
		}

		for (int i = 0; i < candidates.size(); ++i)
		{
			if (true == dict.find(candidates[i]))
			{
				out.push_back(candidates[i]);
			}
		}
	}
	return out;
}

/*
 * Function to find word or strings in HashTable that is one letter off
 * Param: constant reference to hashtable and string to look for
 * Post: if word is not in dict returns all pairs of strings in dict 
 * that can be made by changing any single letter of word to a
 * different letter in the alphabet
 */
vector<string> incorrectLetter(const HashTable & dict, string word)
{
	vector<string> out;

	if (true == dict.find(word))
	{
		out.push_back(word);
	}
	else
	{
		vector<string> candidates;
		for (int i = 0; i < word.size(); ++i)
		{
			for (char c = 'a'; c < 'z'; ++c)
			{
				string tmp = word;
				tmp.replace(i, 1, string(1, c));
				candidates.push_back(tmp);
			}			
		}

		for (int i = 0; i < candidates.size(); ++i)
		{
			if (true == dict.find(candidates[i]))
			{
				out.push_back(candidates[i]);
			}
		}
	}
	return out;
}

