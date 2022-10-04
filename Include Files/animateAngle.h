// Define a function that displays an angle meter animation and returns the angle
double animateAngle(double p, shotCounter sc, timer t, hoop h, ball b, player pl) {
  
  // Define a variable to hold the current angle
  double r = 0;
  
  // Define a variable to hold the number of loops
  int numLoops = 0;
  
  // Define a variable to hold the direction of angle change
  int dir = 1;
  
  // Define a constant to hold the angle increment
  const double ANGLE_INCREMENT = 6;
  
  // Animate the angle through three loops
  while (numLoops < 3) {

    // Erase previous frame
    drawBackground();
    
    // Draw the given player at the bottom of its stance
    drawPlayerBottom(&pl, 25, HEIGHT, &b);
    
    // Draw the given hoop
    drawHoop(&h, 535, HEIGHT);
    
    // If the game mode is best of ten, draw the given shot counter
    if (sc.mode == 1) {
      
      // Draw the given shot counter
      drawShotCounter(sc);
      
  	}
    
    // If the game mode is timed, draw the given timer
  	else {
      
      // Update the seconds passed
      t.sec = ((double)(clock() - t.begin) / CLOCKS_PER_SEC);
      
      // Draw the given timer
      drawTimer(sc, t);
      
      // If the time has expired, stop the animation and indicate the game is over
      if (t.totalSec - t.sec == 0) {
        
        // Draw the power meter at the given power
        drawPower(p);
        
        // Draw the angle meter at the current angle
   	    drawAngle(r);
        
        // Update the graphics window
        graphics_update();
        
        // Return -69 to indicate the time has expired
		return -69;
        
      }
      
 	}
    
    // Draw the power meter at the given power
    drawPower(p);
    
    // Draw the angle meter at the given angle
    drawAngle(r);
    
    // Update the graphics window
    graphics_update();
    
    // If the space bar is pressed, return the angle
    if (get_key_state(KeySpace) != 0) {
      
      // Update the graphics windows
      graphics_update();
      
      // Add a random increment to the angle that reflects values that are not multiples of the angle increment
      r = r + (((rand() % 1001) / 1000.0) * ANGLE_INCREMENT) - (ANGLE_INCREMENT / 2.0);
      
      // If the random increment made the angle greater than the maximum, make the angle the maximum
      if (r >= 0){
        
        // Make the angle the maximum
        r = 0;
        
      }
      
      // If the random increment made the angle less than the minimum, make the angle the minimum
      else if (r <= -90) {
        
        // Make the angle the minimum
        r = -90;
        
      }
      
      // Return the actual angle
      return r + 90;
      
    }
    
    // Increment the angle
    r = r - (ANGLE_INCREMENT * dir);
    
    // If the angle is greater than the maximum, set it to the maximum and change the direction
    if (r >= 0){
      
      // Change the direction
      dir = 1;
      
      // Set the angle to the maximum
      r = 0;
      
      // Increment the number of loops
      ++numLoops;
      
    }
    
    // If the angle is less than the minimum, set it to the minimum and change the direction
    else if (r <= -90) {
      
      // Change the direction
      dir = -1;
      
      // Set the angle to the minimum
      r = -91;
      
    }
    
  }
  
  // Erase the previous frame
  drawBackground();
  
  // Draw the given player at the bottom of its stance
  drawPlayerBottom(&pl, 25, HEIGHT, &b);
  
  // Draw the given hoop
  drawHoop(&h, 535, HEIGHT);
  
  // If the game mode is best of ten, draw the given shot counter
  if (sc.mode == 1) {
    
    // Draw the given shot counter
    drawShotCounter(sc);
    
  }
  
  // If the game mode is timed, draw the given timer
  else {
    
    // Draw the given timer
    drawTimer(sc, t);
    
  }
  
  // Draw the given power
  drawPower(p);
  
  // Draw the current angle
  drawAngle(r);
  
  // Update the graphics window
  graphics_update();
  
  // Return the default angle
  return 90;
  
}