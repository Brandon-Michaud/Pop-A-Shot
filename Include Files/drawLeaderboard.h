// Define a struct to represent a user
typedef struct user_struct {
  
  // Declare a variable to hold the score
  int score;
  
  // Declare a variable to hold the initials
  char initials[4];
  
  // Declare a variable to hold whether or not the score should be highlighted
  int highlight;
  
} user;

// Define a function to sort a given array of users of a given number of users
void sort(user scores[], int numScores) {  
  
  // Declare variables for probing the array
  int i, j;  
  
  // For each user after the first in the array, perform the necessary swaps
  for (i = 1; i < numScores; ++i) {
    
    // Define the second probing variable to start from the current value of the first
    j = i;
    
    // Swap the values until the sub-array is sorted
    while (j > 0 && scores[j].score > scores[j - 1].score) { 
      
      // Swap the values if they are unsorted
      user temp = scores[j];
      scores[j] = scores[j - 1];
      scores[j - 1] = temp;
      
      // Change the index in the sub-array
      --j;      
      
    }    
    
  }  
  
}

// Define a function to count the number of digits in a given number
int numDigits(int n) {
  
  // Define the number of digits to initially be 0
  int num = 0;
  
  // If the given number is 0, return 1
  if (n == 0) {
    
	return 1;
    
  }
  
  // Divide by ten until the number is 0
  while (n != 0) {
    
    // Divide the number by 10
	n = n / 10;
    
    // Increment the number of digits
    ++num;
    
  }
  
  // Return the number of digits
  return num;
  
}

