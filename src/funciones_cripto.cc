/**
 * @author Alicia G. Cruz Pérez
 * @date 16 dec 2020
 * @brief Funciones que se utilizadan en el programa cripto.cc
 */

#include "funciones_cripto.h"

#include <cstdlib>  // exit
#include <iostream>
using namespace std;

/** Muestra el modo de uso correcto del programa
 *  En caso de que el uso no sea el correcto, se muestra el mensaje y finaliza con la ejecución del programa.
 *  El programa precisa de 5 parámetros para su ejecución:
 *  1. Fichero de entrada
 *  2. Fichero de salida
 *  3. Método de cifrado
 *  4. Password
 *  5. Operación a usar (+: cifrar, -: descifrar)
 *
 *  @param[in] argc Número de parámetros de línea de comandos
 *  @param[in] argv Vector (char*) que contiene los parámetros
 */
void Usage(int argc, char *argv[]) {
  if (argc == 2) {
    string parameter{argv[1]};
    if (parameter == "--help") {
      cout << argv[0] << " -- Cifrado de ficheros\n";
      cout << "Modo de uso: " << argv[0]
                << " fichero_entrada fichero_salida método password operación\n";
      std::cout << kHelpText << "\n";
      exit(EXIT_SUCCESS);
    }
  }
  if (argc == 1 || argc != 6) {
    cout << argv[0] << " -- Cifrado de ficheros\n";
    cout << "Modo de uso: " << argv[0]
              << " fichero_entrada fichero_salida método password operación\n";
    cout << "Pruebe " << argv[0] << " --help para más información\n";
        exit(EXIT_SUCCESS);
  }
}

/** Comprueba que los parámetros introducidos en el programa son válidos.
 *
 *  @param[in] argv Vector (char*) que contiene los parámetros
 *  @return si los parámetros son válidos
 */
bool Parametrosvalidos(char *argv[]) {
  if (argv[3][0] != '1' && argv[3][0] != '2') return false;

  string parameter_4{argv[4]};
  if (argv[3][0] == '2' && !Entero(parameter_4)) {
    return false;
  }

  if (argv[5][0] != '+' && argv[5][0] != '-') return false;

  return true;
}

/** Comprueba si la string que se introduce es un entero.
 *
 *  @param[in] number String que contiene el número.
 *  @return si el número es un entero.
 */
bool Entero(string number) {
  for (auto t : number) {
    if (t < 48 || t > 57) return false;
  }

  return true;
}


/** Efectúa el cifrado/descifrado césar. 
 *
 *  @param[in] texto String que contiene el mensaje.
 *  @param[in] f constante de rotación
 *  @return Mensaje cifrado/descifrado utilizando César
 */
string Cesar(string texto, int f) {
  string encrypted_texto{""};
  for (auto t : texto) {
    encrypted_texto.push_back(t + (char)f);
  }

  return encrypted_texto;
}

/** Efectúa el cifrado/descifrado XOR.
 *
 *  @param[in] texto String que contiene el texto.
 *  @param[in] key String que contiene la key.
 *  @return Mensaje cifrado/descifrado utilizando XOR.
 */
string XOR(string texto, string key) {
  string encrypted_key{""};
  string encrypted_texto{""};

  for (size_t i = 0; i < key.length(); i++) {
    char xored_char = key.at(i) ^ (char)128;

    encrypted_key.push_back(xored_char);
  }

  for (size_t i = 0; i < texto.length(); i++) {
    char xored_char =
        texto.at(i) ^ encrypted_key.at(i % encrypted_key.length());

    encrypted_texto.push_back(xored_char);
  }

  return encrypted_texto;
}
