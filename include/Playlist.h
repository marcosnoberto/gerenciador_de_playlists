/**
 * @file Playlist.h
 * @brief Arquivo header da classe Playlist.
 */

#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>

#include "Lista.h"  /**< Inclui a classe Lista. */
#include "Musica.h" /**< Inclui a classe Musica. */

using namespace std;

/**
 * @class Playlist
 * @brief Classe que representa uma playlist.
 */
class Playlist
{
private:
    string nome;          /*!< Nome da playlist */
    Lista<Musica> *lista; /*!< Lista ligada de músicas da playlist */
    int musicaTocando;    /*!< Ponteiro para a música tocando atualmente */

public:
    // Construtores
    Playlist(string);
    Playlist();
    Playlist(const Playlist &other);

    // Destrutor
    ~Playlist();

    // Sobrecarga de operadores
    bool operator==(const Playlist& other) const;
    Playlist *operator=(const Playlist& other);
    Playlist operator+(const Playlist& other);  
    Playlist operator+(const Musica& other);
    Playlist operator-(const Playlist& other); 
    Playlist operator-(const Musica& other);
    void operator>>(Musica*& musica);
    void operator<<(Musica*& musica);
    
    // método limpar (destrutor)
    void limpar();

    // Gets
    string getNome();
    Lista<Musica> *getLista();

    // CRUD
    bool adicionarMusica(Musica);
    bool adicionarMusica(Playlist);
    bool removerMusica(int);
    int removerMusica(Playlist);

    // Metodos da funcionalidade "tocando"
    No<Musica> *proximaMusica();

    // Impressão com recursão
    void imprimir();
    // Chamado pela função 'imprimir'
    void impressaoRecursiva(No<Musica> *, int);
};

#endif