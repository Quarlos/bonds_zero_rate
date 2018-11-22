//
//  main.cpp
//  bonds_zero_rate
//  When the zero rate curve r(0,t) is given explicitly (defined below in r_zero_rate), this program computes the price of the corresponding bond. The user inputs the cash flow dates, and the cash flows corresponding to the respective dates.
//  The vector of dates and cash flows should be introduced separated by a space with return at the end with no space
//  Reference: Stefanica, Primer for the Math of Fin Eng, Section 2.8
//
//  Created by carlos on 21/11/2018.
//  Copyright © 2018 carlos. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#include <iomanip> // to use setprecision() so that std output gives me more decimal places


// For different zero rate curves EDIT HERE
double r_zero_rate(double t) {
    double r_0t = 0.0525+log(1+2*t)/200;
    return r_0t;
}




int main() {
    
    vector <double> t_cash_flow, v_cash_flow;
    double t, v;
    cout << "vector of cash flow dates: ";
    
    cin >> t;
    t_cash_flow.push_back(t);
    while(cin.get() != '\n') {
        cin >> t;
        t_cash_flow.push_back(t);
    }
    
    cout << "vector of cash flows: ";
    cin >> v;
    v_cash_flow.push_back(v);
    while(cin.get() != '\n') {
        cin >> v;
        v_cash_flow.push_back(v);
    }


    double B=0;
    vector <double> disc(t_cash_flow.size());
    for(unsigned long i=0; i < t_cash_flow.size(); i++) {
        disc.at(i)=exp(-t_cash_flow.at(i)*r_zero_rate(t_cash_flow.at(i)));
        B += v_cash_flow.at(i)*disc.at(i);
    }
    
    cout << "\nprice of the bond B = " << setprecision (8) << B << endl;
    
    return 0;
}
