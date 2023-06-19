# DIM0120 - 2023.1 – Gerenciador de Playlists com Lista Encadeada (Projeto 1)

## Equipe:
A equipe é composta por dois alunos do curso de Bacharelado em Tecnologia da Informação, são eles:
- Glória Maria Souza Campêlo (20220034667)
* Marcos Vinícius Noberto de Oliveira (20220049973)


## Como compilar e rodar o programa:
__Para acessar o programa:__
1. Acesse a pasta 'build';
2. Execute o arquivo 'MeuProjeto.exe'

Pronto, você já tem acesso ao programa :)

__Quanto à navegação pela interface:__ <br>
- O programa contém um menu principal que guia o usuário por outros menus e pelas funções da aplicação, portanto a navegação é bem simples.
- O Menu principal possui 3 opções para submenus: "Gerenciar musicas", "Gerenciar playlists" e "Gerenciar musicas em playlists". Cada função leva o usuário para um segundo menu correspondente à ação que o mesmo deseja realizar.<br>
- Alem disso, o menu principal também conta com uma opção para "Selecione uma playlist para tocar" e outra "O que esta tocando agora?" que informa o usuário qual música está tocando no momento.<br>
- Finalmente, o menu exibe a função "Sair", que encerra o programa.<br>
- Para selecionar uma ação basta digitar o número ao lado da opção desejada e apertar a tecla 'enter'.<br><br>

_Durante toda a execução do programa, são impressas instruções claras para o usuário de como interagir com a aplicação._

## Funções do programa:
- <h3>Gerenciar Musicas:</h3>
    <p>O Gerenciar Músicas é uma funcionalidade para utilizar o CRUD de todas as músicas existentes no projeto. Para acessá-la, basta digitar "1" na tela inicial do programa.
    Após o acesso, o usuário receberá 3 opções de modificações, sendo elas: Adicionar, Remover e Listar Músicas. Ambas podem ser acessadas respectivamente digitando "1", "2" ou "3" no prompt de comando.</p>
    <ul>
        <li>
            <h4>Adicionar Música:</h4>
            <p>O adicionar música serve para cadastrar a música no sistema, mas não necessariamente em uma playlist. Para realizar o cadastro, basta digitar, no prompt de comando, o título da música (Ex: "Título"), pressionar a tecla enter, e logo em seguida digitar o nome do artista responsável pela obra (Ex: "Artista"). Após isso, o sistema manda uma mensagem de confirmação para informar se os dados preenchidos são válidos e se o registro foi bem efetuado.</p>
        </li>
        <li>
            <h4>Remover Música:</h4>
            <p>O remover música serve para excluir uma música no sistema, retirando-a de qualquer playlist em que estivesse. Para realizar a remoção, basta digitar, no prompt de comando, o título da música (Ex: "Título"), pressionar a tecla enter, e logo em seguida digitar o nome do artista responsável pela obra (Ex: "Artista"). Após isso, o sistema manda uma mensagem de confirmação para informar se a exclusão foi bem-sucedida e se a música foi removida de alguma playlist.</p>
        </li>
        <li>
            <h4>Listar Músicas:</h4>
            <p>O listar música imprime uma lista, enumerada em ordem crescente, com todas as músicas cadastradas no sistema.</p>
        </li>
    </ul>
    <p>Após o acesso do Gerenciar Músicas, o usuário pode acessar a função "Voltar" digitando "4" no prompt de comando, sendo retornado para o menu inicial do sistema.</p>


