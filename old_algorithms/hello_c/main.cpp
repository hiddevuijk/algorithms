#include "union_find.h"
#include "percolation.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;


int main(int argc, char** argv )
{
    if( argc != 3 ) {
        cout << "give grid size and trials" << endl;
        return 1;
    }

    int N = atoi(argv[1]);
    int n_trials = atoi(argv[2]);
      
    //srand(time(NULL));
    srand(12345656);

 
    vector<double> p(n_trials,0);
    for(int i=0;i<n_trials; ++i) {
        
        //Percolation<QuickFindUF> percolation(N);
        //Percolation<QuickUnionUF> percolation(N);
        Percolation<QuickUnionWUF> percolation(N);
        double os;
        while(!percolation.path()) {
            int row = rand() % N;
            int col = rand() % N;
            if( percolation.remove(row,col) ) p[i] += 1.;
        }

        p[i] =  p[i]/(N*N);
        cout << i << '\t' << p[i] << endl;
    } 
   
    return 0;
    double pmean = 0;
    for(int i=0;i<n_trials; ++i) pmean += p[i]/n_trials;

    double std = 0;
    for(int i=0;i<n_trials; ++i)
        std += (p[i]-pmean)*(p[i]-pmean)/(n_trials-1);

    cout << pmean << endl;
    cout << sqrt(std) << endl;
    cout << pmean-1.96*sqrt(std/n_trials) << endl;
    cout << pmean+1.96*sqrt(std/n_trials) << endl;

    return 0;
}

