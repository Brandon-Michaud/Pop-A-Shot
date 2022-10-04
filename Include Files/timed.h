#define TOTAL_SEC 15

// Define a function to control the timed game mode
void timed(hoop h, ball b, player pl) {
  
  // Define a variable to hold whether or not the user wishes to play again
  int playAgain = 1;
  
  // While the user wishes to play again, operate the timed game mode
  while (playAgain == 1) {
    
    // Declare a shot counter and timer
    shotCounter sc;
    timer t;
    
    // Initialize the elapsed seconds to 0
    t.sec = 0;
    
    // Define the total seconds
    t.totalSec = TOTAL_SEC;
    
    // Initialize the made shots to 0
    sc.madeShots = 0;
    
    // Set the game mode to timed
    sc.mode = 2;
    
    // Set the high score
    sc.high = getHighScore("timedScores.txt");
    
    // Declare an array of shots
    shot shots[100];

    // Get the processor time
    clock_t start = clock();
    
    // Define the start time
    t.begin = start;
    
    // Get the processsor time
    clock_t end = clock();
    
    // Declare variables to hold whether or not the shot was made and released
    int made, release;
    
    // Define a variable to iterate through the array of shots
    int i = 0;
    
    // While the timer has not expired, get the angle and power of the shot and draw the shot
    while ((double)(end - start) / CLOCKS_PER_SEC < TOTAL_SEC) {
      
      // Initialize the angle and power of the shot to be 0
      shots[i].a = 0;
      shots[i].p = 0;
      
      // Get the angle of the shot
      shots[i].a = animateAngle(shots[i].p, sc, t, h, b, pl);
      
      // If time expired while getting the angle, stop the game mode
      if (shots[i].a == -69) {
        
        // Stop the game mode
        break;
        
      }
      
      // Delay 0.1 seconds to prevent accidental multiple inputs
      delay(0.1);
      
      // Get the power of the shot
      shots[i].p = animatePower(shots[i].a, sc, t, h, b, pl);
      
      // If time expired while getting the power, stop the game mode
      if (shots[i].p == -69) {
        
        // Stop the game mode
        break;
        
      }
      
      // Animate the given player's shot motion and capture whether or not the ball was released
      release = animatePlayer(&pl, 25, HEIGHT, &b, &h, sc, t, shots[i]);
      
      // If the ball was released, draw the shot
      if (release == 1) {
        
        // Draw the shot and capture whether or not it was made
        made = drawShot(shots[i], sc, t, h, &b, pl);
        
        // If the shot was made, increment the made shots
        if (made == 1) {
          
          // Increment the made shots
          ++sc.madeShots;
          
        }
        
      }
      
      // Get the processor time
      end = clock();
      
    }
    
    // Delay 0.5 second to show user how close shot was to releasing
    delay(0.5);
    
    // Declare and define a user object
    user person;
    person.score = sc.madeShots;
    
    // Draw the leaderboard with the user object and capture whether or not the user wishes to play again
    playAgain = drawLeaderboard("timedScores.txt", person);
    
    // Delay 0.1 seconds to prevent accidental multiple inputs
    delay(0.1);
    
  }
  
}