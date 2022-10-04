#include <delay.h>
#include <shapes.h>
#include <colors.h>
#include <letters.h>
#include <drawHoop.h>
#include <drawBackground.h>
#include <drawScore.h>
#include <drawShotCounter.h>
#include <drawTimer.h>
#include <drawBall.h>
#include <drawPlayer.h>
#include <instructions.h>
#include <drawAngle.h>
#include <drawPower.h>
#include <animateAngle.h>
#include <animatePower.h>
#include <drawShot.h>
#include <animatePlayer.h>
#include <getHighScore.h>
#include <drawLeaderboard.h>
#include <drawMainMenu.h>
#include <bestOfTen.h>
#include <timed.h>
#include <options.h>

// 2972 lines before comments and added whitespace
int main() {
  
  // Print out the instructions
  printInstructions(); 
  
  // Open a graphics window of the defined dimensions
  graphics_open(WIDTH, HEIGHT);
  
  // Seed the random number generator with the time
  srand(time(0));
   
  // Define a variable to hold the user's selection
  int selector;
  
  // Define a variable to hold whether or not the user wishes to quit
  int quit = 0;
  
  // Declare and initialize a player object
  player pl;
  playerInitializer(&pl);
  
  // Declare and initialize a hoop object
  hoop h;
  hoopInitializer(&h);
  
  // Declare and initialize a ball object
  ball b;
  ballInitializer(&b);
  
  // While the user does not wish to quit, run the program
  while (quit == 0) {
    
    // Draw the main menu and get the user's selection
    selector = drawMainMenu();
    
    // Delay 0.1 seconds to prevent accidental multiple inputs
    delay(0.1);
    
    // If the user selected best of ten, execute the best of ten mode
    if (selector == 0) {
      
      // Execute the best of ten mode
	  bestOfTen(h, b, pl);
      
    }
    
    // If the user selected timed, execute the timed mode
    else if (selector == 1) {
      
      // Execute the timed mode
	  timed(h, b, pl);
      
    }
    
    // If the user selected options, open the options menu
    else if (selector == 2) {
      
      // Open the options menu
	  options(&h, &b, &pl);
      
    }
    
    // If the user selected quit, update the quit variable
    else if (selector == 3) {
      
      // Update the quit variable
	  quit = 1;
      
    }
    
    // Update the graphics window
    graphics_update();
    
  }
   
  // Update the graphics window
  graphics_update();
  
  // Close the graphics window
  graphics_close();
  
  
  // Default return
  return 0;
  
}