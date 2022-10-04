#define NUM_SHOTS 10

// Define a function that operates the best of ten game mode
void bestOfTen(hoop h, ball b, player pl) {
  
  // Define a variable to hold whether the user wished to play again or not
  int playAgain = 1;
  
  // While the user wishes to play again, play the best of ten game mode
  while (playAgain == 1) {
    
    // Declare a shot counter and timer
    shotCounter sc;
    timer t;
    
    // Update the total number of shots
    sc.totalShots = NUM_SHOTS;
    
    // Initialize the made shots
    sc.madeShots = 0;
    
    // Initialize the taken shots
    sc.takenShots = 1;
    
    // Set the game mode to best of ten
    sc.mode = 1;
    
    // Set the high score
    sc.high = getHighScore("bestOfTenScores.txt");
    
    // Declare an array of shots
    shot shots[NUM_SHOTS];
    
    // Declare variables to hold the index in the shot array, whether the shot was made, and whether the shot was released
    int i, made, release;
    
    // Initialize the angle and power of every shot in the shot array
    for (i = 0; i < NUM_SHOTS; ++i) {
      
      // Set the angle and power to 0
      shots[i].a = 0;
      shots[i].p = 0;
      
    }
    
    // Get the angle and power for each shot and draw it
    for (i = 0; i < NUM_SHOTS; ++i) {
      
      // Get the angle for the shot
      shots[i].a = animateAngle(shots[i].p, sc, t, h, b, pl);
      
      // Add a 0.1 second delay to prevent accidental multiple inputs
      delay(0.1);
      
      // Get the power for the shot
      shots[i].p = animatePower(shots[i].a, sc, t, h, b, pl);
      
      // Animate the shooting motion for the given player and store whether the shot was released
      release = animatePlayer(&pl, 25, HEIGHT, &b, &h, sc, t, shots[i]);
      
      // If the shot was released, draw it
      if (release == 1) {
        
        // Draw the shot and store whether or not it was made
        made = drawShot(shots[i], sc, t, h, &b, pl);
        
        // If the shot was made, increment the made shots
        if (made == 1) {
          
          // Increment the made shots
          ++sc.madeShots;
          
        }
        
      }
      
      // Increment the taken shots
      ++sc.takenShots;
      
    }
    
    // Draw the score
    drawScore(sc);
    
    // Update the graphics window
    graphics_update();
    
    // Declare and define a user object
    user person;
    person.score = sc.madeShots;
    
    // Draw the leaderboard with the user object and capture whether or not the user wishes to play again
    playAgain = drawLeaderboard("bestOfTenScores.txt", person);
    
    // Add a 0.1 second delay to prevent accidental multiple inputs
    delay(0.1);
    
  }
  
}