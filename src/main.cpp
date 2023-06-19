/**
 * @file main.cpp
 * @brief Arquivo principal do programa.
 */

#include <iostream>
#include <string>
#include <locale>
#include <sstream>
#include <fstream> /**< Essa biblioteca fornece classes e funções para manipular arquivos de entrada e saída em C++.*/

#include "Playlist.h" /**< Inclui a classe Playlist. */

using namespace std;

/**
 * @brief Pedir informações de uma música para o usuário.
 *
 * @return a musica que o usuário informou.
 */
Musica pedirMusica()
{
    string nome, artista;
    cout << "Insira o nome da musica: " << endl;
    while (getline(cin, nome))
    {
        if (nome != "")
        {
            break;
        }
    }

    cout << "Insira o artista:" << endl;
    while (getline(cin, artista))
    {
        if (nome != "")
        {
            break;
        }
    }

    Musica musica(nome, artista);

    return musica;
}

/**
 * @brief Cadastra uma nova música na lista de músicas cadastradas.
 * @param listaMusicasCadastradas Ponteiro para a lista de músicas cadastradas.
 */
void cadastrarMusica(Lista<Musica> *listaMusicasCadastradas)
{
    system("clear||cls");

    No<Musica> *noTemp = listaMusicasCadastradas->cabeca;

    Musica musicaNova;
    cout << "Cadastre uma musica: \n"
         << endl;
    musicaNova = pedirMusica();

    // percorre a lista encadeada de músicas já cadastradas e confere se a música a ser cadastrada
    // ainda não existe na lista
    for (int i = 0; i < listaMusicasCadastradas->tamanho; i++)
    {
        // comparação de titulo
        if (noTemp->data.getTitulo().compare(musicaNova.getTitulo()) == 0)
        {
            // comparação de artista
            if (noTemp->data.getArtista().compare(musicaNova.getArtista()) == 0)
            {
                cout << "Cadastro invalido! Musica ja foi cadastrada anteriormente" << endl;
                cout << "Pressione 's' para sair..." << endl;
                cin.ignore(256, 's');
                system("clear||cls");
                return;
            }
        }
        noTemp = noTemp->proximo;
    }

    // cadastro da música no sistema
    listaMusicasCadastradas->inserir(musicaNova);

    // Mensagem de sucesso
    cout << "Musica cadastrada no sistema." << endl
         << endl;
    cout << "Pressione 's' para sair..." << endl;
    cin.ignore(256, 's');
    system("clear||cls");

    return;
}

/**
 * @brief Remove uma música da lista de músicas cadastradas e das playlists em que está presente.
 * @param listaPlaylists Ponteiro para a lista de playlists cadastradas.
 * @param listaMusicasCadastradas Ponteiro para a lista de músicas cadastradas.
 */
void removerMusica(Lista<Playlist> *listaPlaylists, Lista<Musica> *listaMusicasCadastradas)
{
    system("clear||cls");

    /* Caso não exista músicas cadastradas retorna a função imediatamente*/
    if (listaMusicasCadastradas->tamanho == 0)
    {
        cout << "Nao ha musicas para remover" << endl;
        cout << "Pressione 's' para sair..." << endl;
        cin.ignore(256, 's');
        system("clear||cls");
        return;
    }

    bool existe = false;
    bool removidoDePlaylist = false;
    No<Musica> *noTemp = nullptr;
    Lista<Musica> *listaMusicaTemporaria = nullptr;

    Musica musicaRemovida;
    cout << "Remova uma musica: \n"
         << endl;
    musicaRemovida = pedirMusica();

    // removendo da lista de músicas
    noTemp = listaMusicasCadastradas->cabeca;

    for (int i = 0; i < listaMusicasCadastradas->tamanho; i++)
    {
        // comparação de titulo
        if (noTemp->data.getTitulo().compare(musicaRemovida.getTitulo()) == 0)
        {
            // comparação de artista
            if (noTemp->data.getArtista().compare(musicaRemovida.getArtista()) == 0)
            {
                // remoção da música apenas na playlist
                listaMusicasCadastradas->remover(i);
                existe = true;
                i = listaMusicasCadastradas->tamanho;
            }
        }
        noTemp = noTemp->proximo;
    }

    // removendo musica das playlists:
    if (existe == true)
    {
        // percorrendo todas as playlists
        for (int i = 0; i < listaPlaylists->tamanho; i++)
        {
            // buscando lista ligada da playlist
            listaMusicaTemporaria = listaPlaylists->buscarPorIndice(i)->data.getLista();

            // buscando o nó cabeca da lista ligada
            noTemp = listaMusicaTemporaria->cabeca;

            // percorrendo a lista ligada dentro de playlists
            for (int j = 0; j < listaMusicaTemporaria->tamanho; j++)
            {
                // comparação de titulo
                if (noTemp->data.getTitulo().compare(musicaRemovida.getTitulo()) == 0)
                {
                    // comparação de artista
                    if (noTemp->data.getArtista().compare(musicaRemovida.getArtista()) == 0)
                    {
                        // remover musica da playlist
                        removidoDePlaylist = listaPlaylists->buscarPorIndice(i)->data.removerMusica(j);
                    }
                }
                noTemp = noTemp->proximo;
            }

            // aviso de que a música foi removida de tal playlist
            if (removidoDePlaylist)
            {
                cout << musicaRemovida.getTitulo() << " foi removido da playlist " << listaPlaylists->buscarPorIndice(i)->data.getNome() << endl;
                removidoDePlaylist = false;
            }
        }
        cout << "\nMusica removida no sistema!" << endl;
    }
    else
    {
        cout << "\nMusica invalida!" << endl;
    }

    cout << "Pressione 's' para sair..." << endl;
    cin.ignore(256, 's');
    system("clear||cls");

    return;
}

/**
 * @brief Lista as músicas cadastradas.
 * @param listaMusicasCadastradas Ponteiro para a lista de músicas cadastradas.
 */
void listarMusicas(Lista<Musica> *listaMusicasCadastradas)
{
    No<Musica> *noTemp = listaMusicasCadastradas->cabeca;

    system("clear||cls");
    cout << "Musicas cadastradas no sistema:\n"
         << endl;

    // percorre a lista encadeada de músicas já cadastradas e imprime cada uma
    for (int i = 0; i < listaMusicasCadastradas->tamanho; i++)
    {
        cout << i + 1 << ". " << noTemp->data.getTitulo() << " de " << noTemp->data.getArtista() << endl;
        noTemp = noTemp->proximo;
    }

    cout << "Pressione 's' para sair..." << endl;
    cin.ignore(256, 's');
    system("clear||cls");

    return;
}

