#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

#define sz(num) sizeof(num) / sizeof(num[0])
void io()
{
#ifndef ONLINE_JUDGE
	freopen("1INPUT.txt", "r", stdin);
	freopen("2OUTPUT.txt", "w", stdout);
#endif
}

//1d Array Permutation and combination Approach -1
void nPr(vector<int> n, int r, int b)
{
	if (b > r)
	{
		for (auto e : n)
		{
			cout << e;
		}
		cout << endl;
		return;
	}
	for (int i = 0; i < n.size(); i++)
	{

		if (n[i] == 0)
		{
			n[i] = b;
			nPr(n, r, b + 1);
			n[i] = 0;
		}
	}
}
bool isGreater(vector<int> n, int e, int b)
{
	for (int i = n.size() - 1; i >= e; i--)
	{
		if (n[i] != 0 && n[i] < b)
			return false;
	}
	return true;
}
void nCr(vector<int> n, int r, int b)
{
	if (b > r)
	{
		for (auto e : n)
			cout << e;
		cout << endl;
		return;
	}

	for (int i = 0; i < n.size(); i++)
	{
		if (n[i] == 0)
		{
			if (isGreater(n, i, b))
			{
				n[i] = b;
				nCr(n, r, b + 1);
				n[i] = 0;
			}
		}
	}
}

// 1d Array permutation and combination Approach -2
void nCr2(int n, int r, int scount, string asf)
{
	if (n == 0)
	{
		if (scount == r)
			cout << asf << endl;
		return;
	}

	nCr2(n - 1, r, scount + 1, asf + "i");
	nCr2(n - 1, r, scount, asf + "-");
}
void nPr2(int n, int r, bool use[], int scount, string asf)
{
	if (n == 0)
	{
		if (scount == r)
			cout << asf << endl;
		return;
	}

	for (int i = 1; i <= r; i++)
	{
		if (use[i] == false)
		{
			use[i] = true;
			nPr2(n - 1, r, use, scount + 1, asf + to_string(i));
			use[i] = false;
		}
	}
	nPr2(n - 1, r, use, scount, asf + "0");
}

//2d Array permutation and combination Approach -1
void Combination(int *chessBoard, int n, int tqueen, int qCnt, int col, int i, string asf)
{
	if (i == n * n)
	{
		if (qCnt == tqueen)
			cout << asf << endl;
		return;
	}

	string s1;
	string s2;
	if (col == n - 1)
	{
		s1 = "q\n";
		s2 = "-\n";
		col = 0;
	}
	else
	{
		s1 = "q";
		s2 = "-";
		col++;
	}
	Combination(chessBoard, n, tqueen, qCnt + 1, col, i + 1, asf + s1);
	Combination(chessBoard, n, tqueen, qCnt, col, i + 1, asf + s2);
}
void permutation(string *chessBoard, int n, int tqueen, int qno)
{
	if (qno > tqueen)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << chessBoard[i * n + j];

			cout << endl;
		}
		cout << endl;

		return;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (chessBoard[i * n + j] == "0 ")
			{
				*(chessBoard + i * n + j) = "q" + to_string(qno) + " ";
				permutation(chessBoard, n, tqueen, qno + 1);
				*(chessBoard + i * n + j) = "0 ";
			}
		}
	}
}

