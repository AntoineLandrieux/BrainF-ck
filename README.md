
# BrainF-ck

BrainF*ck C interpreter using only stack memory

## How to use

```txt
+ Increment the value in the current cell by 1
- Decrement the value in the current cell by 1
> Move the pointer to the next cell
- Move the pointer to the previous cell
, Read a byte of input into the current cell
. Output the value in the current cell
[ Move past the matching ] if the value in the current cell is zero
] Move back to the matching [ if the value in the current cell is non-zero
```

> [!WARNING]
>
> The Brain*ck code will be executed line by line
>
> 👍 Good practice
>
> `(test/1.bf)`
>
> ```bf
> simple "Hello World!" program :)
> ++++++++++[>+++++++>++++++++++>+++>+<<<<-]
> ++.>+.+++++++..+++.>++.<<+++++++++++++++.
> .+++.------.--------.>+.>.
> ```
>
>👎 Bad practice
>
> `(test/1.bf)`
>
> ```bf
> simple "Hello World!" program :)
> ++++++++++[
> >+++++++>++++++++++>+++>+<<<<-
> ]
> ++.>+.+++++++..+++.>++.<<+++++++++++++++.
> .+++.------.--------.>+.>.
> ```
>

## Test it now

> [!NOTE]
>
> Essential Build may be required to compile this project.
>

```txt
root@pc:/$ make
mkdir -p bin
gcc src/main.c -o bin/brainf_ck -Wall -Wextra -Werror
root@pc:/$ ./bin/brainf_ck test/1.bf
Hello World!
root@pc:/$
```

## Credit

- [Antoine Landrieux](https://github.com/AntoineLandrieux) - Developer
