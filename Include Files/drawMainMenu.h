// Define a function to draw the title
void drawTitle() {
  
  // Erase the previous frame
  drawBackground();
  
  // Define a constant to hold the width of the characters
  const int LETTER_WIDTH = 20; 
  
  // Define constants to hold the positions of each of the characters
  const int P1_X = 10;
  const int TOP_Y = 50; 
  const int O1_X = P1_X + (3 * LETTER_WIDTH) - 17;
  const int P2_X = O1_X + (4 * LETTER_WIDTH) - 5;
  const int DASH1_X = P2_X + (3 * LETTER_WIDTH) - 8;
  const int A_X = DASH1_X + (2 * LETTER_WIDTH) - 6;
  const int DASH2_X = A_X + ((23.0 / 6.0) * LETTER_WIDTH) - 1 - 6;
  const int S_X = DASH2_X + (2 * LETTER_WIDTH) - 8;
  const int H_X = S_X + (4 * LETTER_WIDTH) - 10;
  const int O2_X = H_X + (3 * LETTER_WIDTH) - 5;
  const int T_X = O2_X + (4 * LETTER_WIDTH) - 15;
  
  // Draw the first O
  drawO(O1_X, TOP_Y, LETTER_WIDTH, 255, 255, 255, 0, 0, 0);
  
  // Draw the first P
  drawP(P1_X, TOP_Y, LETTER_WIDTH, 255, 255, 255, 0, 0, 0);
  
  // Draw the second P
  drawP(P2_X, TOP_Y, LETTER_WIDTH, 255, 255, 255, 0, 0, 0);
  
  // Draw the A
  drawA(A_X, TOP_Y, LETTER_WIDTH, 255, 255, 255, 0, 0, 0);
  
  // Draw the first dash
  drawDash(DASH1_X, TOP_Y, LETTER_WIDTH, 255, 255, 255, 0, 0, 0);
  
  // Draw the second O
  drawO(O2_X, TOP_Y, LETTER_WIDTH, 255, 255, 255, 0, 0, 0);
  
  // Draw the H
  drawH(H_X, TOP_Y, LETTER_WIDTH, 255, 255, 255, 0, 0, 0);
  
  // Draw the T
  drawT(T_X, TOP_Y, LETTER_WIDTH, 255, 255, 255, 0, 0, 0);
  
  // Draw the S
  drawS(S_X, TOP_Y, LETTER_WIDTH, 255, 255, 255, 0, 0, 0);
  
  // Draw the second dash
  drawDash(DASH2_X, TOP_Y, LETTER_WIDTH, 255, 255, 255, 0, 0, 0);
  
}

