// Define a function to animate the power meter and return the power
double animatePower(double a, shotCounter sc, timer t, hoop h, ball b, player pl) {

  // Define a variable to hold the current power
  double r = 0;
  
  // Define a variable to hold the number of loops
  int numLoops = 0;
  
  // Define a variable to hold the direction of the power change
  int dir = 1;
  
  // Define a constant to hold the power increment
  const double POWER_INCREMENT = 1;
  
  // Animate the power meter
  while (numLoops < 3){
    
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
      
      // Update the elapsed time
      t.sec = ((double)(clock() - t.begin) / CLOCKS_PER_SEC);
      
      // Draw the given timer
      drawTimer(sc, t);
      
      // If the time has expired, return a value to indicate so
      if (t.totalSec - t.sec == 0) {
        
        // Draw the given angle
        drawAngle(a - 90);
        
        // Draw the current power
        drawPower(r);
        
        // Update the graphics window
        graphics_update();
        
        // Return a value to indicate time has expired
		return -69;
        
      }
      
  	}
    
    // Draw the given angle
    drawAngle(a - 90);
    
    // Draw the current power
    drawPower(r);
    
    // Update the graphics window
    graphics_update();
    
    // If the space bar is pressed, return the power
    if (get_key_state(KeySpace) != 0) {
      
      // Update the graphics window
      graphics_update();
      
      // Add a random increment to the power that reflects values that are not multiples of the power increment
      r = r + (((rand() % 1001) / 1000.0) * POWER_INCREMENT) - (POWER_INCREMENT / 2.0);
      
      // If the random increment made the power less than the minimum, set the power to be the minimum
      if (r < 0){
        
        // Set the power to be minimum
        r = 0;
        
      }
      
      // If the random increment made the power more than the maximum, set the power to be the maximum
      else if (r > POWER_MAX) {
        
        // Set the power to be maximum
        r = POWER_MAX;
        
      }
      
      // Return the power
      return r;
      
    }
    
    // Increment the power
    r = r + (dir * POWER_INCREMENT);
    
    // If the power is greater than the maximum, set it to be maximum and change direction
    if (r >= POWER_MAX) {
      
      // Change the direction
      dir = -1;
      
      // Set the power to be maximum
      r = POWER_MAX;
      
    }
    
    // If the power is less than the minimum, set it to be minimum and change direction
    else if (r <= 0) {
      
      // Change direction
      dir = 1;
      
      // Set the power to be minimum
      r = 0;
      
      // Increment the number of loops
      ++numLoops;
      
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
  
  // Draw the given angle
  drawAngle(a - 90);
  
  // Draw the current power
  drawPower(r);
  
  // Update the graphics window
  graphics_update();
  
  // Return the default power
  return 0;
  
}