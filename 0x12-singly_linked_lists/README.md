<h1>Tasks</h1>
<h2>0. Print list</h2>
<p>Write a function that prints all the elements of a list_t list.</p>
<p>Prototype: <code>size_t print_list(const list_t *h);</code></p>
<p>Return: the number of nodes</p>
<p>Format: see example</p>
<p>If str is NULL, print [0] (nil)</p>
<p>You are allowed to use printf</p>
<h2>1. List length</h2>
<p>Write a function that returns the number of elements in a linked list_t list.</p>
<p>Prototype: <code>size_t list_len(const list_t *h);</code></p>
<h2>2. Add node</h2>
<p>Write a function that adds a new node at the beginning of a list_t list.</p>
<p>Prototype: <code>list_t *add_node(list_t **head, const char *str);</code></p>
<p>Return: the address of the new element, or NULL if it failed</p>
<p>str needs to be duplicated</p>
<p>You are allowed to use strdup</p>
<h2>3. Add node at the end</h2>
<p>Write a function that adds a new node at the end of a list_t list.</p>
<p>Prototype: <code>list_t *add_node_end(list_t **head, const char *str);</code></p>
<p>Return: the address of the new element, or NULL if it failed</p>
<p>str needs to be duplicated</p>
<p>You are allowed to use strdup</p>
<h2>4. Free list</h2>
<p>Write a function that frees a list_t list.</p>
<p>Prototype: <code>void free_list(list_t *head);</code></p>
<h2>5. The Hare and the Tortoise</h2>
<p>Write a function that prints You're beat! and yet, you must allow,<br>I bore my house upon my back!<br> before the main function is executed.</p>
<p>You are allowed to use the printf function</p>
<h2>6. Real programmers can write assembly code in any language</h2>
<p>Write a 64-bit program in assembly that prints Hello, Holberton, followed by a new line.</p>
<p>You are only allowed to use the printf function</p>
<p>You are not allowed to use interrupts</p>
<p>Your program will be compiled using nasm and gcc:</p>
