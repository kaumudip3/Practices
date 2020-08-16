

std::vector<int> reverseDigits(std::vector<int> a)
{
	std::vector<int> res;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] < 10 && a[i] > -1)
		{
			res.push_back(a[i]);
		}
		else {
			int n = a[i], ss = 0;
			while (n > 0)
			{
				int r = n % 10;
				n /= 10;
				ss *= 10;
				ss += r;
			}
			res.push_back(ss);

		}
	}
	return res;
}
int oppSums(vector<int> arr)
{
	// arr[i] + rev(arr[j] ) == arr[j] + rev(arr[j])
	// arr_i - rev(arr[i]) == arr[j]-rev(arr[j])
	// if( i==j ) always true

	std::vector<int> rev =  reverseDigits(arr);
	//std::vector<int> diff, revdiff;
	int sum = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = i; j < arr.size(); j++) {
			if (i == j)
				sum++;
			else {
				int xx = (arr[i] - arr[j]);
				int yy = (rev[i] - rev[j]);
				if (xx == yy) sum++;
			}
		}
	}
	return sum;
}

int main()
{
std::vector<int>arr = { 1, 2, 20, 11 };

	int r = oppSums(arr);
	std::cout << r;


	arr = { 103,45, 21 };

	r = oppSums(arr);
	std::cout << "  " <<r;

	arr = { 33, 77, 909, 101 };

	r = oppSums(arr);
	std::cout << "  " << r;

	system("pause");


	return 0;
}
