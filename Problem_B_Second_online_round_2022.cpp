#include <iostream>
#include <cstring>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;
unsigned int T;
unsigned int m;
unsigned int n;
unsigned int A[50005];
unsigned int compactArrA[50005];
ll maxR;
vector<unsigned int> adjecencyList[200005];
vector<std::pair<unsigned int, unsigned int>> vAds; // luu canh
unsigned int numberEdgeB; // dung de rut gon so nut cua A
vector<std::pair<ll, ll>> resultV;

void clearData() {
	memset(A, 0, sizeof(A));
	memset(compactArrA, 0, sizeof(compactArrA));
	for (unsigned int i = 1; i <= numberEdgeB; i++) adjecencyList[i].clear();
	numberEdgeB = 0;
	n = 0;
	m = 0;
	vAds.clear();
	maxR = 0;
}
bool input() {
	cin >> n >> m;
	if (n <= 50000 && n >= 1 && m <= 200000 && m >= 1) {
		for (unsigned int i = 1; i <= n; ++i) {
			//nhap gia tri moi nut tai 1 diem cua do thi A
			cin >> A[i];
		}
		for (unsigned int j = 0; j < m; ++j) {
			//nhap so canh
			unsigned int x, y;
			cin >> x >> y;
			std::pair<unsigned int, unsigned int> v;
			numberEdgeB = std::max(numberEdgeB, y);
			v.first = x;
			v.second = y;
			vAds.push_back(v);
		}
		return true;
	}
	return false;
}
bool cmp(unsigned int a, unsigned int b) {
	return a > b;
}

void compactA() { // rut gon A
	if (std::begin(A) + n + 1 != std::end(A))
	std::sort(std::begin(A) + 1, std::begin(A) + n + 1, cmp);
	for (unsigned int i = 1; i <= numberEdgeB; i++) {
		if (numberEdgeB <= n) {
			compactArrA[i] = A[i];
		}
	}
}

bool sortArraySize(vector<unsigned int>& a, vector<unsigned int>& b) {
	return a.size() > b.size();
}

void solve() {
	for (unsigned int i = 0; i < m; i++) {
		// tinh danh sach trung lap cac dinh
		unsigned int s = vAds.at(i).first;
		unsigned int e = vAds.at(i).second;
		//cout << "s: " << s << "e: " << e << endl;
		if (s != e) {
			for (unsigned int j = s; j <= e; j++) {
				//cout << "j: " << j << endl;
				adjecencyList[j].push_back(j);
			}
		}
		else {
			adjecencyList[s].push_back(vAds.at(i).first);
		}
	}
	if (std::begin(adjecencyList) + numberEdgeB + 1 + n + 1 != std::end(adjecencyList))
	sort(std::begin(adjecencyList) + 1, std::begin(adjecencyList) + numberEdgeB + 1, sortArraySize);
	for (unsigned int f = 1; f <= numberEdgeB; f++) {
		unsigned int val = compactArrA[f];
		unsigned int sum = adjecencyList[f].size() * val;
		maxR += sum;
	}
	//tinh so cach
	unsigned int factorialB = 1;
	unsigned int factorialM = 1;
	unsigned int factorialNB = 1;
	unsigned int s = n - numberEdgeB;
	for (unsigned int b = 1; b <= s; b++) {
		factorialNB = factorialNB * b;
	}
	for (unsigned int g = 1; g <= numberEdgeB; g++) {
		factorialB = factorialB * g;
	}
	for (unsigned int d = 1; d <= m; d++) {
		factorialM = factorialM * d;
	}
	std::pair<ll, ll> r;
	r.first = maxR;
	r.second = (factorialB * factorialNB) / factorialM;
	resultV.push_back(r);
}

int main() {
	cin >> T;
	bool isRun = true;
	for (unsigned int i = 0; i < T; i++) {
		clearData();
		isRun = input();
		if (isRun) {
			compactA();
			solve();
		}
	}
	if (isRun) {
		for (auto& r : resultV) {
			if (r.second > std::numeric_limits<int>::max())
				cout << r.first << " " << (ll)(pow(10, 9) + 7) << endl;
			else {
				cout << r.first << " " << r.second << endl;
			}
		}
	}
	return 0;
}