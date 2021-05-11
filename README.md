# ThatDayITriedToBecomeTheDemonKing
An rpg game for an epitech project

# Build

## Prerequisites

- cmake
- make
- gcc
- g++
- SFML
- CSFML

Type make on the root directory of the project

## Playing the Game

To launch the game use: `./my_rpg`

### How to Play
  - Main Menu
    * Use the Mouse to chose between settings and play button
  - Overworld
    * Use the arrow keys to move
    * Use Space or Enter to interact with the world
  - Fight
    * Use the mouse to chose if you want to flee or attack
    * You cannot flee in a Boss fight

## Screenshots

In work...

## Trailer

In work...

## Coding Style

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

This code follows completely the C Epitech Coding style

## Valgrind

```c
 ==9251== Bad option: --exit-on-first-error=yes
 ==9251== You must define a non nul exit error code, with --error-exitcode=...
 ==9251== Use --help for more information or consult the user manual.
 ==9251== Memcheck, a memory error detector
 ==9251== Copyright (C) 2002-2017, and GNU GPLd, by Julian Seward et al.
 ==9251== Using Valgrind-3.16.1 and LibVEX; rerun with -h for copyright info
 ==9251== Command: ./my_rpg
 ==9251==
 ==9251==
 ==9251== HEAP SUMMARY:
 ==9251==     in use at exit: 4,699,170 bytes in 20,475 blocks
 ==9251==   total heap usage: 42,802,718 allocs, 42,782,243 frees, 21,383,106,210 bytes allocated
 ==9251==
 ==9251== LEAK SUMMARY:
 ==9251==    definitely lost: 772,347 bytes in 1,778 blocks
 ==9251==    indirectly lost: 1,276,808 bytes in 9,200 blocks
 ==9251==      possibly lost: 1,285,126 bytes in 3,938 blocks
 ==9251==    still reachable: 1,363,197 bytes in 5,558 blocks
 ==9251==         suppressed: 1,692 bytes in 1 blocks
 ==9251== Rerun with --leak-check=full to see details of leaked memory
 ==9251==
 ==9251== For lists of detected and suppressed errors, rerun with: -s
 ==9251== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
As this is a school project and segfault is unforgivable we tried the game with `valgrind --exit-on-first-error=yes` and played the full game for 1h30
Even though 4Mb was leaked for such a big project  such a big quality while following C Epitech Coding Style and 1h30of use I can say we are pretty proud of so few leaks
Thoses could be easily checked with functions of 30 lines at least x)

# Assets

## Tilesets
  * [TimeFantasy](http://timefantasy.net/)

## Music
  
  * E1M1 | Doom
  * Ouverture | Dragon Quest
  * Final Destination | Super Smash Bros
  * Sanctuary Guardian | EarthBound
  * Ancient Egyptian Music - Golden Scarabs | Fantasy & World Music by the Fiechters
  * There is no need to be upset | ???
  * Knights of Blackhall | Brandon Fiechter
  * Pumpkin Woods | Derek Fiechter, Brandon Fiechter
  * Egyptian Warriors | Derek Fiechter, Brandon Fiechter
  * Epic Dark Battle Music - Escape | Powerful Fantasy Horror
  * Volcano Theme | Nintendo
  * Decisive Battle | Hollow Knight
  * Lillia, The Bashful Bloom | League of Legends
  * Val Habar | Monster Hunter 4
