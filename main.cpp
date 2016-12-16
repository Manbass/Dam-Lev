#include <string>
#include <vector>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

long long Dam_Lev(string first_str, string second_str)
{
	int number_sec = second_str.size();
	int number_frst = first_str.size();
	vector<int> now_str(number_sec + 1);
	vector<int> prev_str(number_sec + 1);
	vector<int> prev_prev_str(number_sec + 1);

	for (int i = 0; i <= number_sec; ++i)
	{
		now_str[i] = prev_str[i] = i;
	}

	for (int i = 1; i <= number_frst; ++i)
	{
		prev_prev_str = prev_str;
		prev_str = now_str;
		now_str[0] = i;
		for (int j = 1; j <= number_sec; ++j)
		{
			now_str[j] = min(
				prev_str[j] + 1, min(
				now_str[j - 1] + 1,
				prev_str[j - 1] + 
				(int)(!(first_str[i - 1] == second_str[j - 1]))));
			if (i > 1 && j > 1 && first_str[i - 1] == second_str[j - 2] && first_str[i - 2] == second_str[j - 1])
			{
				now_str[j] = min(
					now_str[j],
					(prev_prev_str[j - 2] + 
					(int)(!(first_str[i - 1] == second_str[j - 1]))));
			}			
		}	
	}
	return now_str[number_sec];
}

int main()
{
	ifstream fin ("input.txt");
	ofstream fout ("output.txt");

	string first, second;
	getline(fin, first);
	getline(fin, second);
	fout << Dam_Lev(first, second);
	fin.close();
	fout.close();
	return 0;
}