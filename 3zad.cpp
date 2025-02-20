#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <windows.h>

using namespace std;


vector<double> coffee(double Tk, double Tsr, double r, int time) { // Функция для вычисления температуры кофе в зависимости от времени
    vector<double> temperatures; // Вектор для хранения температур
    for (int i = 1; i <= time; i++) {
        double t = Tsr + (Tk - Tsr) * exp(-r * i);  // Вычисление температуры по формуле остывания
        temperatures.push_back(t); 
    }
    return temperatures; 
}
pair<double, double> aprox(const vector<double>& x, const vector<double>& y) { // Функция для вычисления коэффициентов линейной аппроксимации
    double sumx = accumulate(x.begin(), x.end(), 0.0);
    double sumy = accumulate(y.begin(), y.end(), 0.0); 
    double xy = inner_product(x.begin(), x.end(), y.begin(), 0.0); 
    double xx = inner_product(x.begin(), x.end(), x.begin(), 0.0); // Сумма квадратов всех x
    double n = x.size(); // Количество точек
    pair<double, double> approximatingLine; // Пара для хранения коэффициентов линейной аппроксимации
    approximatingLine.first = (n * xy - sumx * sumy) / (n * xx - sumx * sumx); // Вычисление коэффициента a
    approximatingLine.second = (sumy - approximatingLine.first * sumx) / n; // Вычисление коэффициента b
    return approximatingLine; // Возвращаем коэффициенты
}

double korrel(const vector<double>& x, const vector<double>& y) { // Функция для вычисления коэффициента корреляции
    double xsr = accumulate(x.begin(), x.end(), 0.0) / x.size(); 
    double ysr = accumulate(y.begin(), y.end(), 0.0) / y.size(); 
    double sumxy = 0, sumxx = 0, sumyy = 0;
    
    
    for (int i = 0; i < x.size(); i++) { // Вычисление сумм для коэффициента корреляции
        sumxy += (x[i] - xsr) * (y[i] - ysr); // Сумма произведений отклонений x и y от их средних значений
        sumxx += (x[i] - xsr) * (x[i] - xsr); 
        sumyy += (y[i] - ysr) * (y[i] - ysr); 
    }
    
    return sumxy / sqrt(sumxx * sumyy); // Возвращаем коэффициент корреляции
}

int main() {
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251); 
    
    double Tk = 90; // Температура кофе
    double Tsr = 25; // Температура окружающей среды
    double r = 0.005; // Коэффициент остывания
    int time = 60; // Время остывания в минутах
    
    vector<double> temperatures = coffee(Tk, Tsr, r, time); // Получение вектора температур кофе
    vector<double> times; 

    cout << "__________________________" << endl;
    cout << "|" << setw(3) << "time (x)|" << setw(5) << "temperature (y)|" << endl; 
    for (int i = 0, j = 1; i < temperatures.size() && j <= time; i++, j++) {
        cout << "|" << setw(5) << j << setw(4) << "|";
        cout << setw(9) << temperatures[i] << setw(7) << "|" << endl; // Вывод значений в табличном формате
        times.push_back(i); // Добавление времени в вектор
    }
    
    cout << "Коэффициенты линейной аппроксимации: a = ";
    pair<double, double> approximatingLine = aprox(times, temperatures); // Получение коэффициентов линейной аппроксимации
    cout << approximatingLine.first << " b = " << approximatingLine.second << endl;
    
    cout << "Коэффициент корреляции: r = " << korrel(times, temperatures);
    
    return 0; 
}
