// Define a function that draws and controls the options menu
void options(hoop* h, ball* b, player* pl) {
  
  // Declare an array of colors
  rgb colors[100];
  
  // Populate the array with colors
  getColors(colors);
  
  // Define a variable to hold whether or not the user wishes to go back
  int back = 0;
  
  // Define a variable to hold the object in question
  int object = 0;
  
  // Define a variable to hold the selection
  int selection = 0;
  
  // Define constants to hold the position of object title and its scale
  const int OBJECT_X = (WIDTH / 2);
  const int OBJECT_Y = 25;
  const double OBJECT_SCALE = 2.0;
  
  // Define a constant to hold the normal text scale
  const double ITEM_SCALE = 2.0;
  
  // Define constants to hold the position of the first column
  const int COLUMN1_X = OBJECT_X - (13 * ITEM_SCALE * 7) + (4.5 * ITEM_SCALE * 7);
  const int COLUMN1_Y = OBJECT_Y + (10 * OBJECT_SCALE * 2);
  
  // Define constants to hold the position of the second column
  const int COLUMN2_X = OBJECT_X + (5.5 * ITEM_SCALE) * 7;
  const int COLUMN2_Y = COLUMN1_Y;
  
  // Define a constant to hold the space inbetween lines
  const int SPACING = (10 * ITEM_SCALE) + 10;
  
  // Define constants to hold the position of the back button
  const int BACK_X = OBJECT_X;
  const int BACK_Y = COLUMN1_Y + (SPACING * 5);
  
  // Define constants to hold the rgb values of normal text
  const int NORMAL_R = 0;
  const int NORMAL_G = 0;
  const int NORMAL_B = 0;
  
  // Define constants to hold the rgb values of highlighted text
  const int HIGHLIGHT_R = 255;
  const int HIGHLIGHT_G = 255;
  const int HIGHLIGHT_B = 255;
  
  // While the user does not wish to go back, draw the options menu
  while (back == 0) {
    
    // Erase the previous frame
    drawBackground();
    
    // Draw the given player and ball objects
    drawPlayerBottom(pl, 25, HEIGHT, b);
    
    // Draw the given hoop object
    drawHoop(h, 535, HEIGHT);
    
    // If the current object is the player, display the player items
	if (object == 0) {
      
      // Draw the skin item
      g_printString("SKIN", COLUMN1_X - (7 * ITEM_SCALE * 2) + ((ITEM_SCALE * 3) / 2), COLUMN1_Y,
                    NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
      
      // Draw the shirt item
      g_printString("SHIRT", COLUMN1_X - (7 * ITEM_SCALE * 2.5) + ((ITEM_SCALE * 3) / 2), COLUMN1_Y + SPACING,
                    NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
      
      // Draw the pants item
      g_printString("PANTS", COLUMN1_X - (7 * ITEM_SCALE * 2.5) + ((ITEM_SCALE * 3) / 2), COLUMN1_Y + (2 * SPACING),
                    NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
      
      // Draw the shoes item
      g_printString("SHOES", COLUMN1_X - (7 * ITEM_SCALE * 2.5) + ((ITEM_SCALE * 3) / 2), COLUMN1_Y + (3 * SPACING),
                    NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
      
      // If the current selection is the object, highlight the object
      if (selection == 0) {
        
        // Draw the object highlighted
        g_printString("PLAYER", OBJECT_X - (7 * OBJECT_SCALE * 3) + ((OBJECT_SCALE * 3) / 2), OBJECT_Y, 
                      HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B, OBJECT_SCALE);
        
        // Draw two triangles to indicate the object can be changed
        graphics_triangle_fill(OBJECT_X - (7 * OBJECT_SCALE * 4), OBJECT_Y - OBJECT_SCALE, 
                               OBJECT_X - (7 * OBJECT_SCALE * 4), OBJECT_Y + (10 * OBJECT_SCALE),
                               OBJECT_X - (7 * OBJECT_SCALE * 5), OBJECT_Y - OBJECT_SCALE + ((10 * OBJECT_SCALE) / 2), 
                               HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B);
        graphics_triangle_fill(OBJECT_X + (7 * OBJECT_SCALE * 4), OBJECT_Y - OBJECT_SCALE, 
                               OBJECT_X + (7 * OBJECT_SCALE * 4), OBJECT_Y + (10 * OBJECT_SCALE),
                               OBJECT_X + (7 * OBJECT_SCALE * 5), OBJECT_Y - OBJECT_SCALE + ((10 * OBJECT_SCALE) / 2), 
                               HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B);
        
        // Draw the skin item color
        g_printString(pl->skin.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(pl->skin.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y, NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the skin item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE, 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE, 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the shirt item color
        g_printString(pl->shirt.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(pl->shirt.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + SPACING, NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the shirt item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the pants item color
        g_printString(pl->pants.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(pl->pants.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + (2 * SPACING), NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the pants item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 2),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 2),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the shoes item color
        g_printString(pl->shoes.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(pl->shoes.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + (3 * SPACING), NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the shoes item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 3),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 3),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the back button
        g_printString("BACK", BACK_X - (7 * OBJECT_SCALE * 2) + ((OBJECT_SCALE * 3) / 2), BACK_Y, 
                      NORMAL_R, NORMAL_G, NORMAL_B, OBJECT_SCALE);
        
      }
      
      // If the current selection is the skin item, highlight the skin color
      else if (selection == 1) {
        
        // Draw the object
        g_printString("PLAYER", OBJECT_X - (7 * OBJECT_SCALE * 3) + ((OBJECT_SCALE * 3) / 2), OBJECT_Y, 
                      NORMAL_R, NORMAL_G, NORMAL_B, OBJECT_SCALE);
        
        // Draw two triangles to indicate the object can be changed
        graphics_triangle_fill(OBJECT_X - (7 * OBJECT_SCALE * 4), OBJECT_Y - OBJECT_SCALE, 
                               OBJECT_X - (7 * OBJECT_SCALE * 4), OBJECT_Y + (10 * OBJECT_SCALE),
                               OBJECT_X - (7 * OBJECT_SCALE * 5), OBJECT_Y - OBJECT_SCALE + ((10 * OBJECT_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(OBJECT_X + (7 * OBJECT_SCALE * 4), OBJECT_Y - OBJECT_SCALE, 
                               OBJECT_X + (7 * OBJECT_SCALE * 4), OBJECT_Y + (10 * OBJECT_SCALE),
                               OBJECT_X + (7 * OBJECT_SCALE * 5), OBJECT_Y - OBJECT_SCALE + ((10 * OBJECT_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the skin item color highlighted
        g_printString(pl->skin.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(pl->skin.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y, HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B, ITEM_SCALE);
        
        // Draw two highlighted triangles to indicate the skin item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE, 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + ((10 * ITEM_SCALE) / 2), 
                               HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE, 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + ((10 * ITEM_SCALE) / 2), 
                               HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B);
        
        // Draw the shirt item color
        g_printString(pl->shirt.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(pl->shirt.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + SPACING, NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the shirt item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the pants items color
        g_printString(pl->pants.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(pl->pants.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + (2 * SPACING), NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the pants item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 2),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 2),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the shoes item color
        g_printString(pl->shoes.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(pl->shoes.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + (3 * SPACING), NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the shoes item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 3),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 3),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the back button
        g_printString("BACK", BACK_X - (7 * OBJECT_SCALE * 2) + ((OBJECT_SCALE * 3) / 2), BACK_Y, 
                      NORMAL_R, NORMAL_G, NORMAL_B, OBJECT_SCALE);
        
      }
      
      // If the current selection is the shirt item, highlight the shirt color
      else if (selection == 2) {
        
        // Draw the object
        g_printString("PLAYER", OBJECT_X - (7 * OBJECT_SCALE * 3) + ((OBJECT_SCALE * 3) / 2), OBJECT_Y, 
                      NORMAL_R, NORMAL_G, NORMAL_B, OBJECT_SCALE);
        
        // Draw two triangles to indicate the object can be changed
        graphics_triangle_fill(OBJECT_X - (7 * OBJECT_SCALE * 4), OBJECT_Y - OBJECT_SCALE, 
                               OBJECT_X - (7 * OBJECT_SCALE * 4), OBJECT_Y + (10 * OBJECT_SCALE),
                               OBJECT_X - (7 * OBJECT_SCALE * 5), OBJECT_Y - OBJECT_SCALE + ((10 * OBJECT_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(OBJECT_X + (7 * OBJECT_SCALE * 4), OBJECT_Y - OBJECT_SCALE, 
                               OBJECT_X + (7 * OBJECT_SCALE * 4), OBJECT_Y + (10 * OBJECT_SCALE),
                               OBJECT_X + (7 * OBJECT_SCALE * 5), OBJECT_Y - OBJECT_SCALE + ((10 * OBJECT_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the skin item color
        g_printString(pl->skin.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(pl->skin.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y, NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the skin item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE, 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE, 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the shirt item color highlighted
        g_printString(pl->shirt.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(pl->shirt.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + SPACING, HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B, ITEM_SCALE);
        
        // Draw two highlighted triangles to indicate the skin item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING) + ((10 * ITEM_SCALE) / 2), 
                               HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING) + ((10 * ITEM_SCALE) / 2), 
                               HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B);
        
        // Draw the pants item color
        g_printString(pl->pants.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(pl->pants.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + (2 * SPACING), NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the pants item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 2),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 2),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the shoes item color
        g_printString(pl->shoes.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(pl->shoes.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + (3 * SPACING), NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the shoes item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 3),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 3),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the back button
        g_printString("BACK", BACK_X - (7 * OBJECT_SCALE * 2) + ((OBJECT_SCALE * 3) / 2), BACK_Y, 
                      NORMAL_R, NORMAL_G, NORMAL_B, OBJECT_SCALE);
        
      }
      
      // If the current selection is the pants item, highlight the pants color
      else if (selection == 3) {
        
        // Draw the object
        g_printString("PLAYER", OBJECT_X - (7 * OBJECT_SCALE * 3) + ((OBJECT_SCALE * 3) / 2), OBJECT_Y, 
                      NORMAL_R, NORMAL_G, NORMAL_B, OBJECT_SCALE);
        
        // Draw two triangles to indicate the object can be changed
        graphics_triangle_fill(OBJECT_X - (7 * OBJECT_SCALE * 4), OBJECT_Y - OBJECT_SCALE, 
                               OBJECT_X - (7 * OBJECT_SCALE * 4), OBJECT_Y + (10 * OBJECT_SCALE),
                               OBJECT_X - (7 * OBJECT_SCALE * 5), OBJECT_Y - OBJECT_SCALE + ((10 * OBJECT_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(OBJECT_X + (7 * OBJECT_SCALE * 4), OBJECT_Y - OBJECT_SCALE, 
                               OBJECT_X + (7 * OBJECT_SCALE * 4), OBJECT_Y + (10 * OBJECT_SCALE),
                               OBJECT_X + (7 * OBJECT_SCALE * 5), OBJECT_Y - OBJECT_SCALE + ((10 * OBJECT_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the skin item color
        g_printString(pl->skin.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(pl->skin.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y, NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the skin item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE, 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE, 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the shirt item color
        g_printString(pl->shirt.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(pl->shirt.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + SPACING, NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the shirt item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the pants item color highlighted
        g_printString(pl->pants.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(pl->pants.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + (2 * SPACING), HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B, ITEM_SCALE);
        
        // Draw two highlighted triangles to indicate the skin item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 2),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2) + ((10 * ITEM_SCALE) / 2), 
                               HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 2),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2) + ((10 * ITEM_SCALE) / 2), 
                               HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B);
        
        // Draw the shoes item color
        g_printString(pl->shoes.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(pl->shoes.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + (3 * SPACING), NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the shoes item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 3),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 3),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the back button
        g_printString("BACK", BACK_X - (7 * OBJECT_SCALE * 2) + ((OBJECT_SCALE * 3) / 2), BACK_Y, 
                      NORMAL_R, NORMAL_G, NORMAL_B, OBJECT_SCALE);
        
      }
      
      // If the current selection is the shoes item, highlight the shoes color
      else if (selection == 4) {
        
        // Draw the object
        g_printString("PLAYER", OBJECT_X - (7 * OBJECT_SCALE * 3) + ((OBJECT_SCALE * 3) / 2), OBJECT_Y, 
                      NORMAL_R, NORMAL_G, NORMAL_B, OBJECT_SCALE);
        
        // Draw two triangles to indicate the object can be changed
        graphics_triangle_fill(OBJECT_X - (7 * OBJECT_SCALE * 4), OBJECT_Y - OBJECT_SCALE, 
                               OBJECT_X - (7 * OBJECT_SCALE * 4), OBJECT_Y + (10 * OBJECT_SCALE),
                               OBJECT_X - (7 * OBJECT_SCALE * 5), OBJECT_Y - OBJECT_SCALE + ((10 * OBJECT_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(OBJECT_X + (7 * OBJECT_SCALE * 4), OBJECT_Y - OBJECT_SCALE, 
                               OBJECT_X + (7 * OBJECT_SCALE * 4), OBJECT_Y + (10 * OBJECT_SCALE),
                               OBJECT_X + (7 * OBJECT_SCALE * 5), OBJECT_Y - OBJECT_SCALE + ((10 * OBJECT_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the skin item color
        g_printString(pl->skin.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(pl->skin.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y, NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the skin item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE, 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE, 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the shirt item color
        g_printString(pl->shirt.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(pl->shirt.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + SPACING, NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the shirt item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the pants item color
        g_printString(pl->pants.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(pl->pants.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + (2 * SPACING), NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the pants item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 2),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 2),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the shoes item color highlighted
        g_printString(pl->shoes.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(pl->shoes.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + (3 * SPACING), HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B, ITEM_SCALE);
        
        // Draw two highlighted triangles to indicate the skin item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 3),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3) + ((10 * ITEM_SCALE) / 2), 
                               HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 3),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3) + ((10 * ITEM_SCALE) / 2), 
                               HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B);
        
        // Draw the back button
        g_printString("BACK", BACK_X - (7 * OBJECT_SCALE * 2) + ((OBJECT_SCALE * 3) / 2), BACK_Y, 
                      NORMAL_R, NORMAL_G, NORMAL_B, OBJECT_SCALE);
        
      }
      
      // If the current selection is back, highlight back
      else if (selection == 5) {
        
        // Draw the object
        g_printString("PLAYER", OBJECT_X - (7 * OBJECT_SCALE * 3) + ((OBJECT_SCALE * 3) / 2), OBJECT_Y, 
                      NORMAL_R, NORMAL_G, NORMAL_B, OBJECT_SCALE);
        
        // Draw two triangles to indicate the object can be changed
        graphics_triangle_fill(OBJECT_X - (7 * OBJECT_SCALE * 4), OBJECT_Y - OBJECT_SCALE, 
                               OBJECT_X - (7 * OBJECT_SCALE * 4), OBJECT_Y + (10 * OBJECT_SCALE),
                               OBJECT_X - (7 * OBJECT_SCALE * 5), OBJECT_Y - OBJECT_SCALE + ((10 * OBJECT_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(OBJECT_X + (7 * OBJECT_SCALE * 4), OBJECT_Y - OBJECT_SCALE, 
                               OBJECT_X + (7 * OBJECT_SCALE * 4), OBJECT_Y + (10 * OBJECT_SCALE),
                               OBJECT_X + (7 * OBJECT_SCALE * 5), OBJECT_Y - OBJECT_SCALE + ((10 * OBJECT_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the skin item color
        g_printString(pl->skin.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(pl->skin.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y, NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the skin item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE, 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE, 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the shirt item color
        g_printString(pl->shirt.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(pl->shirt.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + SPACING, NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the shirt item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the pants item color
        g_printString(pl->pants.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(pl->pants.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + (2 * SPACING), NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the pants item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 2),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 2),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the shoes item color
        g_printString(pl->shoes.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(pl->shoes.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + (3 * SPACING), NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the shoes item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 3),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 3),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the back button highlighted
        g_printString("BACK", BACK_X - (7 * OBJECT_SCALE * 2) + ((OBJECT_SCALE * 3) / 2), BACK_Y, 
                      HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B, OBJECT_SCALE);
        
      }
      
    }
    
    // If the current object is the ball, display the ball items
    else if (object == 1) {
      
      // Draw the ball item
      g_printString("BALL", COLUMN1_X - (7 * ITEM_SCALE * 2) + ((ITEM_SCALE * 3) / 2), COLUMN1_Y,
                    NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
      
      // Draw the seam item
      g_printString("SEAM", COLUMN1_X - (7 * ITEM_SCALE * 2) + ((ITEM_SCALE * 3) / 2), COLUMN1_Y + SPACING,
                    NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
      
      // If the current selection is the object, highlight the object
      if (selection == 0) {
        
        // Draw the object highlighed
        g_printString("BALL", OBJECT_X - (7 * OBJECT_SCALE * 2) + ((OBJECT_SCALE * 3) / 2), OBJECT_Y, 
                      HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B, OBJECT_SCALE);
        
        // Draw two highlighted triangles to indicate the object can be changed
        graphics_triangle_fill(OBJECT_X - (7 * OBJECT_SCALE * 4), OBJECT_Y - OBJECT_SCALE, 
                               OBJECT_X - (7 * OBJECT_SCALE * 4), OBJECT_Y + (10 * OBJECT_SCALE),
                               OBJECT_X - (7 * OBJECT_SCALE * 5), OBJECT_Y - OBJECT_SCALE + ((10 * OBJECT_SCALE) / 2), 
                               HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B);
        graphics_triangle_fill(OBJECT_X + (7 * OBJECT_SCALE * 4), OBJECT_Y - OBJECT_SCALE, 
                               OBJECT_X + (7 * OBJECT_SCALE * 4), OBJECT_Y + (10 * OBJECT_SCALE),
                               OBJECT_X + (7 * OBJECT_SCALE * 5), OBJECT_Y - OBJECT_SCALE + ((10 * OBJECT_SCALE) / 2), 
                               HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B);
        
        // Draw the ball item color
        g_printString(b->ball.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(b->ball.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y, NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the ball item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE, 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE, 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the seam item color
        g_printString(b->seam.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(b->seam.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + SPACING, NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the seam item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the back button
        g_printString("BACK", BACK_X - (7 * OBJECT_SCALE * 2) + ((OBJECT_SCALE * 3) / 2), BACK_Y, 
                      NORMAL_R, NORMAL_G, NORMAL_B, OBJECT_SCALE);
        
      }
      
      // If the current selection is the ball item, highlight the ball color
      else if (selection == 1) {
        
        // Draw the object
		g_printString("BALL", OBJECT_X - (7 * OBJECT_SCALE * 2) + ((OBJECT_SCALE * 3) / 2), OBJECT_Y, 
                      NORMAL_R, NORMAL_G, NORMAL_B, OBJECT_SCALE);
        
        // Draw two triangles to indicate the object can be changed
        graphics_triangle_fill(OBJECT_X - (7 * OBJECT_SCALE * 4), OBJECT_Y - OBJECT_SCALE, 
                               OBJECT_X - (7 * OBJECT_SCALE * 4), OBJECT_Y + (10 * OBJECT_SCALE),
                               OBJECT_X - (7 * OBJECT_SCALE * 5), OBJECT_Y - OBJECT_SCALE + ((10 * OBJECT_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(OBJECT_X + (7 * OBJECT_SCALE * 4), OBJECT_Y - OBJECT_SCALE, 
                               OBJECT_X + (7 * OBJECT_SCALE * 4), OBJECT_Y + (10 * OBJECT_SCALE),
                               OBJECT_X + (7 * OBJECT_SCALE * 5), OBJECT_Y - OBJECT_SCALE + ((10 * OBJECT_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the ball item color highlighted
        g_printString(b->ball.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(b->ball.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y, HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B, ITEM_SCALE);
        
        // Draw two highlighed triangles to indicate the ball item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE, 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + ((10 * ITEM_SCALE) / 2), 
                               HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE, 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + ((10 * ITEM_SCALE) / 2), 
                               HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B);
        
        // Draw the seam item color
        g_printString(b->seam.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(b->seam.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + SPACING, NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the seam item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the back button
        g_printString("BACK", BACK_X - (7 * OBJECT_SCALE * 2) + ((OBJECT_SCALE * 3) / 2), BACK_Y, 
                      NORMAL_R, NORMAL_G, NORMAL_B, OBJECT_SCALE);
        
      }
      
      // If the current selection is the seam item, highlight the seam color
      else if (selection == 2) {
        
        // Draw the object
		g_printString("BALL", OBJECT_X - (7 * OBJECT_SCALE * 2) + ((OBJECT_SCALE * 3) / 2), OBJECT_Y, 
                      NORMAL_R, NORMAL_G, NORMAL_B, OBJECT_SCALE);
        
        // Draw two triangles to indicate the object can be changed
        graphics_triangle_fill(OBJECT_X - (7 * OBJECT_SCALE * 4), OBJECT_Y - OBJECT_SCALE, 
                               OBJECT_X - (7 * OBJECT_SCALE * 4), OBJECT_Y + (10 * OBJECT_SCALE),
                               OBJECT_X - (7 * OBJECT_SCALE * 5), OBJECT_Y - OBJECT_SCALE + ((10 * OBJECT_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(OBJECT_X + (7 * OBJECT_SCALE * 4), OBJECT_Y - OBJECT_SCALE, 
                               OBJECT_X + (7 * OBJECT_SCALE * 4), OBJECT_Y + (10 * OBJECT_SCALE),
                               OBJECT_X + (7 * OBJECT_SCALE * 5), OBJECT_Y - OBJECT_SCALE + ((10 * OBJECT_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the ball item color
        g_printString(b->ball.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(b->ball.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y, NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the ball item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE, 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE, 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the seam item color highlighted
        g_printString(b->seam.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(b->seam.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + SPACING, HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B, ITEM_SCALE);
        
        // Draw two highlighted triangles to indicate the ball item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING) + ((10 * ITEM_SCALE) / 2), 
                               HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING) + ((10 * ITEM_SCALE) / 2), 
                               HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B);
        
        // Draw the back button
        g_printString("BACK", BACK_X - (7 * OBJECT_SCALE * 2) + ((OBJECT_SCALE * 3) / 2), BACK_Y, 
                      NORMAL_R, NORMAL_G, NORMAL_B, OBJECT_SCALE);
        
      }
      
      // If the current selection is back, highlight back
      else if (selection == 3) {
        
        // Draw the object
        g_printString("BALL", OBJECT_X - (7 * OBJECT_SCALE * 2) + ((OBJECT_SCALE * 3) / 2), OBJECT_Y, 
                      NORMAL_R, NORMAL_G, NORMAL_B, OBJECT_SCALE);
        
        // Draw two triangles to indicate the object can be changed
        graphics_triangle_fill(OBJECT_X - (7 * OBJECT_SCALE * 4), OBJECT_Y - OBJECT_SCALE, 
                               OBJECT_X - (7 * OBJECT_SCALE * 4), OBJECT_Y + (10 * OBJECT_SCALE),
                               OBJECT_X - (7 * OBJECT_SCALE * 5), OBJECT_Y - OBJECT_SCALE + ((10 * OBJECT_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(OBJECT_X + (7 * OBJECT_SCALE * 4), OBJECT_Y - OBJECT_SCALE, 
                               OBJECT_X + (7 * OBJECT_SCALE * 4), OBJECT_Y + (10 * OBJECT_SCALE),
                               OBJECT_X + (7 * OBJECT_SCALE * 5), OBJECT_Y - OBJECT_SCALE + ((10 * OBJECT_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the ball item color
        g_printString(b->ball.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(b->ball.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y, NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the ball item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE, 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE, 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the seam item color
        g_printString(b->seam.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(b->seam.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + SPACING, NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the seam item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the back button highlighted
        g_printString("BACK", BACK_X - (7 * OBJECT_SCALE * 2) + ((OBJECT_SCALE * 3) / 2), BACK_Y, 
                      HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B, OBJECT_SCALE);
        
      }
      
    }
    
    // If the current object is the hoop, display the hoop items
    else {
      
      // Draw the pole item
	  g_printString("POLE", COLUMN1_X - (7 * ITEM_SCALE * 2) + ((ITEM_SCALE * 3) / 2), COLUMN1_Y,
                    NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
      
      // Draw the backboard item
      g_printString("BACKBOARD", COLUMN1_X - (7 * ITEM_SCALE * 4.5) + ((ITEM_SCALE * 3) / 2), COLUMN1_Y + SPACING,
                    NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
      
      // Draw the rim item
      g_printString("RIM", COLUMN1_X - (7 * ITEM_SCALE * 1.5) + ((ITEM_SCALE * 3) / 2), COLUMN1_Y + (2 * SPACING),
                    NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
      
      // Draw the net item
      g_printString("NET", COLUMN1_X - (7 * ITEM_SCALE * 1.5) + ((ITEM_SCALE * 3) / 2), COLUMN1_Y + (3 * SPACING),
                    NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
      
      // If the current selection is the object, highlight the object
      if (selection == 0) {
        
        // Draw the object highlighted
        g_printString("HOOP", OBJECT_X - (7 * OBJECT_SCALE * 2) + ((OBJECT_SCALE * 3) / 2), OBJECT_Y, 
                      HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B, OBJECT_SCALE);
        
        // Draw two highlighted triangles to indicate the object can be changed
        graphics_triangle_fill(OBJECT_X - (7 * OBJECT_SCALE * 4), OBJECT_Y - OBJECT_SCALE, 
                               OBJECT_X - (7 * OBJECT_SCALE * 4), OBJECT_Y + (10 * OBJECT_SCALE),
                               OBJECT_X - (7 * OBJECT_SCALE * 5), OBJECT_Y - OBJECT_SCALE + ((10 * OBJECT_SCALE) / 2), 
                               HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B);
        graphics_triangle_fill(OBJECT_X + (7 * OBJECT_SCALE * 4), OBJECT_Y - OBJECT_SCALE, 
                               OBJECT_X + (7 * OBJECT_SCALE * 4), OBJECT_Y + (10 * OBJECT_SCALE),
                               OBJECT_X + (7 * OBJECT_SCALE * 5), OBJECT_Y - OBJECT_SCALE + ((10 * OBJECT_SCALE) / 2), 
                               HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B);
        
        // Draw the pole item color
        g_printString(h->pole.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(h->pole.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y, NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the pole item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE, 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE, 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the backboard item color
        g_printString(h->backboard.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(h->backboard.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + SPACING, NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the backboard item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the rim item color
        g_printString(h->rim.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(h->rim.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + (2 * SPACING), NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the rim item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 2),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 2),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the net item color
        g_printString(h->net.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(h->net.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + (3 * SPACING), NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the net item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 3),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 3),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the back button
        g_printString("BACK", BACK_X - (7 * OBJECT_SCALE * 2) + ((OBJECT_SCALE * 3) / 2), BACK_Y, 
                      NORMAL_R, NORMAL_G, NORMAL_B, OBJECT_SCALE);
        
      }
      
      // If the current selection is the pole item, highlight the pole color
      else if (selection == 1) {
        
        // Draw the object
        g_printString("HOOP", OBJECT_X - (7 * OBJECT_SCALE * 2) + ((OBJECT_SCALE * 3) / 2), OBJECT_Y, 
                      NORMAL_R, NORMAL_G, NORMAL_B, OBJECT_SCALE);
        
        // Draw two triangles to indicate the object can be changed
        graphics_triangle_fill(OBJECT_X - (7 * OBJECT_SCALE * 4), OBJECT_Y - OBJECT_SCALE, 
                               OBJECT_X - (7 * OBJECT_SCALE * 4), OBJECT_Y + (10 * OBJECT_SCALE),
                               OBJECT_X - (7 * OBJECT_SCALE * 5), OBJECT_Y - OBJECT_SCALE + ((10 * OBJECT_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(OBJECT_X + (7 * OBJECT_SCALE * 4), OBJECT_Y - OBJECT_SCALE, 
                               OBJECT_X + (7 * OBJECT_SCALE * 4), OBJECT_Y + (10 * OBJECT_SCALE),
                               OBJECT_X + (7 * OBJECT_SCALE * 5), OBJECT_Y - OBJECT_SCALE + ((10 * OBJECT_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the pole item color highlighted
        g_printString(h->pole.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(h->pole.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y, HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B, ITEM_SCALE);
        
        // Draw two highlighted triangles to indicate the pole item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE, 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + ((10 * ITEM_SCALE) / 2), 
                               HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE, 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + ((10 * ITEM_SCALE) / 2), 
                               HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B);
        
        // Draw the backboard item color
        g_printString(h->backboard.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(h->backboard.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + SPACING, NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the backboard item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the rim item color
        g_printString(h->rim.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(h->rim.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + (2 * SPACING), NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the rim item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 2),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 2),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the net item color
        g_printString(h->net.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(h->net.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + (3 * SPACING), NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the net item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 3),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 3),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the back button
        g_printString("BACK", BACK_X - (7 * OBJECT_SCALE * 2) + ((OBJECT_SCALE * 3) / 2), BACK_Y, 
                      NORMAL_R, NORMAL_G, NORMAL_B, OBJECT_SCALE);
        
      }
      
      // If the current selection is the backboard item, highlight the backboard color
      else if (selection == 2) {
        
        // Draw the object
        g_printString("HOOP", OBJECT_X - (7 * OBJECT_SCALE * 2) + ((OBJECT_SCALE * 3) / 2), OBJECT_Y, 
                      NORMAL_R, NORMAL_G, NORMAL_B, OBJECT_SCALE);
        
        // Draw two triangles to indicate the object can be changed
        graphics_triangle_fill(OBJECT_X - (7 * OBJECT_SCALE * 4), OBJECT_Y - OBJECT_SCALE, 
                               OBJECT_X - (7 * OBJECT_SCALE * 4), OBJECT_Y + (10 * OBJECT_SCALE),
                               OBJECT_X - (7 * OBJECT_SCALE * 5), OBJECT_Y - OBJECT_SCALE + ((10 * OBJECT_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(OBJECT_X + (7 * OBJECT_SCALE * 4), OBJECT_Y - OBJECT_SCALE, 
                               OBJECT_X + (7 * OBJECT_SCALE * 4), OBJECT_Y + (10 * OBJECT_SCALE),
                               OBJECT_X + (7 * OBJECT_SCALE * 5), OBJECT_Y - OBJECT_SCALE + ((10 * OBJECT_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the pole item color
        g_printString(h->pole.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(h->pole.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y, NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the pole item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE, 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE, 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the backboard item color highlighted
        g_printString(h->backboard.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(h->backboard.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + SPACING, HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B, ITEM_SCALE);
        
        // Draw two highlighted triangles to indicate the backboard item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING) + ((10 * ITEM_SCALE) / 2), 
                               HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING) + ((10 * ITEM_SCALE) / 2), 
                               HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B);
        
        // Draw the rim item color
        g_printString(h->rim.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(h->rim.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + (2 * SPACING), NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the rim item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 2),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 2),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the net item color
        g_printString(h->net.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(h->net.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + (3 * SPACING), NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the net item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 3),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 3),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the back button
        g_printString("BACK", BACK_X - (7 * OBJECT_SCALE * 2) + ((OBJECT_SCALE * 3) / 2), BACK_Y, 
                      NORMAL_R, NORMAL_G, NORMAL_B, OBJECT_SCALE);
        
      }
      
      // If the current selection is the rim item, highlight the rim color
      else if (selection == 3) {
        
        // Draw the object
        g_printString("HOOP", OBJECT_X - (7 * OBJECT_SCALE * 2) + ((OBJECT_SCALE * 3) / 2), OBJECT_Y, 
                      NORMAL_R, NORMAL_G, NORMAL_B, OBJECT_SCALE);
        
        // Draw two triangles to indicate the object can be changed
        graphics_triangle_fill(OBJECT_X - (7 * OBJECT_SCALE * 4), OBJECT_Y - OBJECT_SCALE, 
                               OBJECT_X - (7 * OBJECT_SCALE * 4), OBJECT_Y + (10 * OBJECT_SCALE),
                               OBJECT_X - (7 * OBJECT_SCALE * 5), OBJECT_Y - OBJECT_SCALE + ((10 * OBJECT_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(OBJECT_X + (7 * OBJECT_SCALE * 4), OBJECT_Y - OBJECT_SCALE, 
                               OBJECT_X + (7 * OBJECT_SCALE * 4), OBJECT_Y + (10 * OBJECT_SCALE),
                               OBJECT_X + (7 * OBJECT_SCALE * 5), OBJECT_Y - OBJECT_SCALE + ((10 * OBJECT_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the pole item color
        g_printString(h->pole.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(h->pole.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y, NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the pole item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE, 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE, 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the backboard item color
        g_printString(h->backboard.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(h->backboard.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + SPACING, NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the backboard item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the rim item color highlighted
        g_printString(h->rim.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(h->rim.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + (2 * SPACING), HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B, ITEM_SCALE);
        
        // Draw two highlighted triangles to indicate the rim item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 2),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2) + ((10 * ITEM_SCALE) / 2), 
                               HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 2),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2) + ((10 * ITEM_SCALE) / 2), 
                               HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B);
        
        // Draw the net item color
        g_printString(h->net.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(h->net.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + (3 * SPACING), NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the net item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 3),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 3),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the back button
        g_printString("BACK", BACK_X - (7 * OBJECT_SCALE * 2) + ((OBJECT_SCALE * 3) / 2), BACK_Y, 
                      NORMAL_R, NORMAL_G, NORMAL_B, OBJECT_SCALE);
        
      }
      
      // If the current selection is the net item, highlight the net color
      else if (selection == 4) {
        
        // Draw the object
		g_printString("HOOP", OBJECT_X - (7 * OBJECT_SCALE * 2) + ((OBJECT_SCALE * 3) / 2), OBJECT_Y, 
                      NORMAL_R, NORMAL_G, NORMAL_B, OBJECT_SCALE);
        
        // Draw two triangles to indicate the object can be changed
        graphics_triangle_fill(OBJECT_X - (7 * OBJECT_SCALE * 4), OBJECT_Y - OBJECT_SCALE, 
                               OBJECT_X - (7 * OBJECT_SCALE * 4), OBJECT_Y + (10 * OBJECT_SCALE),
                               OBJECT_X - (7 * OBJECT_SCALE * 5), OBJECT_Y - OBJECT_SCALE + ((10 * OBJECT_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(OBJECT_X + (7 * OBJECT_SCALE * 4), OBJECT_Y - OBJECT_SCALE, 
                               OBJECT_X + (7 * OBJECT_SCALE * 4), OBJECT_Y + (10 * OBJECT_SCALE),
                               OBJECT_X + (7 * OBJECT_SCALE * 5), OBJECT_Y - OBJECT_SCALE + ((10 * OBJECT_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the pole item color
        g_printString(h->pole.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(h->pole.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y, NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the pole item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE, 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE, 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the backboard item color
        g_printString(h->backboard.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(h->backboard.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + SPACING, NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the backboard item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the rim item color
        g_printString(h->rim.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(h->rim.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + (2 * SPACING), NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the rim item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 2),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 2),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the net item color highlighted
        g_printString(h->net.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(h->net.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + (3 * SPACING), HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B, ITEM_SCALE);
        
        // Draw two highlighted triangles to indicate the net item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 3),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3) + ((10 * ITEM_SCALE) / 2), 
                               HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 3),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3) + ((10 * ITEM_SCALE) / 2), 
                               HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B);
        
        // Draw the back button
        g_printString("BACK", BACK_X - (7 * OBJECT_SCALE * 2) + ((OBJECT_SCALE * 3) / 2), BACK_Y, 
                      NORMAL_R, NORMAL_G, NORMAL_B, OBJECT_SCALE);
        
      }
      
      // If the current selection is back, highlight back
      else if (selection == 5) {
        
        // Draw the object
		g_printString("HOOP", OBJECT_X - (7 * OBJECT_SCALE * 2) + ((OBJECT_SCALE * 3) / 2), OBJECT_Y, 
                      NORMAL_R, NORMAL_G, NORMAL_B, OBJECT_SCALE);
        
        // Draw two triangles to indicate the object can be changed
        graphics_triangle_fill(OBJECT_X - (7 * OBJECT_SCALE * 4), OBJECT_Y - OBJECT_SCALE, 
                               OBJECT_X - (7 * OBJECT_SCALE * 4), OBJECT_Y + (10 * OBJECT_SCALE),
                               OBJECT_X - (7 * OBJECT_SCALE * 5), OBJECT_Y - OBJECT_SCALE + ((10 * OBJECT_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(OBJECT_X + (7 * OBJECT_SCALE * 4), OBJECT_Y - OBJECT_SCALE, 
                               OBJECT_X + (7 * OBJECT_SCALE * 4), OBJECT_Y + (10 * OBJECT_SCALE),
                               OBJECT_X + (7 * OBJECT_SCALE * 5), OBJECT_Y - OBJECT_SCALE + ((10 * OBJECT_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the pole item color
        g_printString(h->pole.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(h->pole.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y, NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the pole item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE, 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE, 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the backboard item color
        g_printString(h->backboard.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(h->backboard.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + SPACING, NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the backboard item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the rim item color
        g_printString(h->rim.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(h->rim.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + (2 * SPACING), NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the rim item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 2),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 2),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 2) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the net item color
        g_printString(h->net.name, COLUMN2_X - (7 * ITEM_SCALE * (strlen(h->net.name) / 2.0)) + ((ITEM_SCALE * 3) / 2),
                      COLUMN2_Y + (3 * SPACING), NORMAL_R, NORMAL_G, NORMAL_B, ITEM_SCALE);
        
        // Draw two triangles to indicate the net item color can be changed
        graphics_triangle_fill(COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3), 
                               COLUMN2_X - (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 3),
                               COLUMN2_X - (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        graphics_triangle_fill(COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3), 
                               COLUMN2_X + (7 * ITEM_SCALE * 6.5), COLUMN2_Y + (10 * ITEM_SCALE) + (SPACING * 3),
                               COLUMN2_X + (7 * ITEM_SCALE * 7.5), COLUMN2_Y - ITEM_SCALE + (SPACING * 3) + ((10 * ITEM_SCALE) / 2), 
                               NORMAL_R, NORMAL_G, NORMAL_B);
        
        // Draw the back button highlighted
        g_printString("BACK", BACK_X - (7 * OBJECT_SCALE * 2) + ((OBJECT_SCALE * 3) / 2), BACK_Y, 
                      HIGHLIGHT_R, HIGHLIGHT_G, HIGHLIGHT_B, OBJECT_SCALE);
        
      }
      
    }
    
    // Update the graphics window
    graphics_update();
    
    // If the up key is pressed, update the selection
    if (get_key_state(KeyUp) != 0) {
      
      // Decrement the selection
      --selection;
      
      // If the object is the player and the selection passes object, set it to back
      if (object == 0 && selection < 0) {
        
        // Set the selection to back
		selection = 5;
        
      }
      
      // If the object is the ball and the selection passes object, set it to back
      else if (object == 1 && selection < 0) {
        
        // Set the selection to back
        selection = 3;
        
      }
      
      // If the object is the hoop and the selection passes object, set it to back
      else if (object == 2 && selection < 0) {
        
        // Set the selection to back
        selection = 5;
        
      }
      
      // Delay 0.1 seconds to prevent accidental multiple inputs
      delay(0.1);
      
    }
    
    // If the down key is pressed update the selection
    if (get_key_state(KeyDown) != 0) {
      
      // Increment the selection
      ++selection;
      
      // If the object is the player and the selection passes back, set it to object
      if (object == 0 && selection > 5) {
        
        // Set the selection to object
		selection = 0;
        
      }
      
      // If the object is the ball and the selection passes back, set it to object
      else if (object == 1 && selection > 3) {
        
        // Set the selection to object
        selection = 0;
        
      }
      
      // If the object is the hoop and the selection passes back, set it to object
      else if (object == 2 && selection > 5) {
        
        // Set the selection to object
        selection = 0;
        
      }
      
      // Delay 0.1 seconds to prevent accidental multiple inputs
      delay(0.1);
      
    }
    
    // If the left key is pressed, update the selected item or object
    if (get_key_state(KeyLeft) != 0) {
      
      // If the selection is the object, update the object
      if (selection == 0) {
        
        // Decrement the object
		--object;
        
        // If the object goes past player, set it to hoop
        if (object < 0) {
          
          // Set the object to hoop
          object = 2;
          
        }
        
      }
      
      // If the object is the player, update its corresponding selection
      else if (object == 0) {
        
        // If the selection is the skin item, update it
        if (selection == 1) {
          
          // Decrement the skin item color index
		  pl->skinIdx -= 1;
          
          // If the skin item color index passes skin color 1, set it to basketball
          if (pl->skinIdx < 0) {
            
            // Set the skin item color index to basketball
            pl->skinIdx = 28;
            
          }
          
          // Update the skin item color
          pl->skin = colors[pl->skinIdx];
          
        }
        
        // If the selection is the shirt item, update it
        else if (selection == 2) {
          
          // Decrement the shirt item color index
		  pl->shirtIdx -= 1;
          
          // If the shirt item color index passes skin color 1, set it to basketball
          if (pl->shirtIdx < 0) {
            
            // Set the shirt item color index to basketball
            pl->shirtIdx = 28;
            
          }
          
          // Update the shirt item color
          pl->shirt = colors[pl->shirtIdx];
          
        }
        
        // If the selection is the pants item, update it
        else if (selection == 3) {
          
          // Decrement the pants item color index
		  pl->pantsIdx -= 1;
          
          // If the pants item color index passes skin color 1, set it to basketball
          if (pl->pantsIdx < 0) {
            
            // Set the pants item color index to basketball
            pl->pantsIdx = 28;
            
          }
          
          // Update the pants item color
          pl->pants = colors[pl->pantsIdx];
          
        }
        
        // If the selection is the shoes item, update it
        else if (selection == 4) {
          
          // Decrement the shoes item color index
		  pl->shoesIdx -= 1;
          
          // If the shoes item color index passes skin color 1, set it to basketball
          if (pl->shoesIdx < 0) {
            
            // Set the shoes item color index to basketball
            pl->shoesIdx = 28;
            
          }
          
          // Update the shoes item color
          pl->shoes = colors[pl->shoesIdx];
          
        }
        
      }
      
      // If the object is the ball, update its corresponding selection
      else if (object == 1) {
        
        // If the selection is the ball item, update it
        if (selection == 1) {
          
          // Decrement the ball item color index
		  b->ballIdx -= 1;
          
          // If the ball item color index passes skin color 1, set it to basketball
          if (b->ballIdx < 0) {
            
            // Set the ball item color index to basketball
            b->ballIdx = 28;
            
          }
          
          // Update the ball item color
          b->ball = colors[b->ballIdx];
          
        }
        
        // If the selection is the seam item, update it
        else if (selection == 2) {
          
          // Decrement the seam item color index
		  b->seamIdx -= 1;
          
          // If the seam item color index passes skin color 1, set it to basketball
          if (b->seamIdx < 0) {
            
            // Set the seam item color index to basketball
            b->seamIdx = 28;
            
          }
          
          // Update the seam item color
          b->seam = colors[b->seamIdx];
          
        }
        
      }
      
      // If the object is the hoop, update its corresponding selection
      else {
        
        // If the selection is the pole item, update it
        if (selection == 1) {
          
          // Decrement the pole item color index
		  h->poleIdx -= 1;
          
          // If the pole item color index passes skin color 1, set it to basketball
          if (h->poleIdx < 0) {
            
            // Set the pole item color index to basketball
            h->poleIdx = 28;
            
          }
          
          // Update the pole item color
          h->pole = colors[h->poleIdx];
          
        }
        
        // If the selection is the backboard item, update it
        else if (selection == 2) {
          
          // Decrement the backboard item color index
		  h->backboardIdx -= 1;
          
          // If the backboard item color index passes skin color 1, set it to basketball
          if (h->backboardIdx < 0) {
            
            // Set the backboard item color index to basketball
            h->backboardIdx = 28;
      
          }
          
          // Update the backboard item color
          h->backboard = colors[h->backboardIdx];
          
        }
        
        // If the selection is the rim item, update it
        else if (selection == 3) {
          
          // Decrement the rim item color index
		  h->rimIdx -= 1;
          
          // If the rim item color index passes skin color 1, set it to basketball
          if (h->rimIdx < 0) {
            
            // Set the rim item color index to basketball
            h->rimIdx = 28;
            
          }
          
          // Update the rim item color
          h->rim = colors[h->rimIdx];
          
        }
        
        // If the selection is the net item, update it
        else if (selection == 4) {
          
          // Decrement the net item color index
		  h->netIdx -= 1;
          
          // If the net item color index passes skin color 1, set it to basketball
          if (h->netIdx < 0) {
            
            // Set the net item color index to basketball
            h->netIdx = 28;
            
          }
          
          // Update the net item color
          h->net = colors[h->netIdx];
          
        }
        
      }
      
      // Delay 0.1 seconds to prevent accidental multiple inputs
      delay(0.1);
      
    }
    
    
    // If the right key is pressed, update the selected item or object
    if (get_key_state(KeyRight) != 0) {
      
      // If the selection is the object, update the object
      if (selection == 0) {
        
        // Increment the object
		++object;
        
        // If the objects passes hoop, set it to player
        if (object > 2) {
          
          // Set the object to player
          object = 0;
          
        }
        
      }
      
      // If the object is the player, update its corresponding selection
      else if (object == 0) {
        
        // If the selction is the skin item, update it
        if (selection == 1) {
          
          // Increment the skin item color index
		  pl->skinIdx += 1;
          
          // If the skin item color index passes basketball, set it to skin tone 1
          if (pl->skinIdx > 28) {
            
            // Set the skin item color index to skin tone 1
            pl->skinIdx = 0;
            
          }
          
          // Update the skin item color
          pl->skin = colors[pl->skinIdx];
          
        }
        
        // If the selection is the shirt item, update it
        else if (selection == 2) {
          
          // Increment the shirt item color index
		  pl->shirtIdx += 1;
          
          // If the shirt item color index passes basketball, set it to skin tone 1
          if (pl->shirtIdx > 28) {
            
            // Set the shirt item color index to skin tone 1
            pl->shirtIdx = 0;
            
          }
          
          // Update the shirt item color
          pl->shirt = colors[pl->shirtIdx];
          
        }
        
        // If the selection is the pants item, update it
        else if (selection == 3) {
          
          // Increment the pants item color index
		  pl->pantsIdx += 1;
          
          // If the pants item color index passes basketball, set it to skin tone 1
          if (pl->pantsIdx > 28) {
            
            // Set the pants item color index to skin tone 1
            pl->pantsIdx = 0;
            
          }
          
          // Update the pants item color
          pl->pants = colors[pl->pantsIdx];
          
        }
        
        // If the selection is the shoes item, update it
        else if (selection == 4) {
          
          // Increment the shoes item color index
		  pl->shoesIdx += 1;
          
          // If the shoes item color index passes basketball, set it to skin tone 1
          if (pl->shoesIdx > 28) {
            
            // Set the shoes item color index to skin tone 1
            pl->shoesIdx = 0;
            
          }
          
          // Update the shoes item color
          pl->shoes = colors[pl->shoesIdx];
          
        }
        
      }
      
      // If the object is the ball, update its corresponding selection
      else if (object == 1) {
        
        // If the selection is the ball item, update it
        if (selection == 1) {
          
          // Update the ball item color index
		  b->ballIdx += 1;
          
          // If the ball item color index passes basketball, set it to skin tone 1
          if (b->ballIdx > 28) {
            
            // Set the ball item color index to skin tone 1
            b->ballIdx = 0;
            
          }
          
          // Update the ball item color
          b->ball = colors[b->ballIdx];
          
        }
        
        // If the selection is the seam item, update it
        else if (selection == 2) {
          
          // Increment the seam item color index
		  b->seamIdx += 1;
          
          // If the seam item color index passes basketball, set it to skin tone 1
          if (b->seamIdx > 28) {
            
            // Set the seam item color index to skin tone 1
            b->seamIdx = 0;
            
          }
          
          // Update the seam item color
          b->seam = colors[b->seamIdx];
          
        }
        
      }
      
      // If the object is the hoop, update its corresponding selection
      else {
        
        // If the selection is the pole item, update it
        if (selection == 1) {
          
          // Increment the pole item color index
		  h->poleIdx += 1;
          
          // If the pole item color index passes basketball, set it to skin tone 1
          if (h->poleIdx > 28) {
            
            // Set the pole item color index to skin tone 1
            h->poleIdx = 0;
            
          }
          
          // Update the pole item color
          h->pole = colors[h->poleIdx];
          
        }
        
        // If the selection is the backboard item, update it
        else if (selection == 2) {
          
          // Increment the backboard item color index
		  h->backboardIdx += 1;
          
          // If the backboard item color index passes basketball, set it to skin tone 1
          if (h->backboardIdx > 28) {
            
            // Set the backboard item color index to skin tone 1
            h->backboardIdx = 0;
            
          }
          
          // Update the backboard item color
          h->backboard = colors[h->backboardIdx];
          
        }
        
        // If the selection is the rim item, update it
        else if (selection == 3) {
          
          // Increment the rim item color index
		  h->rimIdx += 1;
          
          // If the rim item color index passes basketball, set it to skin tone 1
          if (h->rimIdx > 28) {
            
            // Set the rim item color index to skin tone 1
            h->rimIdx = 0;
            
          }
          
          // Update the rim item color
          h->rim = colors[h->rimIdx];
          
        }
        
        // If the selection is the net item, update it
        else if (selection == 4) {
          
          // Increment the net item color index
		  h->netIdx += 1;
          
          // If the net item color index passes basketball, set it to skin tone 1
          if (h->netIdx > 28) {
            
            // Set the net item color index to skin tone 1
            h->netIdx = 0;
            
          }
          
          // Update the net item color
          h->net = colors[h->netIdx];
          
        }
        
      }
      
      // Delay 0.1 seconds to prevent accidental multiple inputs
      delay(0.1);
      
    }
    
    // If the space is pressed, check to see if the back button was selected
    if (get_key_state(KeySpace) != 0) {
      
      // If the object was the player or hoop, check if the back button was selected
	  if (object == 0 || object == 2) {
        
        // If the back button was selected, update the back variable
        if (selection == 5) {
          
          // Update the back variable
          back = 1;
          
          // Delay 0.1 seconds to prevent accidental multiple inputs
          delay(0.1);
          
        }
        
      }
      
      // If the object was the ball, check if the back button was selected
      else {
        
        // If the back button was selected, update the back variable
		if (selection == 3) {
          
          // Update the back variable
          back = 1;
          
          // Delay 0.1 seconds to prevent accidental multiple inputs
          delay(0.1);
          
        }
        
      }
      
    }
    
  }
  
}