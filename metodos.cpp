#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

using namespace std;

int Count_File(){

    DIR *dp;
    int N = -2;
    struct dirent *ep;
    dp = opendir ("./Dataset");

    if (dp != NULL){
        while (ep = readdir (dp))
            N++;

        (void) closedir (dp);
    }
    return (N);
}

vector<string> Read_Files(){

    string NameFile, line;
    vector<string> x;
    for(int i=1; i<Count_File(); i++){
        NameFile = "Doc-"+to_string(i)+".txt";
        ifstream myfile(NameFile);

        if (myfile.is_open()){
            while (! myfile.eof() ){
                getline (myfile,line);
                if(line.empty())
                    continue;
                transform(line.begin(), line.end(), line.begin(), ::tolower);
                istringstream iss(line);

                string word;
                while(iss >> word){
                    x.push_back(word);
                }
            }
        }
            myfile.close();
    }
    return x;
}

vector<string> Read_File(string NameFile){

    string line;
    vector<string> x;

    ifstream myfile (NameFile);

    if (myfile.is_open()){
        while (! myfile.eof() ){
            getline (myfile,line);
            if(line.empty())
                continue;
            transform(line.begin(), line.end(), line.begin(), ::tolower);
            istringstream iss(line);

            string word;
            while(iss >> word){
                x.push_back(word);
            }
        }
    }
    myfile.close();
    return x;
}

int Count_Files_Word(string palavra){

    string NameFile, line;
    int x = 0;
    int y;
    for(int i=1; i<Count_File(); i++){
        NameFile = "Doc-"+to_string(i)+".txt";
        ifstream myfile(NameFile);

        if (myfile.is_open()){
            while (! myfile.eof() ){
                getline (myfile,line);
                if(line.empty())
                    continue;
                transform(line.begin(), line.end(), line.begin(), ::tolower);
                istringstream iss(line);

                string word;
                while(iss >> word){
                    y = x;
                    if(word == palavra){
                        x++;
                    }
                }
                if(x>y){
                    break;
                }
            }
        }
        myfile.close();
    }
    return x;
}

double Modulo(vector<double> x){

    double s = 0;
    for(vector<double>::iterator it = x.begin(); it != x.end(); ++it){

        s += ((*it) * (*it));
    }
    s = sqrt(s);
    return s;
}

double Somatorio(vector<double> a, vector<double> b){

    double s;
    s = inner_product(begin(a), end(a), begin(b), 0.0);
    return s;
}

double Cosine_Similarity(vector<double> a, vector<double> b){

    double x;
    x = (Somatorio(a, b)) / (Modulo(a)*Modulo(b));
    return x;
}

double idf(string palavra){

    double N = Count_File();
    double nt = Count_Files_Word(palavra);
    double idf;
    idf = log(N/nt);
    return (idf);
}

double tf(string NameFile, string palavra){

    double tf=0;
    for(vector<string>::iterator it = Read_File(NameFile).begin(); it!= Read_File(NameFile).end(); ++it){
        if(*it==palavra){
            tf++;
        }
    }
    return tf;
}

vector<double> Vetor_Documento(string NameFile, vector<string> palavra){

    vector<double> coordenadas;
    for(vector<string>::iterator it=palavra.begin();                it!=palavra.end(); ++it){
    coordenadas.push_back((idf(*it)) * (tf(NameFile, *it)));
    }
    return coordenadas;
}
