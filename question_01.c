/*
@author
Name: Muhammad Yameen
email: yameenmuhammad960@gmail.com
*/

#include <stdio.h>
#include <stdlib.h>

// Define an enumeration to represent the type of each node
typedef enum TypeTag
{
    ADD,
    SUB,
    MUL,
    FIBO,
} TypeTag;

// Define a struct to represent each node in the tree
typedef struct Node
{
    TypeTag type;       // type of node
    int value;          // value of node (if applicable)
    struct Node *left;  // pointer to the left child node
    struct Node *right; // pointer to the right child node
} Node;

// Define a function pointer type to hold the address of the 'func' function
typedef Node *(*ptr)();

// Define a global node that can be used by the 'func' function to store a result
Node *myNode;

// Function to create a new node with a given integer value
Node *createNode(int x)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->left = NULL;
    n->right = NULL;
    n->value = x;
    return n;
}

// Function to calculate the nth fibonacci number
int fibonacci(int n)
{
    if (n <= 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;

    // Create an array to hold the fibonacci sequence up to n
    int *fib = (int *)malloc((n + 1) * sizeof(int));
    fib[0] = 0;
    fib[1] = 1;

    // Calculate the fibonacci sequence up to n
    for (int i = 2; i <= n; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    int result = fib[n - 1];
    free(fib);
    return result;
}

// Function to calculate the result of a node
int calc(Node *n)
{
    switch (n->type)
    {
    case ADD:
        return n->left->value + n->right->value;
        break;
    case MUL:
        return n->left->value * n->right->value;
    case SUB:
        return n->left->value - n->right->value;
    case FIBO:
        return fibonacci(n->left->value);

    default:
        break;
    }
}

// Function that returns a node based on two input parameters, a and b
Node *func(void *a, void *b)
{
    if (b == NULL)
    {
        Node *r = (Node *)a;
        int q = calc(r);
        Node *n1 = createNode(abs(q));
        myNode->left = n1;
        myNode->type = FIBO;
        return myNode;
    }

    int x = *(int *)a;
    int y = *(int *)b;

    // If the input parameters leis in this range then assume above void pointers are intger pointer,
    // and then create two new nodes and return them
    if (x > 0 && x < 2000)
    {
        Node *n1 = createNode(x);
        Node *n2 = createNode(y);
        myNode->left = n1;
        myNode->right = n2;
        return myNode;
    }
    // Otherwise, calculate the result of the two input nodes and recursively call the function with the result
    else
    {
        Node *r = (Node *)a;
        Node *s = (Node *)b;
        int q = calc(r);
        int w = calc(s);
        func(&q, &w);
    }
}

// Function to create a new function pointer based on the input
// type (ADD, SUB, MUL, FIBO) and return it
ptr makeFunc(TypeTag type)
{
    Node *newNode = (Node *)malloc(sizeof(Node)); // Allocate memory for a new Node

    // Assign the input type to the node's type
    newNode->type = type;
    // Initialize the node's left and right child as null
    newNode->left = NULL;
    newNode->right = NULL;
    // Set the global node variable to the newly created node
    myNode = newNode;

    return &func; // Return the address of the function 'func'
}

int main()
{
    // Initialize integers a,b c and d
    int a = 10;
    int b = 6;
    int c = 5;
    int d = 4;
    // Create a new Node for ADD operation, and pass pointers to the integers 'a' and 'b'
    Node *add = (*makeFunc(ADD))(&a, &b);

    // Create a new Node for MUL operation, and pass pointers to the integers 'c' and 'd'
    Node *mul = (*makeFunc(MUL))(&c, &d);

    // Create a new Node for SUB operation, and pass pointers to the previously created Nodes 'add' and 'mul'
    Node *sub = (*makeFunc(SUB))(add, mul);

    // Create a new Node for FIBO operation, and pass a pointer to the previously created Node 'sub'
    Node *fibo = (*makeFunc(SUB))(sub, NULL);

    // Print the results of the calculations performed by each node
    printf("\n%d \n", calc(add));
    printf("%d\n", calc(mul));
    printf("%d\n", calc(sub));
    printf("%d\n\n", calc(fibo));

    return 0;
}