/**
 * @brief Gerencia as músicas cadastradas.
 * @param listaPlaylists Ponteiro para a lista de playlists cadastradas.
 * @param listaMusicasCadastradas Ponteiro para a lista de músicas cadastradas.
 * @details Esta função permite ao usuário adicionar, remover ou listar as músicas cadastradas.
 * O usuário escolhe a ação que deseja realizar.
 */
void gerenciarMusicas(Lista<Musica> *listaMusicasCadastradas, Lista<Playlist> *listaPlaylists)
{
    // Função Gerenciar Músicas

    system("clear||cls");

    // Menu para gerenciar as músicas
    int continuar = 1;

    do
    {
        cout << "MENU!" << endl
             << "O que voce deseja fazer? (Digite o numero apenas)" << endl;
        cout << "1 - Adicionar musicas" << endl;
        cout << "2 - Remover musicas" << endl;
        cout << "3 - Listar musicas" << endl;
        cout << "4 - Voltar" << endl;

        cin >> continuar;

        switch (continuar)
        {
        case 1:
            cadastrarMusica(listaMusicasCadastradas);
            break;
        case 2:
            removerMusica(listaPlaylists, listaMusicasCadastradas);
            break;
        case 3:
            listarMusicas(listaMusicasCadastradas);
            break;
        case 4:
            system("clear||cls");
            return;
            break;
        default:
            system("clear||cls");
            cout << "========================" << endl;
            cout << "Digite uma opcao valida!" << endl;
            cout << "========================" << endl;
            break;
        }

    } while (continuar);
}

/**
 * @brief Adiciona uma nova playlist à lista de playlists cadastradas.
 * @param listaPlaylistsCadastradas Ponteiro para a lista de playlists cadastradas.
 */
void adicionarPlaylist(Lista<Playlist> *listaPlaylistsCadastradas)
{
    string nome;

    system("clear||cls");
    cout << "Adicione um playlist:\n"
         << endl;

    cout << "Insira o nome da playlist a ser adicionada:" << endl;
    while (getline(cin, nome))
    {
        if (nome != "")
        {
            break;
        }
    }

    // Chama construtor de playlist
    Playlist playlistNova(nome);

    // Insere a nova playlist na lista de playlists cadastradas
    listaPlaylistsCadastradas->inserir(playlistNova);

    // Mensagem de sucesso

    cout << "Playlist adicionada no sistema" << endl;
    cout << "Pressione 's' para sair..." << endl;
    cin.ignore(256, 's');
    system("clear||cls");
}

/**
 * @brief Remove uma playlist da lista de playlists cadastradas.
 * @param listaPlaylistsCadastradas Ponteiro para a lista de playlists cadastradas.
 * @param indicePlaylistEscolhida O índice da playlist selecionada pelo usuário.
 */
void removerPlaylist(Lista<Playlist> *listaPlaylistsCadastradas, int indicePlaylistEscolhida)
{
    system("clear||cls");

    /* Caso não exista playlist cadastradas retorna a função imediatamente. */
    if (listaPlaylistsCadastradas->tamanho == 0)
    {
        cout << "Nao ha playlists para remover" << endl;
        cout << "Pressione 's' para sair..." << endl;
        cin.ignore(256, 's');
        system("clear||cls");
        return;
    }

    /* Verifica se o índice escolhido é válido. */
    if (indicePlaylistEscolhida >= listaPlaylistsCadastradas->tamanho || indicePlaylistEscolhida < 0)
    {
        cout << "========================" << endl;
        cout << "Playlist Invalida" << endl;
        cout << "========================" << endl;
    }
    else
    {
        // Limpando memória
        listaPlaylistsCadastradas->buscarPorIndice(indicePlaylistEscolhida)->data.limpar();
        listaPlaylistsCadastradas->remover(indicePlaylistEscolhida);

        // Mensagem de sucesso

        cout << "Playlist removida do sistema" << endl;
        cout << "Pressione 's' para sair..." << endl;
        cin.ignore(256, 's');
        system("clear||cls");
    }
}

/**
 * @brief Lista as playlists cadastradas.
 * @param listaPlaylistsCadastradas Ponteiro para a lista de playlists cadastradas.
 */
void listarPlaylists(Lista<Playlist> *listaPlaylistsCadastradas)
{
    No<Playlist> *listaTemp = listaPlaylistsCadastradas->cabeca;

    // percorre a lista encadeada de playlists já cadastradas e imprime o nome de cada uma
    for (int i = 0; i < listaPlaylistsCadastradas->tamanho; i++)
    {
        cout << i + 1 << ". " << listaTemp->data.getNome() << endl;
        listaTemp = listaTemp->proximo;
    }
    return;
}

/**
 * @brief Realiza operações de adição, subtração, extração e inserção com as playlists cadastradas.
 * @param listaPlaylistsCadastradas Ponteiro para a lista de playlists cadastradas.
 */
