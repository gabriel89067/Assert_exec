#pragma once

#include <cassert>
#include <vector>

// Define um arranjo de qualquer Tipo cujos índices variam em
// qualquer intervalo, inclusive negativos.
template <class Tipo> 
class Arranjo {
  public:
    // Cria um arranjo cujos índices variam de 'inicio' até 'fim'.
    // PRECONDIÇÃO: fim >= inicio.
    Arranjo(int inicio, int fim);

    // Altera o valor do índice i.
    // PRECONDIÇÃO: i está dentro do intervalo de índices do vetor.
    void atribuir(int i, Tipo valor);

    // Retorna o valor do índice i.
    // PRECONDIÇÕES: 
    // (1) i está dentro do intervalo de índices do vetor.
    // (2) i foi inicializando anteriormente.
    Tipo valor(int i) const; 
  
  private:
    int inicio_;  // Primeiro índice válido do arranjo.
    int fim_;  // Último índice válido do arranjo.
    std::vector<Tipo> elementos_;  // Elementos do arranjo.
    std::vector<Tipo> valores_;
};

// DEFINIÇÃO DAS CLASSES DE EXCEÇÃO.

struct ExcecaoIntervaloVazio {
  int inicio;
  int fim;
 
  //assert(fim >= inicio;);
};

struct ExcecaoIndiceInvalido {
  int indice;
  int inicio;
  int fim;
  
 //assert(i >= inicio_ && i <= fim_);
};

struct ExcecaoIndiceNaoInicializado {
  int indice;
};

// IMPLEMENTAÇÃO DOS MÉTODOS DA CLASSE.

template <class Tipo> 
Arranjo<Tipo>::Arranjo(int inicio, int fim) : 
    inicio_(inicio), 
    fim_(fim) {
      
  if(fim < inicio) throw ExcecaoIntervaloVazio{inicio_, fim_};   
  elementos_.resize(fim - inicio + 1);
  valores_.resize(fim - inicio + 1);
}

template <class Tipo> 
void Arranjo<Tipo>::atribuir(int i, Tipo valor) {
 if(i < inicio_ || i > fim_) throw ExcecaoIndiceInvalido{i, inicio_, fim_};
  int j = i - inicio_;
  elementos_[j] = valor;
  valores_[j] = valor;
}

template <class Tipo> 
Tipo Arranjo<Tipo>::valor(int i) const { 
  if(i < inicio_ || i > fim_) throw ExcecaoIndiceInvalido{i, inicio_, fim_};
  int contem_val = 0;
 
  int j = i - inicio_;  
   
   for(int x=0;x<j;x++){
     if(valores_[x]==elementos_[j]){
         contem_val++;}}
       
   if(!contem_val<1) throw ExcecaoIndiceNaoInicializado{i};
   
  return elementos_[j];
}