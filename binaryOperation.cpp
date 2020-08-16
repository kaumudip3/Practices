

std::string binops(int n, vector<string> ops)
{
	if( n == 0) return "";

	string res(n, '0');
	int latestz = 0;
	for (auto ch : ops)
	{
		if (ch == "L") {
			if (latestz == -1) continue;
			res[latestz] = '1'; latestz++;
			while (res[latestz] != '0' && latestz < n) {
				latestz++;
			}
			if (latestz > n - 1) latestz = -1;
			//latestz--;
		}
		if (ch[0] == 'C') {
			char c = ch[1];
			res[c-'0'] = '0';
			if (c - '0' < (latestz))
				latestz = (c - '0');
		}
	}

	return res;

}

int main(){

std::string ans = binops(10, { "L", "L" , "C0" , "L" , "C3" });
	std::cout << ans.c_str(); // 110000000

	std::string ans1 = binops(2, { "L", "L" , "L" , "C1" });
	std::cout << ans1.c_str(); // 10


	system("pause");
		

	return 0;
}
