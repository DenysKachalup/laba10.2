#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
int Count(char* str)
{
	int k = 0, max = 0;
	for (int i = 0; str[i] != EOF; i++)
		if (str[i] == ' ')
			k++;
		else
			if (k > max)
			{
				max = k;
				k = 0;
			}
			else k = 0;

	return max;
}
int main()
{
	FILE* t;
	char ch;
	char str[101];

	if ((t = fopen("1.txt", "r")) == NULL)
	{
		cerr << "Error opening file '" << "1.txt" << "'" << endl;
		exit(1);
	}
	int i = 0;
	do {
		ch = getc(t);
		str[i] = ch;
		i++;
	} while (ch != EOF);
	cout << "Length of the biggest number of spaces:" << Count(str);

	fclose(t);
	return 0;
}