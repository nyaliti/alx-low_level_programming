<h1>More Pointers, Arrays and Strings</h1>

| TaskNo | Title | Explanation | Solution |
|----------|---------|---------|----------|
| 0 | 0-strcat.c |Write a function that concatenates two strings.<ul><li> Prototype:  </li><li> This function appends the  string to the  string, overwriting the terminating null byte () at the end of , and then adds a terminating null byte </li><li> Returns a pointer to the resulting string  </li></ul>FYI: The standard library provides a similar function: . Run STRCAT(3)                                               Linux Programmer's Manual                                               STRCAT(3)

NAME
       strcat, strncat - concatenate two strings

SYNOPSIS
       #include <string.h>

       char *strcat(char *dest, const char *src);

       char *strncat(char *dest, const char *src, size_t n);

DESCRIPTION
       The  strcat() function appends the src string to the dest string, overwriting the terminating null byte ('\0') at the end of dest,
       and then adds a terminating null byte.  The strings may not overlap, and the dest string must have enough space  for  the  result.
       If  dest  is  not large enough, program behavior is unpredictable; buffer overruns are a favorite avenue for attacking secure pro‐
       grams.

       The strncat() function is similar, except that

       *  it will use at most n bytes from src; and

       *  src does not need to be null-terminated if it contains n or more bytes.

       As with strcat(), the resulting string in dest is always null-terminated.

       If src contains n or more bytes, strncat() writes n+1 bytes to dest (n from src plus the terminating null byte).   Therefore,  the
       size of dest must be at least strlen(dest)+n+1.

       A simple implementation of strncat() might be:

           char *
           strncat(char *dest, const char *src, size_t n)
           {
               size_t dest_len = strlen(dest);
               size_t i;

               for (i = 0 ; i < n && src[i] != '\0' ; i++)
                   dest[dest_len + i] = src[i];
               dest[dest_len + i] = '\0';

               return dest;
           }

RETURN VALUE
       The strcat() and strncat() functions return a pointer to the resulting string dest.

ATTRIBUTES
       For an explanation of the terms used in this section, see attributes(7).

       ┌────────────────────┬───────────────┬─────────┐
       │Interface           │ Attribute     │ Value   │
       ├────────────────────┼───────────────┼─────────┤
       │strcat(), strncat() │ Thread safety │ MT-Safe │
       └────────────────────┴───────────────┴─────────┘
CONFORMING TO
       POSIX.1-2001, POSIX.1-2008, C89, C99, SVr4, 4.3BSD.

NOTES
       Some systems (the BSDs, Solaris, and others) provide the following function:

           size_t strlcat(char *dest, const char *src, size_t size);

       This  function appends the null-terminated string src to the string dest, copying at most size-strlen(dest)-1 from src, and adds a
       terminating null byte to the result, unless size is less than strlen(dest).  This function fixes the  buffer  overrun  problem  of
       strcat(),  but the caller must still handle the possibility of data loss if size is too small.  The function returns the length of
       the string strlcat() tried to create; if the return value is greater than or equal to size, data loss occurred.  If data loss mat‐
       ters,  the caller must either check the arguments before the call, or test the function return value.  strlcat() is not present in
       glibc and is not standardized by POSIX, but is available on Linux via the libbsd library.

EXAMPLE
       Because strcat() and strncat() must find the null byte that terminates the string dest using a search that starts at the beginning
       of  the string, the execution time of these functions scales according to the length of the string dest.  This can be demonstrated
       by running the program below.  (If the goal is to concatenate many strings to one target, then manually  copying  the  bytes  from
       each source string while maintaining a pointer to the end of the target string will provide better performance.)

   Program source

       #include <string.h>
       #include <time.h>
       #include <stdio.h>

       int
       main(int argc, char *argv[])
       {
       #define LIM 4000000
           int j;
           char p[LIM + 1];    /* +1 for terminating null byte */
           time_t base;

           base = time(NULL);
           p[0] = '\0';

           for (j = 0; j < LIM; j++) {
               if ((j % 10000) == 0)
                   printf("%d %ld\n", j, (long) (time(NULL) - base));
               strcat(p, "a");
           }
       }

