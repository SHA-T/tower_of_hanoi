# Tower of Hanoi
This is an implementation of the mathematical disk game 'Tower of Hanoi'. Refer to [wikipedia.org/wiki/Tower_of_Hanoi](https://en.wikipedia.org/wiki/Tower_of_Hanoi) for the rules of the game.

## Usage
After starting the program it will ask you to select the height of the tower. Note that the time complexity of solving a tower of height N is O(2^N). So, for faster computation don't choose a height greater than 12. If you want to cancel the computation press `Ctrl` + `C`.

### Exemplary Output
```
Choose the height of your tower (e.g. 4):
4
Move from TowerA to TowerC

  ####
 ######
########             ##
__________________________

Move from TowerA to TowerB


 ######
########   ####      ##
__________________________

Move from TowerC to TowerB


 ######     ##
########   ####
__________________________

Move from TowerA to TowerC


            ##
########   ####    ######
__________________________

Move from TowerB to TowerA


   ##
########   ####    ######
__________________________

Move from TowerB to TowerC


   ##               ####
########           ######
__________________________

Move from TowerA to TowerC

                     ##
                    ####
########           ######
__________________________

Move from TowerA to TowerB

                     ##
                    ####
         ########  ######
__________________________

Move from TowerC to TowerB


            ##      ####
         ########  ######
__________________________

Move from TowerC to TowerA


            ##
  ####   ########  ######
__________________________

Move from TowerB to TowerA


   ##
  ####   ########  ######
__________________________

Move from TowerC to TowerB


   ##     ######
  ####   ########
__________________________

Move from TowerA to TowerC


          ######
  ####   ########    ##
__________________________

Move from TowerA to TowerB

           ####
          ######
         ########    ##
__________________________

Move from TowerC to TowerB
            ##
           ####
          ######
         ########
__________________________
```

## Build
If you want to modify the program you can afterwards rebuild it by executing the 'makefile'. If make does not work on your system, you can manually build your executable using g++:
1. First compile 'hanoi.cpp' and 'main.cpp':
  ```
  g++ -c -o hanoi.o hanoi.cpp
  ```
  ```
  g++ -c -o main.o main.cpp
  ```
2. Then link those object-files to receive the executable:
  ```
  g++ -o program_name hanoi.o main.o
  ```
This project was created on C++17 and GCC 10 and functionality was successfully tested on Windows 10 and several Linux distributions.
