// Define a funtion the draws the letter P at a given point, width, main color, and outline color
void drawP(int x, int y, int width, int r1, int g1, int b1, int r2, int g2, int b2) {
  
  // Define a constant to hold the bottom y cordinate of the letter
  const int BOTTOM_Y = y + (6 * width);
  
  // Draw the shape and outline of the letter
  drawQuadrilateral(x, y, x + width, y, x + width, BOTTOM_Y, x, BOTTOM_Y, r1, g1, b1);
  drawQuarterWasherFill(x + width, y + (2 * width), width, (2 * width), 0, r1, g1, b1);
  drawQuarterWasherFill(x + width, y + (2 * width), width, (2 * width), -90, r1, g1, b1);
  graphics_line(x, y, x, BOTTOM_Y, r2, g2, b2);
  graphics_line(x, y, x + width, y, r2, g2, b2);
  graphics_line(x, BOTTOM_Y, x + width, BOTTOM_Y, r2, g2, b2);
  graphics_line(x + width, y + (4 * width), x + width, BOTTOM_Y, r2, g2, b2);
  graphics_line(x + width, y + width, x + width, y + (3 * width), r2, g2, b2);
  drawQuarterCircle(x + width, y + (2 * width), width, 0, r2, g2, b2);
  drawQuarterCircle(x + width, y + (2 * width), (2 * width), 0, r2, g2, b2);
  drawQuarterCircle(x + width, y + (2 * width), width, -90, r2, g2, b2);
  drawQuarterCircle(x + width, y + (2 * width), (2 * width), -90, r2, g2, b2);
  
}

// Define a funtion the draws the letter O at a given point, width, main color, and outline color
void drawO(int x, int y, int width, int r1, int g1, int b1, int r2, int g2, int b2) {
  
  // Define a constant to hold the bottom y cordinate of the letter
  const int BOTTOM_Y = y + (6 * width);
  
  // Draw the shape and outline of the letter
  drawQuarterWasherFill(x + (2 * width), y + (2 * width), width, (2 * width), 0, r1, g1, b1);
  drawQuarterWasherFill(x + (2 * width), y + (2 * width), width, (2 * width), 90, r1, g1, b1);
  drawQuarterWasherFill(x + (2 * width), BOTTOM_Y - (2 * width), width, (2 * width), -90, r1, g1, b1);
  drawQuarterWasherFill(x + (2 * width), BOTTOM_Y - (2 * width), width, (2 * width), 180, r1, g1, b1);
  drawQuadrilateral(x, y + (2 * width), x + width, y + (2 * width), 
                    x + width, BOTTOM_Y - (2 * width), x, BOTTOM_Y - (2 * width), r1, g1, b1);
  drawQuadrilateral(x + (3 * width), y + (2 * width), x + (4 * width), y + (2 * width), 
                    x + (4 * width), BOTTOM_Y - (2 * width), x + (3 * width), BOTTOM_Y - (2 * width), 
                    r1, g1, b1);
  graphics_line(x, y + (2 * width), x, BOTTOM_Y - (2 * width), r2, g2, b2);
  graphics_line(x + width, y + (2 * width), x + width, BOTTOM_Y - (2 * width), r2, g2, b2);
  graphics_line(x + (3 * width), y + (2 * width), x + (3 * width), BOTTOM_Y - (2 * width), r2, g2, b2);
  graphics_line(x + (4 * width), y + (2 * width), x + (4 * width), BOTTOM_Y - (2 * width), r2, g2, b2);
  drawQuarterCircle(x + (2 * width), y + (2 * width), width, r2, g2, b2, 0);
  drawQuarterCircle(x + (2 * width), y + (2 * width), (2 * width), r2, g2, b2, 0);
  drawQuarterCircle(x + (2 * width), y + (2 * width), width, 90, r2, g2, b2);
  drawQuarterCircle(x + (2 * width), y + (2 * width), (2 * width), 90, r2, g2, b2);
  drawQuarterCircle(x + (2 * width), BOTTOM_Y - (2 * width), width, -90, r2, g2, b2);
  drawQuarterCircle(x + (2 * width), BOTTOM_Y - (2 * width), (2 * width), -90, r2, g2, b2);
  drawQuarterCircle(x + (2 * width), BOTTOM_Y - (2 * width), width, 180, r2, g2, b2);
  drawQuarterCircle(x + (2 * width), BOTTOM_Y - (2 * width), (2 * width), 180, r2, g2, b2);
  
}

