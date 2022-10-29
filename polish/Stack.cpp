#include "Stack.h"
#include "AST.h"
#include "AST.cpp"
// Implement your Stack member functions here.

// q: what functions should we have in our stack class?
// a: constructor, destructor, push, pop, ~ top would also be helpful

//Your stack isn’t a subclass of AST. It stores AST*s, but it’s a separate type (like how FibVec stored ints, but wasn’t an int).

// q: Yeah I think I meant something different than what I typed...in our stack, we want to initialize and array that holds data of type AST* right?

// a: Ah. Yep - exactly.

// And you can choose if you want to use a vector stack or a linked list stack (I used a linked list so I wouldn’t have