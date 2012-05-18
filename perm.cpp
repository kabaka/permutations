#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		printf("Usage: %s text\n", argv[0]);
		return 0;
	}

	// Concat all the input text. We'll be finding permutations of this later.
	// Spaces are discarded. Input is converted to lower case.
	string input;
	for(int i = 1; i < argc; ++i)
		input.append(argv[i]);

	std::transform(input.begin(), input.end(), input.begin(), ::tolower);


	// Read the wordlist by line into a vector. Input is converted to lower case.
	// Check for matches while we read.
	ifstream ifile("wordlist.txt");

	if(ifile)
	{
		char c;
		string line;
		bool word_match = true;

		while(ifile.get(c))
		{
			if(c == '\n' && line.length() > 0)
			{
				if(word_match)
					cout << line << endl;

				line.clear();
				word_match = true;
			}
			else if(word_match && isalpha(c))
			{
				c = (char)tolower(c);
				line += c;

				string::iterator it;

				bool c_match = false;

				for(it = input.begin(); it < input.end(); it++)
				{
					if(c == *it)
					{
						c_match = true;
						break;
					}        
				}
				if(!c_match)
					word_match = false;

			}
		}
	}

	return 0;
}
