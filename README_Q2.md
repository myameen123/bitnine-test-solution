# Question #02

## Development Environment:

The code for solving a piecewise recurrence relation was written in the C programming language and can be compiled and executed on any platform that supports a C compiler. The code was developed using the GCC compiler on a Linux operating system. The version of GCC used for compilation was 9.3.0.

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

## Explanation of Code:

### Method 1 - Recursive:

The first method uses a recursive approach to solve the piecewise recurrence relation. The function `F()` takes an integer `n` as input and returns the value of the function for that input. The function first checks if `n` is less than 0, and if it is, it returns -1. If `n` is 0, 1, or 2, it returns the value of `n`. Otherwise, it calls itself recursively with arguments `n-3` and `n-2` and returns the sum of the two results.

#### Advantages:

- Easy to implement and understand.
- Suitable for small values of `n`.

#### Disadvantages:

- Inefficient for large values of `n`.
- Recursion can lead to stack overflow for very large `n`.
- The same subproblem can be calculated multiple times.

### Method 2 - Memorization:

The second method uses memorization to avoid computing the same values multiple times. The function `F()` takes an integer `n` as input and returns the value of the function for that input. The function first checks if `n` is less than 0, and if it is, it returns -1. If `n` is 0, 1, or 2, it returns the value of `n`. Otherwise, it creates a memorization array of size `n+1` and initializes it with -1. If the value of `F(n)` is already computed and stored in the array, it returns that value. Otherwise, it computes `F(n-3)` and `F(n-2)` recursively and stores the sum in the memorization array. Finally, it returns the value of `F(n)`.

#### Advantages:

- Efficient for large values of `n`.
- Avoids redundant calculations of the same subproblem.
- Easy to implement and understand.

#### Disadvantages:

- Requires extra memory for memorization.
- Recursion can lead to stack overflow for very large `n`.

### Method 3 - Iterative:

The third method uses an iterative approach to solve the piecewise recurrence relation. The function `F()` takes an integer `n` as input and returns the value of the function for that input. The function first checks if `n` is less than 0, and if it is, it returns -1. If `n` is 0, 1, or 2, it returns the value of `n`. Otherwise, it uses three variables (`prev1`, `prev2`, and `prev3`) to keep track of the previous three values of `F()`. It initializes `prev1` to 0, `prev2` to 1, and `prev3` to 2. Then, it uses a loop to compute the value of `F(n)` iteratively by adding `prev1` and `prev2` and storing the result in `current`. It updates `prev1`, `prev2`, and `prev3` for the next iteration and continues the loop until it reaches `n`. Finally, it returns the value of `F(n)`.

#### Advantages:

- Efficient for large values of `n`.
- Avoids recursion and stack overflow.
- No extra memory required.

#### Disadvantages:

- More complex than the recursive implementation.
- May be harder to understand for beginners.

## Conclusion:

The three methods presented above provide different ways of computing the values of a piecewise recurrence relation. The first method is simple and easy to understand but can be slow for large values of `n`. The second method uses memorization to speed up the computation, but it requires additional memory to store the values. The third method is an iterative approach that avoids recursion and is usually the most efficient method for computing the values of a recurrence relation.

---

Feel free to modify or expand the sections as needed to provide more details about the piecewise recurrence relation, its application, or any other relevant information.
