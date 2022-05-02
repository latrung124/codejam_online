#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//
//int T; // the test cases
//int arrn[1001]; // n numbers of digits
//int arrB[1001]; /// Bob's number
//int arrA[1001]; // Alice's number
//int maxV = 0;
//
//void input() {
//	cin >> T;
//	for (int i = 0; i < T; ++i) {
//		cin >> arrn[i] >> arrB[i] >> arrA[i];
//	}
//}
//
//bool cmp(char a, char b) {
//	return a > b;
//}
//
//vector<int> chuyenDoiKyTu(int num) {
//	vector<int> result;
//	int thuong = 0;
//	while (num != 0) {
//		thuong = num / 10;
//		int soDu = num - thuong*10;
//		result.push_back(soDu);
//		num = thuong;
//	}
//	return result;
//}
//
//int reverseDigits(int num)
//{
//	int rev_num = 0;
//	while (num > 0) {
//		rev_num = rev_num * 10 + num % 10;
//		num = num / 10;
//	}
//	return rev_num;
//}
//
//int calculateNum(vector<int>& r) {
//	int result = 0;
//	for (int j = 0; j < r.size(); ++j) {
//		result += r.at(j) * pow(10, r.size() - (j + 1));
//	}
//	return result;
//}
//
//
//void cmpDigits(vector<int> b, vector<int> a, int k) {
//	int result = 0;
//
//	vector<int> temp = a;
//	//cout <<"k: "<< k << endl;
//	//cout << "maxV: " << maxV << endl;
//	//for (auto& t : a) {
//	//	cout << t;
//	//}
//	//cout << endl;
//	for (int i = k; i < temp.size(); ++i) {
//		int valA = calculateNum(temp);
//		int minB = calculateNum(b);
//		if (valA < minB) {
//			maxV = max(valA, maxV);
//		}
//		if (b.at(i) == temp.at(i)) {
//			//valA = calculateNum(temp);
//			//if (valA < minB) {
//			//	maxV = max(valA, maxV);
//			//}
//			//else {
//			//	cmpDigits(b, a, k + 1);
//			//}
//		}
//		else if (b.at(i) > temp.at(i)) {
//			//int m = calculateNum(temp);
//			//if (m < minB )
//			//maxV = max(m, maxV);
//		}
//		else {
//			for (int j = i; j < temp.size(); ++j) {
//				vector<int> t = temp;
//				if (t.at(j) <= b.at(i)) {
//					int tmp = t.at(j);
//					t.erase(t.begin() + j);
//					t.insert(t.begin() + i, tmp);
//					cmpDigits(b, t, k + 1);
//				}
//			}			
//		}
//	}
//}
//
//
//
//void solve() {
//	//cout << "result: " << endl;
//	for (int i = 0; i < T; ++i) {
//		maxV = 0;
//		int rD = reverseDigits(arrB[i]);
//		vector<int> bob;
//		int minB = std::min(arrB[i], rD);
//		if (minB == rD) {
//			 bob = chuyenDoiKyTu(arrB[i]);
//		}
//		else {
//			 bob = chuyenDoiKyTu(rD);
//		}
//		
//		
//		vector<int> alice = chuyenDoiKyTu(arrA[i]);
//		std::sort(alice.begin(), alice.end(), cmp);
//		int  k = 0;
//		cmpDigits(bob, alice, k);
//		int r = maxV;
//		if (r == minB) {
//			cout << r / 10 << endl;
//		}
//		else if (r == 0) {
//			r = calculateNum(alice) / 10 ;
//			cout << r << endl;
//		}
//		else {
//			cout << r << endl;
//		}
//
//	}
//}
//
////int main() {
////	input();
////	solve();
////	return 0;
////}
int A[5000];
int n, m;
bool cmp(unsigned int a, unsigned int b) {
	return a > b;
}
int main() {
	cin >> n >> m;
	std::sort(std::begin(A) + 1, std::begin(A) + n + 1, cmp);
	cout << "trungla" << endl;
	return 0;
}