#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
using namespace std;
int main(int argc, char *argv[])
{
	//изменения для ветки master
	setlocale(LC_ALL, "rus");
	if (argc > 1) {
	string b1 = argv[1], b2 = argv[2];
	
	vector<string> FILE1(1);
	vector<string> FILE2(1);

	ifstream F1(b1.c_str());
	ifstream F2(b2.c_str());
	
	if (!F1.is_open() && !F2.is_open()) cout << "ERROR" << endl;
	else {
		string buf;
		while (getline(F1, buf)) FILE1.insert(FILE1.end(), buf);
		while (getline(F2, buf)) FILE2.insert(FILE2.end(), buf);
	}

	for (int i = 0; i < FILE1.size(); i++) {
		bool k = false;
		for (int j = 0; j < FILE2.size(); j++)
		{
			if (FILE1[i] == FILE2[j]) { k = true; break; }
		}
		if (!k) cout << "file1 " << i + 1 << " " << FILE1[i] << endl;
	}
	for (int i = 0; i < FILE2.size(); i++) {
		bool k = false;
		for (int j = 0; j < FILE1.size(); j++)
		{
			if (FILE2[i] == FILE1[j]) { k = true; break; }
		}
		if (!k) cout << "file2 " << i + 1 << " " << FILE2[i] << endl;
	}

	F1.close();
	F2.close();
	}
	else
	{
		cout << "Running without arguments" << endl;
	}
	system("pause");
	return 0;
}
