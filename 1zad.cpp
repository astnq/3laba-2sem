#include <iostream> 
#include <math.h>  
#include <Windows.h>
using namespace std; 

 
void pudge(float start, float end, float step) { //вычисляем значения функции в заданном диапазоне
    for (float x = start; x <= end; x += step) { // Цикл от начального до конечного значения с заданным шагом
        float result; // Переменная для хранения результата вычислений
        
        if (x >= -10 && x <= -6) {
            result = round((-1 * (sqrt(4 - (pow(x + 8, 2)))) + 2) * 100) / 100; // Вычислениям значения функции и округление до двух знаков после запятой
            cout << x << "\t" << result << endl; 
        }

       
        if (x > -6 && x <= -4) {
            result = 2; // Значение функции постоянно равно 2
            cout << x << "\t" << result << endl; 
        }

        if (x > -4 && x <= 2) {
            result = -0.5 * x; 
            if (result == -0) result = abs(result); // Приведение результата к положительному значению, если он равен нулю
            cout << x << "\t" << result << endl; 
        }

        if (x > 2) {
            result = x - 3; 
            cout << x << "\t" << result << endl; 
        }
    }
}

int main() {
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251); 

    float xstart, xend, step; 
    cout << "Ââåäèòå íà÷àëüíûé x: "; 
    cin >> xstart; 
    cout << "Ââåäèòå êîíå÷íûé x: "; 
    cin >> xend; 
    cout << "Ââåäèòå øàã: "; 
    cin >> step;

    cout << "X\t" << "Y\n"; 
    pudge(xstart, xend, step); 

    return 0; 
}
