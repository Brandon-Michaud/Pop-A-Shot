// Define a function that animates the given player's shot motion
int animatePlayer(player* pl, int x, int y, ball* b, hoop* h, shotCounter sc, timer t, shot sh) {
  
  // Define joint angles to reflect intial positions
  double a = -25;
  double k = 25;
  double s = -100;
  double e = -15;
  double w = 0;
  
  // Define directions of rotation for the elbow and wrist joints
  int edir = 1;
  int wdir = 1;
  
  // Animate the given player's shot
  while(a <= 0) {
    
    // Erase the previous frame
    drawBackground();
    
    // Draw the power meter at the given power
    drawPower(sh.p);
    
    // Draw the angle meter at the given angle
   	drawAngle(sh.a - 90);
    
    // Draw the player at its specified joint angles
    drawPlayer(pl, 25, HEIGHT, a, k, s, e, w, 1, b);
    
    // Draw the given hoop
    drawHoop(h, 535, HEIGHT);
    
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
      
      // If the time has expired, return a value indicating so
      if (t.totalSec - t.sec == 0) {
        
        // Update the graphics window
        graphics_update();
        
        // Return a value indicating time has expired
		return -69;
        
      }
      
 	}
    
    // Update the graphics window
    graphics_update();
    
    // Change the ankle, knee, and shoulder angles
    ++a;
    --k;
    s = s + 6.8;
    
    // If the elbow angle direction is positive, increase the elbow angle
    if (edir == 1) {
      
      // Increase the elbow angle
	  e = e + 8.529411765;
      
    }
    
    // If the elbow angle direction is negative, decrease the elbow angle
    else {
      
      // Decrease the elbow angle
      e = e - 7.5;
      
    }
    
    // If the elbow angle reaches its maximum, change the elbow angle direction
    if (e >= 130) {
      
      // Change the elbow angle direction
      edir = -1;
      
    }
    
    // If the wrist angle is positive, increase the wrist angle
    if (wdir == 1) {
      
      // Increase the wrist angle
	  w = w + 10.58823529;
      
    }
    
    // If the wrist angle is negative, decrease the wrist angle
    else {
      
      // Decrease the wrist angle
      w = w - 11.25;
      
    }
    
    // If the wrist angle reaches its maximum, change the wrist angle direction
    if (w >= 179) {
      
      // Change the wrist angle direction
      wdir = -1;
      
    }
    
  }
  
  // If the shot was released in time, return 1
  return 1;
  
}