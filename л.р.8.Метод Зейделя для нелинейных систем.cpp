#include <iostream>
#include <cmath>

using namespace std;

// ������� ������� ���������
double f1(double x1, double x2) {
    return sin(x2)+2*x1-2;
}

double f2(double x1, double x2) {
    return x2+cos(x1-1)-0.7;
}

// ������� ��� ���������� �������� x1 � x2 �� ������ �������
double update_x1(double x1, double x2) {
    return sin(x2)/2 - 1;
}

double update_x2(double x1, double x2) {
    return cos(x1 - 1) - 0.7;
}

// ����� ������� ��� ������� ���������� ������� ���������
void gauss_seidel_nonlinear(double x1, double x2, int max_iter, double tol) {
    double x1_new, x2_new;
    for (int iter = 0; iter < max_iter; ++iter) {
        x1_new = update_x1(x1, x2); // ��������� x1
        x2_new = update_x2(x1_new, x2); // ��������� x2, ��������� ����� �������� x1
        if (abs(x1_new - x1) < tol && abs(x2_new - x2) < tol) {
            cout << "������� �������:" << endl;
            cout << "x1 = " << x1_new << ", x2 = " << x2_new << endl;
            return;
        }
        x1 = x1_new;
        x2 = x2_new;
    }
    cout << "������� �� ������� ����� " << max_iter << " ��������." << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    double x1_guess = 0.0; // ��������� ����������� ��� x1
    double x2_guess = 0.0; // ��������� ����������� ��� x2
    int max_iter = 1000; // ������������ ���������� ��������
    double tol = 1e-6; // �����������

    gauss_seidel_nonlinear(x1_guess, x2_guess, max_iter, tol);

    return 0;
}
