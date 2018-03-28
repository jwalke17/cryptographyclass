#include <iostream>
#include <sstream>
#include <stdio.h>
#include <time.h>
#include <gmp.h>
#include <gmpxx.h>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

//Jasmine Walker

int main(int argc, char *argv[]){
    
    mpz_t p;
    mpz_init(p);
    mpz_class temp(pow(2, 999) + 1239);
    mpz_t q;
    mpz_init(q);
    mpz_set(q, temp.get_mpz_t());
    
    temp = mpz_class(time(NULL));
    
    mpz_t seed;
    gmp_randstate_t state;
    mpz_init(seed);
    mpz_set(seed, temp.get_mpz_t());
    
    gmp_randinit_default(state);
    gmp_randseed(state, seed);
    
    while(true){
        mpz_set_ui(p, 0);
        mpz_add(p, p, q);
        mpz_add(p, p, q);
        mpz_add_ui(p, p, 1);
        if(mpz_probab_prime_p(p, 30) != 0){
            break;
        }else{
            mpz_nextprime(q, q);
        }
    }
    
    
    mpz_t g;
    mpz_t test;
    mpz_t q2;
    mpz_init(g);
    mpz_init(test);
    mpz_init(q2);
    
    mpz_add(q2, q, q);
    
    while(true){
        mpz_urandomb(g,state,32);
        mpz_powm_ui(test, g, 1, p);
        if(mpz_cmp_ui(test, 1) == 0){
            continue;
        }
        mpz_powm_ui(test, g, 2, p);
        if(mpz_cmp_ui(test, 1) == 0){
            continue;
        }
        mpz_powm(test, g, q, p);
        if(mpz_cmp_ui(test, 1) == 0){
            continue;
        }
        mpz_powm(test, g, q2, p);
        if(mpz_cmp_ui(test, 1) == 0){
            break;
        }
    }
    
    
    
    cout << p << ',' << q << ',' << g << endl;
    
    return 0;
}