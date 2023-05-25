# So-Long
This project is a very small 2D game.
Its purpose is to work with textures, sprites,
and some other very basic gameplay elements.

The project involves creating a computer graphics game using the MiniLibX library. The goals of the project include improving skills in window management, event handling, colors, textures, and other related areas. The project aims to be rigorous, enhance C programming skills, utilize basic algorithms, and conduct information research.

The project must adhere to the following rules:

The MiniLibX library must be used, either the version available on the school machines or by installing it from its sources.
A Makefile should be provided to compile the source files without relinking.
The program should take a map description file with the .ber extension as a parameter.
The game consists of a player collecting all the collectibles on the map and then escaping by choosing the shortest route. The W, A, S, and D keys (or ZQSD or arrow keys) are used to move the main character in the four directions: up, down, left, and right. The player should not be able to move into walls, and the current number of movements should be displayed in the shell after each move. The game can have a 2D top-down or profile view and does not need to be real-time. The theme of the game can be chosen freely.

The graphic management aspect of the project requires displaying the game image in a window. The window management should be smooth, allowing tasks such as changing to another window or minimizing. Pressing ESC or clicking on the cross in the window's frame should close the window and quit the program cleanly. The use of MiniLibX images is mandatory.

The map is constructed with walls, collectibles, and free space represented by the characters '1', 'C', '0', 'E', and 'P'. The map must contain at least one exit, one collectible, and one starting position to be considered valid. Duplicates of exit or starting position characters should result in an error message. The map must be rectangular and surrounded by walls; otherwise, an error should be returned. It is necessary to check if there is a valid path in the map. Any valid map that follows the specified rules can be parsed. Errors or misconfigurations in the map file should cause the program to exit cleanly and display an error message of choice, preceded by "Error\n".

Examples of valid and minimal .ber maps are provided in the document.
