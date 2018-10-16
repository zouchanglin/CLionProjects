#include<iostream>

int main(){
    
    const int a = 10;
    const int& b = a;

    //int c = 20;
    //onst int& d = c; error
    
    int e = 10;
    //double& f = e; error
    const double& f = e;

    return 0;
}