void realizarOperacoesPlaylist(Lista<Playlist> *listaPlaylistsCadastradas)
{
    // Menu para gerenciar as músicas da playlist escolhida
    int continuar = 1;

    // Declara as variáveis necessárias
    Musica musicaEscolhida, *musicaPtr = &musicaEscolhida;
    int playlistEscolhida1, playlistEscolhida2;

    do
    {
        cout << "MENU!" << endl
             << "O que voce deseja fazer? (Digite o numero apenas)" << endl;
        cout << "1 - Playlist a + Playlist b" << endl;
        cout << "2 - Playlist a + Musica b" << endl;
        cout << "3 - Playlist a - Playlist b" << endl;
        cout << "4 - Playlist a - Musica b" << endl;
        cout << "5 - Extrair a ultima musica de uma playlist" << endl;
        cout << "6 - Inserir uma musica ao final de uma playlist" << endl;
        cout << "7 - Voltar" << endl;

        cin >> continuar;

        switch (continuar)
        {
        case 1:

            // imprimir playlists cadastradas
            listarPlaylists(listaPlaylistsCadastradas);

            // Solicita o índice da playlist a ser tocada
            cout << "Digite o numero da playlist a: " << endl;
            cin >> playlistEscolhida1;
            playlistEscolhida1--;
            cout << "Digite o numero da playlist b: " << endl;
            cin >> playlistEscolhida2;
            playlistEscolhida2--;

            listaPlaylistsCadastradas->inserir(listaPlaylistsCadastradas->buscarPorIndice(playlistEscolhida1)->getData() + listaPlaylistsCadastradas->buscarPorIndice(playlistEscolhida2)->getData());

            cout << "Pressione 's' para sair..." << endl;
            cin.ignore(256, 's');
            system("clear||cls");
            break;
        case 2:
            // imprimir playlists cadastradas
            listarPlaylists(listaPlaylistsCadastradas);

            // Solicita o índice da playlist a ser tocada
            cout << "Digite o numero da playlist: " << endl;
            cin >> playlistEscolhida1;
            playlistEscolhida1--;
            cout << "Cadastre uma musica: \n"
                 << endl;
            musicaEscolhida = pedirMusica();

            listaPlaylistsCadastradas->inserir(listaPlaylistsCadastradas->buscarPorIndice(playlistEscolhida1)->getData() + musicaEscolhida);

            cout << "Pressione 's' para sair..." << endl;
            cin.ignore(256, 's');
            system("clear||cls");
            break;
        case 3:
            // imprimir playlists cadastradas
            listarPlaylists(listaPlaylistsCadastradas);

            // Solicita o índice da playlist a ser tocada
            cout << "Digite o numero da playlist a: " << endl;
            cin >> playlistEscolhida1;
            playlistEscolhida1--;
            cout << "Digite o numero da playlist b: " << endl;
            cin >> playlistEscolhida2;
            playlistEscolhida2--;

            listaPlaylistsCadastradas->inserir(listaPlaylistsCadastradas->buscarPorIndice(playlistEscolhida1)->getData() - listaPlaylistsCadastradas->buscarPorIndice(playlistEscolhida2)->getData());

            cout << "Pressione 's' para sair..." << endl;
            cin.ignore(256, 's');
            system("clear||cls");

            break;
        case 4:
            // imprimir playlists cadastradas
            listarPlaylists(listaPlaylistsCadastradas);

            // Solicita o índice da playlist a ser tocada
            cout << "Digite o numero da playlist: " << endl;
            cin >> playlistEscolhida1;
            playlistEscolhida1--;
            cout << "Cadastre uma musica: \n"
                 << endl;
            musicaEscolhida = pedirMusica();

            listaPlaylistsCadastradas->inserir(listaPlaylistsCadastradas->buscarPorIndice(playlistEscolhida1)->getData() - musicaEscolhida);

            cout << "Pressione 's' para sair..." << endl;
            cin.ignore(256, 's');
            system("clear||cls");

            break;
        case 5:
            // imprimir playlists cadastradas
            listarPlaylists(listaPlaylistsCadastradas);

            // Solicita o índice da playlist a ser tocada
            cout << "Digite o numero da playlist: " << endl;
            cin >> playlistEscolhida1;
            playlistEscolhida1--;

            listaPlaylistsCadastradas->buscarPorIndice(playlistEscolhida1)->data >> musicaPtr;

            cout << "A musica extraida da playlist foi: " << musicaPtr->getTitulo() << " de " << musicaPtr->getArtista() << endl;

            cout << "Pressione 's' para sair..." << endl;
            cin.ignore(256, 's');
            system("clear||cls");

            break;
        case 6:
            // imprimir playlists cadastradas
            listarPlaylists(listaPlaylistsCadastradas);

            // Solicita o índice da playlist a ser tocada
            cout << "Digite o numero da playlist: " << endl;
            cin >> playlistEscolhida1;
            playlistEscolhida1--;
            cout << "Cadastre uma musica: \n"
                 << endl;
            musicaEscolhida = pedirMusica();

            listaPlaylistsCadastradas->buscarPorIndice(playlistEscolhida1)->data << musicaPtr;

            cout << "Musica adicionada com sucesso" << endl;

            cout << "Pressione 's' para sair..." << endl;
            cin.ignore(256, 's');
            system("clear||cls");

            break;
        case 7:
            system("clear||cls");
            return;
            break;
        default:
            system("clear||cls");
            cout << "========================" << endl;
            cout << "Digite uma opcao valida!" << endl;
            cout << "========================" << endl;
            break;
        }

    } while (continuar);
}

/**
 * @brief Gerencia as playlists cadastradas.
 * @param listaPlaylistsCadastradas Ponteiro para a lista de playlists cadastradas.
 * @param listaMusicasCadastradas Ponteiro para a lista de músicas cadastradas.
 * @details Esta função permite ao usuário adicionar, remover ou listar as playlists cadastradas.
 * O usuário escolhe a ação que deseja realizar por meio de um menu.
 */
void gerenciarPlaylists(Lista<Playlist> *listaPlaylistsCadastradas, Lista<Musica> *listaMusicasCadastradas)
{
    // Função Gerenciar Playlists

    system("clear||cls");
    int playlistEscolhida;

    // Menu para gerenciar as playlists
    int continuar = 1;

    do
    {
        cout << "MENU!" << endl
             << "O que voce deseja fazer? (Digite o numero apenas)" << endl;
        cout << "1 - Adicionar playlists" << endl;
        cout << "2 - Remover playlists" << endl;
        cout << "3 - Listar playlists" << endl;
        cout << "4 - Realizar operacoes de uniao, subtracao, extracao e insercao" << endl;
        cout << "5 - Voltar" << endl;

        cin >> continuar;

        switch (continuar)
        {
        case 1:
            adicionarPlaylist(listaPlaylistsCadastradas);
            break;
        case 2:
            system("clear||cls");
            cout << "Digite o numero da playlist que deseja excluir: " << endl;
            cout << "------------------------------------------------ " << endl;
            listarPlaylists(listaPlaylistsCadastradas);
            cout << "------------------------------------------------ " << endl;
            cout << "Numero: ";

            cin >> playlistEscolhida;
            playlistEscolhida--;

            removerPlaylist(listaPlaylistsCadastradas, playlistEscolhida);
            break;
        case 3:
            system("clear||cls");
            cout << "Playlists cadastradas no sistema:\n"
                 << endl;

            listarPlaylists(listaPlaylistsCadastradas);
            cout << "Pressione 's' para sair..." << endl;
            cin.ignore(256, 's');
            system("clear||cls");
            break;
        case 4:
            realizarOperacoesPlaylist(listaPlaylistsCadastradas);
            break;
        case 5:
            system("clear||cls");
            return;
            break;
        default:
            system("clear||cls");
            cout << "========================" << endl;
            cout << "Digite uma opcao valida!" << endl;
            cout << "========================" << endl;
            break;
        }

    } while (continuar);
}

/**
 * @brief Exibe a música que está tocando atualmente.
 * @param listaPlaylistsCadastradas Ponteiro para a lista de playlists cadastradas.
 * @param playlistTocando O índice da playlist selecionada pelo usuário.
 * @details Esta função busca a próxima música da playlist escolhida e exibe o título dela.
 * @note A função não retorna nenhum valor, apenas exibe-o para o usuário.
 */
