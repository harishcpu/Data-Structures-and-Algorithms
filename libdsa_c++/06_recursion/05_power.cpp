#include <iostream>
using namespace std;

int power(int x, int y) {
	if(y == 0) {
		return 1;
	}

	return (x * power(x, y-1));
}

int fastPower(int x, int y) {
    if(y==0)
        return 1;

    int result = fastPower(x, y/2);
    int resultSquare = result*result;
    if(y&1) {
        return resultSquare*x;
    }
    return resultSquare;
}

int main(void) {
    int x;
    int y;

    cin >> x >> y;
  cout << "power: " << power(x, y) << endl;
 cout << "fastPower: " << fastPower(x, y) << endl; 
}
