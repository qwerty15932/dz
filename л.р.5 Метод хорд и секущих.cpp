#include <iostream>
#include <cmath>

using namespace std;

// �������, ��������� ������� �� ������
double f(double x) {
    return sin(x) + x -2; // ������ ������� - sin(x) + x -2
}

// ����� ���� ��� ������� ��������� f(x) = 0
double chord_method(double a, double b, double tol, int max_iter) {
    double x0 = a;
    double x1 = b;
    double fx0 = f(x0);
    double fx1 = f(x1);
    double x_next;

    for (int iter = 0; iter < max_iter; ++iter) {
        x_next = (x0 * fx1 - x1 * fx0) / (fx1 - fx0); // ����� ����� ����� �����
        double fx_next = f(x_next);

        if (abs(fx_next) < tol) {
            cout << "����� ���� �������� �� " << iter + 1 << " ��������." << endl;
            return x_next;
        }

        // ��������� �������� ��� ��������� ��������
        x0 = x1;
        fx0 = fx1;
        x1 = x_next;
        fx1 = fx_next;
    }

    cout << "����� ���� �� ������� ����� " << max_iter << " ��������." << endl;
    return x_next;
}

// ����� ������� ��� ������� ��������� f(x) = 0
double secant_method(double a, double b, double tol, int max_iter) {
    double x0 = a;
    double x1 = b;
    double fx0 = f(x0);
    double fx1 = f(x1);
    double x_next;

    for (int iter = 0; iter < max_iter; ++iter) {
        x_next = x1 - (fx1 * (x1 - x0)) / (fx1 - fx0); // ����� ����� ����� �������
        double fx_next = f(x_next);

        if (abs(fx_next) < tol) {
            cout << "����� ������� �������� �� " << iter + 1 << " ��������." << endl;
            return x_next;
        }

        // ��������� �������� ��� ��������� ��������
        x0 = x1;
        fx0 = fx1;
        x1 = x_next;
        fx1 = fx_next;
    }

    cout << "����� ������� �� ������� ����� " << max_iter << " ��������." << endl;
    return x_next;
}

int main() {
    setlocale(LC_ALL, "Russian");

    double a = 1.0;   // ��������� ����������� a
    double b = 3.0;   // ��������� ����������� b
    double tol = 1e-6; // ��������
    int max_iter = 100; // ������������ ���������� ��������

    // ���������� ����� ���� ��� ���������� �������
    double root_chord = chord_method(a, b, tol, max_iter);
    cout << "������������ ������ ������� ����: " << root_chord << endl;

    // ���������� ����� ������� ��� ���������� �������
    double root_secant = secant_method(a, b, tol, max_iter);
    cout << "������������ ������ ������� �������: " << root_secant << endl;

    return 0;
}
