#include "Nodes.h"
#include <iostream>
#include "Stack.h"
#include <cmath>
#include <cstddef>
#include <stdexcept>
#include <sstream>
// Implement your AST subclasses' member functions here.


// To format a double for output:
//   std::ostringstream stream;
//   stream << value;
//   return stream.str();

// --------------------------------- Numbers ------------------------------------
numbers::numbers(double token){
    number = token;
}


std::string numbers::prefix() const {
    return std::to_string(number);
}

std::string numbers::postfix() const {
    return std::to_string(number);
}

double numbers::value() const {
    return number;
}

//--------------------------------------- Add -----------------------------------

add::add() {
    
}

add::~add()  {
    delete left;
    delete right;
}

std::string add::prefix() const {
    return "+ " + left->prefix() + " " + right->prefix();
}

std::string add::postfix() const {
    return left->postfix() + " " + right->postfix() + " +";
}

double add::value() const{
    return left->value() + right->value();
};

//-------------------------------------- Subtract -----------------------------

subtract::subtract(AST* token1, AST* token2){
    left = token1;
    right = token2;
}

subtract::~subtract() {
    delete left;
    delete right;
}

std::string subtract::prefix() const {
    return "- " + left->prefix() + " " + right->prefix();
}
 
std::string subtract::postfix() const {
    return left->postfix() + " " + right->postfix() + " -";
}

double subtract::value() const {
    return left->value() - right->value();
}

//-------------------------------------- Multiply -------------------------------

multiply::multiply(AST* token1, AST* token2){
    left = token1;
    right = token2;
}

multiply::~multiply(){
    delete left;
    delete right;
}

std::string multiply::prefix() const {
    return "* " + left->prefix() + " " + right->prefix();
}

std::string multiply::postfix() const {
    return left->postfix() + " " + right->postfix() + " *";
}

double multiply::value() const {
    return left->value() * right->value();
}

//------------------------------------- Divide ----------------------------------

divide::divide(AST* token1, AST* token2){
    left = token1;
    right = token2;
}

divide::~divide(){
    delete left;
    delete right;
}

std::string divide::prefix() const {
    return "/ " + left->prefix() + " " + right->prefix();
}

std::string divide::postfix() const {
   
    return left->postfix() + " " + right->postfix() + " /";
}

double divide::value() const { 
    if (right->value() == 0) throw std::runtime_error("Cannot divide by 0.");
    return left->value() / right->value();
}

// ---------------------------------- Modulus ------------------------------

modulus::modulus(AST* token1, AST* token2){
    left = token1;
    right = token2;
}

modulus::~modulus(){
    delete left;
    delete right;
}

std::string divide::prefix() const {
    return "% " + left->prefix() + " " + right->prefix();
}

std::string divide::postfix() const {
    return left->postfix() + " " + right->postfix() + " %";
}

double divide::value() const { 
    if (right->value() == 0) throw std::runtime_error("Cannot divide by 0");
    return std::fmod( left->value(), right->value());
}

//--------------------------------- neg ------------------------------------

