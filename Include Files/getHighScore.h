// Define a function that gets the high score from a given file
int getHighScore(char* fileName) {
  
  // Declare a variable to hold the high score
  int high;
  
  // Declare a variable to hold the unnecessary intials
  char burn[4];
  
  // Declare a file variable for input
  FILE* inFile = NULL;
  
  // Open the given file in read mode
  inFile = fopen(fileName, "r");
  
  // If the given file was opened and has data, return the high score
  if (inFile != NULL && fscanf(inFile, "%s %d", burn, &high) == 2) {
    
    // Close the input file
    fclose(inFile);
  
    // Return the high score
    return high;
    
  }
  
  // If the given file was not opened or did not have data, return 0
  else {
    
    // Close the input file
    fclose(inFile);
  
    // Return the high score
    return high;
    
  }
  
}