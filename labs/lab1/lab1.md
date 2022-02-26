
그런즉 너희가 먹든지 마시든지 무엇을 하든지 다 하나님의 영광을 위하여 하라 (고전10:31)

-------
<img src="https://github.com/idebtor/nowic/blob/85a7852bf0f6000fded586dadaeac02c186027a6/images/cplus_ds_title.jpg?raw=true" width=1000>

__NOTE:__ The following materials have been compiled and adapted from the numerous sources including my own. Please help me to keep this tutorial up-to-date by reporting any issues or questions. Send any comments or criticisms to `idebtor@gmail.com` Your assistances and comments will be appreciated.

-------------------
# Lab1 - C/C++ code conversion
## Subjects
1. C vs C++
2. #define vs const
3. printf vs cout
4. memory allocation - new & delete
5. pointer vs reference

C++ reference is a major concept in C++ programming language. Although it’s not as strong as pointers, nonetheless it allows us to use it to write efficient programs. 

## Reference variable
C++ reference allows you to create a second name (or __alias__) for the a variable that you can use to read or modify the original data stored in that variable. This means that when you declare a reference and assign it a variable, it will allow you to treat the reference exactly as though it were the original variable for the purpose of __accessing and modifying the value of the original variable__ even if the second name (the reference) is located within a different scope. This means, for instance, that if you __make your function arguments references__, and you will effectively have a way to change the original data passed into the function.

## Step 1. C Programming

1. Create a source file, `cplus.cpp`, with the following code, as it is.
    - While coding, read and understand what the code does.
    - With the macro `#if 1`, it will use the code between `#if 1` and `#else`, and ignore the rest of the code. 
    - With the macro `#if 0`, it will use the code between `#else` and `#endif`, and ignore the upper portion of the code. 

    ```
    // Lab1 - C/C++ code conversion
    // Subjects:
    // 1. C vs C++
    // 2. #define vs const
    // 3. printf vs cout
    // 4. memory allocation - new & delete
    // 5. pointer vs reference
    //
    // TODO: Convert a C program into C++ 
    // - Use a reference operator, but not a pointer.
    // - Use const, but not #define.
    // - Use new and delete operators.
    // - Use cout & endl instead of printf().
    // - Do not use "using namespace std;".
    // - Do not change the return type of sum().
    // 
    #if 1
    #include <stdio.h>
    #define N 40

    void sum(int d[], int n, int* p) {
        *p = 0;
        for(int i = 0; i < n; ++i) 
            *p = *p + d[i];
    } 

    int main(int argc, char *argv[]) {
        int total = 0;
        int data[N];

        for(int i = 0; i < N; ++i) 
            data[i] = i;
        
        sum(data, N, &total);  // total - pass-by-pointer
        printf("Total is %d\n", total);
        return 0;
    }
    #else 
    #include <iostream>

    // your code here - sum() function

    int main(int argc, char *argv[]) {

        cout << "your code here" << endl;

        return 0;
    }
    #endif
    ```

2. Compile and run it. 

#### Sample Run:
```
$ g++ -std=c++11 cplus.cpp -o cplus
$ ./cplus
The total is 780
```

## Step 2: Convert a C program into C++.

1. Convert the C program into C++ between `#else` and `endif` in `cplus.cpp` as shown below:
    ```
    #include <iostream>

    // your code here - sum() function

    int main(int argc, char *argv[]) {

        cout << "your code here" << endl;

        return 0;
    }
    #endif
    ```
2. While converting it, keep some guidelines instructed below: 
    - Use `const`, but not `#define`.
    - Use a reference operator, but not a pointer.
    - Use `new` and `delete` operators.
    - Use `cout` & `endl` instead of `printf()`.
    - Do not use `using namespace std;`.
    - Do not change the return type of `sum()`.  
    
3. Compile and run it. 
    - Set `#if 1` to `#if 0` such that it uses the code below `#else`. 
    - The output should be the same as the previous step. 

#### Sample Run:
```
$ g++ -std=c++11 cplus.cpp -o cplus
$ ./cplus
The total is 780
```

----------------------------
# File(s) to submit at Piazza lab1 folder:
  - cplus.cpp

----------------------------
_One thing I know, I was blind but now I see. John 9:25_
----------------------------