/**
 * @file Lista.h
 * @brief Arquivo header da classe Lista.
 */

#ifndef LISTA_H
#define LISTA_H

#include <string>
#include <cstring>

#include "No.h" /**< Inclui a classe Nó. */

using namespace std;

/**
 * @brief Classe que representa uma lista encadeada.
 *
 * @tparam cabeca é o típo de dado armazenado no nó.
 */
template <typename T>
class Lista
{
public:
    No<T> *cabeca; /*!< Ponteiro para o primeiro nó da lista.*/
    No<T> *cauda;  /*!< Ponteiro para o último nó da lista.*/
    int tamanho;   /*!< Tamanho atual da lista.*/

public:
    /**
     * @brief Construtor padrão da classe Lista.
     *
     * Inicializa os ponteiros de cabeça e cauda como nulos e o tamanho como 0
     */
    Lista()
    {
        this->cabeca = nullptr;
        this->cauda = nullptr;
        this->tamanho = 0;
    }

    /**
     * @brief Construtor de cópia da classe Lista.
     * 
     * @param other Lista a ser copiada.
     */
    Lista(const Lista &other)
    {
        this->cabeca = nullptr;
        this->cauda = nullptr;
        this->tamanho = 0;

        // Copia os elementos da lista "other" para a nova lista
        No<T> *noAtual = other.cabeca;
        while (noAtual != nullptr)
        {
            inserir(noAtual->getData());
            noAtual = noAtual->proximo;
        }
    }

    /**
     * @brief Destrutor da classe Lista.
     *
     */
    virtual ~Lista()
    {
        No<T> *atual;
        No<T> *prox;
        atual = this->cabeca;
        while (atual != nullptr)
        {
            prox = atual->proximo;
            delete atual;
            atual = prox;
        }
    }

    /**
     * @brief Sobrecarga do operador de adição/concatenação (+) para unir duas listas.
     * 
     * @param other A outra lista a ser concatenada.
     * @return Ponteiro para a nova lista resultante da concatenação.
     */
    Lista<T> *operator+(Lista<T> &other) const
    {
        Lista<T> *novaLista = new Lista<T>();

        // Copia os elementos da lista atual para a nova lista
        No<T> *noAtual = this->cabeca;
        while (noAtual != nullptr)
        {
            novaLista->inserir(noAtual->getData());
            noAtual = noAtual->proximo;
        }

        // Copia os elementos da outra lista para a nova lista
        noAtual = other.cabeca;
        while (noAtual != nullptr)
        {
            novaLista->inserir(noAtual->getData());
            noAtual = noAtual->proximo;
        }

        return novaLista;
    }

    /**
     * @brief Sobrecarga do operador de extração (>>) do último nó da lista.
     * 
     * @param no Ponteiro para o nó extraído.
     */
    void operator>>(No<T> *&no) const
    {
        if (cauda == nullptr)
        {
            no = nullptr;
            return;
        }

        no = new No<T>(cauda->data);
        no->proximo = nullptr;
    }

    /**
     * @brief Sobrecarga do operador de inserção de nó.
     * 
     * @param no Ponteiro para o nó a ser inserido.
     */
    void operator<<(No<T> *&no)
    {
        if (no == nullptr)
        {
            return;
        }

        this->inserir(no->getData());
    }

    /**
     * @brief Insere um novo elemento na lista.
     *
     * @param data O dado a ser inserido na lista.
     * @details Verifica se a lista está vazia.
     * Se sim, a cabeça e a cauda da lista apontam para o novo nó.
     * Caso contrário, o ponteiro 'próximo' do nó que atualmente é a cauda passa a apontar para o novo nó
     * e a cauda é atualizada para apontar para o novo nó.
     * Após a inserção do novo nó na lista, o tamanho é atualizado.
     */
    void inserir(T data)
    {
        /// Cria um novo nó.
        No<T> *nova = new No<T>(data);

        // Verificar se a lista está vazia.
        if (this->cauda == nullptr)
        {
            this->cabeca = nova;
            this->cauda = nova;
        }
        else
        {
            this->cauda->proximo = nova;
            this->cauda = nova;
        }

        // Atualiza o tamanho da lista.
        this->tamanho++;
    }

