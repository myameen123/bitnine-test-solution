# Question #01

## Development Environment:

To compile and run the code, you will need:

- A C compiler such as GCC, Clang, or Visual Studio
- A terminal or command prompt

The code was written in C and should be compatible with most C compilers.

## Compiling and Running the Code:

To compile the code, open a terminal or command prompt and navigate to the directory where the code is located. Then run the following command:

```bash
gcc -o program program.c
```

This will compile the code and generate an executable file named "program". To run the code, type the following command:

```bash
./program
```

This will execute the compiled program.

## Explanation of the Code:

The code defines a few data structures and functions.

### Node Struct

It defines a Node struct that has the following fields:

- `type` field of type `TypeTag` enum to indicate the type of operation being performed by a given Node.
- `value` field of type `int` to hold the value of the node.
- `left` field of type `Node*` to hold the pointer to the left child node.
- `right` field of type `Node*` to hold the pointer to the right child node.

### TypeTag Enum:

The code also defines an enum called `TypeTag` that has a few predefined values:

- `ADD`
- `SUB`
- `MUL`
- `FIBO`

These values are used to indicate the type of operation being performed by a given Node.

### calc Function:

The code defines a function called `calc` that takes a Node as an argument and performs the operation indicated by its `type` field on its left and right child nodes. For example, if `n->type` is `ADD`, then `calc` will add the values of `n->left` and `n->right`.

### fibonacci Function:

There is also a function called `fibonacci` that takes an `int` argument and calculates the nth Fibonacci number.

### Main Function:

The main function defines four `int` variables and uses them to create four different Node objects using the `makeFunc` and `func` functions. These Node objects are then passed to the `calc` function to perform the operations and print out the results.

## Working of the Code:

1. `makeFunc()` is first called from the main function. It creates the Node (named as `myNode` which I have initialized globally), assigns the operation type to the node, and returns a pointer to the `func` function.
2. `func()` function has two attributes `x` and `y` (both `void` pointers). In this function, there are 3 conditions according to inputs in the main function:

   - If `y` is null, it means `func` function is being called for creating a node for the `fibo` pointer which is already defined by `makeFunc` with type `SUB`. So in this if condition, `void` pointer `a` is being cast into `Node` pointer, assuming that it is a `Node` pointer and then passing it to the `calc` function to calculate subtraction and return its result. For this returned result, a new node is created with this value, and then modify the type of `fibo` node to `FIBO` from `SUB`, then return this new modified node.

   - After casting both `a` and `b` `void` pointers into integer pointers and then dereferencing integer pointers to get values (assuming that these are integer pointers) (Note: I am also assuming that these integer values would always be less than 2000. If these are greater than it means they are garbage values, and taking the conclusion that these `void` pointers were `Node` pointers), creating 2 nodes with the value field `x` and `y` respectively.

   - If `x` value is greater than 2000, then assuming these `void` pointers are `Node` pointers.

3. The main function calls the `makeFunc(Operation)`, so it dynamically creates a new struct (`NODE`), stores the operation in `TypeTag` type (Which is an enum), and its address is passed to a global Node namely `myNode` to make this node accessible in the `func` function. And `makeFunc(Operation)` returns a pointer for the `func` function, which is then dereferenced, and finally, operators for arithmetic operations are passed to the function, and `func` function creates 2 new nodes (with left and right node pointers NULL and the value field with integers passed in func (`x` and `y`) respectively). The current Node (`myNode`)’s left node points toward the first, and right towards the second node, and `func` function returns this modified `myNode`.

4. This new node is passed to the `calc` function, which performs the operation according to the type of this node and returns the result after performing the respective operation.

5. And finally, the main function displays the result.
