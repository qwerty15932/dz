#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// ������� ��� ���������� ����� ��������� �������
double vector_sum(const vector<double>& v) {
    double sum = 0.0;
    for (double x : v) {
        sum += x;
    }
    return sum;
}

// ������� ��� ���������� ������ �������� ���������� x_i � ������ �������
double new_x_value(const vector<vector<double>>& A, const vector<double>& b, const vector<double>& x, int i) {
    int n = A.size();
    double sum1 = 0.0, sum2 = 0.0;

    // ��������� �������� ������� A * x_k, ��� k < i
    for (int j = 0; j < i; ++j) {
        sum1 += A[i][j] * x[j];
    }

    // ��������� �������� ������� A * x_k, ��� k > i
    for (int j = i + 1; j < n; ++j) {
        sum2 += A[i][j] * x[j];
    }

    return (b[i] - sum1 - sum2) / A[i][i];
}

// ����� ������� ��� ������� ������� �������� ���������
vector<double> gauss_seidel(const vector<vector<double>>& A, const vector<double>& b, int max_iter, double tol) {
    int n = A.size();
    vector<double> x(n, 0.0); // ��������� �����������
    vector<double> x_new(n); // ����� �������� ����������
    double diff; // ������� ����� ������� � ������ ����������

    for (int iter = 0; iter < max_iter; ++iter) {
        for (int i = 0; i < n; ++i) {
            // ��������� ����� �������� x_i
            x_new[i] = new_x_value(A, b, x, i);
        }

        // ��������� ������� ���������
        diff = vector_sum(x_new) - vector_sum(x);
        if (abs(diff) < tol) {
            cout << "���������� ���������� �� " << iter + 1 << " ��������." << endl;
            return x_new;
        }

        x = x_new; // ��������� �������� ���������� ��� ��������� ��������
    }

    cout << "���������� ������������ ���������� ��������." << endl;
    return x_new;
}

int main() {
    setlocale(LC_ALL, "Russian");

    // ������ ������� ���������: 5.4x - 2.4y + 3.8z = 5.5, 
    //                           2.5x + 6.8y - 1.1z = 4.3,
    //                           2.7x - 0.6y + 1.5z = -3.5
    vector<vector<double>> A = { {5.4, -2.4, 3.8}, {2.5, 6.8, -1.1}, {2.7, -0.6, 1.5} };
    vector<double> b = { 5.5, 4.3, -3.5 };
    int max_iter = 100; // ������������ ���������� ��������
    double tol = 1e-6; // �����������

    vector<double> solution = gauss_seidel(A, b, max_iter, tol);

    // ����� �������
    cout << "�������:" << endl;
    for (size_t i = 0; i < solution.size(); ++i) {
        cout << "x[" << i << "] = " << solution[i] << endl;
    }

    return 0;
}