// 2d Array permutation and combination  Approach - 2
void permutation2d(bool use[], int n, int queen, int row, int col, string asf, int qsf)
{

	if (row == n)
	{
		if (qsf == queen)
			cout << asf << endl;
		return;
	}
	int nr = row, nc = col;
	string s1 = "";
	if (col == n - 1)
	{
		nr = row + 1;
		nc = 0;
		s1 = "\n";
	}
	else
	{
		nc = col + 1;
		s1 = "";
	}

	for (int i = 1; i <= queen; i++)
	{
		if (use[i] == false)
		{

			use[i] = true;
			permutation2d(use, n, queen, nr, nc, asf + "q" + to_string(i) + s1, qsf + 1);
			use[i] = false;
		}
	}
	permutation2d(use, n, queen, nr, nc, asf + "_ " + s1, qsf);
}
void combinaton2d(bool *use, int n, int tq, int row, int col, int qsf)
{

	if (qsf == tq)
	{
		for (int i = 0; i < tq; i++)
		{
			for (int j = 0; j < tq; j++)
			{
				if (use[i * tq + j] == true)
					cout << "q";
				else
					cout << "-";
			}
			cout << endl;
		}
		cout << endl;
		return;
	}

	for (int j = col + 1; j < tq; j++)
	{
		use[row * tq + j] = true;
		combinaton2d(use, n, tq, row, j, qsf + 1);
		use[row * tq + j] = false;
	}

	for (int i = row + 1; i < tq; i++)
	{
		for (int j = 0; j < tq; j++)
		{
			use[i * tq + j] = true;
			combinaton2d(use, n, tq, i, j, qsf + 1);
			use[i * tq + j] = false;
		}
	}
}
void combinattion2dto1d(bool *use, int n, int tq, int col, int qsf)
{

	if (qsf == tq)
	{
		for (int i = 0; i < tq; i++)
		{
			for (int j = 0; j < tq; j++)
			{
				if (use[i * tq + j] == true)
					cout << "q";
				else
					cout << "-";
			}
			cout << endl;
		}
		cout << endl;

		return;
	}

	for (int cell = col; cell < n * n; cell++)
	{
		int r = cell / n;
		int c = cell % n;

		use[r * n + c] = true;
		combinattion2dto1d(use, n, tq, cell + 1, qsf + 1);
		use[r * n + c] = false;
	}
}

bool isSafe(bool *use, int n, int r, int c)
{

	for (int i = r; i >= 0; i--)
	{
		if (use[i * n + c] == true)
			return false;
	}

	for (int j = c; j >= 0; j--)
	{
		if (use[r * n + j] == true)
			return false;
	}
	for (int i = r, j = c; i >= 0 && j < n; i--, j++)
	{

		if (use[i * n + j] == true)
			return false;
	}
	for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
	{

		if (use[i * n + j] == true)
			return false;
	}

	return true;
}
bool isKnightSafe(bool *use, int n, int r, int c)
{
	if (c - 2 >= 0 && r - 1 >= 0)
	{
		if (use[(r - 1) * n + (c - 2)] == true)
			return false;
	}
	if (c + 2 < n && r - 1 >= 0)
	{
		if (use[(r - 1) * n + (c + 2)] == true)
			return false;
	}
	if (r - 2 >= 0 && c + 1 < n)
	{
		if (use[(r - 2) * n + (c + 1)] == true)
			return false;
	}
	if (r - 2 >= 0 && c - 1 >= 0)
	{
		if (use[(r - 2) * n + (c - 1)] == true)
			return false;
	}

	return true;
}
void NQueenCombination(bool *use, int n, int col, int tq, int qsf)
{
	if (qsf == tq)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				if (use[i * n + j] == true)
					cout << "q ";
				else
					cout << "- ";
			cout << endl;
		}
		cout << endl;
		return;
	}

	for (int cell = col; cell < n * n; cell++)
	{
		int r = cell / n;
		int c = cell % n;

		if (use[r * n + c] == false && isSafe(use, n, r, c) == true)
		{
			use[r * n + c] = true;
			NQueenCombination(use, n, cell + 1, tq, qsf + 1);
			use[r * n + c] = false;
		}
	}
}
void KnightCombination(bool *use, int n, int col, int tq, int qsf)
{
	if (qsf == tq)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				if (use[i * n + j] == true)
					cout << "q ";
				else
					cout << "- ";
			cout << endl;
		}
		cout << endl;
		return;
	}

	for (int cell = col; cell < n * n; cell++)
	{
		int r = cell / n;
		int c = cell % n;

		if (use[r * n + c] == false && isKnightSafe(use, n, r, c) == true)
		{
			use[r * n + c] = true;
			KnightCombination(use, n, cell + 1, tq, qsf + 1);
			use[r * n + c] = false;
		}
	}
}

