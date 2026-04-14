#include<iostream>
#include<vector>
using namespace std;
vector<int> countingSort(const vector<int> &A, int k)
{
int n=A.size();
vector<int> C(k+1, 0);
vector<int> B(n);

for(int i=0; i<n; i++)
{
C[A[i]]++; //c[a[i]] = c[a[i]] + 1
}

for(int i=1; i<=k; i++)
{
C[i] += C[i-1]; //c[i] = c[i] + c[i-1]
}

for(int i=n-1; i>=0; i--)
{
B[C[A[i]]-1] = A[i];
C[A[i]]--; //c[a[i]] = c[a[i]] - 1
}

return B;
}
int main()
{
  int n, k;

  cout << "Enter number of elements: ";
  cin >> n;

  vector<int> A(n);

  cout << "Enter elements (range 0 to k):\n";
  for (int i = 0; i < n; i++)
  {
    cin >> A[i];
  }

  cout << "Enter maximum value k: ";
  cin >> k;

  vector<int> B = countingSort(A, k);

  cout << "\nSorted array:\n";
  for (int x : B)
  {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}