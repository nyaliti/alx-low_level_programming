<h1 style="color: green;">Tasks</h1>
<h2>0. Print list</h2>
<p>Write a function that prints all the elements of a <code>list_t</code> list.</p>
<p>Prototype: <code>size_t print_list(const list_t *h);</code></p>
<p>Return: the number of nodes</p>
<p>Format: see example</p>
<p>If <code>str</code> is <code>NULL</code>, print <code>[0] (nil)</code></p>
<p>You are allowed to use <code>printf</code></p>
<h2>1. List length</h2>
<p>Write a function that returns the number of elements in a linked <code>list_t</code> list.</p>
<p>Prototype: <code>size_t list_len(const list_t *h);</code></p>
<h2>2. Add node</h2>
<p>Write a function that adds a new node at the beginning of a <code>list_t</code> list.</p>
<p>Prototype: <code>list_t *add_node(list_t **head, const char *str);</code></p>
<p>Return: the address of the new element, or <code>NULL</code> if it failed</p>
<p><code>str</code> needs to be duplicated</p>
<p>You are allowed to use <code>strdup</code></p>
<h2>3. Add node at the end</h2>
<p>Write a function that adds a new node at the end of a <code>list_t</code> list.</p>
<p>Prototype: <code>list_t *add_node_end(list_t **head, const char *str);</code></p>
<p>Return: the address of the new element, or <code>NULL</code> if it failed</p>
<p><code>str</code> needs to be duplicated</p>
<p>You are allowed to use <code>strdup</code></p>
<h2>4. Free list</h2>
<p>Write a function that frees a <code>list_t</code> list.</p>
<p>Prototype: <code>void free_list(list_t *head);</code></p>
<h2>5. The Hare and the Tortoise</h2>
<p>Write a function that prints <code>You're beat! and yet, you must allow,</code><br><code>I bore my house upon my back!</code><br> before the <code>main</code> function is executed.</p>
<p>You are allowed to use the <code>printf</code> function</p>
<h2>6. Real programmers can write assembly code in any language</h2>
<!-- <p>Write a 64-bit program in assembly that prints <code>Hello, Holberton<code>, followed by a new line.</p> -->
<p>You are only allowed to use the <code>printf</code> function</p>
<p>You are not allowed to use interrupts</p>
<p>Your program will be compiled using <code>nasm</code> and <code>gcc</code>:</p>
