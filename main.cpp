#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include "metodos.h"

//recuperaçao da informação professor marcos

using namespace std;

vector<string> make_sentence(string s){

    stringstream ss(s);
    istream_iterator<string> begin(ss);
    istream_iterator<string> end;
    vector<string> vstrings(begin, end);

    return vstrings;
}


vector<double> Cosine_Ranking(string busca){

    string NameFile;
    vector<double> ranking;
    for(int i=1; i<=Count_File(); i++){
        NameFile = "Doc-"+to_string(i)+".txt";
        ranking.push_back(Cosine_Similarity(Vetor_Documento(NameFile, Read_File(NameFile)), Vetor_Documento(NameFile, make_sentence(busca))));
    }
    return(ranking);
}

int main(){

    string busca;
    cout << "Entre com a busca: "<<endl;
    getline(cin, busca);

    vector<double> b = Cosine_Ranking(busca);
    map<double,string, greater <double>> m;
    int i=1;
    for(vector<double>::iterator it=b.begin(); it!=b.end(); ++it){
        m.insert(pair<double,string>(*it, "Doc-"+to_string(i)+".txt"));
        i++;
    }

    for (auto itr = m.begin(); itr != m.end(); ++itr) {
        cout << itr->second << '\n';
    }
}
