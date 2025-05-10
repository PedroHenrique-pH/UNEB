#include <iostream>
#include <string>

struct Nodo2 {
    std::string palavra;
    Nodo2 *ant, *prox;
};

class EditorDeTexto {
private:
    Nodo2 *inicio;
    Nodo2 *palavraAtual;

public:
    EditorDeTexto(): 
        inicio(nullptr), 
        palavraAtual(nullptr) {}

    void inserir(const std::string& palav);
    void imprimir();
    void eliminar();
    void editar(const std::string& novaPalavra);
    void palavraAnterior();
    void palavraPosterior();
    void menu(char opcao);
    void limpartela();

};

void EditorDeTexto::inserir(const std::string& palav) {
    Nodo2* novo = new Nodo2{palav, nullptr, nullptr};
    if (!inicio) {
        novo->prox = novo->ant = novo;
        inicio = palavraAtual = novo;
    } else {
        novo->prox = palavraAtual->prox;
        novo->ant = palavraAtual;
        palavraAtual->prox->ant = novo;
        palavraAtual->prox = novo;
    }
    palavraAtual = novo;
}

void EditorDeTexto::eliminar() {
    if (!palavraAtual) {
        std::cout << "Nada para eliminar.\n";
        return;
    }

    if (palavraAtual->prox == palavraAtual) {
        delete palavraAtual;
        inicio = palavraAtual = nullptr;
    } else {
        Nodo2* aux = palavraAtual;
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
        if (inicio == aux) inicio = aux->prox;
        palavraAtual = aux->prox;
        delete aux;
    }
}

void EditorDeTexto::editar(const std::string& novaPalavra) {
    if (palavraAtual)
        palavraAtual->palavra = novaPalavra;
}

void EditorDeTexto::palavraAnterior() {
    if (palavraAtual)
        palavraAtual = palavraAtual->ant;
}

void EditorDeTexto::palavraPosterior() {
    if (palavraAtual)
        palavraAtual = palavraAtual->prox;
}

void EditorDeTexto::imprimir() {
    if (!inicio) {
        std::cout << "Frase: (vazia)\n";
        return;
    }

    std::cout << "Frase: ";
    Nodo2* aux = inicio;
    do {
        if (aux == palavraAtual)
            std::cout << aux->palavra << " ";
        else
            std::cout << aux->palavra << " ";
        aux = aux->prox;
    } while (aux != inicio);
    std::cout << "\nPalavra atual: " << palavraAtual->palavra << "\n";
}

void EditorDeTexto::menu(char opcao) {
    std::string entrada;
    switch (opcao) {
    case 'E':
        std::cout << "Nova palavra: ";
        std::cin >> entrada;
        editar(entrada);
        break;
    case 'D':
        std::cout << "Insira a palavra: ";
        std::cin >> entrada;
        inserir(entrada);
        break;
    case 'S':
        eliminar();
        break;
    case '<':
        palavraAnterior();
        break;
    case '>':
        palavraPosterior();
        break;
    case 'X':
        exit(0);
    default:
        std::cout << "Opção inválida!\n";
    }
    limpartela();
    imprimir();
}

void EditorDeTexto::limpartela(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    EditorDeTexto editor;
    char opc;
    while (true) {
        std::cout << "\n[E] Editar | [D] Inserir | [S] Eliminar | [<] Anterior | [>] Posterior | [X] Sair\n";
        std::cout << "Digite sua opção: ";
        std::cin >> opc;
        editor.menu(opc);
    }
}