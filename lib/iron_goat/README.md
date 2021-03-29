# IronGoat

## Disclaimer 

This library only supports json exports and csv for now to load maps `layers.data`

Will only work on UNIX as `<unistd.h>` is required

## How to use

```c
#include <iron_goat/deser.h>
#include <erty/json.h>

int main(void)
{
    json_t json_file = {0};
    ig_map_t map_conf = {0};
    
    if (jsonparser("map.json") == false)
        return (1);
    if (iron_goat_load_map(&json_file, &map_conf) == false) {
        destroy_json(&json_file);
        return (1);
    }
    destroy_json(&json_file);
    // now you can load whatever from the structure
    map.layer.data[0].data
    // to access data of a layer for example -> see documentation for more
    destroy_iron_goat_map(&map_conf);
    return (0);
}
```

The way to load any objects is the same on each type of data
See [Tiled Json Documentation](https://doc.mapeditor.org/en/stable/reference/json-map-format/) to see what you can load from the program

## Coding style

The code follows a particular coding style enforced by my school. The most
important aspects are:
- No more than 5 functions in a `*.c` file.
- No more than 3 levels of branching.
- No more than 1 `else if` in a branching chain.
- No `typedef`s in `*.c` files.
- No structure arguments passed by value (always use a pointer).
- Functions must not exceed 20 lines.
- Variable declarations must always be done at the top of the function scope.
- The only empty line in functions is the one separating variable declarations
  with the rest of the function's body.
- Source files must start with some header containing the project name and file
  description.
