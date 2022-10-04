#define MAX_VELOCITY 28.75
#define MIN_VELOCITY 15.0

// Define a struct to represent a shot
typedef struct shot_struct {
  
  // Declare a variable for the angle
  double a;
  
  // Declare a variable for the power
  double p;
  
} shot;

// Define a struct to represent a vector
typedef struct vector_struct {
  
  // Declare a variable for the x value
  double x;
  
  // Declare a variable for the y value
  double y;
  
} vector;

// Define a function to find the distance between two given points
double distance(double x1, double y1, double x2, double y2) {
  
  // Return the distance between two given points
  return sqrt(pow((x2- x1), 2.0) + pow((y2 - y1), 2.0));
  
}

// Define a function that draws the given shot
int drawShot(shot sh, shotCounter sc, timer t, hoop h, ball* b, player pl) {
  
  // Define a variable to indicate whether the shot was made or not
  int made = 0;
  
  // Define a variable to hold the total velocity of the ball
  double totalVelocity = (((sh.p / POWER_MAX) * (MAX_VELOCITY - MIN_VELOCITY) + MIN_VELOCITY));
  
  // Define a variable to hold the velocity in the x direction of the ball
  double xVelocity = totalVelocity * cos(sh.a * (PI / 180.0));
  
  // Define a variable to hold the velocity in the y direction of the ball
  double yVelocity = -totalVelocity * sin(sh.a * (PI / 180.0));
  
  // Define constants to represent the joint angles of the player
  const int A = 0;
  const int K = 0;
  const int S = 70;
  const int E = 70;
  
  // Define a variable to hold the wrist angle of the player
  double w = 90;
  
  // Define a variable to hold the rotation of the ball
  double r = 90;
  
  // Update the x and y positions of the ball
  b->x = b->x + xVelocity;
  b->y = b->y + yVelocity;
  
  // Change the y velocity to reflect gravity
  yVelocity += 0.99;
  
  // Draw the shot
  while (b->x < WIDTH - BALL_RADIUS && b->y < HEIGHT - BALL_RADIUS) {
    
    // Erase the previous frame
    drawBackground();
    
    // Draw the power meter at the given power
    drawPower(sh.p);
    
    // Draw the angle meter at the given angle
   	drawAngle(sh.a - 90);
    
    // Draw the given player to the joint angle specifications
    drawPlayer(&pl, 25, HEIGHT, A, K, S, E, w, 0, b);
    
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
      
 	}
    
    // Draw the given ball at its specified rotation
    drawBall(b, r);
    
    // Draw the given hoop
    drawHoop(&h, 535, HEIGHT);
    
    // Update the graphics window
    graphics_update();
    
    // Update the x and y positions of the ball
    b->x = b->x + xVelocity;
    b->y = b->y + yVelocity;
    
    // Define a variable to use for calculate trajectory
    double c = (xVelocity * b->y) - (yVelocity * b->x);
    
    // Define closest distances from the centers of the front rim and back rim
    double d1 = abs((448.5 * yVelocity) + (202.5 * -xVelocity) + c) / sqrt(pow(yVelocity, 2.0) + pow(-xVelocity, 2.0));
    double d2 = abs((492.5 * yVelocity) + (202.5 * -xVelocity) + c) / sqrt(pow(yVelocity, 2.0) + pow(-xVelocity, 2.0));
    
    // If the ball is going to hit the front rim, update its velocities
    if ((d1 < BALL_RADIUS + 2.5) && (abs(448.5 - (b->x + xVelocity)) < BALL_RADIUS + 2.5) && 
        (abs(202.5 - (b->y + yVelocity)) < BALL_RADIUS + 2.5)) {
      
      // Declare a normal vector
      vector normal;
      
      // Define the normal vector
      normal.x = (b->x - 448.5) / distance(b->x, b->y, 448.5, 202.5);
      normal.y = (b->y - 202.5) / distance(b->x, b->y, 448.5, 202.5);
      
      // Define a variable to use for updating the velocities
      double z = (2 * ((xVelocity * normal.x) + (yVelocity * normal.y))) / (59 + 0.62);
      
      // Update the velocities using normal vector
      xVelocity = (xVelocity - z * 0.62 * normal.x - z * 59 * normal.x) * 0.5;
      yVelocity = (yVelocity - z * 0.62 * normal.y - z * 59 * normal.y) * 0.5;
      
    }
    
    // If the ball is going to hit the back rim, update its velocities
    else if ((d2 < BALL_RADIUS + 2.5) && (distance(b->x, b->y, 492.5, 202.5) < BALL_RADIUS + 2.5 + totalVelocity)) {
      
      // Declare a normal vector
      vector normal;
      
      // Define the normal vector
      normal.x = (b->x - 492.5) / distance(b->x, b->y, 492.5, 202.5);
      normal.y = (b->y - 202.5) / distance(b->x, b->y, 492.5, 202.5);
      
      // Define a variable to use for updating the velocities
      double z = (2 * ((xVelocity * normal.x) + (yVelocity * normal.y))) / (59 + 0.62);
      
      // Update the velocities using normal vector
      xVelocity = (xVelocity - z * 0.62 * normal.x - z * 59 * normal.x) * 0.5;
      yVelocity = (yVelocity - z * 0.62 * normal.y - z * 59 * normal.y) * 0.5;
      
    }
    
    // If the ball is going to hit the top of the rim connecter, update its velocities
    if (((b->x < 500 + BALL_RADIUS && b->x > 495 - BALL_RADIUS) && b->y < 200 - BALL_RADIUS) &&
      		b->y + yVelocity >= 200 - BALL_RADIUS){
      
      // Declare and define a normal vector
	  vector normal;
      normal.x = 0;
      normal.y = -1;
      
      // Define a variable to use for updating the velocities
      double z = (2 * ((xVelocity * normal.x) + (yVelocity * normal.y))) / (59 + 0.62);
      
      // Update the velocities using the normal vector
      xVelocity = (xVelocity - z * 0.62 * normal.x - z * 59 * normal.x) * 0.5;
      yVelocity = (yVelocity - z * 0.62 * normal.y - z * 59 * normal.y) * 0.5;
      
    }
    
    // If the ball is going to hit the bottom of the rim connecter, update its velocities
    else if (((b->x < 500 + BALL_RADIUS && b->x > 495 - BALL_RADIUS) && b->y > 205 + BALL_RADIUS) &&
      		b->y + yVelocity <= 205 + BALL_RADIUS){
      
      // Declare and define a normal vector
	  vector normal;
      normal.x = 0;
      normal.y = 1;
      
      // Define a variable to use for updating the velocities
      double z = (2 * ((xVelocity * normal.x) + (yVelocity * normal.y))) / (59 + 0.62);
      
      // Update the velocities using the normal vector
      xVelocity = (xVelocity - z * 0.62 * normal.x - z * 59 * normal.x) * 0.5;
      yVelocity = (yVelocity - z * 0.62 * normal.y - z * 59 * normal.y) * 0.5;
      
    }
    
    // If the ball is going to hit the top of the backboard, update the velocities
    else if (((b->x < 515 + BALL_RADIUS && b->x > 500 - BALL_RADIUS) && b->y < 86 - BALL_RADIUS) && 
      		b->y + yVelocity >= 86 - BALL_RADIUS) {
      
      // Declare and define a normal vector
      vector normal;
      normal.x = 0;
      normal.y = -1;
      
      // Define a variable to use for updating the velocities
      double z = (2 * ((xVelocity * normal.x) + (yVelocity * normal.y))) / (59 + 0.62);
      
      // Update the velocities
      xVelocity = (xVelocity - z * 0.62 * normal.x - z * 59 * normal.x) * 0.5;
      yVelocity = (yVelocity - z * 0.62 * normal.y - z * 59 * normal.y) * 0.5;
      
    }
    
    // If the ball is going to hit the bottom of the backboard, update the velocities
    else if (((b->x < 515 + BALL_RADIUS && b->x > 500 - BALL_RADIUS) && b->y > 225 + BALL_RADIUS) && 
      		b->y + yVelocity <= 225 + BALL_RADIUS) {
      
      // Declare and define a normal vector
      vector normal;
      normal.x = 0;
      normal.y = 1;
      
      // Define a variable to use for updating the velocities
      double z = (2 * ((xVelocity * normal.x) + (yVelocity * normal.y))) / (59 + 0.62);
      
      // Update the velocities
      xVelocity = (xVelocity - z * 0.62 * normal.x - z * 59 * normal.x) * 0.5;
      yVelocity = (yVelocity - z * 0.62 * normal.y - z * 59 * normal.y) * 0.5;
      
    }
    
    // If the ball is going to hit the top of the rim connecter/pole, update its velocities
    else if (((b->x < 550 + BALL_RADIUS && b->x > 515 - BALL_RADIUS) && b->y < 200 - BALL_RADIUS) &&
            b->y + yVelocity >= 200 - BALL_RADIUS) {
      
      // Declare and define a normal vector
	  vector normal;
      normal.x = 0;
      normal.y = -1;
      
      // Define a variable to use for updating the velocities
      double z = (2 * ((xVelocity * normal.x) + (yVelocity * normal.y))) / (59 + 0.62);
      
      // Update the velocities
      xVelocity = (xVelocity - z * 0.62 * normal.x - z * 59 * normal.x) * 0.5;
      yVelocity = (yVelocity - z * 0.62 * normal.y - z * 59 * normal.y) * 0.5;
      
    }
    
    // If the ball is going to hit the bottom of the rim connecter, update the velocities
    else if (((b->x < 535 + BALL_RADIUS && b->x > 515 - BALL_RADIUS) && b->y > 215 + BALL_RADIUS) &&
            b->y + yVelocity <= 215 + BALL_RADIUS) {
      
      // Declare and define a normal vector
	  vector normal;
      normal.x = 0;
      normal.y = -1;
      
      // Define a variable to use for updating the velocities
      double z = (2 * ((xVelocity * normal.x) + (yVelocity * normal.y))) / (59 + 0.62);
      
      // Update the velocities
      xVelocity = (xVelocity - z * 0.62 * normal.x - z * 59 * normal.x) * 0.5;
      yVelocity = (yVelocity - z * 0.62 * normal.y - z * 59 * normal.y) * 0.5;
      
    }
    
    // If the ball is going to hit the left of the backboard, update its velocities
    if (((b->y < 225 + BALL_RADIUS && b->y > 86 - BALL_RADIUS) && b->x < 500 - BALL_RADIUS) && 
            b->x + xVelocity >= 500 - BALL_RADIUS) {
      
      // Declare and define a normal vector
	  vector normal;
      normal.x = -1;
      normal.y = 0;
      
      // Define a variable to use for updating the velocities
      double z = (2 * ((xVelocity * normal.x) + (yVelocity * normal.y))) / (59 + 0.62);
      
      // Update the velocities
      xVelocity = (xVelocity - z * 0.62 * normal.x - z * 59 * normal.x) * 0.5;
      yVelocity = (yVelocity - z * 0.62 * normal.y - z * 59 * normal.y) * 0.5;
      
    }
    
    // If the ball is going to hit the right of the backboard, update its velocities
    else if (((b->y < 225 + BALL_RADIUS && b->y > 86 - BALL_RADIUS) && b->x > 515 + BALL_RADIUS) && 
      b->x + xVelocity <= 515 + BALL_RADIUS) {
      
      // Declare and define a normal vector
	  vector normal;
      normal.x = 1;
      normal.y = 0;
      
      // Define a variable to use for updating the velocities
      double z = (2 * ((xVelocity * normal.x) + (yVelocity * normal.y))) / (59 + 0.62);
      
      // Update the velocities
      xVelocity = (xVelocity - z * 0.62 * normal.x - z * 59 * normal.x) * 0.5;
      yVelocity = (yVelocity - z * 0.62 * normal.y - z * 59 * normal.y) * 0.5;
      
    }
    
    // If the ball is going to hit the left of the pole, update its velocities
    else if (((b->y < 525 + BALL_RADIUS && b->y > 215 - BALL_RADIUS) && b->x < 535 - BALL_RADIUS) &&
            b->x + xVelocity >= 535 - BALL_RADIUS) {
      
      // Declare and define a normal vector
      vector normal;
      normal.x = -1;
      normal.y = 0;
      
      // Define a variable to use for updating the velocities
      double z = (2 * ((xVelocity * normal.x) + (yVelocity * normal.y))) / (59 + 0.62);
      
      // Update the velocities
      xVelocity = (xVelocity - z * 0.62 * normal.x - z * 59 * normal.x) * 0.5;
      yVelocity = (yVelocity - z * 0.62 * normal.y - z * 59 * normal.y) * 0.5;
      
    }
    
    // If the ball is going to hit the right of the pole, update its velocities
    else if (((b->y < 525 + BALL_RADIUS && b->y > 215 - BALL_RADIUS) && b->x > 550 + BALL_RADIUS) &&
            b->x + xVelocity <= 550 + BALL_RADIUS) {
      
      // Declare and define a normal vector
      vector normal;
      normal.x = 1;
      normal.y = 0;
      
      // Define a variable to user for updating the velocities
      double z = (2 * ((xVelocity * normal.x) + (yVelocity * normal.y))) / (59 + 0.62);
      
      // Update the velocities
      xVelocity = (xVelocity - z * 0.62 * normal.x - z * 59 * normal.x) * 0.5;
      yVelocity = (yVelocity - z * 0.62 * normal.y - z * 59 * normal.y) * 0.5;
      
    }
    
    // Update the y velocity to reflect gravity
    yVelocity += 0.99;
    
    // Recalculate the total velocity
    totalVelocity = sqrt(pow(xVelocity, 2.0) + pow(yVelocity, 2.0));
    
    // If the ball is going to go in, update the made variable
    if (distance(b->x, b->y, 470.5, 202.5) < totalVelocity) {
      
      // Redefine c to use to calculate the new trajectory
      c = (xVelocity * b->y) - (yVelocity * b->x);
      
      // Calculate the x position at the rim height
      double mx = ((xVelocity * 202.5) - c) / yVelocity;
      
      // If the x position is a ball radius away from the edge of rim, update the made variable
      if (mx >= 448.5 + 2.5 + BALL_RADIUS && mx <= 492.5 - 2.5 - BALL_RADIUS) {
        
        // Update the made variable
        made = 1;
        
      }
      
    }
    
    // Decrement the wrist angle
    w -= 30;
    
    // If the wrist angle is less than 0, set it to 0
    if (w < 0) {
      
      // Set the wrist angle to 0
	  w = 0;
      
    }
    
    // Update the angle of the ball
    r += 112.79;
    
  }
  
  // Erase the last frame
  drawBackground();
  
  // Draw the power meter at the given power
  drawPower(sh.p);
  
  // Draw the angle meter at the given angle
  drawAngle(sh.a - 90);
  
  // Draw the given player at the defined joint angles
  drawPlayer(&pl, 25, HEIGHT, A, K, S, E, w, 0, b);
  
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
    
  }
  
  // If the ball goes past the rightmost point, set its x position to the rightmost point
  if (b->x > WIDTH - BALL_RADIUS) {
    
    // Set the ball's x position to the rightmost point
    b->x = WIDTH - BALL_RADIUS;
    
  }
  
  // If the ball goes past the bottommost point, set its y position to the bottommost point
  if (b->y > HEIGHT - BALL_RADIUS) {
    
    // Set the ball's y position to the bottommost point
	b->y = HEIGHT - BALL_RADIUS;
    
  }
  
  // Draw the ball at its rotation angle
  drawBall(b, r);
  
  // Draw the given hoop
  drawHoop(&h, 535, HEIGHT);
  
  // Update the graphics window
  graphics_update();
  
  // Return whether or not the shot was made
  return made;
  
}