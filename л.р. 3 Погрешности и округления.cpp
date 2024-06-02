#include <iostream>
#include <cmath>

// ������� ��� ���������� ����� �� ��������� ���������� ������ ����� �������
double roundToPrecision(double value, int precision) {
    double multiplier = std::pow(10, precision);
    return std::round(value * multiplier) / multiplier;
}

// ������� ��� �����������, ����� ��������� ������
void compareEquality(double a, double b) {
    double errorA = std::abs(a - 6.0 / 7.0);
    double errorB = std::abs(b - std::sqrt(41));

    std::cout << "Absolute error for 6/7 = 0.857: " << errorA << std::endl;
    std::cout << "Absolute error for sqrt(41) = 6.40: " << errorB << std::endl;

    if (errorA < errorB) {
        std::cout << "6/7 = 0.857 is more precise." << std::endl;
    }
    else {
        std::cout << "sqrt(41) = 6.40 is more precise." << std::endl;
    }
}

// ������� ��� ���������� ������������ ���� ����� � ���������� ���������� �����������
void roundNumber(double number, double uncertainDigit, double percentageError) {
    double roundedNumber = roundToPrecision(number, 1); // ��������� �� ������ ����� ����� �������
    double absoluteError = std::abs(roundedNumber - number);

    std::cout << "Rounded number: " << roundedNumber << std::endl;
    std::cout << "Absolute error: " << absoluteError << std::endl;
}

// ������� ��� ���������� ���������� ���������� � ������������� ������������
void findLimitErrors(double number) {
    double maxAbsoluteError = 0.001; // ���������� ���������� �����������
    double maxRelativeError = maxAbsoluteError / number; // ���������� ������������� �����������

    std::cout << "Max absolute error: " << maxAbsoluteError << std::endl;
    std::cout << "Max relative error: " << maxRelativeError * 100 << "%" << std::endl;
}

int main() {
    std::cout << "Task (a): Compare equalities" << std::endl;
    compareEquality(0.857, 6.40);

    std::cout << "\nTask (b): Round number 46.7843" << std::endl;
    roundNumber(46.7843, 5, 0.32);

    std::cout << "\nTask (c): Find limit errors for 7.38" << std::endl;
    findLimitErrors(7.38);

    return 0;
}
