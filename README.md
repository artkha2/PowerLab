# PowerLab

# 🔖 Background Information
Many programming languages allow us to calculate the power of a number using a built-in function. For example, the cmath library in C++ gives us an overloaded pow function:


pow(2, 3) == 8;
Meanwhile, the Java language gives us a pow method within the Math library:


Math.pow(2, 3) == 8;
In this lab, we are going to write and analyze three different ways of calculating the power of a number:

- Using a naive approach
- Using an unoptimized divide and conquer approach
- Using an optimized divide and conquer approach

# 🎯 Problem Statement
Write three functions that calculate the power of a number in the different ways outlined below. Then, answer the Thought-Provoking Questions based on your implementations.

Use recursion to multiply a number by itself some number of times. The pseudocode for this approach is:

def naivePower(int x, int n):
  if x equals 0:
    return 0;
  if n equals 0:
    return 1;
  return x * naivePower(x, n - 1)

Recursively calculate the number raised to half the power given, and then square this result for the case of an even power. Do the same thing but also multiply it by the original number one more time for the case of an odd power. The pseudocode for the divide and conquer approach is:

def unoptimizedDCPower(int x, int n):
  if x equals 0:
    return 0;
  if n equals 0:
    return 1
  if n is even:
    return unoptimizedDCPower(x, n / 2) * unoptimizedDCPower(x, n / 2);
  else:
    return x * unoptimizedDCPower(x, n / 2) * unoptimizedDCPower(x, n / 2);
Use the same strategy as algorithm two, but this time create a temporary variable to prevent duplicate calculations. The pseudocode for the divide and conquer approach is:

def optimizedDCPower(int x, int n):
  if x equals 0:
    return 0;
  if n equals 0:
    return 1
 
  temp = optimizedDCPower(x, n / 2);
  if n is even:
    return temp * temp;
  else:
    return x * temp * temp;

# ✅ Acceptance Criteria
Implement the three algorithms listed in the Problem Statement using either C++ or Java.
Ensure that your functions work either through unit tests or a driver program.
Use these functions to answer the Thought-Provoking Questions.

# 📋 Dev Notes
We will only concern ourselves with positive values for x and n in power(x, n). You do not need to take negative numbers into account.

# 🖥️ Example Output
Regardless of which algorithm you use, you should get the same correct result when taking a number to a power. However, the runtime of each of these functions will change based on the size of the inputs.


naivePower(2, 3) == 8;
unoptimizedDCPower(2, 3) == 8;
optimizedDCPower(2, 3) == 8;
