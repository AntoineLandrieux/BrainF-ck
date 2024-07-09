
# BrainF-ck

C BrainF*ck interperter

## How to use

> [!WARNING]
>
> The Brain*ck code will be executed line by line
>
> 👍 Good practice
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