// Define a funtion the draws a dash at a given point, width, main color, and outline color
void drawDash(int x, int y, int width, int r1, int g1, int b1, int r2, int g2, int b2) {
  
  // Define a constant to hold the bottom y cordinate of the letter
  const int BOTTOM_Y = y + (6 * width);
  
  // Define constants to hold the top and bottom of the hash
  const int TOP_HASH = ((BOTTOM_Y - y) / 2) + y - (width / 2);
  const int BOTTOM_HASH = ((BOTTOM_Y - y) / 2) + y + (width / 2);
  
  // Draw the shape and outline of the letter
  drawQuadrilateral(x, TOP_HASH, x + (2 * width), TOP_HASH, x + (2 * width), BOTTOM_HASH, x, BOTTOM_HASH, r1, g1, b1);
  graphics_line(x, TOP_HASH, x, BOTTOM_HASH, r2, g2, b2);
  graphics_line(x, TOP_HASH, x + (2 * width), TOP_HASH, r2, g2, b2);
  graphics_line(x + (2 * width), TOP_HASH, x + (2 * width), BOTTOM_HASH, r2, g2, b2);
  graphics_line(x, BOTTOM_HASH, x + (2 * width), BOTTOM_HASH, r2, g2, b2);
  
}

// Define a funtion the draws the letter A at a given point, width, main color, and outline color
void drawA(int x, int y, int width, int r1, int g1, int b1, int r2, int g2, int b2) {
  
  // Define a constant to hold the bottom y cordinate of the letter
  const int BOTTOM_Y = y + (6 * width);
  
  // Draw the shape and outline of the letter
  graphics_line(x + width + 1, BOTTOM_Y, x + (2 * width) + 1, y, r2, g2, b2);
  graphics_line(x + ((11.0 / 6.0) * width) - 2, y, x + ((17.0 / 6.0) * width) - 2, BOTTOM_Y, r2, g2, b2);
  graphics_line(x + width, y + (3 * width) - 1, x + ((17.0 / 6.0) * width) - 1, y + (3 * width) - 1, r2, g2, b2);
  graphics_line(x + width, y + (4 * width) + 1, x + ((17.0 / 6.0) * width) - 1, y + (4 * width) + 1, r2, g2, b2);
  drawQuadrilateral(x + width, y, x + (2 * width), y, x + width, BOTTOM_Y, x, BOTTOM_Y, r1, g1, b1);
  drawQuadrilateral(x + ((11.0 / 6.0) * width) - 1, y, x + ((17.0 / 6.0) * width) - 1, y, x + ((23.0 / 6.0) * width) - 1, BOTTOM_Y, 
                    x + ((17.0 / 6.0) * width) - 1, BOTTOM_Y, r1, g1, b1);
  drawQuadrilateral(x + width, y + (3 * width), x + ((17.0 / 6.0) * width) - 1, y + (3 * width), 
                    x + ((17.0 / 6.0) * width) - 1, y + (4 * width), x + width, y + (4 * width), r1, g1, b1);
  graphics_line(x + width, y, x, BOTTOM_Y, r2, g2, b2);
  graphics_line(x + ((17.0 / 6.0) * width) - 1, y, x + ((23.0 / 6.0) * width) - 1, BOTTOM_Y, r2, g2, b2);
  graphics_line(x + width, y, x + ((17.0 / 6.0) * width) - 1, y, r2, g2, b2);
  graphics_line(x, BOTTOM_Y, x + width, BOTTOM_Y, r2, g2, b2);
  graphics_line(x + ((17.0 / 6.0) * width) - 1, BOTTOM_Y, x + ((23.0 / 6.0) * width) - 1, BOTTOM_Y, r2, g2, b2);
  
}

// Define a funtion the draws the letter S at a given point, width, main color, and outline color
void drawS(int x, int y, int width, int r1, int g1, int b1, int r2, int g2, int b2) {
  
  // Define a constant to hold the bottom y cordinate of the letter
  const int BOTTOM_Y = y + (6 * width);
  
  // Draw the shape and outline of the letter
  drawQuarterWasherFill(x + (2 * width), y + (2 * width), width, (2 * width), 0, r1, g1, b1);
  drawQuarterWasherFill(x + (2 * width), y + (2 * width), width, (2 * width), 90, r1, g1, b1);
  drawQuarterWasherFill(x + (2 * width), BOTTOM_Y - (2 * width), width, (2 * width), -90, r1, g1, b1);
  drawQuarterWasherFill(x + (2 * width), BOTTOM_Y - (2 * width), width, (2 * width), 180, r1, g1, b1);
  drawQuadrilateral(x + width, y + (3 * width), x + width, y + (2 * width), x + (3 * width), BOTTOM_Y - (3 * width), 
                    x + (3 * width), BOTTOM_Y - (2 * width), r1, g1, b1);
  drawQuarterCircleFill(x + (3 * width), BOTTOM_Y - (2 * width), width, 0, r1, g1, b1);
  drawQuarterCircleFill(x + width, y + (2 * width), width, 180, r1, g1, b1);
  drawQuarterCircle(x + (3 * width), BOTTOM_Y - (2 * width), width, 0, r2, g2, b2);
  drawQuarterCircle(x + width, y + (2 * width), width, 180, r2, g2, b2);
  drawQuarterCircle(x + (2 * width), y + (2 * width), (2 * width), 90, r2, g2, b2);
  drawQuarterCircle(x + (2 * width), y + (2 * width), (2 * width), 0, r2, g2, b2);
  drawQuarterCircle(x + (2 * width), y + (2 * width), width, 90, r2, g2, b2);
  drawQuarterCircle(x + (2 * width), y + (2 * width), width, 0, r2, g2, b2);
  drawQuarterCircle(x + (2 * width), BOTTOM_Y - (2 * width), (2 * width), -90, r2, g2, b2);
  drawQuarterCircle(x + (2 * width), BOTTOM_Y - (2 * width), (2 * width), 180, r2, g2, b2);
  drawQuarterCircle(x + (2 * width), BOTTOM_Y - (2 * width), width, -90, r2, g2, b2);
  drawQuarterCircle(x + (2 * width), BOTTOM_Y - (2 * width), width, 180, r2, g2, b2);
  graphics_line(x, BOTTOM_Y - (2 * width), x + width, BOTTOM_Y - (2 * width), r2, g2, b2);
  graphics_line(x + (3 * width), y + (2 * width), x + (4 * width), y + (2 * width), r2, g2, b2);
  graphics_line(x + width, y + (2 * width), x + (3 * width), BOTTOM_Y - (3 * width), r2, g2, b2);
  graphics_line(x + width, y + (3 * width), x + (3 * width), BOTTOM_Y - (2 * width), r2, g2, b2);
  
}