- <h3>Gerenciar Playlists:</h3>
    <p>O Gerenciar Playlists é uma funcionalidade para utilizar o CRUD das playlists de musica. Para acessa-lá, basta digitar "2" na tela inicial do programa. 
    Após o acesso, o usuário receberá 4 opções de modificações, sendo elas: Adicionar, Remover, Listar Playlists e Realizar Operações. Ambas podem ser acessadas respectivamente digitando "1", "2", "3" e "4" no prompt de comando.</p>
    <ul>
        <li>
            <h4>Adicionar Playlists</h4>
            <p>O adicionar playlists serve para cadastro de novas playlists pro sistema. Para realizar o cadastro, basta digitar, no prompt de comando, o nome da playlist(Ex: "Minhas Musicas") seguido da tecla enter. Após isso, o sistema manda uma mensagem de confirmação para informar se os dados preenchido são válidos e se o registro foi bem efetuado.</p>
        </li>
        <li>
            <h4>Remover Playlists</h4>
            <p>O remover playlists serve para excluir uma playlist do sistema. Para realizar a remoção, basta digitar, no prompt de comando, o nome da playlist(Ex: "Minhas Musicas") seguido da tecla enter. Após isso, o sistema manda uma mensagem de confirmação para informar se o exclusão foi bem-sucedida.</p>
        </li>
        <li>
            <h4>Listar Playlists</h4>
            <p>O listar playlists imprime uma lista, enumerada em ordem crescente, com todas as playlists cadastradas no sistema.</p>
        </li>
        <li>
            <h4>Realizar Operações</h4>
            <p>Após o acesso, o usuário recebe 6 opções de operações, sendo elas: Soma de playlist com outra playlist, soma de playlist com uma musica, remoção de musicas iguais entre 2 playlist, remoção de uma musica de uma playlist, extrair a ultima musica de uma playlist e inserir uma musica no final de uma playlist, sendo acessadas respectivamente por "1", "2", "3", "4", "5" e "6" no terminal.
            
            Playlist A + Playlist B:
            O programa imprime uma lista das playlists cadastradas no sistema, basta o usuário digitar o número de uma playlist no termianl (Ex: "1"), clicar enter, e depois repetir o processo com a outra playlist que será somada (Ex: "2"). Após isso, o sistema manda uma mensagem de confirmação para informar se as escolhas são válidas, se sim, uma nova playlist será criado com as musicas das duas playlists.

            Playlist A + Musica B:
            O programa imprime uma lista das playlists cadastradas no sistema, basta o usuário digitar o número de uma playlist no termianl (Ex: "1"), clicar enter, e depois realizar o cadastro da música que será adicionada. Para realizar o cadastro, basta digitar, no prompt de comando, o título da música(Ex: "Titulo"), pressionar a tecla enter, e logo em seguida digitar o nome do artista respónsavel pela obra (Ex: "Artista"). Após isso, o sistema manda uma mensagem de confirmação para informar se o registro foi bem sucedido, se sim, uma nova playlist semelhante será criada com a musica adicionada.

            Playlist A - Playlist B:
            O programa imprime uma lista das playlists cadastradas no sistema, basta o usuário digitar o número de uma playlist no termianl (Ex: "1"), clicar enter, e depois repetir o processo com a outra playlist (Ex: "2"). Após isso, o sistema manda uma mensagem de confirmação para informar se as escolhas são válidas, se sim, uma nova playlist será criado com as musicas da primeira playlist que não estão na segunda playlist.

            Playlist A - Musica B:
            O programa imprime uma lista das playlists cadastradas no sistema, basta o usuário digitar o número de uma playlist no termianl (Ex: "1"), clicar enter, e depois realizar o cadastro da música que será removida. Para realizar o cadastro, basta digitar, no prompt de comando, o título da música(Ex: "Titulo"), pressionar a tecla enter, e logo em seguida digitar o nome do artista respónsavel pela obra (Ex: "Artista"). Após isso, o sistema manda uma mensagem de confirmação para informar se a remoção foi bem sucedido, se sim, uma nova playlist semelhante será criada sem a musica que foi cadastrada.

            Extrair a ultima musica de uma playlist:
            O programa imprime uma lista das playlists cadastradas no sistema, basta o usuário digitar o número de uma playlist no termianl (Ex: "1") e clicar enter. Após isso, se a remoção foi bem sucedida, i sistema informará a musica que foi extraida da playlist.

            Inserir uma nova música no final de uma playlist:
            O programa imprime uma lista das playlists cadastradas no sistema, basta o usuário digitar o número de uma playlist no termianl (Ex: "1"), clicar enter, e depois realizar o cadastro da música que será adicionada. Para realizar o cadastro, basta digitar, no prompt de comando, o título da música(Ex: "Titulo"), pressionar a tecla enter, e logo em seguida digitar o nome do artista respónsavel pela obra (Ex: "Artista"). Após isso, o sistema manda uma mensagem de confirmação para informar se o registro foi bem sucedido.
            </p>
        </li>
    </ul>
    <p>Após o acesso do Gerenciar Playlists, o usuário pode acessar a função "Voltar" digitando "4" no prompt de comando, sendo retornado para o menu inicial do sistema.</p>

