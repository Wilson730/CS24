#include "AST.h"
#include "Nodes.h"
#include <iostream>
using namespace std;

AST* AST::parse(const std::string& expression) {
    for (int i = 0; i < expression.length(); i++){
        char token = expression[i];
        switch(token){
            case '+':
                break;
            case '-':
                break;
            case '*':
                break;
            case '/':
                break;
            case '%':
                break;
            case '~':
                break;
        }
    }
    return nullptr;
}


std::string AST::prefix() const {

}

std::string AST::postfix() const {

}

double AST::value() const {

}