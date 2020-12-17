/**
 * @file cripto.cc
 * @author Alicia G. Cruz Pérez
 * @date 16 dec 2020
 * @brief Encripta o desencripta un archivo dado con el método César o XOR, guardando la salida un archivo diferente.
 *
 */

#include <cstdlib>  /// exit
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;

#include "funciones_cripto.h"

/** Función principal
 *  @param[in] argl Número de parámetros de línea de comandos
 *  @param[in] argz Vector (char*) que contiene los parámetros
 */
int main(int argl, char* argz[]) {
  Usage(argl, argz);
  if (!Parametrosvalidos(argz)) {
    cout << "Son invalidos algunos de los parametros que se introducen"
              << "\n";
    exit(EXIT_FAILURE);
  }

  ifstream input_file(argz[1], ifstream::in);
  ofstream output_file(argz[2], ofstream::out);

  stringstream buffer;
  buffer << input_file.rdbuf();

  string texto{buffer.str()};
  string key{argz[4]};
  string output{""};

  if (argz[3][0] == '2') {
    int cesar_constante{stoi(key)};

    if (argz[5][0] == '+') {
      output = Cesar(texto, cesar_constante);
    } else if (argz[5][0] == '-') {
      output = Cesar(texto, -cesar_constante);
    }
  } else if (argz[3][0] == '1') {
    output = XOR(texto, key);
  }

  output_file << output;
  output_file.close();

  ContarA(texto);  

  return 0;
}