// Define a function to draw the leaderboard given a file name and a user
int drawLeaderboard(char* fileName, user person) {
  
  // Declare an array of users
  user scores[11];
  
  // Declare a file for input
  FILE* inFile = NULL;
  
  // Open the given file name in read mode
  inFile = fopen(fileName, "r");
  
  // Declare a variable to hold the read initials
  char buffer[4];
  
  // Declare a variable to hold the read score
  int holder;
  
  // Define a variable to hold the index in the user array
  int i = 0;
  
  // If the input file is open, capture its data
  if (inFile != NULL) {
    
    // While the input file has data, capture and store it
    while (fscanf(inFile, "%s %d", buffer, &holder) == 2 && i < 10) {
      
      // Store the data from the current line into the user array
      strcpy(scores[i].initials, buffer);
      scores[i].score = holder;
      scores[i].highlight = 0;
      
      // Increment the index in the user array
      ++i;
      
    }  
    
  }
  
  // Close the input file
  fclose(inFile);
  
  // Define the number of users in the array
  int numScores = i;
  
  // Sort the user array
  sort(scores, numScores);
  
  // If the given user should be in the array, add it
  if (person.score > scores[numScores - 1].score || numScores < 10) {
    
    // Prompt the user to enter their initials
	printf("\nEnter your initials to save score\n");
    
    // Capture and store the user-entered initials
    scanf("%s", person.initials);
    
    // Indicate that the score should be highlighted
    person.highlight = 1;
    
    // Add the given user to the user array
    scores[numScores] = person;
    
    // Increment the number of scores
    ++numScores;
    
  }
  
  // Sort the user array
  sort(scores, numScores);
  
  // Declare a variable for output
  FILE* outFile = NULL;
  
  // Open the given file name in write mode
  outFile = fopen(fileName, "w");
  
  // Define a variable to iterate through the user array
  i = 0;
  
  // Write the top ten, or the number of users if less than ten total users, to the output file 
  while (i < 10 && i < numScores) {
    
    // Write the initials and score of the current user to the output file
    fprintf(outFile, "%s %d\n", scores[i].initials, scores[i].score);
    
    // Increment the user array index
    ++i;
    
  }
  
  // Close the output file
  fclose(outFile);
  
  // Define constants to hold the rgb values of normal text
  const int NORMAL_R = 0;
  const int NORMAL_G = 0;
  const int NORMAL_B = 0;
  
  // Define constants to hold the rgb values of highlighted text
  const int HIGHLIGHT_R = 255;
  const int HIGHLIGHT_G = 255;
  const int HIGHLIGHT_B = 255;
  
  // Define constants to hold the positon and scale of the title
  const int TITLE_X = WIDTH / 2;
  const int TITLE_Y = 50;
  const int TITLE_SCALE = 3.0;
  
  // Define a constant to hold the normal scale
  const int NORMAL_SCALE = 2.0;
  
  // Define constants to hold the positions of the scores
  const int SCORES_X = TITLE_X;
  const int SCORES_Y = (TITLE_SCALE * 10) + 10 + TITLE_Y;
  
  // Define constants to hold the x position of each column
  const int COLUMN1 = SCORES_X - (7 * NORMAL_SCALE * 2.5);
  const int COLUMN2 = SCORES_X - (3.5 * NORMAL_SCALE * 3);
  const int COLUMN3 = COLUMN2 + (7 * NORMAL_SCALE * 5.5);
  
  // Define a constant to hold the space inbetween scores
  const int SPACING = (10 * NORMAL_SCALE) + 2;
  
  // Define constants to hold the positon of the play again prompt
  const int PLAY_AGAIN_X = TITLE_X;
  const int PLAY_AGAIN_Y = (10 * SPACING) + SCORES_Y + 50;
  
  // Define a constant to hold the y position of the yes button
  const int YES_Y = PLAY_AGAIN_Y + (10 * TITLE_SCALE) + 10;
  
  // Define a constant to hold the y position of the no button
  const int NO_Y = YES_Y + (10 * NORMAL_SCALE) + 2;
  
  // Define a variable to hold whether or not the user wished to play again
  int selection = 1;
  
  // While the space bar is not pressed
  while (get_key_state(KeySpace) == 0) {
    
    // Erase the previous frame
    drawBackground();
    
    // Draw the leaderboard title
    g_printString("LEADERBOARD", TITLE_X - (11 * TITLE_SCALE * 3.5) + ((TITLE_SCALE * 3) / 2), TITLE_Y, 
                  NORMAL_R, NORMAL_G, NORMAL_B, TITLE_SCALE);
    
    // If the up key is pressed, switch the selection
    if (get_key_state(KeyUp) != 0) {
      
      // Increment the selection
	  ++selection;
      
      // If the selection went past yes, change it to no
      if (selection > 1) {
        
        // Change the selection to no
		selection = 0;
        
      }
      
      // Delay 0.1 seconds to prevent accidental multiple inputs
      delay(0.1);
      
    }
    
    // If the down key is pressed, switch the selection
    if (get_key_state(KeyDown) != 0) {
      
      // Decrement the selection
      --selection;
      
      // If the selection went past no, change it to yes
      if (selection < 0) {
        
        // Change the selection to yes
		selection = 1;
        
      }
      
      // Delay 0.1 seconds to prevent accidental multiple inputs
      delay(0.1);
      
    }
    
    // Define a variable to hold the index in the user array
    i = 0;
    
    // Draw the top ten, or the number of users if less than ten total users, users 
    while (i < 10 && i < numScores) {
      
      // If the user is supposed to be highlighted, highlight it
      if (scores[i].highlight == 0) {
        
        // Draw the rank of the user
        g_printInt(i + 1, 0, COLUMN1 - (7 * NORMAL_SCALE * numDigits(i + 1)), SCORES_Y + (i * SPACING), 
                   NORMAL_R, NORMAL_G, NORMAL_B, NORMAL_SCALE);
        
        // Draw the initials of the user
        g_printString(scores[i].initials, COLUMN2, SCORES_Y + (i * SPACING), NORMAL_R, NORMAL_G, NORMAL_B, NORMAL_SCALE);
        
        // Draw the score of the user
        g_printInt(scores[i].score, 1, COLUMN3 - (7 * NORMAL_SCALE * numDigits(scores[i].score)), SCORES_Y + (i * SPACING), 
                   NORMAL_R, NORMAL_G, NORMAL_B, NORMAL_SCALE);
        
      }
      
      // If the user is not supposed to be highlighted, draw it normally
      else {
        
        // Draw the rank of the user
        g_printInt(i + 1, 0, COLUMN1 - (7 * NORMAL_SCALE * numDigits(i + 1)), SCORES_Y + (i * SPACING), 
                   HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B, NORMAL_SCALE);
        
        // Draw the initials of the user
        g_printString(scores[i].initials, COLUMN2, SCORES_Y + (i * SPACING), HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B, NORMAL_SCALE);
        
        // Draw the score of the user
        g_printInt(scores[i].score, 1, COLUMN3 - (7 * NORMAL_SCALE * numDigits(scores[i].score)), SCORES_Y + (i * SPACING), 
                   HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B, NORMAL_SCALE);
        
      }
      
      // Increment the index of the user array
      ++i;
      
    }
    
    // Draw the play again prompt
    g_printString("PLAY AGAIN?", PLAY_AGAIN_X - (11 * TITLE_SCALE * 3.5) + ((TITLE_SCALE * 3) / 2), PLAY_AGAIN_Y, 
                  NORMAL_R, NORMAL_G, NORMAL_B, TITLE_SCALE);
    
    // If the user has selected yes, highlight yes
    if (selection == 1) {
      
      // Draw yes highlighted
	  g_printString("YES", PLAY_AGAIN_X - (3 * NORMAL_SCALE * 3.5) + ((NORMAL_SCALE * 3) / 2), YES_Y, 
                    HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B, NORMAL_SCALE);
      
      // Draw no
      g_printString("NO", PLAY_AGAIN_X - (2 * NORMAL_SCALE * 3.5) + ((NORMAL_SCALE * 3) / 2), NO_Y,
                    NORMAL_R, NORMAL_G, NORMAL_B, NORMAL_SCALE);
      
    }
    
    // If the user has selected no, highlight no
    else {
      
      // Draw yes
	  g_printString("YES", PLAY_AGAIN_X - (3 * NORMAL_SCALE * 3.5) + ((NORMAL_SCALE * 3) / 2), YES_Y, 
                    NORMAL_R, NORMAL_G, NORMAL_B, NORMAL_SCALE);
      
      // Draw no highlighted
      g_printString("NO", PLAY_AGAIN_X - (2 * NORMAL_SCALE * 3.5) + ((NORMAL_SCALE * 3) / 2), NO_Y,
                    HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B, NORMAL_SCALE);
      
    }
    
    // Update the graphics window
    graphics_update();
    
  }
  
  // Return the user's selection
  return selection;
  
}