void estaTocandoAgora(Lista<Playlist> *listaPlaylistsCadastradas, int playlistTocando)
{
    system("clear||cls");

    No<Musica> *celula = NULL;

    /** Verifica se há playlists cadastradas no sistema. */
    if (listaPlaylistsCadastradas->tamanho != 0)
    {
        celula = listaPlaylistsCadastradas->buscarPorIndice(playlistTocando)->data.proximaMusica();
    }

    /** Verifica se a célula é NULL.
     *
     * A célula pode ser igual a NULL por vários motivos, dentre eles:
     * 1. Não há playlists cadastradas no sistema;
     * 2. A playlist não possui nenhuma música;
     * 3. Todas as músicas da playlists já foram tocadas e o usuário chegou ao fim dela.
     *
     * Caso a célula seja NULL, imprime uma mensagem de erro "Nao ha uma proxima musica na fila.",
     * caso contrário imprime a música tocando atualmente.
     */
    if (celula != NULL)
    {
        cout << "------------------------" << endl;
        cout << "Musica tocando agora: " << celula->data.getTitulo() << " de " << celula->data.getArtista() << endl;
        cout << "------------------------" << endl;
    }
    else
    {
        cout << "----------------------------------" << endl;
        cout << "Nao ha uma proxima musica na fila." << endl;
        cout << "----------------------------------" << endl;

        cout << "Pressione 's' para sair..." << endl;
        cin.ignore(256, 's');
        system("clear||cls");

        cout << "------------------------" << endl;
        cout << "Nenhuma musica tocando!" << endl;
        cout << "------------------------" << endl;
    }
}

/**
 * @brief Solicita que o usuário escolha uma playlist para ser tocada.
 * @param listaPlaylistsCadastradas Ponteiro para a lista de playlists cadastradas.
 * @details Esta função apresenta um menu com as playlists cadastradas e solicita ao usuário
 * que escolha uma opção a partir deste menu.
 * @return O índice da playlist escolhida pelo usuário.
 */
int escolherPlaylist(Lista<Playlist> *listaPlaylistsCadastradas)
{
    int playlistEscolhida;
    system("clear||cls");

    // imprimir playlists cadastradas
    listarPlaylists(listaPlaylistsCadastradas);

    // Solicita o índice da playlist a ser tocada
    cout << "Digite o numero da playlist que deseja tocar: " << endl;
    cin >> playlistEscolhida;
    playlistEscolhida--;

    system("clear||cls");
    cout << "------------------------" << endl;
    if (playlistEscolhida < 0 || playlistEscolhida >= listaPlaylistsCadastradas->tamanho)
    {
        cout << "Playlist invalida!" << endl;
        cout << "------------------------" << endl;
        return 0;
    }

    cout << listaPlaylistsCadastradas->buscarPorIndice(playlistEscolhida)->getData().getNome() << " esta tocando agora." << endl;
    cout << "------------------------" << endl;

    return playlistEscolhida;
}

/**
 * @brief Adicionar uma música à uma playlist.
 *
 * @param listaPlaylist Ponteiro para a lista de playlists cadastradas.
 * @param listaMusicasCadastradas Ponteiro para a lista de músicas cadastradas.
 * @param indicePlaylist O índice da playlist selecionada pelo usuário.
 */
void adicionarMusicaPlaylist(Lista<Playlist> *listaPlaylist, Lista<Musica> *listaMusicasCadastradas, int indicePlaylist)
{
    system("clear||cls");

    // pergunta ao usuário se ele deseja adicionar apenas uma música ou várias músicas de outra playlist.
    int opcaoEscolhida;
    cout << "Escolha a opcao: \n 1. Adicionar uma musica\n 2. Adicionar musicas de outra playlist\n"
         << endl;
    cout << "Digite a opcao: ";
    cin >> opcaoEscolhida;

    // caso o usuário deseje adicionar apenas uma música
    if (opcaoEscolhida == 1)
    {
        cout << "Adicione uma musica a playlist:\n"
             << endl;

        No<Musica> *noTemp = listaMusicasCadastradas->cabeca;

        Musica musicaNova;
        musicaNova = pedirMusica();

        // percorre a lista encadeada de músicas já cadastradas e confere se a música a ser cadastrada
        // ainda não existe na lista
        for (int i = 0; i < listaMusicasCadastradas->tamanho; i++)
        {
            // comparação de titulo
            if (noTemp->data.getTitulo().compare(musicaNova.getTitulo()) == 0)
            {
                // comparação de artista
                if (noTemp->data.getArtista().compare(musicaNova.getArtista()) == 0)
                {
                    // cadastro da música apenas na playlist
                    listaPlaylist->buscarPorIndice(indicePlaylist)->data.adicionarMusica(musicaNova);
                    return;
                }
            }
            noTemp = noTemp->proximo;
        }

        // cadastro da música na playlist e no sistema
        listaPlaylist->buscarPorIndice(indicePlaylist)->data.adicionarMusica(musicaNova);
        listaMusicasCadastradas->inserir(musicaNova);

        // Mensagem de sucesso
        cout << "Musica adicionada com sucesso." << endl;
    }
    // caso o usuário deseje adicionar várias músicas de uma outra playlist
    else if (opcaoEscolhida == 2)
    {
        int playlistEscolhida;

        // imprimir playlists cadastradas
        listarPlaylists(listaPlaylist);

        // Solicita o índice da playlist a ser tocada
        cout << "Digite o numero da playlist que sera juntada: " << endl;
        cin >> playlistEscolhida;
        playlistEscolhida--;

        // Verifica se o índice existe
        if (playlistEscolhida > listaPlaylist->tamanho)
        {
            cout << "Opcao invalida." << endl;
        }
        else
        {
            listaPlaylist->buscarPorIndice(indicePlaylist)->data.adicionarMusica(listaPlaylist->buscarPorIndice(playlistEscolhida)->getData());
            cout << "Playlist atualizada com sucesso" << endl;
        }
    }
    // Resposta padrão caso nenhuma opção válida seja selecionada
    else
    {
        cout << "Opcao invalida" << endl;
    }

    // Pausa o programa no terminal
    cout << "Pressione 's' para sair..." << endl;
    cin.ignore(256, 's');
    system("clear||cls");

    return;
}

/**
 * @brief Remover música de uma playlist.
 *
 * @param listaPlaylists Ponteiro para a lista de playlists cadastradas.
 * @param playlistEscolhida O índice da playlist selecionada pelo usuário.
 */
