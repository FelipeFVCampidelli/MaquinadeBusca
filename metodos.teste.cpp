#include "doctest.h"
#include "auxiliar.h"

#include <iostream>
#include <vector>
#include <string>

TEST_CASE("Modulo(vector<double>)"){
    vector<double> x = {0,0};
    vector<double> y = {3,4};
    CHECK(Modulo(x)==0);
    CHECK(Modulo(y)==5);

}

TEST_CASE("Somatorio(vector<double>, vector<double>)"){
    vector<double> x = {0,0};
    vector<double> y = {3,4};
    vector<double> w = {1,1};

    CHECK(Somatorio(x, x)==0);
    CHECK(Somatorio(x, w)==2);
    CHECK(Somatorio(y, w)==7);
}

TEST_CASE("Cosine_Similarity(vector<double>, vector<double>)"){
    vector<double> x = {0,0};
    vector<double> y = {3,4};
    vector<double> z = {0,1};

    CHECK(Cosine_Similarity(x, y)==0);
    CHECK(Cosine_Similarity(y, y)==1);
    CHECK(Cosine_Similarity(y, z)==(4/5));

}

TEST_CASE("Read_Files()"){
    vector<string> a = Read_Files();
    CHECK(a==Read_Files());
}

TEST_CASE("Count_File()"){
    int x = Count_File();
    CHECK(x==Count_File());
}

