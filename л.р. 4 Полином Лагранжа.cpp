#include <iostream>
#include <cmath>
#include <vector>

// ������� ��� ���������� �������� ����������������� �������� �������� � ����� x
double lagrange_interpolation(double x, const std::vector<double>& x_nodes, const std::vector<double>& y_nodes) {
    double result = 0.0;
    int n = x_nodes.size();

    for (int i = 0; i < n; ++i) {
        double term = y_nodes[i];
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                term *= (x - x_nodes[j]) / (x_nodes[i] - x_nodes[j]);
            }
        }
        result += term;
    }

    return result;
}

int main() {
    setlocale(LC_ALL, "Russian");
    // ���� ������������ � �������� ������� � ���� ����� 
    std::vector<double> x_nodes = { 7.0, 8.0, 9.0 };
    std::vector<double> y_nodes;
    for (double x : x_nodes) {
        y_nodes.push_back(std::sin(x)); // �������� ������� � ����� ������������
    }

    // �����, � ������� �� ����� ��������� ������� �������� � ������� f(x)
    double a = 7.5;

    // ��������� �������� f(x) � �������� �������� � ����� a ��� ����� �������
    double f_a = std::log(a)/ (std::log(a)* std::log(a)); // �������� ������� � ����� a
    double lagrange_a = lagrange_interpolation(a, x_nodes, y_nodes); // �������� �������� �������� � ����� a

    // ������� �������� f(x) � �������� �������� � ����� a ��� ����� �������
    std::cout << "f(" << a << ") = " << f_a << std::endl;
    std::cout << "������� �������� � ����� " << a << " = " << lagrange_a << std::endl;

    // ������ ����������� ������������ � ����� a ��� ����� �������
    double interpolation_error = std::abs(f_a - lagrange_a);
    std::cout << "����������� ������������ � ����� " << a << " = " << interpolation_error << std::endl;

    return 0;
}