void removerMusicaPlaylist(Lista<Playlist> *listaPlaylists, int playlistEscolhida)
{
    /* Caso não exista músicas cadastradas na playlist retorna a função imediatamente*/
    if (listaPlaylists->buscarPorIndice(playlistEscolhida)->data.getLista()->tamanho == 0)
    {
        cout << "Nao ha musicas para remover" << endl;
        cout << "Pressione 's' para sair..." << endl;
        cin.ignore(256, 's');
        system("clear||cls");
        return;
    }

    // pergunta ao usuário se ele deseja remover apenas uma música ou várias músicas de outra playlist.
    int opcaoEscolhida;
    cout << "Escolha a opcao: \n 1. Remover uma musica \n 2. Remover musicas iguais a outra playlist\n"
         << endl;
    cout << "Digite a opcao: ";
    cin >> opcaoEscolhida;

    // caso o usuário deseje remover apenas uma música
    if (opcaoEscolhida == 1)
    {
        Lista<Musica> *listaMusicaTemporaria = nullptr;
        No<Musica> *noTemp = nullptr;

        bool removidoDePlaylist = false;

        Musica musicaRemovida;
        cout << "Remover uma musica da playlist:\n"
             << endl;
        musicaRemovida = pedirMusica();

        // buscando lista ligada de playlist
        listaMusicaTemporaria = listaPlaylists->buscarPorIndice(playlistEscolhida)->data.getLista();

        // buscando o nó cabeca da lista ligada
        noTemp = listaMusicaTemporaria->cabeca;

        // percorrendo a lista ligada dentro de playlists
        for (int j = 0; j < listaMusicaTemporaria->tamanho; j++)
        {
            // comparação de titulo
            if (noTemp->data.getTitulo().compare(musicaRemovida.getTitulo()) == 0)
            {
                // comparação de artista
                if (noTemp->data.getArtista().compare(musicaRemovida.getArtista()) == 0)
                {
                    // remover musica da playlist
                    removidoDePlaylist = listaPlaylists->buscarPorIndice(playlistEscolhida)->data.removerMusica(j);
                    break;
                }
            }
            noTemp = noTemp->proximo;
        }

        // Imprime um aviso caso a música tenha sido removida de alguma playlist ou
        // caso a música não tenha sido encontrada
        if (removidoDePlaylist)
        {
            cout << musicaRemovida.getTitulo() << " foi removido da playlist " << listaPlaylists->buscarPorIndice(playlistEscolhida)->data.getNome() << endl;
            removidoDePlaylist = false;
        }
        else
        {
            cout << "Musica nao encontrada." << endl;
        }
    }
    // caso o usuário deseje remover várias músicas que estão em outra playlist
    else if (opcaoEscolhida == 2)
    {
        int indicePlaylist, qntMusicasExcluidas;

        // imprimir playlists cadastradas
        listarPlaylists(listaPlaylists);

        // Solicita o índice da playlist a ser tocada
        cout << "Digite o numero da playlist que possui as musicas que serao excluidas: " << endl;
        cin >> indicePlaylist;
        indicePlaylist--;

        if (playlistEscolhida > listaPlaylists->tamanho)
        {
            cout << "Opcao invalida." << endl;
        }
        else
        {
            qntMusicasExcluidas = listaPlaylists->buscarPorIndice(playlistEscolhida)->data.removerMusica(listaPlaylists->buscarPorIndice(indicePlaylist)->getData());
            cout << qntMusicasExcluidas << " musicas foram excluidas da playlist." << endl;
        }
    }
    // Resposta padrão caso nenhuma opção válida seja selecionada
    else
    {
        cout << "Opcao invalida." << endl;
    }

    // Pausa o programa no terminal
    cout << "Pressione 's' para sair..." << endl;
    cin.ignore(256, 's');
    system("clear||cls");

    return;
}

/**
 * @brief Listar músicas de uma playlist.
 *
 * @param listaPlaylists Ponteiro para a lista de playlists cadastradas.
 * @param playlistEscolhida O índice da playlist selecionada pelo usuário.
 */
void listarMusicasPlaylist(Lista<Playlist> *listaPlaylists, int playlistEscolhida)
{
    system("clear||cls");
    cout << "Musicas da playlist:\n"
         << endl;

    // Chama método que imprime a playlist
    listaPlaylists->buscarPorIndice(playlistEscolhida)->data.imprimir();

    cout << "Pressione 's' para sair..." << endl;
    cin.ignore(256, 's');
    system("clear||cls");

    return;
}

/**
 * @brief Move uma música dentro de uma playlist.
 *
 * @param listaPlaylists Ponteiro para a lista de playlists cadastradas.
 * @param playlistEscolhida O índice da playlist selecionada pelo usuário.
 * @details Esta função permite ao usuário selecionar uma música em uma playlist
 * e movê-la para outra posição dentro da mesma playlist. O usuário informa o índice
 * da música escolhida e o índice da posição para onde a música deve ser movida.
 * @note A função não realiza nenhuma validação do input do usuário.
 */
void moverMusicaPlaylist(Lista<Playlist> *listaPlaylists, int playlistEscolhida)
{
    /* Caso não exista músicas cadastradas na playlist retorna a função imediatamente. */
    if (listaPlaylists->buscarPorIndice(playlistEscolhida)->data.getLista()->tamanho == 0)
    {
        cout << "Nao ha musicas para mover" << endl;
        cout << "Pressione 's' para sair..." << endl;
        cin.ignore(256, 's');
        system("clear||cls");
        return;
    }

    /* Imprime a lista de músicas. */
    cout << "Musicas da playlist: " << endl;
    listarMusicasPlaylist(listaPlaylists, playlistEscolhida);

    int musicaIndice, indiceNovo; /**< Índice atual da música a ser movida e o novo índice. */

    /* Solicita os índices ao usuário. */
    cout << "\nDigite o numero da musica escolhida: " << endl;
    cin >> musicaIndice;
    musicaIndice--;

    cout << "\nDigite para qual posicao voce deseja move-la: " << endl;
    cin >> indiceNovo;
    indiceNovo--;

    /* Caso o índice novo seja igual ao antigo retorna a função. */
    if (musicaIndice == indiceNovo)
    {
        return;
    }
    /* Verifica se o índice atual é válido. */
    else if (listaPlaylists->buscarPorIndice(playlistEscolhida)->getData().getLista()->tamanho <= musicaIndice && musicaIndice > 0)
    {
        cout << "Indice de musica invalido." << endl;
        cout << "Pressione 's' para sair..." << endl;
        cin.ignore(256, 's');
        system("clear||cls");
        return;
    }
    /* Verifica se o índice novo é válido. */
    else if (listaPlaylists->buscarPorIndice(playlistEscolhida)->getData().getLista()->tamanho <= indiceNovo && indiceNovo > 0)
    {
        cout << "Indice de musica invalido." << endl;
        cout << "Pressione 's' para sair..." << endl;
        cin.ignore(256, 's');
        system("clear||cls");
        return;
    }

    No<Musica> *noTemp = nullptr;
    No<Musica> *noMusicaMovida = nullptr;

    /* Caso os dois índices fornecidos sejam diferentes de 0. */
    if (musicaIndice != 0 && indiceNovo != 0)
    {
        noTemp = listaPlaylists->buscarPorIndice(playlistEscolhida)->data.getLista()->buscarPorIndice(musicaIndice - 1);
        noMusicaMovida = listaPlaylists->buscarPorIndice(playlistEscolhida)->data.getLista()->buscarPorIndice(musicaIndice);
        noTemp->proximo = noMusicaMovida->proximo;

        noTemp = listaPlaylists->buscarPorIndice(playlistEscolhida)->data.getLista()->buscarPorIndice(indiceNovo);
        noMusicaMovida->proximo = noTemp;

        noTemp = listaPlaylists->buscarPorIndice(playlistEscolhida)->data.getLista()->buscarPorIndice(indiceNovo - 1);
        noTemp->proximo = noMusicaMovida;
    }
    /* Caso o índice novo for igual a 0. */
    if (indiceNovo == 0)
    {
        noTemp = listaPlaylists->buscarPorIndice(playlistEscolhida)->data.getLista()->buscarPorIndice(musicaIndice - 1);
        noMusicaMovida = listaPlaylists->buscarPorIndice(playlistEscolhida)->data.getLista()->buscarPorIndice(musicaIndice);
        noTemp->proximo = noMusicaMovida->proximo;

        noMusicaMovida->proximo = listaPlaylists->buscarPorIndice(playlistEscolhida)->data.getLista()->cabeca;

        listaPlaylists->buscarPorIndice(playlistEscolhida)->data.getLista()->cabeca = noMusicaMovida;
    }
    /* Caso o índice atual for igual a 0. */
    if (musicaIndice == 0)
    {
        noMusicaMovida = listaPlaylists->buscarPorIndice(playlistEscolhida)->data.getLista()->buscarPorIndice(musicaIndice);
        listaPlaylists->buscarPorIndice(playlistEscolhida)->data.getLista()->cabeca = noMusicaMovida->proximo;

        noTemp = listaPlaylists->buscarPorIndice(playlistEscolhida)->data.getLista()->buscarPorIndice(indiceNovo - 1);
        noMusicaMovida->proximo = noTemp->proximo;
        noTemp->proximo = noMusicaMovida;
    }

    /* Mensagem de sucesso. */

    cout << "Musica movida com sucesso." << endl;
    cout << "Pressione 's' para sair..." << endl;
    cin.ignore(256, 's');
    system("clear||cls");
    return;
}

