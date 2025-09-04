#include<iostream>

struct nodo{
    int info;
    struct nodo *dir, *esq;
};

class Arvore{
    public:
        nodo *raiz;
        Arvore(){
            this->raiz = nullptr;
        }
    
    nodo *inserir(nodo *&raiz, int n);
    nodo *remover(nodo *raiz, int n);
    nodo *removerPelaEsquerda(nodo *raiz, nodo *anterior);
    void emOrdem(nodo *raiz);
    int buscar(nodo *raiz, int n);
    int contarNodos(nodo *raiz);
    int contarFolhas(nodo *raiz);
    bool arvoreCompleta(nodo *raiz);
    bool completarArvore(nodo *raiz);
};

nodo *Arvore::inserir(nodo *&raiz, int n){
    if(raiz == nullptr){
        raiz = new nodo();

        raiz->info = n;
        raiz->esq = nullptr;
        raiz->dir = nullptr;
    }

    if(n > raiz->info){
        raiz->dir = this->inserir(raiz->dir, n);
    } else if (n < raiz->info){
        raiz->esq = this->inserir(raiz->esq, n);
    } else //std::cout << "Este número já existe na árvore";

    return raiz;
}

nodo *Arvore::remover(nodo *raiz, int n){
    nodo *temp;

    if (raiz == nullptr){
        return raiz;
    }

    if(n > raiz->info){
        raiz->dir = this->remover(raiz->dir, n);
    } else if (n < raiz->info){
        raiz->esq = this->remover(raiz->esq, n);
    } else{
        if (raiz->esq == nullptr)
        {
            temp = raiz;
            raiz = raiz->dir;
            delete temp;
            return raiz;
        }

        if (raiz->dir == nullptr)
        {
            temp = raiz;
            raiz = raiz->esq;
            delete temp;
            return raiz;
        }

        else{
            raiz->esq = this->removerPelaEsquerda(raiz, raiz->esq);
        }        
    }

return raiz;
}

nodo *Arvore::removerPelaEsquerda(nodo *raiz, nodo *anterior){
    if (anterior->dir != nullptr){
        anterior->dir = removerPelaEsquerda(raiz, anterior->dir);
        return anterior;
    } else{
        raiz->info = anterior->info;
        nodo *temp = anterior;
        anterior = anterior->esq;
        delete temp;
        return anterior;
    }
}

void Arvore::emOrdem(nodo *raiz){
    if (raiz == nullptr)
    {
        return;
    }

    this->emOrdem(raiz->esq);
    std::cout << raiz->info << std::endl;
    this->emOrdem(raiz->dir);
}

int Arvore::buscar(nodo *raiz, int n){
    if (raiz == nullptr)
    {
        return -1;
    }

    if (raiz->info == n)
    {
        return raiz->info;
    }

    if (raiz->info > n)
    {
        return buscar(raiz->esq, n);
    }

    else
    {
        return buscar(raiz->dir, n);
    }
}

int Arvore::contarNodos(nodo *raiz){
    if (raiz == nullptr)
    {
        return 0;
    }

    return (1 + contarNodos(raiz->esq) + contarNodos(raiz->dir));
}

int Arvore::contarFolhas(nodo *raiz){
    if (raiz == nullptr)
    {
        return 0;
    } 
    if (raiz->esq == nullptr && raiz->dir == nullptr)
    {
        return 1;
    }

    return (contarFolhas(raiz->esq) + contarFolhas(raiz->dir));
}

bool Arvore::arvoreCompleta(nodo *raiz){
    if (raiz == nullptr)
    {
        return true;
    }

    if (raiz->esq != nullptr && raiz->dir == nullptr || 
        raiz->esq == nullptr && raiz->dir !=nullptr)
    {
        return false;
    }
    return (this->arvoreCompleta(raiz->esq) && this->arvoreCompleta(raiz->dir));
    
}

bool Arvore::completarArvore(nodo *raiz){
    if (raiz == nullptr)
    {
        return true;
    }

    if (raiz->esq == nullptr && raiz->dir == nullptr)
    {
        return true;
    }

    if (raiz->esq != nullptr && raiz->dir == nullptr || raiz->esq == nullptr && raiz->dir != nullptr)
    {
        if (raiz->esq == nullptr)
        {
            this->inserir(raiz, raiz->info - 1);
        }
        else
        {
            this->inserir(raiz, raiz->info + 1);
        }     
    }

    return(this->completarArvore(raiz->esq) && this->completarArvore(raiz->dir));    
}

int main(){
    Arvore tree = Arvore();
   
    tree.raiz = tree.inserir(tree.raiz, 8);
    tree.raiz = tree.inserir(tree.raiz, 9);
    tree.raiz = tree.inserir(tree.raiz, 10);
    tree.raiz = tree.inserir(tree.raiz, 11);
    tree.raiz = tree.inserir(tree.raiz, 12);
    tree.raiz = tree.inserir(tree.raiz, 13);


    tree.emOrdem(tree.raiz);

    std::cout << "Quantidade de nodos na árvore: " << (tree.contarNodos(tree.raiz)) << std::endl;
    std::cout << "quantidade de folhas: " << (tree.contarFolhas(tree.raiz)) << std::endl;
    std::cout << "Arvore completa?: " << (tree.arvoreCompleta(tree.raiz) ? "Sim"  : "Não") << std::endl;
    std::cout << "completando arvore: " << (tree.completarArvore(tree.raiz)) << std::endl;
    std::cout << "Arvore completa?: " << (tree.arvoreCompleta(tree.raiz) ? "Sim"  : "Não") << std::endl;

}
