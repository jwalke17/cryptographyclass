#include <iostream>
#include <sstream>
#include <stdio.h>
#include <time.h>
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
    if(input.size() != 1){
        usage(0);
    }
    
    mpz_class m(input[0]);
    mpz_class g("2447052586", 10);
    mpz_t g2;
    mpz_init(g2);
    mpz_mul(g2, g.get_mpz_t(), g.get_mpz_t());
    mpz_class p("10715086071862673209484250490600018105614048117055336074437503883703510511249361224931983788156958581275946729175531468251871452856923140435984577574698574803934567774824230985421074605062371141877954182153046474983581941267398767559165543946077062914571196477686542167660429831652624386837205668661619", 10);
    // q = "5357543035931336604742125245300009052807024058527668037218751941851755255624680612465991894078479290637973364587765734125935726428461570217992288787349287401967283887412115492710537302531185570938977091076523237491790970633699383779582771973038531457285598238843271083830214915826312193418602834330809"
    mpz_class x("40622201812345", 10);
    
    mpz_class temp(time(NULL));
    
    mpz_t seed;
    gmp_randstate_t state;
    mpz_init(seed);
    mpz_set(seed, temp.get_mpz_t());
    
    gmp_randinit_default(state);
    gmp_randseed(state, seed);
    
    
    mpz_t h;
    mpz_init(h);
    mpz_t r;
    mpz_init(r);
    mpz_t c1;
    mpz_init(c1);
    mpz_t c2;
    mpz_t hr;
    mpz_init(c2);
    mpz_init(hr);
    
    for(int i = 0; i < 5; i++){
        //mpz_powm(h, g.get_mpz_t(), x.get_mpz_t(), p.get_mpz_t());
        mpz_powm(h, g2, x.get_mpz_t(), p.get_mpz_t());
    
        mpz_urandomb(r,state,32);
        mpz_add_ui(r, r, 1);
    
        //mpz_powm(c1, g.get_mpz_t(), r, p.get_mpz_t());
        mpz_powm(c1, g2, r, p.get_mpz_t());
    
        mpz_powm(hr, h, r, p.get_mpz_t());
        mpz_mul(c2, m.get_mpz_t(), hr);
        mpz_mod(c2, c2, p.get_mpz_t());
    
        cout << c1 << ',' << c2 << ',' << p << endl << endl;
    }
    
    return 0;
    
}

void usage(int exitvalue){
    cout << "Usage: ./elgamal $m" << endl;
    cout << "$m\tMessage" << endl;
    exit(exitvalue);
}