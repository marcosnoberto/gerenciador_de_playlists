/**
 * @file No.h
 * @brief Arquivo header da classe No.
 */

#ifndef NO_H
#define NO_H

/**
 * @brief Classe que representa um nó de uma lista encadeada.
 *
 * @tparam T é o típo de dado armazenado no nó.
 */
template <typename T>
class No
{
public:
    T data;      /*!< Dado armazenado no nó.*/
    No *proximo; /*!< Ponteiro para o próximo nó.*/

public:
    /**
     * @brief Construtor da classe No.
     *
     * @param data Dado armazenao no nó.
     *
     * Inicializa o ponteiro de proximo como nulo.
     */
    No(T data)
    {
        this->data = data;
        this->proximo = nullptr;
    }

    /**
     * @brief Construtor padrão da classe No.
     */
    No() {}

    /**
     * @brief Destrutor padrão da classe No.
     *
     */
    ~No() {}

    /**
     * @brief Retorna o dado armazenado no Nó.
     * @return O dado armazenado no Nó.
     */
    T getData() { return this->data; }
};

#endif