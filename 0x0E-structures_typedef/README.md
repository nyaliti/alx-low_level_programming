<h1> Structures, typedef </h1>

| TaskNo | Name | Explanation | Code |
|-------|-------|------------|-------|
| 0 | dog.h | Define a new type struct dog with the following elements:<ul><li>`name`, type = `char *`</li><li>`age`, type = `float`</li><li>`owner`, type = `char *`</li></ul> | <a href = "https://github.com/nyaliti/alx-low_level_programming/blob/main/0x0E-structures_typedef/dog.h"> View Code </a> |
| 1 | 1-init_dog.c | Write a function that initialize a variable of type `struct dog`<ul><li> Prototype: `void init_dog(struct dog *d, char *name, float age, char *owner);`</li></ul> | <a href = "#"> View Code </a> |
|2| 2-print_dog.c | Write a function that prints a `struct dog`<ul>
<li>Prototype: `void print_dog(struct dog *d);`</li>
<li> Format: see example bellow</li>
<li>You are allowed to use the standard library</li>
<li>If an element of `d` is `NULL`, print `(nil)` instead of this element. (if `name` is `NULL`, print `Name: (nil)`)</li>
<li>If `d` is `NULL` print nothing.</li>
</ul> | <a href="https://github.com/nyaliti/alx-low_level_programming/blob/main/0x0E-structures_typedef/2-print_dog.c">View Code</a>|
