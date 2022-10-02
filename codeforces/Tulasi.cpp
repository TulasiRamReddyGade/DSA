#include<bits/stdc++.h>
using namespace std;

bool isVowel(char a) {
	if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') {
		return true;
	}
	return false;
}

int binarySearch(int *arr, int ele) {
	int s = 0;
	int e = sizeof(*arr) / sizeof(int) - 1;

	while (s <= e) {
		int mid = s + (e - s) / 2;
		//cout << s << e;
		if (ele == arr[mid]) {
			return mid;
		} else if (ele < arr[mid]) {
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}
	return -1;
}


int main() {
#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

#endif

	int t;
	cin >> t;
	while (t-- > 0) {
		string str;
		cin >> str;
		int *arr = (int *)calloc(str.length(), sizeof(int));
		int *arr_cpy = (int *)calloc(str.length(), sizeof(int));
		for (int i = 0; i < str.length(); i++) {
			arr[i] = str[i] - 'a' + 1;
			arr_cpy[i] = str[i] - 'a' + 1;
		}
		int n = sizeof(arr) / sizeof(arr[0]);
		sort(arr, arr + n);
		int a = binarySearch(arr, arr_cpy[0]);
		int b = binarySearch(arr, arr_cpy[str.length() - 1]);
		cout << "a" << a << "b" << b;
		cout << abs(arr_cpy[str.length() - 1] - arr_cpy[0]) << " " << abs(a - b) << endl;
		for (int i = min(a, b); i <= max(a, b); i++) {
			cout << binarySearch(arr_cpy, arr[i]) + 1 << " ";
		}
		cout << endl;
	}
}

