# C-Lib
Some functions from the basics c libs maked, and new ones.

## Description
This project create a lib with a lot of function of the string.h lib and others utils functions.
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
- str_get_len (strlen that return int not size_t)
- str_is_same (like strcmp, but return a boolean)
- str_to_array (a split function)
- array_get_len (get len of an array) 
