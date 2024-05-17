#include <iostream>
#include "Expresion.hpp"

using namespace std;

int main() {
    Expresion expresion1("3 + 4 * 2 / ( 1 - 5 ) ^ 2");
    expresion1.imprimirExpresion();
    cout << "Resultado: " << expresion1.evaluarExpresion() << endl;

    Expresion expresion2("7 * 2 + 8 / 4 - 3 * 2");
    expresion2.imprimirExpresion();
    cout << "Resultado: " << expresion2.evaluarExpresion() << endl;

    return 0;
}
