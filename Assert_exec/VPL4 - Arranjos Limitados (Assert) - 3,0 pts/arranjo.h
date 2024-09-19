#pragma once

#include <vector>
#include <assert.h>

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
    std::vector<Tipo> valores_; //valores armazenados
    
};

// IMPLEMENTAÇÃO DOS MÉTODOS DA CLASSE.

template <class Tipo> 
Arranjo<Tipo>::Arranjo(int inicio, int fim) : 
    inicio_(inicio),
    fim_(fim) {
    assert(fim >= inicio);    
  elementos_.resize(fim - inicio + 1);
  valores_.resize(fim - inicio + 1);
}

template <class Tipo> 
void Arranjo<Tipo>::atribuir(int i, Tipo valor) {
  assert(i >= inicio_ && i <= fim_);
  int j = i - inicio_;
  elementos_[j] = valor;
   valores_[j] = valor;
}

template <class Tipo> 
Tipo Arranjo<Tipo>::valor(int i) const { 
  assert(i >= inicio_ && i <= fim_);
  int contem_val = 0;
 
  int j = i - inicio_;  
   
   for(int x=0;x<j;x++){
     if(valores_[x]==elementos_[j]){
         contem_val++;}}
       
   assert(contem_val<1);
   
  return elementos_[j];
}