SEE ALSO
       bcopy(3), memccpy(3), memcpy(3), strcpy(3), string(3), strncpy(3), wcscat(3), wcsncat(3)

COLOPHON
       This page is part of release 5.05 of the Linux man-pages project.  A description of the project, information about reporting bugs,
       and the latest version of this page, can be found at https://www.kernel.org/doc/man-pages/.

GNU                                                             2019-08-02                                                      STRCAT(3) to learn more. | <a href = https://github.com/nyaliti/alx-low_level_programming/blob/main/0x06-pointers_arrays_strings/0-strcat.c> View Code </a> |
| 1 | 1-strncat.c | Write a function that concatenates two strings.<ul><li> Prototype:  </li><li> The  function is similar to the  function, except that </li><ul><li> it will use at most  bytes from ; and </li><li>  does not need to be null-terminated if it contains  or more bytes </li></ul><li> Return a pointer to the resulting string  </li></ul>FYI: The standard library provides a similar function: . Run STRCAT(3)                                               Linux Programmer's Manual                                               STRCAT(3)

NAME
       strcat, strncat - concatenate two strings

SYNOPSIS
       #include <string.h>

       char *strcat(char *dest, const char *src);

       char *strncat(char *dest, const char *src, size_t n);

DESCRIPTION
       The  strcat() function appends the src string to the dest string, overwriting the terminating null byte ('\0') at the end of dest,
       and then adds a terminating null byte.  The strings may not overlap, and the dest string must have enough space  for  the  result.
       If  dest  is  not large enough, program behavior is unpredictable; buffer overruns are a favorite avenue for attacking secure pro‐
       grams.

       The strncat() function is similar, except that

       *  it will use at most n bytes from src; and

       *  src does not need to be null-terminated if it contains n or more bytes.

       As with strcat(), the resulting string in dest is always null-terminated.

       If src contains n or more bytes, strncat() writes n+1 bytes to dest (n from src plus the terminating null byte).   Therefore,  the
       size of dest must be at least strlen(dest)+n+1.

       A simple implementation of strncat() might be:

           char *
           strncat(char *dest, const char *src, size_t n)
           {
               size_t dest_len = strlen(dest);
               size_t i;

               for (i = 0 ; i < n && src[i] != '\0' ; i++)
                   dest[dest_len + i] = src[i];
               dest[dest_len + i] = '\0';

               return dest;
           }

RETURN VALUE
       The strcat() and strncat() functions return a pointer to the resulting string dest.

ATTRIBUTES
       For an explanation of the terms used in this section, see attributes(7).

       ┌────────────────────┬───────────────┬─────────┐
       │Interface           │ Attribute     │ Value   │
       ├────────────────────┼───────────────┼─────────┤
       │strcat(), strncat() │ Thread safety │ MT-Safe │
       └────────────────────┴───────────────┴─────────┘
CONFORMING TO
       POSIX.1-2001, POSIX.1-2008, C89, C99, SVr4, 4.3BSD.

NOTES
       Some systems (the BSDs, Solaris, and others) provide the following function:

           size_t strlcat(char *dest, const char *src, size_t size);

       This  function appends the null-terminated string src to the string dest, copying at most size-strlen(dest)-1 from src, and adds a
       terminating null byte to the result, unless size is less than strlen(dest).  This function fixes the  buffer  overrun  problem  of
       strcat(),  but the caller must still handle the possibility of data loss if size is too small.  The function returns the length of
       the string strlcat() tried to create; if the return value is greater than or equal to size, data loss occurred.  If data loss mat‐
       ters,  the caller must either check the arguments before the call, or test the function return value.  strlcat() is not present in
       glibc and is not standardized by POSIX, but is available on Linux via the libbsd library.

