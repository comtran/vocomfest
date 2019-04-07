// Created by Eko Hardiyanto (ehardi19)

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001

bool prime[MAX + 1];
void SieveOfEratosthenes() {
  memset(prime, true, sizeof(prime));

  prime[1] = false;

  for (int p = 2; p * p <= MAX; p++) {

    if (prime[p] == true) {

      for (int i = p * 2; i <= MAX; i += p)
        prime[i] = false;
    }
  }
}

int solve(int n) {
  int count = 0, num = 1;

  long long int sum = 0;

  while (count < n) {

    if (prime[num]) {
      sum += num;

      count++;
    }

    num++;
  }
  return sum;
}

int main() {
  SieveOfEratosthenes();

  int t, n;
  cin >> t;
  for (int i = 0; i < t; i++) {
      cin >> n;
      cout << solve(n) << endl;
  }

  return 0;
}