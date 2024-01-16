#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

double octalToDecimal(const string& octal) {
   

    double decimal = 0.0;
    double base = 1.0 / 8.0;

    for (char digit : octal) {
      
        
        decimal += (digit - '0') * base;
        base /= 8.0;
    }

    return decimal;
}

string trimTrailingZeros(string str) {
    

    str.erase(str.find_last_not_of('0') + 1, string::npos);
    // Je?li przecinek dziesi?tny jest teraz ostatnim znakiem, usu? go
    if (!str.empty() && str.back() == '.') {
        str.pop_back();
    }
    return str;
}

int main() {
    int n;
    cin >> n;

    const int maxExamples = 50;
    double results[maxExamples];
    int exampleCount = 0;
    int decimalPlaces[maxExamples];

    while (n--) {
       
        string octalFraction;
        cin >> octalFraction; 

        // Usu? "0." cz??? do konwersji
        string octalPart = octalFraction.substr(2);

        // Oblicz liczb? miejsc dziesi?tnych na podstawie d?ugo?ci cz??ci octalPart
        decimalPlaces[exampleCount] = octalPart.length() * 3;

        // Oblicz i zapisz wynik
        double result = octalToDecimal(octalPart);
        results[exampleCount] = result;
        exampleCount++;
    }

    cout << endl;
    cout << "Result: " << endl;
    // Podaj wyniki z poprawnymi miejscami po przecinku
    for (int i = 0; i < exampleCount; ++i) {

        stringstream ss;
        ss << fixed << setprecision(decimalPlaces[i]) << results[i];
        cout << trimTrailingZeros(ss.str()) << endl;
    }

    system("pause");
}