EXAMPLE
       Because strcat() and strncat() must find the null byte that terminates the string dest using a search that starts at the beginning
       of  the string, the execution time of these functions scales according to the length of the string dest.  This can be demonstrated
       by running the program below.  (If the goal is to concatenate many strings to one target, then manually  copying  the  bytes  from
       each source string while maintaining a pointer to the end of the target string will provide better performance.)

   Program source

       #include <string.h>
       #include <time.h>
       #include <stdio.h>

       int
       main(int argc, char *argv[])
       {
       #define LIM 4000000
           int j;
           char p[LIM + 1];    /* +1 for terminating null byte */
           time_t base;

           base = time(NULL);
           p[0] = '\0';

           for (j = 0; j < LIM; j++) {
               if ((j % 10000) == 0)
                   printf("%d %ld\n", j, (long) (time(NULL) - base));
               strcat(p, "a");
           }
       }

SEE ALSO
       bcopy(3), memccpy(3), memcpy(3), strcpy(3), string(3), strncpy(3), wcscat(3), wcsncat(3)

COLOPHON
       This page is part of release 5.05 of the Linux man-pages project.  A description of the project, information about reporting bugs,
       and the latest version of this page, can be found at https://www.kernel.org/doc/man-pages/.

GNU                                                             2019-08-02                                                      STRCAT(3) to learn more. | <a href = https://github.com/nyaliti/alx-low_level_programming/blob/main/0x06-pointers_arrays_strings/1-strncat.c> View Code </a> |
| 2 | 2-strncpy.c |Write a function that copies a string.<ul><li> Prototype:  </li><li> Your function should work exactly like  </li></ul>FYI: The standard library provides a similar function: . RunSTRCPY(3)                                               Linux Programmer's Manual                                               STRCPY(3)

NAME
       strcpy, strncpy - copy a string

SYNOPSIS
       #include <string.h>

       char *strcpy(char *dest, const char *src);

       char *strncpy(char *dest, const char *src, size_t n);

DESCRIPTION
       The strcpy() function copies the string pointed to by src, including the terminating null byte ('\0'), to the buffer pointed to by
       dest.  The strings may not overlap, and the destination string dest must be large enough to receive the copy.   Beware  of  buffer
       overruns!  (See BUGS.)

       The  strncpy()  function  is  similar, except that at most n bytes of src are copied.  Warning: If there is no null byte among the
       first n bytes of src, the string placed in dest will not be null-terminated.

       If the length of src is less than n, strncpy() writes additional null bytes to dest to ensure that a total of n bytes are written.

       A simple implementation of strncpy() might be:

           char *
           strncpy(char *dest, const char *src, size_t n)
           {
               size_t i;

               for (i = 0; i < n && src[i] != '\0'; i++)
                   dest[i] = src[i];
               for ( ; i < n; i++)
                   dest[i] = '\0';

               return dest;
           }

RETURN VALUE
       The strcpy() and strncpy() functions return a pointer to the destination string dest.

ATTRIBUTES
       For an explanation of the terms used in this section, see attributes(7).

       ┌────────────────────┬───────────────┬─────────┐
       │Interface           │ Attribute     │ Value   │
       ├────────────────────┼───────────────┼─────────┤
       │strcpy(), strncpy() │ Thread safety │ MT-Safe │
       └────────────────────┴───────────────┴─────────┘
CONFORMING TO
       POSIX.1-2001, POSIX.1-2008, C89, C99, SVr4, 4.3BSD.

NOTES
       Some programmers consider strncpy() to be inefficient and error prone.  If the programmer knows (i.e.,  includes  code  to  test!)
       that the size of dest is greater than the length of src, then strcpy() can be used.

       One  valid  (and  intended) use of strncpy() is to copy a C string to a fixed-length buffer while ensuring both that the buffer is
       not overflowed and that unused bytes in the destination buffer are zeroed out (perhaps to prevent information leaks if the  buffer
       is to be written to media or transmitted to another process via an interprocess communication technique).

       If  there  is no terminating null byte in the first n bytes of src, strncpy() produces an unterminated string in dest.  If buf has
       length buflen, you can force termination using something like the following:

           if (buflen > 0) {
               strncpy(buf, str, buflen - 1);
               buf[buflen - 1]= '\0';
           }

       (Of course, the above technique ignores the fact that, if src contains more than buflen - 1 bytes,  information  is  lost  in  the
       copying to dest.)

   strlcpy()
       Some systems (the BSDs, Solaris, and others) provide the following function:

           size_t strlcpy(char *dest, const char *src, size_t size);

       This  function  is similar to strncpy(), but it copies at most size-1 bytes to dest, always adds a terminating null byte, and does
       not pad the destination with (further) null bytes.  This function fixes some of the problems of strcpy() and  strncpy(),  but  the
       caller  must  still  handle  the possibility of data loss if size is too small.  The return value of the function is the length of
       src, which allows truncation to be easily detected: if the return value is greater than or equal to size, truncation occurred.  If
       loss of data matters, the caller must either check the arguments before the call, or test the function return value.  strlcpy() is
       not present in glibc and is not standardized by POSIX, but is available on Linux via the libbsd library.

