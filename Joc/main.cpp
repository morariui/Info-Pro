#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("joc.in");
ofstream fout("joc.out");

long purtere(int baza, int exponent){
    long p = 1;
    for(int i = 0; i<exponent; i++){
        p = p*baza;
    }
    return p;
}

int main()
{
    //1.
    long long int cprima = 0;
    long long int cultima = 0;
    long long int nr_nou = 0;
    long long int cpred = 0;
    long long int bune = 0;
    long long int rau = 0;
    long long int nr = 0;
    long long int n = 0;
    long long int c = 0;
    long long int nrc = 0;
    long long int lama1 = 0;
    long long int lama2 = 0;

    //2.
    fin >> n;

    //3.
    for(int i = 0; i<n; i++){
        fin >> nr;
        nrc = 0;
        rau = 0;
        lama1 = 1;

        for(int nr2 = nr; nr2>0; nr2/=10) nrc = nrc + 1;
        for(int i = 1; i<nrc; i++) lama1 = lama1*10;

        cultima = nr%10;
        cprima = nr/lama1;

        //cout << "cultima = " << cultima << endl;
        //cout << "cprima = "  << cprima  << endl;

        if(cultima > 0){
            if(cultima>=cprima) nr_nou = cprima*10 + cultima;
            if(cultima<=cprima) nr_nou = cultima*10 + cprima;
        }else{
            nr_nou = cprima * 10;
        }

        fout << nr_nou << " ";

        nr = (nr%lama1)/10;

        lama1 = lama1/10;
        lama2 = lama1/10;

        c = 0;

        for(int nr2 = nr; nr2>0; nr2%=lama1){
            cpred = (nr2%lama1)/lama2;
            if((c<cpred && c > 0) || c == cpred){
                rau = 1;
                break;
            }
            c = cpred;
            lama1 = lama1/10;
            lama2 = lama2/10;
        }

        if(rau == 0) bune = bune + 1;
    }

    //4.
    fout << endl << bune << endl;

    return 0;
}