- <h3>Gerenciar Musica em Playlists:</h3>
    <p>O Gerenciar Playlists é uma funcionalidade para utilizar o CRUD das músicas que estão dentro de uma determinada playlist. Para acessa-lá, basta digitar "3" na tela inicial do programa. 
    Após o acesso, o sistema imprime uma lista enumerada das playlists existentes no programa, permitindo que o usuário digite o número equivalente a playlist que ele quer modificar.
    Depois de escolher a playlist desejada, o usuário receberá 4 opções de modificações, sendo elas: Adicionar, Remover, Listar e Mover as músicas dentro da playlists correspondente. Ambas podem ser acessadas respectivamente digitando "1", "2", "3" ou "4" no prompt de comando.</p>
    <ul>
        <li>
            <h4>Adicionar Musicas a Playlist</h4>
            <p>O adicionar musicas a playlist serve para cadastro de novas musicas para a playlist, também sendo cadastrada na lista de músicas gerais caso ainda não existisse. Após acessar a opção, o usuário recebe 2 formas de cadastro: Adicionar musica ou adicionar musicas de outras playlists.

            Adicionar Musica:
             Para realizar o cadastro, basta digitar, no prompt de comando, o título da música(Ex: "Titulo"), pressionar a tecla enter, e logo em seguida digitar o nome do artista respónsavel pela obra (Ex: "Artista"). Após isso, o sistema manda uma mensagem de confirmação para informar se os dados preenchido são válidos e se o registro foi bem efetuado.</p>

             Adicionar Musicas de Outras Playlists:
             O prompt listará as playlists cadastradas no sistema, basta o usuário digitar o número equivalente a playlist que será adicionada a atual (Ex: "1") e pressionar a tecla enter.
             Após isso, o sistema manda uma mensagem de confirmação para informar se a opção selecionada é válida e se o registro foi bem efetuado.

        </li>
        <li>
            <h4>Remover Musicas da Playlist</h4>
            <p>O remover musicas da playlist serve para excluir uma musica para a playlist, mas não necessáriamente do sistema. Após acessar a opção, o usuário recebe 2 formas de remoção: Remover uma Musica ou Remover Musicas Iguais a Outra Playlist. 
            
            Remover uma Musica:
            Para realizar a remoção, basta digitar, no prompt de comando, o título da música(Ex: "Titulo"), pressionar a tecla enter, e logo em seguida digitar o nome do artista respónsavel pela obra (Ex: "Artista"). Após isso, o sistema manda uma mensagem de confirmação para informar se o exclusão foi bem-sucedida.</p>

            Remover Musicas Iguais a Outra Playlist:
            O prompt listará as playlists cadastradas no sistema, basta o usuário digitar o número equivalente a playlist que possui as musicas que serão removidas (Ex: "1"), e pressionar a tecla enter. Após isso, o sistema manda uma mensagem de confirmação para informar se a opção selecionada é válida e se a remoção foi bem efetuada.

        </li>
        <li>
            <h4>Listar Musicas da Playlist</h4>
            <p>O listar musicas da playlist imprime uma lista, enumerada em ordem crescente, com todas as musicas existentes dentro da playlist selecionada anteriormente.</p>
        </li>
        <li>
            <h4>Mover Musicas da Playlist</h4>
            <p>O mover musicas da playlist imprime uma lista, enumerada em ordem crescente, com todas as musicas existentes dentro da playlist, após isso, basta digitar a posição da música que deseja ser movida(Ex: "4"), para a posição que deseja move-lá (Ex: "1"), arrastando a musica correspondente a po sição realocada e todas entre elas para uma posição a mais. Após isso, o sistema manda uma mensagem de confirmação para informar se a realocação da musica foi bem-sucedida.</p>
        </li>
    </ul>
    <p>Após o acesso do Gerenciar Musicas Playlists, o usuário pode acessar a função "Voltar" digitando "5" no prompt de comando, sendo retornado para o menu inicial do sistema.</p>


- <h3>Selecione uma playlist para tocar:</h3>
    <p>É uma funcionalidade para selecionar a playlist que terá suas musicas percorridas pelos sistema. Para acessa-lá, basta digitar "4" na tela inicial do programa. 
    Após o acesso, o sistema imprime uma lista enumerada das playlists existentes no programa, permitindo que o usuário digite no prompt o número equivalente a playlist que ele quer ouvir(Ex: "1"). Caso a entrada seja válida, o sistema manda uma mensagem de confirmação e retorna para o menu inicial.</p>

- <h3>O que está tocando agora?:</h3>
    <p>É uma funcionalidade para tocar a próxima música da playlist que está sendo percorrida pelo sistema. Caso nenhuma playlist seja selecionada, ele percorrerá a primeira. Para acessa-lá, basta digitar "5" na tela inicial do programa. 
    Após o acesso, o sistema retorna para o menu inicial com uma mensagem ao topo, mostrando qual música está sendo tocada e qual o artista respónsavel. Caso todas as músicas da playlist tenham sido percorridas, o sistema imprime uma mensagem notificando o acontecimento.</p>

- <h3>Sair:</h3>
    <p>É uma funcionalidade que fecha o programa e o prompt de comando. Tchau-tchau usuário, volte sempre!</p>

## Novas atualizações do programa:
<h3>Gerenciar Musica em Playlists:</h3>
    <li>
        <h4>Adicionar Musicas a Playlist - Adição de musicas de outra playlist</h4>
        <h4>Remover Musicas da Playlist - Remoção de musicas iguais a outra playlist</h4>
    </li>
<h3>Gerenciar Playlists:</h3>
    <li>
        <h4>Realizar Operações(Nova Aba)</h4>
        <li>
            <h4>Playlist A + Playlist B</h4>
            <h4>Playlist A + Musica B</h4>
            <h4>Playlist A - Playlist B</h4>
            <h4>Playlist A - Musica B</h4>
            <h4>Extrair a ultima musica</h4>
            <h4>Inserir uma musica no final</h4>
        </li>
    </li>


## Limitações do Programa:
- O programa não consegue restringir as entradas que recebe, assim, ele pode receber um texto no lugar de um número, ocasionando em bugs.
- O programa não possui um banco de dados, assim, todos o dados modificados serão perdidos ao fim do programa.

## Dificuldades encontradas durante o desenvolvimento:
- Um dos principais problemas foi a desalocação de memória, não sabiamos a forma correta de fazer e tivemos muitas dificuldades por tentar integrar de uma forma errada.
- Utilização de template para o tipo de dado da classe lista, não conseguimos utilizar o template e manter um arquivo cpp ao mesmo tempo.