BUGS
       If the destination string of a strcpy() is not large enough, then anything might happen.  Overflowing fixed-length string  buffers
       is  a  favorite cracker technique for taking complete control of the machine.  Any time a program reads or copies data into a buf‐
       fer, the program first needs to check that there's enough space.  This may be unnecessary if you can show that overflow is  impos‐
       sible, but be careful: programs can get changed over time, in ways that may make the impossible possible.

SEE ALSO
       bcopy(3), memccpy(3), memcpy(3), memmove(3), stpcpy(3), stpncpy(3), strdup(3), string(3), wcscpy(3), wcsncpy(3)

COLOPHON
       This page is part of release 5.05 of the Linux man-pages project.  A description of the project, information about reporting bugs,
       and the latest version of this page, can be found at https://www.kernel.org/doc/man-pages/.

GNU                                                             2019-03-06                                                      STRCPY(3) to learn more. | <a href = https://github.com/nyaliti/alx-low_level_programming/blob/main/0x06-pointers_arrays_strings/2-strncpy.c> View Code </a> |
| 3 | 3-strcmp.c | Write a function that compares two strings.<ul><li> Prototype:  </li><li> Your function should work exactly like  </li></ul>FYI: The standard library provides a similar function: . RunSTRCMP(3)                                               Linux Programmer's Manual                                               STRCMP(3)

NAME
       strcmp, strncmp - compare two strings

SYNOPSIS
       #include <string.h>

       int strcmp(const char *s1, const char *s2);

       int strncmp(const char *s1, const char *s2, size_t n);

DESCRIPTION
       The  strcmp()  function  compares the two strings s1 and s2.  The locale is not taken into account (for a locale-aware comparison,
       see strcoll(3)).  It returns an integer less than, equal to, or greater than zero if s1 is found, respectively, to be  less  than,
       to match, or be greater than s2.

       The strncmp() function is similar, except it compares only the first (at most) n bytes of s1 and s2.

RETURN VALUE
       The  strcmp()  and  strncmp()  functions  return  an integer less than, equal to, or greater than zero if s1 (or the first n bytes
       thereof) is found, respectively, to be less than, to match, or be greater than s2.

ATTRIBUTES
       For an explanation of the terms used in this section, see attributes(7).

       ┌────────────────────┬───────────────┬─────────┐
       │Interface           │ Attribute     │ Value   │
       ├────────────────────┼───────────────┼─────────┤
       │strcmp(), strncmp() │ Thread safety │ MT-Safe │
       └────────────────────┴───────────────┴─────────┘
CONFORMING TO
       POSIX.1-2001, POSIX.1-2008, C89, C99, SVr4, 4.3BSD.

SEE ALSO
       bcmp(3), memcmp(3), strcasecmp(3), strcoll(3), string(3), strncasecmp(3), strverscmp(3), wcscmp(3), wcsncmp(3)

COLOPHON
       This page is part of release 5.05 of the Linux man-pages project.  A description of the project, information about reporting bugs,
       and the latest version of this page, can be found at https://www.kernel.org/doc/man-pages/.

                                                                2019-03-06                                                      STRCMP(3) to learn more. | <a href = https://github.com/nyaliti/alx-low_level_programming/blob/main/0x06-pointers_arrays_strings/3-strcmp.c> View Code </a> |
