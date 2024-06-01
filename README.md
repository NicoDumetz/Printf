# My_Printf 📝

The objective of this Epitech project is to recode the `printf` function from the C library according to the C99 standard, supporting various format specifiers, flags, and modifiers.

## How to Run

To compile and run the `my_printf` project, follow these steps:

1. Clone or download the project repository.

2. Navigate to the directory containing the project files.

3. Compile the project using the provided Makefile. Open a terminal and run the following command:
    ```
    make
    ```

4. Once the compilation is successful, you can use the `my_printf` function in your own C programs. Include the `my.h` header file in your code:

    ```c
    #include "my.h"
    ```

5. Write your C program using `my_printf` as needed. Here's an example:

    ```c
    #include "my.h"

    int main(void) {
        my_printf("Hello, %s!\n", "world");
        return 0;
    }
    ```

6. Compile your C program along with the `libmy.a` library. Assuming your source file is named `example.c`, you can compile it using:

    ```
    gcc -o example example.c -L. -lmy
    ```

   This command links your program with the `libmy.a` library.

7. Run your compiled program. If using the example above, you can run it with:

    ```
    ./example
    ```

8. If you want to clean up and remove the compiled files, you can use the provided Makefile rules:
    - To remove object files: `make clean`
    - To remove all generated files: `make fclean`

## Flags

To see all the possible flags and options for my_printf, type the command:
```
man 3 printf
```

## Grade

I received a score of 100% on this project.

## Authors
Thank you for checking out this project! If you have any questions or would like to collaborate, feel free to contact me.

[Nicolas Dumetz](mailto:nicolasdumetzpro@gmail.com)
