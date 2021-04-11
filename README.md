# StringBuilder

A dynamic string builder using a linked list for allocations

# Installation

* Install the library

`em list`

`em install`

`em build lib`

## Usage

* Include in a file

`touch test.c`
```c
#include <export/StringBuilder.h>
int main(void) {
    char *sb_p = NULL;
    string *sb = string_new("initial");

    string_addf(sb, "%s,%s", "Hello, ", "World!");
    printf("%s\n", (sb_p = string_get(sb)));

    free(sb_p);
}
```

## Development

* Implement the rest of the string interface
* Write tests

## Contributing

1. Fork it (<https://github.com/EmeraldsFramework/StringBuilder/fork>)
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create a new Pull Request

## Contributors

- [Oblivious](https://github.com/Oblivious) - creator and maintainer
