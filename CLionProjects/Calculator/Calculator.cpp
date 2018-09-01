#include "Calculator.h"

//
// Created by manuel on 22/05/18.
//
Calculator::Calculator(): value(0){}
Calculator::Calculator(int v): value(v){}

int Calculator:: sum(int x){
    if (x<0) value-=x;
    else value+=x;
    return value;
}
// if x<0 invert it before subtracting
int Calculator::subtract(int x){
    if (x>=0) value-=x;
    else value+=x;
    return value;
}
int Calculator:: mul(int x){
    value*=x;
    return value;
}
