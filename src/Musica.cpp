/**
 * @file Musica.cpp
 * @brief Implementação dos métodos da classe Musica
 */

#include <iostream>

#include "Musica.h" /**< Inclui a classe Musica. */

using namespace std;

/**
 * @brief Construtor da classe Musica.
 * @param t é o nome da Musica.
 * @param a é o artista responsável pela Musica.
 */
Musica::Musica(string t, string a)
{
    this->titulo = t;
    this->artista = a;
}

/**
 * @brief Construtor padrão da classe Musica.
 */
Musica::Musica() {}

/**
 * @brief Destrutor da classe Musica.
 */
Musica::~Musica() {}

/**
 * @brief Retornar o titulo da musica.
 * @return o titulo da musica.
 */
string Musica::getTitulo() const { return titulo; }

/**
 * @brief Retornar o artista responsável pela musica.
 * @return o artista responsável pela musica.
 */
string Musica::getArtista() { return artista; }

/**
 * @brief Sobrecarga do operador de igualdade (==) para comparar duas músicas.
 * @param other A outra música a ser comparada.
 * @return Retorna true se as músicas forem iguais, caso contrário retorna false.
 */
bool Musica::operator==(const Musica& other) const
{
    if (this->titulo.compare(other.titulo) || this->artista.compare(other.artista)) {
        return false;
    }

    return true;
}