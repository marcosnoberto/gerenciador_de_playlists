/**
 * @file Musica.h
 * @brief Arquivo header da classe Musica.
 */

#ifndef MUSICA_H
#define MUSICA_H

#include <string>

using namespace std;

/**
 * @class Musica
 * @brief Classe que representa uma musica.
 */
class Musica
{
private:
    string titulo;      /*!< Nome da música */
    string artista;     /*!< Artista responsável pela música */

public:
    // Construtores
    Musica(string, string);
    Musica();

    //Destrutor
    ~Musica();

    // Gets
    string getTitulo() const;
    string getArtista();

    // Sobrecargas de operadores
    bool operator==(const Musica& other) const;
};

#endif