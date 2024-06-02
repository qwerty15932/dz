#include <iostream>
#include <cmath>

using namespace std;

// �������, ��������� ������� �� ������
double f(double x) {
    return x - 2*sin(x); // ������ ������� - � � 2sin(x)=0

}

// ����� ��������� ��� ������� ��������� f(x) = 0
double bisection_method(double a, double b, double tol, int max_iter) {
    if (f(a) * f(b) >= 0) {
        cout << "������������ ��������� �������� a � b." << endl;
        return 0;
    }

    double c;
    for (int iter = 0; iter < max_iter; ++iter) {
        c = (a + b) / 2; // ������� �������� �������

        if (abs(f(c)) < tol) {
            cout << "����� ��������� �������� �� " << iter + 1 << " ��������." << endl;
            return c;
        }

        // ����� ������� �������
        if (f(c) * f(a) < 0) {
            b = c;
        }
        else {
            a = c;
        }
    }

    cout << "����� ��������� �� ������� ����� " << max_iter << " ��������." << endl;
    return c;
}

int main() {
    setlocale(LC_ALL, "Russian");
    double a = 1.0;   // ����� ����� ���������� ���������
    double b = 3.0;   // ������ ����� ���������� ���������
    double tol = 1e-6; // ��������
    int max_iter = 100; // ������������ ���������� ��������

    double root = bisection_method(a, b, tol, max_iter);
    cout << "������������ ������ ������� ���������: " << root << endl;

    return 0;
}
