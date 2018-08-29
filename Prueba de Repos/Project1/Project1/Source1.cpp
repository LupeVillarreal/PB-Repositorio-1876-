#include <iostream>
#include <math.h>

using namespace std;

void main()
{
	float x, y, r, angulo;

	cout << "inserte x" << endl;
	cin >> x;
	cout << "inserte y" << endl;
	cin >> y;

	r = sqrt(pow(y, 2) + pow(x, 2));

	r = round(r);

	angulo = atan(y / x);

	angulo = angulo * 180 / 3.1416;

	angulo = round(angulo);

	cout << "el radio resultante es " << r << " y su angulo es " << angulo << endl; 

	system("pause");

}
