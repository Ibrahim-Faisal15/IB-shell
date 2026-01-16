# Toy Shell

Toy Shell is a simple custom shell implementation built for learning purposes.
It supports basic commands and is designed to be easily extendable by adding new commands.

## Features

* Basic shell loop
* Command parsing
* Modular command system
* Easy to add new custom commands

## Project Structure

```
toy-shell/
├── commands/        # Directory containing all shell commands
│   ├── example_cmd.h
│   └── example_cmd.c       
└── main.c     //entry point of execution
└── parser.c   //parser implementation
└── parser.h       
```

## Build and Run

```bash
make all
make run
```

## Contributing

Contributions are welcome!
You can easily add new commands to the shell by following the steps below.

### Adding a New Command

1. Navigate to the commands/ folder:

```bash
cd commands
```

2. Create a function signature in the header file `commands.h` with the following naming pattern:

```c
return_type commandName_cmd(params);
```

3. Create a source file with the same base name:

```text
commandName_cmd.c
```

4. Implement the command logic in the `.c` file:

```c
#include "commands.h"

return_type commandName_cmd(params) {
    // command implementation
}
```

5. Call the command function in the selection control statement located in `main.c`.

6. Rebuild the project:

```bash
make all
```

## Project Output


<img width="695" height="116" alt="Screenshot from 2026-01-16 21-29-03" src="https://github.com/user-attachments/assets/64e70e1e-47cd-4ae7-887d-2fca4931921e" />