| 4 | 4-rev_array.c | Write a function that reverses the content of an array of integers.<ul><li> Prototype:  </li><li> Where  is the number of elements of the array </li></ul> | <a href = https://github.com/nyaliti/alx-low_level_programming/blob/main/0x06-pointers_arrays_strings/4-rev_array.c> View Code </a> |
| 5 | 5-string_toupper.c | Write a function that changes all lowercase letters of a string to uppercase.<ul><li> Prototype:  </li></ul> | <a href = https://github.com/nyaliti/alx-low_level_programming/blob/main/0x06-pointers_arrays_strings/5-string_toupper.c> View Code </a> |
| 7 | 7-leet.c | Write a function that encodes a string into 1337.<ul><li> Letters  and  should be replaced by  </li><li> Letters  and  should be replaced by  </li><li> Letters  and  should be replaced by  </li><li> Letters  and  should be replaced by  </li><li> Letters 0-strcat.c	    103-infinite_add.c	3-strcmp.c	    7-leet.c
100-rot13.c	    104-print_buffer.c	4-rev_array.c	    main.h
101-print_number.c  1-strncat.c		5-string_toupper.c  push*
102-magic.c	    2-strncpy.c		6-cap_string.c and  should be replaced by  </li><li> Prototype:  </li><li> You can only use one  in your code </li><li> You can only use two loops in your code </li><li> You are not allowed to use  </li><li> You are not allowed to use any ternary operation </li></ul> | <a href = https://github.com/nyaliti/alx-low_level_programming/blob/main/0x06-pointers_arrays_strings/7-leet.c> View Code </a> |
| 8 | 100-rot13.c | Write a function that encodes a string using <a href = https://en.wikipedia.org/wiki/ROT13> rot13</a>.<ul><li> Prototype:  </li><li> You can only use  statement once in your code </li><li> You can only use two loops in your code </li><li> You are not allowed to use  </li><li> You are not allowed to use any ternary operation </li></ul> | <a href = https://github.com/nyaliti/alx-low_level_programming/blob/main/0x06-pointers_arrays_strings/100-rot13.c> View Code </a> |
| 9 | 101-print_number.c | Write a function that prints an integer.<ul><li> Prototype:  </li><li> You can only use  function to print </li><li> You are not allowed to use  </li><li> You are not allowed to use arrays or pointers </li><li> You are not allowed to hard-code special values </li></ul> | <a href = https://github.com/nyaliti/alx-low_level_programming/blob/main/0x06-pointers_arrays_strings/101-print_number.c> View Code </a> |
| 11 | 103-infinite_add.c | Write a function that adds two numbers.<ul><li> Prototype:  </li><li> Where  and  are the two numbers </li><li>  is the buffer that the function will use to store the result </li><li>  is the buffer size </li><li> The function returns a pointer to the result </li><li> You can assume that you will always get positive numbers, or  </li><li> You can assume that there will be only digits in the strings  and  </li><li>  and  will never be empty </li><li> If the result can not be stored in r the function must return  </li></ul> | <a href = https://github.com/nyaliti/alx-low_level_programming/blob/main/0x06-pointers_arrays_strings/103-infinite_add.c> View Code </a> |
| 12 | 104-print_buffer.c | Write a function that prints a buffer.<ul><li> Prototype:  </li><li> The function must print the content of  bytes of the buffer pointed by  </li><li> The output should print 10 bytes per line </li><li> Each line starts with the position of the first byte of the line in hexadecimal (8 chars), starting with  </li><li> Each line shows the hexadecimal content (2 chars) of the buffer, 2 bytes at a time, separated by a space </li><li> Each line shows the content of the buffer. If the byte is a printable character, print the letter, if not, print . </li><li> Each line ends with a new line  </li><li> If  is 0 or less, the output should be a new line only  </li><li> You are allowed to use the standard library </li><li> The output should look like the following example, and formatted exactly the same way: </li></ul> | <a href = https://github.com/nyaliti/alx-low_level_programming/blob/main/0x06-pointers_arrays_strings/104-print_buffer.c> View Code </a> |


