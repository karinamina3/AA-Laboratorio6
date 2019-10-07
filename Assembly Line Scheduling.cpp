#include <bits/stdc++.h> 

#define n 4 

using namespace std; 

int min (int a, int b) {
    if (a < b) return a;
    else return b; 
} 

int fastestWay (int a[][n], int t[][n], int *e, int *x) { 
	int T1[n];
	int T2[n];
	int i; 

	T1[0] = e[0] + a[0][0]; 
	T2[0] = e[1] + a[1][0]; 

	for (i = 1; i < n; ++i) { 
		T1[i] = min(T1[i - 1] + a[0][i], T2[i - 1] + t[1][i] + a[0][i]); 
		T2[i] = min(T2[i - 1] + a[1][i], T1[i - 1] + t[0][i] + a[1][i]); 
		cout << " -> " << min(T1[i], T2[i]);
	} 
 
	return min(T1[n - 1] + x[0], T2[n - 1] + x[1]); 
} 

int main() { 
	int a[][n] = {{4, 5, 3, 2}, {2, 10, 1, 4}}; 
	int t[][n] = {{0, 7, 4, 5}, {0, 9, 2, 8}};							
	int e[] = {10, 12};
	int x[] = {18, 7}; 

	cout << " -> " << fastestWay(a, t, e, x); 

	return 0; 
} 