/**
 * @brief Gerencia as músicas em todas as playlists cadastradas.
 * @param listaPlaylistsCadastradas Ponteiro para a lista de playlists cadastradas.
 * @param listaMusicasCadastradas Ponteiro para a lista de músicas cadastradas.
 * @details Esta função permite ao usuário adicionar, remover ou mover músicas em todas as playlists cadastradas.
 * O usuário escolhe a ação que deseja realizar e a playlist na qual deseja realizar a ação.
 * @note A função não realiza nenhuma validação do input do usuário.
 */
void gerenciarMusicasEmPlaylists(Lista<Playlist> *listaPlaylistsCadastradas, Lista<Musica> *listaMusicasCadastradas)
{
    // Função Gerenciar Músicas em Playlists

    system("clear||cls");

    /* Caso não exista playlist cadastrada retorna a função imediatamente*/
    if (listaPlaylistsCadastradas->tamanho == 0)
    {
        cout << "Nao ha playlists para gerenciar" << endl;
        cout << "Pressione 's' para sair..." << endl;
        cin.ignore(256, 's');
        system("clear||cls");
        return;
    }

    int playlistEscolhida;

    cout << "Digite o numero da playlist que deseja gerenciar:\n " << endl;
    /// imprimir playlists cadastradas.
    listarPlaylists(listaPlaylistsCadastradas);

    /* Solicita aos usuários o índice de uma playlist. */
    cin >> playlistEscolhida;
    playlistEscolhida--;

    if (listaPlaylistsCadastradas->tamanho <= playlistEscolhida)
    {
        system("clear||cls");
        cout << "========================" << endl;
        cout << "Essa playlist não existe." << endl;
        cout << "========================" << endl;
        return;
    }

    // Menu para gerenciar as músicas da playlist escolhida
    int continuar = 1;

    do
    {
        cout << "MENU!" << endl
             << "O que voce deseja fazer? (Digite o numero apenas)" << endl;
        cout << "1 - Adicionar musicas a playlist" << endl; // adicionar opção de sobrecarga
        cout << "2 - Remover musicas da playlist" << endl;  // adicionar opção de sobrecarga
        cout << "3 - Listar musicas da playlist" << endl;
        cout << "4 - Mover musica da playlist" << endl;
        cout << "5 - Voltar" << endl;

        cin >> continuar;

        switch (continuar)
        {
        case 1:
            adicionarMusicaPlaylist(listaPlaylistsCadastradas, listaMusicasCadastradas, playlistEscolhida);
            break;
        case 2:
            removerMusicaPlaylist(listaPlaylistsCadastradas, playlistEscolhida);
            break;
        case 3:
            listarMusicasPlaylist(listaPlaylistsCadastradas, playlistEscolhida);
            break;
        case 4:
            moverMusicaPlaylist(listaPlaylistsCadastradas, playlistEscolhida);
            break;
        case 5:
            system("clear||cls");
            return;
            break;
        default:
            system("clear||cls");
            cout << "========================" << endl;
            cout << "Digite uma opcao valida!" << endl;
            cout << "========================" << endl;
            break;
        }

    } while (continuar);
}

/**
 * @brief Encerra o programa.
 *
 */
void sair(Lista<Musica> *listaMusicasCadastradas, Lista<Playlist> *listaPlaylistsCadastradas)
{
    /* Libera a memória das listas. */
    delete listaMusicasCadastradas;   /**< Libera lista de músicas cadastradas*/
    delete listaPlaylistsCadastradas; /**< Libera lista de playlists cadastradas*/
}

