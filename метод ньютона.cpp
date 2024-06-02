#include <iostream>
#include <cmath>

using namespace std;

// �������, ��������� ������� �� ������
double f(double x) {
    return x - 2*sin(x); // � � 2sin(x) = 0

}

// ����������� ������� f(x)
double f_derivative(double x) {
    return 2 * x; // ����������� ������� - 2x
}

// ����� ������� ��� ������� ��������� f(x) = 0
double newton_method(double x0, double tol, int max_iter) {
    double x = x0;

    for (int iter = 0; iter < max_iter; ++iter) {
        double fx = f(x);
        double f_prime_x = f_derivative(x);

        if (abs(fx) < tol) {
            cout << "����� ������� �������� �� " << iter + 1 << " ��������." << endl;
            return x;
        }

        // ��������� �������� x � ������� ������ �������
        x = x - fx / f_prime_x;
    }

    cout << "����� ������� �� ������� ����� " << max_iter << " ��������." << endl;
    return x;
}

int main() {
    setlocale(LC_ALL, "Russian");
    double x0 = 1.0;   // ��������� �����������
    double tol = 1e-6; // ��������
    int max_iter = 100; // ������������ ���������� ��������

    double root = newton_method(x0, tol, max_iter);
    cout << "������������ ������ ������� �������: " << root << endl;

    return 0;
}