bool isSafeForPermutation(int *use, int n, int r, int c)
{

	for (int i = r, j = c; i >= 0; i--)
	{
		if (use[i * n + j] != 0)
			return false;
	}
	for (int i = r, j = c; i < n; i++)
	{
		if (use[i * n + j] != 0)
			return false;
	}
	for (int i = r, j = c; j >= 0; j--)
	{
		if (use[i * n + j] != 0)
			return false;
	}
	for (int i = r, j = c; j < n; j++)
	{
		if (use[i * n + j] != 0)
			return false;
	}
	for (int i = r, j = c; j < n && i >= 0; i--, j++)
	{
		if (use[i * n + j] != 0)
			return false;
	}
	for (int i = r, j = c; j >= 0 && i >= 0; i--, j--)
	{
		if (use[i * n + j] != 0)
			return false;
	}
	for (int i = r, j = c; j >= 0 && i < n; i++, j--)
	{
		if (use[i * n + j] != 0)
			return false;
	}
	for (int i = r, j = c; j < n && i < n; i++, j++)
	{
		if (use[i * n + j] != 0)
			return false;
	}
	return true;
}
void NQueenPermutation(int *use, int n, int tq, int qsf)
{

	if (qsf == tq)
	{
		int cnt = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				if (use[i * n + j] != 0)
					cout << "q" << use[i * n + j] << " ";
				else
					cout << "- ";
			cout << endl;
		}
		cout << endl;

		return;
	}

	for (int cell = 0; cell < n * n; cell++)
	{
		int r = cell / n;
		int c = cell % n;

		if (use[(r * n) + c] == 0 && isSafeForPermutation(use, n, r, c))
		{
			use[(r * n) + c] = qsf + 1;
			NQueenPermutation(use, n, tq, qsf + 1);
			use[(r * n) + c] = 0;
		}
	}
}

void wordBreak1(map<char, int> hmap, string str, int n, int i, string asf)
{
	if (i == n)
	{
		cout << asf << endl;
		return;
	}

	for (auto hm : hmap)
	{
		if (hm.second > 0)
		{

			hmap.at(hm.first)--;
			wordBreak1(hmap, str, n, i + 1, asf + hm.first);
			hmap.at(hm.first)++;
		}
	}
}
void wordBreak2(map<char, int> hmap, string str, int n, int i, vector<char> spote)
{
	if (i == n)
	{
		if (spote.size() == n)
		{
			for (auto item : spote)
				cout << item;

			cout << endl;
		}
		return;
	}

	char ch = str[i];
	int pos = hmap.at(ch);

	for (int j = pos + 1; j < spote.size(); j++)
	{
		if (spote[j] == '-')
		{
			spote[j] = ch;
			hmap.at(ch) = j;

			wordBreak2(hmap, str, n, i + 1, spote);

			spote[j] = '-';
			hmap.at(ch) = pos;
		}
	}
}

void wordSelection1(string uniqueChars, int n, int i, int k, int wcnt, string asf)
{
	if (i == n)
	{
		if (wcnt == k)
			cout << asf << endl;
		return;
	}
	wordSelection1(uniqueChars, n, i + 1, k, wcnt + 1, asf + uniqueChars[i] + "");
	wordSelection1(uniqueChars, n, i + 1, k, wcnt, asf);
}
void wordSelection2(string uniquechars, int k, int selc, int n, int sstart, string asf)
{

	if (selc > k)
	{
		cout << asf << endl;
		return;
	}

	for (int i = sstart + 1; i < n; i++)
	{
		char ch = uniquechars[i];
		wordSelection2(uniquechars, k, selc + 1, n, i, asf + ch);
	}
}

void wordLength1(string str, int k, int i, vector<char> spote, int chcnt)
{

	if (i == str.length())
	{
		if (chcnt == k)
		{
			for (auto e : spote)
				cout << e;
			cout << endl;
		}
		return;
	}

	char ch = str[i];
	for (int j = 0; j < k; j++)
	{
		if (spote[j] == '-')
		{
			spote[j] = ch;
			wordLength1(str, k, i + 1, spote, chcnt + 1);
			spote[j] = '-';
		}
	}
	wordLength1(str, k, i + 1, spote, chcnt);
}
void wordLength3(string str, int k, set<char> use, string asf)
{

	if (k == 0)
	{
		cout << asf << endl;
		return;
	}

	for (int i = 0; i < str.length(); i++)
	{
		char ch = str[i];

		if (use.count(ch) == 0)
		{
			use.insert(ch);
			wordLength3(str, k - 1, use, asf + ch);
			use.erase(ch);
		}
	}
}
void wordLength4(string str, map<char, int> hmap, int k, int i, int chcnt, string asf)
{
	if (chcnt > k)
		return;

	if (chcnt == k || i == k)
	{
		if (chcnt == k)
			cout << asf << endl;

		return;
	}
	char ch = str[i];
	for (int j = hmap.at(ch); j >= 0; j--)
	{
		int cnt = j;
		string s1 = "";
		for (int k = 0; k < j; k++)
			s1 += ch;
		wordLength4(str, hmap, k, i + 1, chcnt + cnt, asf + s1);
	}
}
void wordLength5(string str, map<char, int> hmap, int k, int i, int chcnt, string asf)
{
	if (chcnt == k || i == k)
	{
		if (chcnt == k)
			cout << asf << endl;

		return;
	}

	char ch = str[i];
	if (hmap.at(ch) > 0)
	{
		hmap.at(ch)--;
		wordLength5(str, hmap, k, i, chcnt + 1, asf + ch);
		hmap.at(ch)++;
	}

	wordLength5(str, hmap, k, i + 1, chcnt, asf);
}