// Define a funtion the draws the letter H at a given point, width, main color, and outline color
void drawH(int x, int y, int width, int r1, int g1, int b1, int r2, int g2, int b2) {
  
  // Define a constant to hold the bottom y cordinate of the letter
  const int BOTTOM_Y = y + (6 * width);
  
  // Define a constant hold the middle y cordinate of the letter
  const int MID_Y = ((BOTTOM_Y - y) / 2) + y;
  
  // Draw the shape and outline of the letter
  drawQuadrilateral(x, y, x + width, y, x + width, BOTTOM_Y, x, BOTTOM_Y, r1, g1, b1);
  drawQuadrilateral(x + (2 * width), y, x + (3 * width), y, x + (3 * width), BOTTOM_Y, x + (2 * width), BOTTOM_Y, r1, g1, b1);
  drawQuadrilateral(x + width, MID_Y - (width / 2), x + (2 * width), MID_Y - (width / 2), x + (2 * width), MID_Y + (width / 2),
                    x + width, MID_Y + (width / 2), r1, g1, b1);
  graphics_line(x, y, x, BOTTOM_Y, r2, g2, b2);
  graphics_line(x + (3 * width), y, x + (3 * width), BOTTOM_Y, r2, g2, b2);
  graphics_line(x + width, y, x + width, MID_Y - (width / 2), r2, g2, b2);
  graphics_line(x + width, MID_Y + (width / 2), x + width, BOTTOM_Y, r2, g2, b2);
  graphics_line(x + (2 * width), y, x + (2 * width), MID_Y - (width / 2), r2, g2, b2);
  graphics_line(x + (2 * width), MID_Y + (width / 2), x + (2 * width), BOTTOM_Y, r2, g2, b2);
  graphics_line(x, y, x + width, y, r2, g2, b2);
  graphics_line(x, BOTTOM_Y, x + width, BOTTOM_Y, r2, g2, b2);
  graphics_line(x + (2 * width), y, x + (3 * width), y, r2, g2, b2);
  graphics_line(x + (2 * width), BOTTOM_Y, x + (3 * width), BOTTOM_Y, r2, g2, b2);
  graphics_line(x + width, MID_Y - (width / 2), x + (2 * width), MID_Y - (width / 2), r2, g2, b2);
  graphics_line(x + width, MID_Y + (width / 2), x + (2 * width), MID_Y + (width / 2), r2, g2, b2);
  
}

// Define a funtion the draws the letter T at a given point, width, main color, and outline color
void drawT(int x, int y, int width, int r1, int g1, int b1, int r2, int g2, int b2) {
  
  // Define a constant to hold the bottom y cordinate of the letter
  const int BOTTOM_Y = y + (6 * width);
  
  // Draw the shape and outline of the letter
  drawQuadrilateral(x, y, x + (3 * width), y, x + (3 * width), y + width, x, y + width, r1, g1, b1);
  drawQuadrilateral(x + width, y + width, x + (2 * width), y + width, x + (2 * width), BOTTOM_Y, x + width, BOTTOM_Y, r1, g1, b1);
  graphics_line(x, y, x + (3 * width), y, r2, g2, b2);
  graphics_line(x, y + width, x + width, y + width, r2, g2, b2);
  graphics_line(x + (2 * width), y + width, x + (3 * width), y + width, r2, g2, b2);
  graphics_line(x + width, BOTTOM_Y, x + (2 * width), BOTTOM_Y, r2, g2, b2);
  graphics_line(x, y, x, y + width, r2, g2, b2);
  graphics_line(x + (3 * width), y, x + (3 * width), y + width, r2, g2, b2);
  graphics_line(x + width, y + width, x + width, BOTTOM_Y, r2, g2, b2);
  graphics_line(x + (2 * width), y + width, x + (2 * width), BOTTOM_Y, r2, g2, b2);
  
}