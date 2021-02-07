# 42'S FT_PRINTF SUBJECT

<h2>MANDATORY PART</h2>
<br>

  **Program name** | <samp>libftprintf.a</samp> 
  -----------------|----------
  **Turn in files** | <samp>*.c, */*.c, *.h, */*.h, Makefile</samp>
  **Makefile** | <samp>all, clean, fclean, re, bonus</samp> 
  **Libft authorized** | Yes 
  **Description** | Write a library that contains <samp>ft_printf</samp>, a function that will mimic the real printf
  
<br>

- The prototype of ft_printf should be int <code>ft_printf(const char *, ...);</code>
- You have to recode the <samp>libc</samp>’s <samp>printf</samp> function
- It must not do the buffer management like the real <samp>printf</samp>
- It will manage the following conversions: <samp>cspdiuxX%</samp>
- It will manage any combination of the following flags: ’<samp>-0.*</samp>’ and minimum field width with all conversions
- It will be compared with the real printf
- You must use the command ar to create your librairy, using the command libtool is forbidden.

<samp><b>NOTE</b>: man 3 printf / man 3 stdarg</samp>

<br>

<h2>BONUS PART</h2>
<br>

- If the Mandatory part is not perfect don’t even think about bonuses
- You don’t need to do all the bonuses
- Manage one or more of the following conversions: <samp>nfge</samp>
- Manage one or more of the following flags: <samp>l ll h hh</samp>
- Manage all the following flags: ’<samp># +</samp>’ (yes, one of them is a space)
