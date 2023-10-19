Building a Simple Shell
Project Overview
This collaborative project aims to develop a simple Unix shell, a command-line interpreter program for operating systems. This shell program was created by contributors Godfrey Njoroge and Hlalefi Kgasago. The shell is designed to execute various system commands, handle built-in commands, and provide a user-friendly interface for interacting with the operating system.

Features
Basic Shell Functionality
Interactive Mode: The shell runs in interactive mode, where users can enter commands interactively.

Batch Mode: The shell can also process commands from a batch file passed as an argument when starting the shell.

Prompt Display: The shell displays a prompt to indicate that it is ready to accept user input.

Exit Command: Users can exit the shell by typing the "exit" command.

Change Directory (cd): Users can change the current working directory using the "cd" command, with support for relative and absolute paths.

Print Environment (env): The "env" command prints the current environment variables.

Handle Arguments: The shell can execute commands with arguments, allowing users to pass options and arguments to system commands.

Handle PATH: The shell searches for and executes commands by searching the directories listed in the PATH environment variable.

Error Handling: The shell provides error messages in case of command execution errors.

Custom Functions
getline Replacement: A custom read_usr_command function reads user input to handle command lines with custom buffer management and without relying on the standard getline function.

Additional Utility Functions: The codebase includes utility functions like simple_shell_print for printing messages and execute_usr_command for executing system commands.

Development Notes
Programming Language: The shell is implemented in C, a low-level programming language commonly used for system and application development on Unix-based operating systems.

Functionality Implementation: The shell's functionality is divided into several source files, each responsible for specific tasks. The codebase follows best practices for modular and maintainable code.

Testing: Testing the shell includes both unit testing for individual functions and integration testing for overall shell functionality.

How to Use
Clone the repository to your local machine.

Compile the shell program using a C compiler.

Run the compiled program in interactive mode or provide a batch file as an argument.

Use the shell interactively, entering commands, or execute the shell in batch mode using a predefined script.

Contributors
Godfrey Njoroge
Hlalefi Kgasago
License
This shell program is open-source and distributed under the MIT License.