void wordSelection4(string str, map<char, int> hmap, int chcnt, int k, char ch, string asf)
{
	if (chcnt == k)
	{
		cout << asf << endl;
		return;
	}
	for (auto it = hmap.find(ch); it != hmap.end(); it++)
	{
		if (hmap.at(it->first) > 0)
		{
			hmap.at(it->first)--;
			wordSelection4(str, hmap, chcnt + 1, k, it->first, asf + it->first);
			hmap.at(it->first)++;
		}
	}
}
void wordSelection5(string str, map<char, int> hmap, int chcnt, int k, string asf, int lcui)
{
	if (chcnt == k)
	{
		cout << asf << endl;
		return;
	}
	for (int i = lcui; i < str.length(); i++)
	{
		char ch = str[i];
		if (hmap.at(ch) > 0)
		{
			hmap.at(ch)--;
			wordSelection5(str, hmap, chcnt + 1, k, asf + ch, i);
			hmap.at(ch)++;
		}
	}
}

void wordSelection6(string str, int k, int i, int chcnt, set<char> container, vector<char> spote, int loi)
{
	if (i == str.length())
	{
		if (chcnt == k)
		{
			for (int i = 0; i < k; i++)
				cout << spote[i];
			cout << endl;
		}
		return;
	}
	char ch = str[i];
	if (container.count(ch) != 0)
	{
		for (int j = loi + 1; j < str.length(); j++)
		{
			if (spote[j] == '-')
			{
				spote[j] = ch;
				container.insert(ch);
				wordSelection6(str, k, i + 1, chcnt + 1, container, spote, j);
				spote[j] = '-';
				container.erase(ch);
			}
		}
	}
	else
	{

		for (int j = 0; j < str.length(); j++)
		{
			if (spote[j] == '-')
			{
				spote[j] = ch;
				container.insert(ch);
				wordSelection6(str, k, i + 1, chcnt + 1, container, spote, j);
				spote[j] = '-';
				container.erase(ch);
			}
		}
		wordSelection6(str, k, i + 1, chcnt, container, spote, 0);
	}
}
void kLengthWord(map<char, int> hmap, int k, string asf)
{
	if (k == 0)
	{
		cout << asf << endl;
		return;
	}

	for (auto p : hmap)
	{
		if (p.second > 0)
		{
			hmap.at(p.first)--;
			kLengthWord(hmap, k - 1, asf + p.first);
			hmap.at(p.first)++;
		}
	}
}

void coinChange1(vector<int> coins, int target, int i, int csum, string asf)
{
	if (i == coins.size())
	{
		if (csum == target)
			cout << asf << endl;

		return;
	}

	coinChange1(coins, target, i + 1, csum + coins[i], asf + to_string(coins[i]) + ",");
	coinChange1(coins, target, i + 1, csum, asf);
}
void coinChange2(vector<int> coins, int target, int i, int csum, string asf)
{
	if (i == coins.size())
	{
		if (csum == target)
			cout << asf << endl;

		return;
	}

	int coin = coins[i];
	for (int j = 1; j * coin <= target; j++)
	{
		int sum = j * coin;
		string tstr = "";
		for (int k = 0; k < j; k++)
			tstr += to_string(coin);

		coinChange2(coins, target, i + 1, csum + sum, asf + tstr);
	}

	coinChange2(coins, target, i + 1, csum, asf);
}

