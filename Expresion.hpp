/**
 * \file Expresion.hpp
 * \brief Aplicaci&oacute;n de Pila
 * \author Romero Lagarda Jose Pablo ,Martinez Lopez Sergio Eduardo
 * \date 07/03/2024
 */

#ifndef EXPRESION_HPP
#define EXPRESION_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <sstream> // Para convertir string a double
#include "Pila.hpp"

using namespace std;

/**
 * @class Expresion
 * @brief Clase para representar y evaluar <b>expresiones matem&aacute;ticas</b>.
 *
 * Esta clase permite capturar una expresi&oacute;n matem&aacute;tica en notaci&oacute;n infija,
 * convertirla a notaci&oacute;n postfija y evaluar su resultado. Soporta operaciones
 * b&aacute;sicas como suma, resta, multiplicaci&oacute;n y divisi&oacute;n.
 */
class Expresion
{
    public:
        /**
         * @brief Constructor por defecto que inicializa una <i>expresi&oacute;n vac&iacute;a</i>.
         */
        Expresion();

        /**
         * @brief Constructor que inicializa una expresi&oacute;n con una cadena dada.
         * @param expresion Cadena que representa la <b>expresi&oacute;n matem&aacute;tica</b> en notaci&oacute;n infija.
         */
        Expresion(const string& expresion);

        /**
         * @brief Captura una nueva <i>expresi&oacute;n matem&aacute;tica</i>.
         * @param expresion Cadena que representa la expresi&oacute;n matem&aacute;tica en notaci&oacute;n infija.
         */
        void capturarExpresion(const string& expresion);

        /**
         * @brief Imprime la <b>expresi&oacute;n matem&aacute;tica</b> actual.
         */
        void imprimirExpresion();

        /**
         * @brief Eval&uacute;a la expresi&oacute;n matem&aacute;tica actual y devuelve el resultado.
         * @return Resultado de la evaluaci&oacute;n de la expresi&oacute;n.
         */
        double evaluarExpresion();

    private:
        string expresionInfix; ///< Expresi&oacute;n en notaci&oacute;n <b>infija</b>.
        bool esValida; ///< Indica si la expresi&oacute;n es <i>v&aacute;lida</i>.
        string expresionPostfix; ///< Expresi&oacute;n en notaci&oacute;n <b>postfija</b>.

        /**
         * @brief Determina si un car&aacute;cter es un operador.
         * @param op Car&aacute;cter a evaluar.
         * @return <code>true</code> si el car&aacute;cter es un operador, <code>false</code> en caso contrario.
         */
        bool esOperador(char op);

        /**
         * @brief Determina si un car&aacute;cter es un operador unario.
         * @param op Car&aacute;cter a evaluar.
         * @return <code>true</code> si el car&aacute;cter es un operador unario, <code>false</code> en caso contrario.
         */
        bool esOperadorMonario(char op);

        /**
         * @brief Devuelve la prioridad de un operador.
         * @param op Operador cuya prioridad se quiere determinar.
         * @return Entero que representa la <b>prioridad</b> del operador.
         */
        int prioridad(char op);

        /**
         * @brief Convierte una expresi&oacute;n en notaci&oacute;n infija a notaci&oacute;n postfija.
         * @param infijo Cadena que representa la expresi&oacute;n en notaci&oacute;n infija.
         * @return Cadena que representa la expresi&oacute;n en notaci&oacute;n postfija.
         */
        string infijoAPostfijo(string infijo);

        /**
         * @brief Realiza la operaci&oacute;n especificada entre dos operandos.
         * @param operand1 Primer operando.
         * @param operand2 Segundo operando.
         * @param operador Operador que indica la operaci&oacute;n a realizar.
         * @return Resultado de la operaci&oacute;n.
         */
        double realizarOperacion(double operand1, double operand2, char operador);
};

#endif // EXPRESION_HPP
