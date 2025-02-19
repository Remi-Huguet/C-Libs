# C-String-Lib
Functions from the lib string.h maked

## Description
This project create a lib with a lot of function of the string.h lib.
The idea of this project was make again a project i had to to in first year, but after learning more things (4 years later).

## Run
```bash
make
```

## Run Unit Tests
```bash
make tests_run
```

## Run Unit Tests Dependencies
```bash
sudo apt update
sudo apt install libcriterion-dev
```

## Functions handled
- Execution of all binary in the differents paths they can be : "/bin/", "/usr/bin/", "/usr/local/bin/", "/sbin/"
- cd is not handled with ~
- env, setenv, unsetenv
- exit to leave

## Options that are planed to be handled
- ";" handler, to use multiple commands
- Redirections (">", ">>", "<", "<<") handlers
- Pipes ("|", "||") handlers