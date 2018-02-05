#include <iostream>
#include <sstream>
#include <stdio.h>
#include <gmp.h>
#include <gmpxx.h>
#include <string>
#include <vector>
using namespace std;

//Jasmine Walker

void usage(int);

int main(int argc, char *argv[]){
    
    if(argc != 2){
        usage(0);
    }
    string line;
    istringstream iss (argv[1]);
    vector <string> input;
    while (getline(iss, line, ',')) {
        input.push_back(line);
    }
    if(input.size() != 4){
        usage(0);
    }
    
    mpz_class p(input[0]);
    mpz_class q(input[1]);
    mpz_class e(input[2]);
    mpz_class m(input[3]);
    mpz_class n(p*q);
    mpz_class Eulers_totient((p-1) * (q-1));

    mpz_t d;
    mpz_init(d);
    mpz_invert(d, e.get_mpz_t(), Eulers_totient.get_mpz_t());
    
    mpz_t c;
    mpz_init(c);
    mpz_powm(c, m.get_mpz_t(), e.get_mpz_t(), n.get_mpz_t());
    
    cout << "n = " << n << ", d = " << d << ", c = " << c << endl;
    
    return 0;
    
}

void usage(int exitvalue){
    cout << "Usage: ./RSA $p,$q,$e,$m" << endl;
    cout << "$p\tFirst prime number" << endl;
    cout << "$q\tSecond prime number" << endl;
    cout << "$e\tPublic key" << endl;
    cout << "$m\tMessage" << endl;
    exit(exitvalue);
}