void coinPermutation1(vector<int> coins, int target, bool use[], int csum, string asf)
{
	if (csum > target)
		return;

	if (csum == target)
	{
		cout << asf << endl;
		return;
	}

	for (int j = 0; j < coins.size(); j++)
	{
		int coin = coins[j];
		if (use[coin] == false)
		{
			use[coin] = true;
			coinPermutation1(coins, target, use, csum + coin, asf + to_string(coin) + ",");
			use[coin] = false;
		}
	}
}
void coinPermutation2(vector<int> coins, int target, bool use[], int csum, string asf)
{
	if (csum > target)
		return;

	if (csum == target)
	{
		cout << asf << endl;
		return;
	}

	for (int j = 0; j < coins.size(); j++)
	{
		int coin = coins[j];
		coinPermutation2(coins, target, use, csum + coin, asf + to_string(coin) + ",");
	}
}

int main()
{
	io();

	// Permutation
	// int n, r;
	// cin >> n >> r;
	// vector<int> num(n);

	// nPr(num, r, 1);
	// nCr(num, r, 1);

	// nCr2(n, r, 0, "");
	// bool use[r + 1];

	// fill(use, use + r + 1, false);
	// nPr2(n, r,use, 0, "");

	// int n, queen;
	// cin >> n >> queen;
	// string *chessBoard = new string[n * n];
	// // fill(chessBoard,ch])
	// // Combination((int *)chessBoard, n, queen, 0, 0,0, "");
	// for (int i = 0; i < n; i++)
	// 	for (int j = 0; j < n; j++)
	// 		chessBoard[i * n + j] = "0 ";

	// permutation2d(use, n, r, 0, 0, "", 0);
	// permutation(chessBoard, n, queen, 1);
	// bool *use = new bool[n * n];
	// fill(use, use + (n * n), false);
	// combinaton2d(use, n, r, 0, -1, 0);
	// combinattion2dto1d(use, n, r, 0, 0);
	// NQueenCombination(use, n, 0, r, 0);
	// KnightCombination(use, n, 0, r, 0);
	// cout<<isSafe(use,n,0,1);
	// int *use = new int[n * n];
	// fill(use, use + (n * n), 0);
	// NQueenPermutation(use, n, r, 0);
	// string str;
	// cin >> str;

	// vector<char> spote(str.length(), '-');

	// wordBreak2(hmap, str, str.length(), 0, spote);
	// string str;
	// int k;
	// cin >> str >> k;
	// set<char> uniquechars;

	// wordSelection1(uniquechstr, uniquechstr.length(), 0, k, 0, "");

	// wordSelection2(uniquechstr,k,1,uniquechstr.length(),-1,"");
	// string str;
	// int k;
	// cin >> str >> k;
	// vector<char> spote(k, '-');
	// set<char> uchset;
	// for (int i = 0; i < str.length(); i++)
	// 	uchset.insert(str[i]);

	// string uchstr = "";
	// for (auto e : uchset)
	// 	uchstr += e;

	// set<char> use;

	// map<char, int> hmap;

	// for (int i = 0; i < str.length(); i++)
	// {
	// 	if (hmap.count(str[i]) == 0)
	// 		hmap.emplace(str[i], 1);
	// 	else
	// 		hmap.at(str[i])++;
	// }
	// // iterator<hmap> it::
	// for (auto it = hmap.find(uchstr[1]); it != hmap.end(); it++)
	// {
	// 	cout << it->first;
	// }

	// wordLength1(uchstr, k, 0, spote, 0);
	// wordLength3(uchstr, k, use, "");

	// wordLength5(uchstr, hmap, k, 0, 0, "");
	// wordSelection4(uchstr, hmap, 0, k, uchstr[0], "");
	// wordSelection5(uchstr, hmap, 0, k, "", 0);
	// set<char> container;
	// vector<char> spote(k, '-');
	// wordSelection6(str, k, 0, 0, container, spote, -1);
	// kLengthWord(hmap, k, "");

	int n;
	cin >> n;
	vector<int> coins(n);
	for (int i = 0; i < n; i++)
	{
		cin >> coins[i];
	}
	int target;
	cin >> target;
	bool use[n + 1];
	fill(use, use + n + 1, false);
	// coinChange1(coins, target, 0, 0, "");
	// coinChange2(coins, target, 0, 0, "");
	// coinPermutation1(coins, target, use, 0, "");
	coinPermutation2(coins, target, use, 0, "");
	return 0;
}