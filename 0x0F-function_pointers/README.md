<h2>Task 0</h2>
<p>Write a function that prints a name.</p>
<pre>
	void print_name(char *name, void (*f)(char *));
</pre>

<h2>Task 1</h2>
<p>Write a function that executes a function given as a parameter on each element of an array.</p>
<pre>
	void array_iterator(int *array, size_t size, void (*action)(int));
</pre>

<h2>Task 2</h2>
<p>Write a function that searches for an integer.</p>
<pre>
	int int_index(int *array, int size, int (*cmp)(int));
</pre>

<h2>Task 3</h2>
<p>Write a program that performs simple operations.</p>
<p>You are allowed to use the standard library</p>
<p>Usage: calc num1 operator num2</p>
<p>You can assume num1 and num2 are integers, so use the atoi function to convert them from the string input to int</p>
<p>operator is one of the following:</p>
<ul>
	<li>+: addition</li>
	<li>-: subtraction</li>
	<li>*: multiplication</li>
	<li>/: division</li>
	<li>%: modulo</li>
</ul>
<p>The program prints the result of the operation, followed by a new line</p>
<ul>
	<li>if the number of arguments is wrong, print Error, followed by a new line, and exit with the status 98</li>
	<li>if the operator is none of the above, print Error, followed by a new line, and exit with the status 99</li>
	<li>if the user tries to divide (/ or %) by 0, print Error, followed by a new line, and exit with the status 100</li>
</ul>

<p>Files:</p>
<h3>3-calc.h</h3>
<p>This file should contain all the function prototypes and data structures used by the program.</p>
<pre>
	/* Function prototypes */
	int (*get_op_func(char *s))(int, int);
	int op_add(int a, int b);
	int op_sub(int a, int b);
	int op_mul(int a, int b);
	int op_div(int a, int b);
	int op_mod(int a, int b);

	/* Data structure */
	typedef struct op {
		char *op;
		int (*f)(int a, int b);
	} op_t;
</pre>

<h3>3-op_functions.c</h3>
<p>This file should contain the 5 following functions (not more):</p>
<pre>
	/* Function definitions */
	int op_add(int a, int b)
	{
		return (a + b);
	}

	int op_sub(int a, int b)
	{
		return (a - b);
	}

	int op_mul(int a, int b)
	{
		return (a * b);
	}

	int op_div(int a, int b)
	{
		return (a / b);
	}

	int op_mod(int a, int b)
	{
		return (a % b);