/**
 * @brief Função principal do programa.
 *
 * @return Valor inteiro indicando sucesso ou falha na execução do programa.
 */
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, ""); /**< Configura o idioma local. */

    Lista<Musica> *listaMusicasCadastradas = new Lista<Musica>; /**< O Ponteiro da lista de músicas cadastradas.*/

    Lista<Playlist> *listaPlaylistsCadastradas = new Lista<Playlist>; /**< O Ponteiro da lista de playlists cadastradas.*/

    /**
     * Insere no sistema valores pré-definidos na lista de músicas cadastradas
     */
    listaMusicasCadastradas->inserir(Musica("The Alcott", "The National"));
    listaMusicasCadastradas->inserir(Musica("Red", "Taylor Swift"));
    listaMusicasCadastradas->inserir(Musica("Lego House", "Ed Sheeran"));
    listaMusicasCadastradas->inserir(Musica("Deixa Eu Viver", "Mari Fernandez"));
    listaMusicasCadastradas->inserir(Musica("Pilantra", "Jao"));
    listaMusicasCadastradas->inserir(Musica("Sorry To Me Too", "Julia Michaels"));
    listaMusicasCadastradas->inserir(Musica("Go Getter", "Mia Giovina"));
    listaMusicasCadastradas->inserir(Musica("So Good", "Halsey"));
    listaMusicasCadastradas->inserir(Musica("You Only Love Me", "Rita Ora"));
    listaMusicasCadastradas->inserir(Musica("Una Noche Sin Pensar", "Sebastian Yatra"));

    listaMusicasCadastradas->inserir(Musica("Bones", "Imagine Dragons"));
    listaMusicasCadastradas->inserir(Musica("Natural", "Imagine Dragons"));
    listaMusicasCadastradas->inserir(Musica("Demons", "Imagine Dragons"));
    listaMusicasCadastradas->inserir(Musica("Birds", "Imagine Dragons"));

    /**
     * Insere uma playlist pré-definida na lista de playlists cadastradas
     */
    listaPlaylistsCadastradas->inserir(Playlist("Playlist Gloria"));
    listaPlaylistsCadastradas->inserir(Playlist("Playlist Marcos"));

    /**
     * Insere valores pré-definidos nas playlists criadas
     */
    listaPlaylistsCadastradas->cabeca->data.adicionarMusica(Musica("Red", "Taylor Swift"));
    listaPlaylistsCadastradas->cabeca->data.adicionarMusica(Musica("Deixa Eu Viver", "Mari Fernandez"));
    listaPlaylistsCadastradas->cabeca->data.adicionarMusica(Musica("Pilantra", "Jao"));
    listaPlaylistsCadastradas->cabeca->data.adicionarMusica(Musica("Go Getter", "Mia Giovina"));
    listaPlaylistsCadastradas->cabeca->data.adicionarMusica(Musica("The Alcott", "The National"));
    listaPlaylistsCadastradas->cabeca->data.adicionarMusica(Musica("You Only Love Me", "Rita Ora"));

    listaPlaylistsCadastradas->cabeca->proximo->data.adicionarMusica(Musica("Bones", "Imagine Dragons"));
    listaPlaylistsCadastradas->cabeca->proximo->data.adicionarMusica(Musica("Natural", "Imagine Dragons"));
    listaPlaylistsCadastradas->cabeca->proximo->data.adicionarMusica(Musica("Demons", "Imagine Dragons"));
    listaPlaylistsCadastradas->cabeca->proximo->data.adicionarMusica(Musica("Birds", "Imagine Dragons"));

    /** TESTES DAS NOVAS FUNÇÕES:
     * | | | | | | | | | | | | |
     * v v v v v v v v v v v v v
     */
    /**
     * Teste da função inserir com parâmetro do tipo Lista<Musica>
     */
    // Lista<Musica> *lista_inserir = new Lista<Musica>;

    // lista_inserir->inserir(Musica("Youre Losing Me", "Taylor Swift"));
    // lista_inserir->inserir(Musica("Eyes Closed", "Ed Sheeran"));
    // lista_inserir->inserir(Musica("Nervous", "John Legend"));

    // listaMusicasCadastradas->inserir(lista_inserir);

    /**
     * Teste da função remover com parâmetro do tipo Lista<Musica>
     */
    // Lista<Musica> *lista_remover = new Lista<Musica>();

    // lista_remover->inserir(Musica("Red", "Taylor Swift"));
    // lista_remover->inserir(Musica("Eyes Closed", "Ed Sheeran"));
    // lista_remover->inserir(Musica("Nervous", "John Legend"));

    // int qnt_teste = listaMusicasCadastradas->remover(lista_remover);
    // cout << qnt_teste << " musicas foram excluidas." << endl;

    /**
     * Teste do construtor cópia de Lista<Musica>.
     */
    // Lista<Musica> lista = *lista_remover;
    // for (int i = 0; i < lista.tamanho; i++)
    // {
    //     cout << i + 1 << ". " << lista.buscarPorIndice(i)->getData().getTitulo() << " de " << lista.buscarPorIndice(i)->getData().getArtista() << endl;
    // }

    // cout << endl;

    /**
     * Teste da sobrecarga no operador + de Lista<Musica>.
     */
    // Lista<Musica> *lista_soma = lista + *lista_inserir;
    // for (int i = 0; i < lista_soma->tamanho; i++)
    // {
    //     cout << i + 1 << ". " << lista_soma->buscarPorIndice(i)->getData().getTitulo() << " de " << lista_soma->buscarPorIndice(i)->getData().getArtista() << endl;
    // }

    // cout << endl;

    /**
     * Teste da sobrecarga no operador >> de Lista<Musica>.
     */
    // No<Musica> *no;
    // *lista_soma >> no;
    // cout << 1 << ". " << no->getData().getTitulo() << " de " << no->getData().getArtista() << endl;

    // cout << endl;

    /**
     * Teste da sobrecarga no operador << de Lista<Musica>.
     */
    // *lista_soma << no;
    // for (int i = 0; i < lista_soma->tamanho; i++)
    // {
    //     cout << i + 1 << ". " << lista_soma->buscarPorIndice(i)->getData().getTitulo() << " de " << lista_soma->buscarPorIndice(i)->getData().getArtista() << endl;
    // }

    // cout << endl;

    /**
     * Teste da função adicionar música com parâmetro do tipo Playlist.
     */
    // listaPlaylistsCadastradas->cabeca->getData().adicionarMusica(listaPlaylistsCadastradas->cabeca->proximo->getData());

    /**
     * Teste da função remover música com parâmetro do tipo Playlist.
     */
    // listaPlaylistsCadastradas->cabeca->getData().removerMusica(listaPlaylistsCadastradas->cabeca->proximo->getData());

    /**
     * Teste do construtor cópia de Playlist.
     */
    // listaPlaylistsCadastradas->inserir(Playlist("Playlist Teste"));
    // listaPlaylistsCadastradas->cabeca->proximo->proximo->data = listaPlaylistsCadastradas->cabeca->proximo->data;

    /**
     * Teste da sobrecarga no operador + de Playlist com função "Playlist + Playlist".
     * */
    // listaPlaylistsCadastradas->cabeca->proximo->data.adicionarMusica(Musica("Red", "Taylor Swift"));
    // Playlist playlist_marcos_gloria = listaPlaylistsCadastradas->cabeca->data + listaPlaylistsCadastradas->cabeca->proximo->data;

    // for (int i = 0; i < playlist_marcos_gloria.getLista()->tamanho; i++)
    // {
    //     cout << i + 1 << ". " << playlist_marcos_gloria.getLista()->buscarPorIndice(i)->getData().getTitulo() << " de " << playlist_marcos_gloria.getLista()->buscarPorIndice(i)->getData().getArtista() << endl;
    // }

    // cout << endl;

    /**
     * Teste da sobrecarga no operador + de Playlist com função "Playlist + Música".
     */
    // playlist_marcos_gloria = playlist_marcos_gloria + Musica("Midnight Rain", "Taylor Swift");
    // cout << 11 << ". " << playlist_marcos_gloria.getLista()->buscarPorIndice(10)->getData().getTitulo() << " de " << playlist_marcos_gloria.getLista()->buscarPorIndice(10)->getData().getArtista() << endl;

    // cout << endl;

    /**
     * Teste da sobrecarga no operador - de Playlist com função "Playlist - Playlist".
     */
    // playlist_marcos_gloria = playlist_marcos_gloria - listaPlaylistsCadastradas->cabeca->getData();

    // for (int i = 0; i < playlist_marcos_gloria.getLista()->tamanho; i++)
    // {
    //     cout << i + 1 << ". " << playlist_marcos_gloria.getLista()->buscarPorIndice(i)->getData().getTitulo() << " de " << playlist_marcos_gloria.getLista()->buscarPorIndice(i)->getData().getArtista() << endl;
    // }

    // cout << endl;

    /**
     * Teste da sobrecarga no operador - de Playlist com função "Playlist - Música".
     */
    // playlist_marcos_gloria = playlist_marcos_gloria - Musica("Midnight Rain", "Taylor Swift");

    // for (int i = 0; i < playlist_marcos_gloria.getLista()->tamanho; i++)
    // {
    //     cout << i + 1 << ". " << playlist_marcos_gloria.getLista()->buscarPorIndice(i)->getData().getTitulo() << " de " << playlist_marcos_gloria.getLista()->buscarPorIndice(i)->getData().getArtista() << endl;
    // }

    // cout << endl;

    /**
     * Teste da sobrecarga no operador >> de Playlist.
     */
    // Musica *musicaExtraida;
    // playlist_marcos_gloria >> musicaExtraida;

    // for (int i = 0; i < playlist_marcos_gloria.getLista()->tamanho; i++)
    // {
    //     cout << i + 1 << ". " << playlist_marcos_gloria.getLista()->buscarPorIndice(i)->getData().getTitulo() << " de " << playlist_marcos_gloria.getLista()->buscarPorIndice(i)->getData().getArtista() << endl;
    // }

    // cout << "A musica extraida foi " << musicaExtraida->getTitulo() << " de " << musicaExtraida->getArtista() << endl;

    // cout << endl;

    /**
     * Teste da sobrecarga no operador << de Playlist.
     */
    // playlist_marcos_gloria << musicaExtraida;

    // for (int i = 0; i < playlist_marcos_gloria.getLista()->tamanho; i++)
    // {
    //     cout << i + 1 << ". " << playlist_marcos_gloria.getLista()->buscarPorIndice(i)->getData().getTitulo() << " de " << playlist_marcos_gloria.getLista()->buscarPorIndice(i)->getData().getArtista() << endl;
    // }

    // cout << endl;

    /** ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^
     *  | | | | | | | | | | | | | | | | |
     * TESTES DAS NOVAS FUNÇÕES ACABOU!!!
     */

    /** Leitura do arquivo. */
    ifstream arquivo;
    string linha;
    arquivo.open("../arquivo_de_texto.txt");

    /* Caso o programa não consiga ler o arquivo retorna com erro. */
    if (!arquivo.is_open())
    {
        cout << "Houve um problema ao abrir o arquivo." << endl;
        return 1;
    }

    /* Se o programa conseguir abrir o arquivo o código lê as informações e cadastra as playlists. */
    while (getline(arquivo, linha))
    {
        istringstream iss(linha);
        string playlistNome;

        if (getline(iss, playlistNome, ';'))
        {
            listaPlaylistsCadastradas->inserir(playlistNome);
        }

        string musicaInfo;

        while (getline(iss, musicaInfo, ','))
        {
            istringstream issMusica(musicaInfo);
            string nomeMusica, nomeArtista;

            if (getline(issMusica, nomeMusica, ':') && getline(issMusica, nomeArtista))
            {
                bool existe = false;
                int index = listaPlaylistsCadastradas->tamanho - 1;
                Musica musica(nomeMusica, nomeArtista);
                listaPlaylistsCadastradas->buscarPorIndice(index)->data.adicionarMusica(musica);

                // Verifica se já existe essa música na lista de músicas cadastradas.
                for (int i = 0; i < listaMusicasCadastradas->tamanho; i++)
                {
                    // comparação de titulo
                    if (musica == listaMusicasCadastradas->buscarPorIndice(i)->getData())
                    {
                        existe = true;
                    }
                }
                /** Verifica se a música está cadastrada.
                 * Se sim, insere na lista de músicas cadastradas. Se não, continua.
                 */
                if (!existe)
                {
                    listaMusicasCadastradas->inserir(musica);
                }
            }
        }
    }

    /** Fecha o arquivo. */
    arquivo.close();

    /** Se o arquivo não fechar, retorna erro. Se o arquivo fechar continua o programa normal.*/
    if (arquivo.is_open())
    {
        cout << "O arquivo não foi fechado corretamente." << endl;
        return 1;
    }
    else
    {
        cout << "O arquivo foi lido com sucesso." << endl;
    }

    /* MENU PRINCIPAL */

    int continuar = 1;       /**< Variável que indica qual opção do menu foi escolhida pelo usuário. */
    int playlistTocando = 0; /**< Variável que indica a playlist tocando atualmente. Caso o usuário não escolha uma playlist irá tocar a primeira cadastrada.*/

    do /**< Loop exibe o menu até que o usuário selecione a opção "Sair"*/
    {
        cout << "MENU!" << endl
             << "O que voce deseja fazer? (Digite o numero apenas)" << endl;
        cout << "1 - Gerenciar musicas" << endl;
        cout << "2 - Gerenciar playlists" << endl;
        cout << "3 - Gerenciar musicas em playlists" << endl;
        cout << "4 - Selecione uma playlist para tocar" << endl;
        cout << "5 - O que esta tocando agora?" << endl;
        cout << "6 - Sair" << endl;

        cin >> continuar;

        switch (continuar)
        {
        case 1:
            gerenciarMusicas(listaMusicasCadastradas, listaPlaylistsCadastradas);
            break;
        case 2:
            gerenciarPlaylists(listaPlaylistsCadastradas, listaMusicasCadastradas);
            break;
        case 3:
            gerenciarMusicasEmPlaylists(listaPlaylistsCadastradas, listaMusicasCadastradas);
            break;
        case 4:
            playlistTocando = escolherPlaylist(listaPlaylistsCadastradas);
            break;
        case 5:
            estaTocandoAgora(listaPlaylistsCadastradas, playlistTocando);
            break;
        case 6:
            sair(listaMusicasCadastradas, listaPlaylistsCadastradas);
            return 0;
        default:
            cout << "Digite uma opção válida!" << endl;
            break;
        }
    } while (continuar);
}