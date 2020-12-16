/**
 * @author Alicia G. Cruz Pérez
 * @date 16 dec 2020
 * @brief Este archivo declara el "Help Text" constante y cinco funciones
 *
 */

#include <iostream>
using namespace std;

const string kHelpText = R"(fichero_entrada: Fichero a codificar
fichero_salida:  Fichero codificado
método:          Indica el método de encriptado
                   1: Cifrado xor
                   2: Cifrado de César
password:        Palabra secreta en el caso de método 1, Valor de K en el método 2
operación:       Operación a realizar en el fichero
                   +: encriptar el fichero
                   -: desencriptar el fichero)";

void Usage(int argc, char *argv[]);
bool Entero(const string str);
bool Parametrosvalidos(char *argv[]);
string Cesar(string message, int key);
string XOR(string message, string key);

