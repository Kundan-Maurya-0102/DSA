#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int f, s;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (n % 2 == 0)
    {
        cout << "YES"<<endl;
        f = n / 2;
        s = n / 2;
    }
    else if (n % 2 != 0)
    {
        f = n / 2 + 1;
        s = n / 2;
    }
    else{
        cout << "No"<<endl;
    }

    int sum = n * (n + 1) / 2;
}