// Define a function that draws the main menu and returns the selection
int drawMainMenu() {
  
  // Draw the title
  drawTitle();
  
  // Define a constant to hold the scale of text on the main menu
  const double SCALE = 3.0;
  
  // Define a constant to hold the position of the best of ten option
  const int BOT_Y = 250;
  
  // Define a constant to hold the position of the timed option
  const int TIMED_Y = BOT_Y + (10 * SCALE) + 10;
  
  // Define a constant to hold the position of the options option
  const int OPTIONS_Y = TIMED_Y + (10 * SCALE) + 50;
  
  // Define a constant to hold the position of the quit option
  const int QUIT_Y = OPTIONS_Y + (10 * SCALE) + 10;
  
  // Define constants to hold the rgb values of normal text
  const int NORMAL_R = 0;
  const int NORMAL_G = 0;
  const int NORMAL_B = 0;
  
  // Define constants to hold the rgb values of highlighted text
  const int HIGHLIGHT_R = 255;
  const int HIGHLIGHT_G = 255;
  const int HIGHLIGHT_B = 255;
  
  // Define a variable to hold the user's selection
  int selector = 0;
  
  // While the space bar is not pressed, draw the main menu
  while (get_key_state(KeySpace) == 0) {
    
    // If the up key is pressed, update the selection
    if (get_key_state(KeyUp) != 0) {
      
      // Decrement the selection
      --selector;
      
      // If the selection goes past best of ten, change it to quit
      if (selector < 0) {
        
        // Change the selection to quit
        selector = 3;
        
      }
      
      // Delay 0.1 seconds to prevent accidental multiple inputs
      delay(0.1);
      
    }
    
    // If the down key is pressed, update the selection
    if (get_key_state(KeyDown) != 0) {
      
      // Increment the selection
      ++selector;
      
      // If the selection goes past quit, change it to best of ten
      if (selector > 3) {
        
        // Change the selection to best of ten
		selector = 0;
        
      }
      
      // Delay 0.1 seconds to prevent accidental multiple inputs
      delay(0.1);
      
    }
    
    // If best of ten is selected, draw it highlighted
    if (selector == 0) {
      
      // Draw the best of ten option highlighted
      g_printString("BEST-OF-TEN", (WIDTH / 2) - ((SCALE * 7 * 11) / 2), BOT_Y, HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B, SCALE);
      
      // Draw the timed option
      g_printString("TIMED", (WIDTH / 2) - ((SCALE * 7 * 5) / 2), TIMED_Y, NORMAL_R, NORMAL_G, NORMAL_B, SCALE);
      
      // Draw the options option
      g_printString("OPTIONS", (WIDTH / 2) - ((SCALE * 7 * 7) / 2), OPTIONS_Y, NORMAL_R, NORMAL_G, NORMAL_B, SCALE);
      
      // Draw the quit option
      g_printString("QUIT", (WIDTH / 2) - ((SCALE * 7 * 4) / 2), QUIT_Y, NORMAL_R, NORMAL_G, NORMAL_B, SCALE);
      
    }
    
    // If timed is selected, draw it highlighted
    else if (selector == 1) {
      
      // Draw the best of ten option
      g_printString("BEST-OF-TEN", (WIDTH / 2) - ((SCALE * 7 * 11) / 2), BOT_Y, NORMAL_R, NORMAL_G, NORMAL_B, SCALE);
      
      // Draw the timed option highlighted
      g_printString("TIMED", (WIDTH / 2) - ((SCALE * 7 * 5) / 2), TIMED_Y, HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B, SCALE);
      
      // Draw the options option
      g_printString("OPTIONS", (WIDTH / 2) - ((SCALE * 7 * 7) / 2), OPTIONS_Y, NORMAL_R, NORMAL_G, NORMAL_B, SCALE);
      
      // Draw the quit option
      g_printString("QUIT", (WIDTH / 2) - ((SCALE * 7 * 4) / 2), QUIT_Y, NORMAL_R, NORMAL_G, NORMAL_B, SCALE);
      
    }
    
    // If options is selected, draw it highlighted
    else if (selector == 2) {
      
      // Draw the best of ten option
      g_printString("BEST-OF-TEN", (WIDTH / 2) - ((SCALE * 7 * 11) / 2), BOT_Y, NORMAL_R, NORMAL_G, NORMAL_B, SCALE);
      
      // Draw the timed option
      g_printString("TIMED", (WIDTH / 2) - ((SCALE * 7 * 5) / 2), TIMED_Y, NORMAL_R, NORMAL_G, NORMAL_B, SCALE);
      
      // Draw the options option highlighted
      g_printString("OPTIONS", (WIDTH / 2) - ((SCALE * 7 * 7) / 2), OPTIONS_Y, HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B, SCALE);
      
      // Draw the quit option
      g_printString("QUIT", (WIDTH / 2) - ((SCALE * 7 * 4) / 2), QUIT_Y, NORMAL_R, NORMAL_G, NORMAL_B, SCALE);
      
    }
    
    // If quit is selected, draw it highlighted
    else {
      
      // Draw the best of ten option
	  g_printString("BEST-OF-TEN", (WIDTH / 2) - ((SCALE * 7 * 11) / 2), BOT_Y, NORMAL_R, NORMAL_G, NORMAL_B, SCALE);
      
      // Draw the timed option
      g_printString("TIMED", (WIDTH / 2) - ((SCALE * 7 * 5) / 2), TIMED_Y, NORMAL_R, NORMAL_G, NORMAL_B, SCALE);
      
      // Draw the options option
      g_printString("OPTIONS", (WIDTH / 2) - ((SCALE * 7 * 7) / 2), OPTIONS_Y, NORMAL_R, NORMAL_G, NORMAL_B, SCALE);
      
      // Draw the quit option highlighted
      g_printString("QUIT", (WIDTH / 2) - ((SCALE * 7 * 4) / 2), QUIT_Y, HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B, SCALE);
      
    }
    
    // Update the graphics window
    graphics_update();
    
  }
  
  // Update the graphics window
  graphics_update();
  
  // Return the selection
  return selector;
  
}