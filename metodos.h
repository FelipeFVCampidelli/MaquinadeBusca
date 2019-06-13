#ifndef METODOS_H
#define METODOS_H

#include<vector>
#include<string>

using namespace std;

//Conta o número de arquivos na pasta Dataset
int Count_File();

//Lê todos os arquivos e coloca cada palavra em um vector de string (separação por espaço)
vector<string> Read_Files();

//Lê um arquivo e coloca suas palavras em um vector de string
vector<string> Read_File(string NameFile);

//Retorna o Modulo (Norma) de um vetor
double Modulo(vector<double> x);

//Retorna o produto escalar entre dois vetores
double Somatorio(vector<double> a, vector<double> b);

//Retorna a similaridade cosseno de dois vetores
double Cosine_Similarity(vector<double> a, vector<double> b);

//Conta quantas arquivos contém a palavra
int Count_Files_Word(string palavra);

//retorna o idf (inverse document frequency) da palavra
double idf(string palavra);

//retorna o tf (term frequency) da palavra
int tf(string NameFile, string palavra);

//Cria o vetor onde cada coordenada representa o peso de uma palavra
vector<double> Vetor_Documento(string NameFile, vector<string> palavra);

#endif // METODOS_H
