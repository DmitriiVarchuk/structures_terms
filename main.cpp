#include <iostream>
using namespace std;

struct Point {
	int x;
	int y;

	void distance(Point p) {
		cout << "Distance between points: " << sqrt(pow(p.x - x, 2) + pow(p.y - y, 2)) << endl;
	}
};

int main() {
	Point p1, p2;
	cout << "Enter x and y coordinates of point 1: ";
	cin >> p1.x >> p1.y;
	cout << "Enter x and y coordinates of point 2: ";
	cin >> p2.x >> p2.y;
	p1.distance(p2);


	return 0;
}

