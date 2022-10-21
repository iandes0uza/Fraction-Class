#include <iostream>

using namespace std;

int simplify(int n, int d)
{
    if((d <= n) && (n%d == 0)) return n;
    else if(n < d) simplify(d, n);
    else return 1;
}
int main()
{

    int x = 3000;
    int y = 3000;
    int gc = simplify(x, y);
    cout << "value: " << gc << endl;
}