#include <iostream>
#include <cmath>
#include <cctype>
#include "Expresion.hpp"

using namespace std;

Expresion::Expresion() : esValida(false) {}
//*********************************************************************************************
Expresion::Expresion(const string& expresion) {
    capturarExpresion(expresion);
}
//*********************************************************************************************
bool Expresion::esOperador(char op) {
    return (op == '+' || op == '-' || op == '*' || op == '/' || op == '^');
}
//*********************************************************************************************
bool Expresion::esOperadorMonario(char op) {
    return (op == '+' || op == '-');
}
//*********************************************************************************************
int Expresion::prioridad(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}
//*********************************************************************************************
string Expresion::infijoAPostfijo(string infijo) {
    string postfijo = "";
    Pila<char> pila;
    for (char& c : infijo) {
        if (isspace(c)) // Ignora los espacios en blanco
            continue;
        if (isalnum(c)) // Operandos
            postfijo += c;
        else if (c == '(' || c == '[' || c == '{') // Paréntesis de apertura.
            pila.push(c);
        else if (c == ')' || c == ']' || c == '}') { // Paréntesis de cierre.
            while (!pila.empty() && pila.peek() != '(' && pila.peek() != '[' && pila.peek() != '{') {
                postfijo += pila.peek();
                pila.pop();
            }
            if (!pila.empty() && ((c == ')' && pila.peek() == '(') || (c == ']' && pila.peek() == '[') || (c == '}' && pila.peek() == '{')))
                pila.pop(); // Quita el primer paréntesis.
            else {
                cerr << "Error: La expresion no esta balanceada." << endl;
                return "";
            }
        } else { // Operadores.
            while (!pila.empty() && prioridad(c) <= prioridad(pila.peek())) {
                postfijo += pila.peek();
                pila.pop();
            }
            pila.push(c);
        }
    }
    while (!pila.empty()) {
        if (pila.peek() == '(' || pila.peek() == '[' || pila.peek() == '{') {
            cerr << "Error: La expresion no esta balanceada." << endl;
            return "";
        }
        postfijo += pila.peek();
        pila.pop();
    }
    return postfijo;
}
//*********************************************************************************************
double Expresion::realizarOperacion(double operand1, double operand2, char operador) {
    switch (operador) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 != 0)
                return operand1 / operand2;
            else {
                cerr << "Error: Division por cero." << endl;
                return 0;
            }
        case '^':
            return pow(operand1, operand2);
        default:
            cerr << "Error: Operador invalido." << endl;
            return 0;
    }
}
//*********************************************************************************************
void Expresion::capturarExpresion(const string& expresion) {
    expresionInfix = expresion;
    esValida = true; // La expresión se inicia como válida.
    expresionPostfix = infijoAPostfijo(expresion);
    if (expresionPostfix == "") // Si la conversión falla, la expresión es inválida.
        esValida = false;
}
//*********************************************************************************************
void Expresion::imprimirExpresion() {
    if (esValida)
        cout << "Expresi\242n infija: " << expresionInfix << endl
                  << "Expresi\242n postfija: " << expresionPostfix << endl;
                        //<<"Resultado expresi\242n: " << evaluarExpresion()<<endl;
    else
        cerr << "Error: La expresi\242n es invalida." << endl;
}
//*********************************************************************************************
double Expresion::evaluarExpresion() {
    if (!esValida) {
        std::cerr << "Error: No se puede evaluar una expresión no válida." << std::endl;
        return 0;
    }
    Pila<double> pila;
    for (char& c : expresionPostfix) {
        if (std::isalnum(c)) // Operandos
            pila.push(c - '0'); // Convertir char a int
        else if (esOperador(c)) { // Operadores binarios
            double operand2 = pila.peek();
            pila.pop();
            double operand1 = pila.peek();
            pila.pop();
            pila.push(realizarOperacion(operand1, operand2, c));
        } else if (esOperadorMonario(c)) { // Operadores monarios
            double operand = pila.peek();
            pila.pop();
            pila.push(realizarOperacion(0, operand, c));
        }
    }
    return pila.peek();
}
//*********************************************************************************************

