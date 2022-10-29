#include "AST.h"
#include "Nodes.h"
#include <iostream>
#include "Stack.h"
#include <sstream>
using namespace std;

AST* AST::parse(const std::string& expression) {

    char token;
    std::istringstream mystream(expression);
    while (mystream>>token){
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
            default:

        }
    }

    return nullptr;
}


