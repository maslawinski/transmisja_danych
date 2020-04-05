//
//  lab2.cpp
//  zadania
//
//  Created by Matt on 01/04/2020.
//  Copyright © 2020 Matt. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#define _USE_MATH_DEFINES
using namespace std;


int a = 9,b = 9,c = 4;

float funkcja( double czas, double amplituda, double czestotliwosc, double przesuniecie )
{
    return amplituda * sin( 2 * M_PI * czestotliwosc * czas + przesuniecie );
}

float kwantyzacja( double signal, int q ) {
    return ceil( ( pow( 2, q ) ) * (signal / 2) );
}

int lab2() {
    ofstream plik;
    
    float poczatek1 = 0;
    float krok1 = 0.05;
    int n = 0;
    float t = poczatek1 + (n * krok1);
    
    //1
    plik.open("probkowanie.txt");
    while (t <= 9)
    {
        plik << t << " " << funkcja(t, 1.0, 9, c * M_PI) << "\n";
        n++;
        t = poczatek1 + (n * krok1);
    }
    plik.close();
    
    //2
    n = 0;
    t = poczatek1 + (n * krok1);
    plik.open("kwantyzacja1.txt");
       while (t <= 9)
       {
           float sygnal = funkcja(t, 1.0, 9, c * M_PI);
           plik << t << " " << kwantyzacja( sygnal, 16 ) << "\n";
           n++;
           t = poczatek1 + (n * krok1);
       }
       plik.close();
    
    //3
    n = 0;
    t = poczatek1 + (n * krok1);
    plik.open("kwantyzacja2.txt");
    while (t <= 9)
    {
        float sygnal = funkcja(t, 1.0, 9 * 2, c * M_PI);
        plik << t << " " << kwantyzacja( sygnal, 8 ) << "\n";
        n++;
        t = poczatek1 + (n * krok1);
    }
    plik.close();
    return 0;
}
