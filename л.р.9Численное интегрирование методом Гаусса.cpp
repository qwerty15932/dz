#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// �������, ������� �� �����������
double func(double x) {
    return 4*x + 1; 
}

// ���� � ���� ������ ������ ��� �������������� �� ��������� [-1, 1] (2 ����)
vector<double> gauss_nodes = { -0.5773502691896257, 0.5773502691896257 };
vector<double> gauss_weights = { 1.0, 1.0 };

// ������� ��� ���������� �������������� ������� ������
double gauss_integration(double (*f)(double), double a, double b) {
    double integral = 0.0;

    // �������������� ��������� �������������� [-1, 1] � [a, b]
    double A = (b - a) / 2.0;
    double B = (a + b) / 2.0;

    // �������������� � �������������� ����� � ����� ������
    for (int i = 0; i < gauss_nodes.size(); ++i) {
        double x = A * gauss_nodes[i] + B;
        integral += gauss_weights[i] * f(x);
    }

    // ��������������� ��������� � ������������ � ����� ����������
    integral *= A;

    return integral;
}

int main() {
    setlocale(LC_ALL, "Russian");
    double a = -1.0;  // ������ ������ ��������������
    double b = 3.0;   // ������� ������ ��������������

    double result = gauss_integration(func, a, b);
    cout << "��������� ��������������: " << result << endl;

    return 0;
}
