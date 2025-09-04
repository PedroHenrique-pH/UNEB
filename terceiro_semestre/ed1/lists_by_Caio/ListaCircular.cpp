#include <iostream>
#include <string>


struct Nodo2
{
    std::string palavra;
    struct Nodo2 *ant, *prox;
};    

class ListaCircular
{

private:
    Nodo2 *inicio, *fim; 

public:
    ListaCircular(){
        inicio = nullptr;
        fim = nullptr;
    };

    void inserir(std::string palav);
    void imprimir();
    void retirar();
};

void ListaCircular::inserir(std::string palav)
{
    Nodo2* novo;
    novo = new Nodo2();

    novo->palavra = palav;

    //se for o primeiro elemento, ou seja, se o ponteiro que está apontando para o início não tiver ninguém ainda.
    if (inicio == nullptr){ 
        inicio = novo; //marca que esse novo que foi add agr é o início.

        novo->ant = inicio; // o ponteiro que aponta para o anterior dele vai apontar pra ele mesmo
        novo->prox = inicio; // o ponteiro que aponta para o próximo vai apontar pra ele mesmo também.

        fim = inicio; //marca que o fim é ele tbm, pq, nesse caso, só tem ele.
    }
    //se não for o primeiro elemento, segue essa regra:
    else{

        novo->ant = fim; //o ponteiro que aponta pra o elemento anterior vai receber "fim", pq "fim" neste momento é o nodo de antes, então o novo->ant vai receber o nodo de antes, que, aqui ainda é chamado de "fim".
        novo->prox = inicio; //o ponteiro que aponta para o próximo do novo, que deve sempre apontar para o primeiro nodo que foi adicionado na fila, agora aponta para o "inicio" que foi inserido primeiro (é o primeiro nodo adicionado na fila)
        fim->prox = novo; //mesma coisa, o "fim", que ainda é o nodo de antes, no seu ponteiro que aponta pro próximo nodo, vai apontar agora para esse novo nodo que foi inserido
        inicio->ant = novo; //o ponteiro que aponta para o anterior do inicio, que deve sempre apontar para o ultimo nodo que foi adicionado na fila, agora aponta para o "novo" que foi inserido agora (é o ultimo nodo adicionado na fila)
        fim = novo; // e, finalmente, o "fim" é/recebe "novo" (que é nodo adicionado agora), ou seja, agora "fim" é esse "novo"
    } 
}

void ListaCircular::retirar()
{
    Nodo2 *aux;

    if (inicio == nullptr)
    {
        std::cout<<("nao tem nada para ser retirado");
        return;
    }

    aux = inicio;

    while ((aux->prox != fim) ){//vai andando do inicio (que é o valor de aux) até o fim da lista
        aux = aux->prox;
    }

    fim = aux->ant; //como o fim vai ser deletado, o novo fim vai ser anterior ao fim atual
    fim->prox = inicio; //agora o ponteiro que aponta para o proximo nodo do novo fim (que era o anterior do fim passado) vai apontar para o inicio, para fazer aquele enlaçe caracteritico
    delete aux; // byebye aux, só serve pra poder passar tudo e n perder os valores antes do delete.

}

void ListaCircular::imprimir(){
    Nodo2 * aux2;
        
    aux2 = inicio;
    do {
        std::cout << aux2->palavra << " ";
        aux2 = aux2->prox;
    } while (aux2 != inicio);
    std::cout<<("\n");
}

int main(){
    ListaCircular listacirc;
    
    listacirc.inserir("eu");
    listacirc.inserir("te");
    listacirc.inserir("amo");

    listacirc.imprimir();

    listacirc.retirar();

    listacirc.imprimir();


}


// exemplo de editor de texto em uma lista fila circular
// #include <iostream>
// #include <string>

// struct Nodo2 {
//     std::string palavra;
//     Nodo2 *ant, *prox;
// };

// class EditorDeTexto {
// private:
//     Nodo2 *inicio, *fim;

// public:
//     EditorDeTexto() : inicio(nullptr), fim(nullptr) {}

//     void inserir(const std::string& palav);
//     void imprimir();
//     void eliminar();
//     void editar(const std::string& novaPalavra);
//     void palavraAnterior();
//     void palavraPosterior();
//     void menu(char opcao);
// };

// void EditorDeTexto::inserir(const std::string& palav) {
//     Nodo2* novo = new Nodo2();
//     novo->palavra = palav;

//     if (inicio == nullptr) {
//         novo->ant = novo;
//         novo->prox = novo;
//         inicio = fim = novo;
//     } else {
//         novo->ant = fim;
//         novo->prox = inicio;
//         fim->prox = novo;
//         inicio->ant = novo;
//         fim = novo;
//     }
// }

// void EditorDeTexto::eliminar() {
//     if (inicio == nullptr) {
//         std::cout << "Não há nada para ser retirado\n";
//         return;
//     }

//     if (inicio == fim) {
//         delete inicio;
//         inicio = fim = nullptr;
//     } else {
//         Nodo2* aux = fim;
//         fim = fim->ant;
//         fim->prox = inicio;
//         inicio->ant = fim;
//         delete aux;
//     }
// }

// void EditorDeTexto::imprimir() {
//     if (inicio == nullptr) {
//         std::cout << "Lista vazia\n";
//         return;
//     }

//     Nodo2* aux = inicio;
//     do {
//         std::cout << aux->palavra << " ";
//         aux = aux->prox;
//     } while (aux != inicio);
//     std::cout << "\n";
// }

// void EditorDeTexto::editar(const std::string& novaPalavra) {
//     if (fim)
//         fim->palavra = novaPalavra;
// }

// void EditorDeTexto::palavraAnterior() {
//     if (fim)
//         std::cout << fim->ant->palavra << "\n";
// }

// void EditorDeTexto::palavraPosterior() {
//     if (fim)
//         std::cout << fim->prox->palavra << "\n";
// }

// void EditorDeTexto::menu(char opcao) {
//     std::string entrada;
//     switch (opcao) {
//     case 'E':
//         std::cout << "Nova palavra: ";
//         std::cin >> entrada;
//         editar(entrada);
//         break;
//     case 'D':
//         std::cout << "Insira a palavra: ";
//         std::cin >> entrada;
//         inserir(entrada);
//         break;
//     case 'S':
//         eliminar();
//         break;
//     case '<':
//         palavraAnterior();
//         break;
//     case '>':
//         palavraPosterior();
//         break;
//     case 'I':
//         imprimir();
//         break;
//     case 'X':
//         exit(0);
//     default:
//         std::cout << "Opção inválida!\n";
//     }
// }

// int main() {
//     EditorDeTexto editorTxt;
//     char opc;
//     while (true) {
//         std::cout << "\nMenu: [D] Inserir | [E] Editar última | [S] Eliminar última | [<] Anterior | [>] Posterior | [I] Imprimir | [X] Sair\n";
//         std::cout << "Digite sua opção: ";
//         std::cin >> opc;
//         editorTxt.menu(opc);
//     }
// }

