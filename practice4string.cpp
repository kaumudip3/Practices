#include <bits/stdc++.h>

using namespace std;

// Complete the alternatingCharacters function below.
int alternatingCharacters(string s) {
	int counterase = 0;
	int i = 0;
	while (i<s.length() - 1)
	{
		int j = i + 1;
		int p = i;
		for (; j<s.length(); j++)
		{
			if (s[i] == s[j]) {
				counterase++;
			}
			else {
				break;
			}

		}
		i = j;

	}
	return counterase;
}
/*
int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	int q;
	cin >> q;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int q_itr = 0; q_itr < q; q_itr++) {
		string s;
		getline(cin, s);

		int result = alternatingCharacters(s);

		fout << result << "\n";
	}

	fout.close();

	return 0;
}
*/