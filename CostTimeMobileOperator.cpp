// Написать программу подсчета стоимости разговора для
// разных мобильных операторов.Пользователь вводит длительность разговора и выбирает с какого на какой оператор
// он звонит.Вывести стоимость на экран.


#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Список операторо
vector<string> mobileOperators = { "", "PTS Link", "NanoNuno-Mobile", "Perezvoni Telecom", "Porochnaya Svyaz", "Day pozvonit Company" };
// Техническая перменная, для определения какой предлог показывать
int countPrefix = 0;

/// <summary>
/// Метод показывает тарифы операторов за минуту
/// </summary>
/// <param name="mobileOperatorIndex">Индекс оператора</param>
/// <returns>Стоимость минуты разговора</returns>
double Tarification(int mobileOperatorIndex)
{
    switch (mobileOperatorIndex)
    {
    case(1):
        return 2.4;
        break;
    case(2):
        return 2.9;
        break;
    case(3):
        return 2.2;
        break;
    case(4):
        return 3.0;
        break;
    case(5):
        return 2.1;
        break;
    default:
        break;
    }
}

/// <summary>
/// Метод расчитывает стоимость разговора
/// </summary>
/// <param name="incomeCost">Цена оператора входящего звонка</param>
/// <param name="outcomeCost">Цена оператора исходящего звонка</param>
/// <param name="timeCall">Мины звонка</param>
/// <returns></returns>
double CalcCostTime(double outcomeCost, int timeCall) 
{
    return outcomeCost * timeCall;
}

/// <summary>
/// Метод показывает доступных мобильных операторов для выборы
/// </summary>
void ShowOperators() 
{
    string prefix = countPrefix == 0 ? "C " : "На ";

    cout << prefix << "какого мобильного оператора был звонок" << endl;
    for (int i = 1; i < mobileOperators.size(); ++i)
    {
        cout << i << ". " << mobileOperators[i] << endl;
    }    

    ++countPrefix;

    // Проверка если countPrefix стал больше допустимного
    countPrefix = countPrefix > 1 ? 0 : countPrefix;
}

/// <summary>
/// Метод для получения ввода пользователя с проверкой ввода допустмой цифры
/// </summary>
/// <returns>Индекс оператора в массиве</returns>
int GetUserChoice() {
    int choice;
    cout << "Введи цифру мобильного оператора: ";
    cin >> choice;

    // Проверка, что введенная цифра находится в диапазоне допустимых значений
    while (choice < 1 || choice >= mobileOperators.size()) {
        cout << "Введено недопустимое значение. Повторите ввод: ";
        cin >> choice;
    }

    return choice;
}

int main()
{
    setlocale(LC_ALL, "Russian");
        
    int incomOperatorIndex = 0;
    int outcomeOperatorIndex = 0;
    int timeCall = 0;
    double costCall = 0;

    cout << "Привет, я помогу тебе рассчитать стоимость разговора, укажи :\n";

    ShowOperators();    
    incomOperatorIndex = GetUserChoice();
    cout << "____________________________________________________________" << endl;
    cout << "\n";

    ShowOperators();    
    outcomeOperatorIndex = GetUserChoice();
    cout << "____________________________________________________________" << endl;
    cout << "\n";       
   
    cout << "Укажите в минутах продолжительность разговора : ";
    cin >> timeCall;

    // Проверка, что введенное время разговора неотрицательно
    while (timeCall < 0) {
        cout << "Введено недопустимое значение. Повторите ввод: ";
        cin >> timeCall;
    }

    cout << "____________________________________________________________" << endl;
    cout << "\n";


    double incomeCost = Tarification(incomOperatorIndex);
    double outcomeCost = Tarification(outcomeOperatorIndex);

    // Звонки внутри сети бесплатны
    if (incomOperatorIndex == outcomeOperatorIndex) 
    {
        cout << "Звонки внутри сети беслпатны" << endl;
        return 0;
    }

    costCall = CalcCostTime(outcomeCost, timeCall);
    // Вывод результата
    cout << "Стоимость разговора: " << fixed << setprecision(2) << costCall << " рублей" << endl;

    return 0;
}

