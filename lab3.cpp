#include <iostream>
using namespace std;

class Rectangle {
	double x1, x2, y1, y2, movX, movY, mnXY;
public:
	Rectangle(double a, double b, double c, double d) : x1(a), x2(b), y1(c), y2(d) {   };
	Rectangle() : x1(2), x2(5), y1(2), y2(0) {   };

	void Input() {
		cout << "Input x1:" << endl; cin >> x1;
		cout << "Input y1:" << endl; cin >> y1;
		cout << "Input x2:" << endl; cin >> x2;
		cout << "Input y2:" << endl; cin >> y2;
	}
	void get_rect() {
		cout << "x1:" << x1 << endl;
		cout << "y1:" << y1 << endl;
		cout << "x2:" << x2 << endl;
		cout << "y2:" << y2 << endl;
	}

	void Output() {
		cout << "The rectangle will look like this:" << endl;
		cout << " A:" << "(" << x1 << "," << y1 << ")" << endl;
		cout << " B:" << "(" << x2 << "," << y1 << ")" << endl;
		cout << " C:" << "(" << x2 << "," << y2 << ")" << endl;
		cout << " D:" << "(" << x1 << "," << y2 << ")" << endl;
	}

	void move() {
		cout << "How many units should the rectangle be moved X?" << endl;
		cin >> movX;
		cout << "How many units should the rectangle be moved Y?" << endl;
		cin >> movY;
		cout << "Result of moving:" << endl;
		cout << "A:(" << x1 + movX << "," << y1 + movY << ")" << endl;
		cout << "B:(" << x2 + movX << "," << y1 + movY << ")" << endl;
		cout << "C:(" << x2 + movX << "," << y2 + movY << ")" << endl;
		cout << "D:(" << x1 + movX << "," << y2 + movY << ")" << endl;
	}
	void size() {
		cout << "How much to increase the size?" << endl;
		cin >> mnXY;
		cout << "Result of increase:" << endl;
		cout << "A:(" << x1 * mnXY << "," << y1 * mnXY << ")" << endl;
		cout << "B:(" << x2 * mnXY << "," << y1 * mnXY << ")" << endl;
		cout << "C:(" << x2 * mnXY << "," << y2 * mnXY << ")" << endl;
		cout << "D:(" << x1 * mnXY << "," << y2 * mnXY << ")" << endl;
	}
	void Rectagle2() {
		double x3, x4, y3, y4, x_min = x1, x_max = x1, y_min = y1, y_max = y1, x1_sred = 0, x2_sred = 0, y1_sred = 0, y2_sred = 0;
		cout << "Input rectagle 2" << endl;
		cout << "Input x1:" << endl; cin >> x3;
		cout << "Input y1:" << endl; cin >> y3;
		cout << "Input x2:" << endl; cin >> x4;
		cout << "Input y2:" << endl; cin >> y4;

		cout << "The rectangle will look like this:" << endl;
		cout << " A:" << "(" << x1 << "," << y1 << ")" << endl;
		cout << " B:" << "(" << x2 << "," << y1 << ")" << endl;
		cout << " C:" << "(" << x2 << "," << y2 << ")" << endl;
		cout << " D:" << "(" << x1 << "," << y2 << ")" << endl;

		cout << "The rectangle 2 will look like this:" << endl;
		cout << " A:" << "(" << x3 << "," << y3 << ")" << endl;
		cout << " B:" << "(" << x4 << "," << y3 << ")" << endl;
		cout << " C:" << "(" << x4 << "," << y4 << ")" << endl;
		cout << " D:" << "(" << x3 << "," << y4 << ")" << endl;

		double X[4] = { x1,x2,x3,x4 }; double Y[4] = { y1,y2,y3,y4 };
		for (int i = 0; i < 4; i++)
		{
			if (x_max < X[i])
			{
				x_max = X[i];
			}
			if (y_max < Y[i])
			{
				y_max = Y[i];
			}
			if (x_min > X[i])
			{
				x_min = Y[i];
			}
			if (y_min > X[i])
			{
				y_min = Y[i];
			}
		}

		cout << "The rectangle 2 now look like this:" << endl;
		cout << " A:" << "(" << x_min << "," << y_max << ")" << endl;
		cout << " B:" << "(" << x_max << "," << y_max << ")" << endl;
		cout << " C:" << "(" << x_max << "," << y_min << ")" << endl;
		cout << " D:" << "(" << x_min << "," << y_min << ")" << endl;

		for (int i = 0; i < 4; i++)
		{
			if ((X[i] != x_max) && (X[i] != x_min))
			{
				x1_sred = X[i];
				break;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if ((X[i] != x_max) && (X[i] != x_min) && (X[i] != x1_sred))
			{
				x2_sred = X[i];
				break;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if ((Y[i] != y_max) && (Y[i] != y_min))
			{
				y1_sred = Y[i];
				break;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if ((Y[i] != y_max) && (Y[i] != y_min) && (Y[i] != y1_sred))
			{
				y2_sred = Y[i];
				break;
			}
		}
		cout << " The total part of the intersection of two rectangles: " << endl;
		cout << " A:" << "(" << x1_sred << "," << y2_sred << ")" << endl;
		cout << " B:" << "(" << x2_sred << "," << y2_sred << ")" << endl;
		cout << " C:" << "(" << x2_sred << "," << y1_sred << ")" << endl;
		cout << " D:" << "(" << x1_sred << "," << y1_sred << ")" << endl;
	}
	};


int main()
{
	Rectangle objectA;

	objectA.Input();
	objectA.get_rect();
	objectA.Output();
	objectA.move();
	objectA.size();
	objectA.Rectagle2();
	return 0;
}