    /**
     * @brief Insere os elementos de outra lista na lista atual.
     * 
     * @param lista Ponteiro para a lista a ser inserida.
     * @details Os elementos da lista fornecida são inseridos na lista atual.
     */
    void inserir(Lista<T> *lista)
    {
        for (int i = 0; i < lista->tamanho; i++)
        {
            this->inserir(lista->buscarPorIndice(i)->getData());
        }
    }

    /**
     * @brief Remove um elemento da lista.
     *
     * @param indiceParaRemover O índice do elemento a ser removido da lista.
     * @return true se o elemento foi removido com sucesso, false caso contrário.
     */
    bool remover(int indiceParaRemover)
    {
        // checa se a lista tem o tamanho menor que o índice
        if (indiceParaRemover >= this->tamanho)
        {
            return false;
        }

        No<T> *noAtual, *noProximo, *noExcluido;
        noAtual = this->cabeca;

        // caso o índice excluído seja a cabeça
        if (indiceParaRemover == 0)
        {
            // Definino que o nó a ser excluído é a cabeça
            noExcluido = this->cabeca;
            // Substituindo endereço da cabeça da lista
            this->cabeca = this->cabeca->proximo;

            // caso a lista tenha apenas um elemento, atualiza a cauda e a cabeça para nullptr
            if (this->tamanho == 1)
            {
                this->cabeca = nullptr;
                this->cauda = nullptr;
            }
        }

        // caso o índice excluído seja a cauda
        else if (indiceParaRemover == this->tamanho - 1)
        {
            // percorre a lista até o penúltimo nó.
            while (noAtual->proximo != this->cauda)
            {
                noAtual = noAtual->proximo;
            }

            // O ponteiro 'noExcluido' é atualizado para apontar ao nó que será excluído.
            noExcluido = noAtual->proximo;
            // O ponteiro 'proximo' de noAtual é atualizado para apontar para nullptr.
            noAtual->proximo = nullptr;
            // O ponteiro 'cauda' é atualizado para a nova cauda.
            this->cauda = noAtual;
        }
        else
        {
            noProximo = noAtual->proximo;
            // loop se repete até achar o indíce anterior ao que será excluído
            for (int i = 0; i != indiceParaRemover - 1; i++)
            {
                noAtual = noAtual->proximo;
                noProximo = noAtual->proximo;
            }

            // altera o endereço armazenado no índice para pular o que foi excluído
            noAtual->proximo = noProximo->proximo;

            // libera o espaço do índice que será excluído
            noExcluido = noProximo;
        }

        delete noExcluido;
        this->tamanho--;

        return true;
    }

    /**
     * @brief Remove os elementos da lista atual que estão presentes na lista fornecida.
     * @param lista Ponteiro para a lista fornecida.
     * @return Quantidade de elementos removidos.
     *
     * @details Percorre a lista fornecida e compara cada elemento com os elementos da lista atual.
     * Se um elemento é encontrado na lista atual, ele é removido.
     * Retorna a quantidade total de elementos removidos.
     */
    int remover(Lista<T> *lista)
    {
        int qntd_removidos = 0;
        for (int i = 0; i < lista->tamanho; i++)
        {
            // percorrendo a lista ligada atual
            for (int j = 0; j < this->tamanho; j++)
            {
                // comparação de titulo
                if (lista->buscarPorIndice(i)->getData() == this->buscarPorIndice(j)->getData())
                {
                    this->remover(j);
                    qntd_removidos++;
                    break;
                }
            }
        }

        return qntd_removidos;
    }

    /**
     * @brief Busca um elemento da lista pelo índice.
     *
     * @param indiceBuscado O índice do elemento que está sendo buscado.
     * @return O nó da lista correspondente ao índice buscado, ou nullptr caso o índice não exista na lista.
     */
    // Função busca nó por índice e retorna o valor armazenado nele
    No<T> *buscarPorIndice(int indiceBuscado)
    {
        No<T> *noAtual;
        noAtual = this->cabeca;

        // checa se a lista tem o tamanho menor que o índice
        if (indiceBuscado > this->tamanho - 1)
        {
            return nullptr;
        }

        // loop se repete até achar o indíce buscado
        for (int i = 0; i != indiceBuscado; i++)
        {
            noAtual = noAtual->proximo;
        }

        return noAtual;
    }
};

#endif