// Define a struct to represent the hoop
typedef struct hoop_struct {
  
  // Declare variables to hold the color of the pole and its index in the color array
  rgb pole;
  int poleIdx;
  
  // Declare variables to hold the color of the backboard and its index in the color array
  rgb backboard;
  int backboardIdx;
  
  // Declare variables to hold the color of the rim and its index in the color array
  rgb rim;
  int rimIdx;
  
  // Declare variables to hold the color of the net and its index in the color array
  rgb net;
  int netIdx;
  
} hoop;

// Define a function to initialize a given hoop object
void hoopInitializer(hoop* h) {
  
  // Declare an array to hold the colors
  rgb colors[100];
  
  // Populate the array with the colors
  getColors(colors);
  
  // Define variables to hold the default color of the pole and its index in the color array
  h->poleIdx = 27;
  h->pole = colors[27];
  
  // Define variables to hold the default color of the backboard and its index in the color array
  h->backboardIdx = 25;
  h->backboard = colors[25];
  
  // Define variables to hold the default color of the rim and its index in the color array
  h->rimIdx = 6;
  h->rim = colors[6];
  
  // Define variables to hold the default color of the net and its index in the color array
  h->netIdx = 24;
  h->net = colors[24];
  
}

// Define a function to draw a given hoop object at a given point
void drawHoop(hoop* h, int x, int y) {
  
  // Define constants to hold the bounds of the pole
  const int POLE_LEFT_X = x;
  const int POLE_RIGHT_X = POLE_LEFT_X + 15;
  const int POLE_BOTTOM_Y = y;
  const int POLE_TOP_Y = POLE_BOTTOM_Y - 325;

  // Draw the pole
  graphics_triangle_fill(POLE_LEFT_X, POLE_BOTTOM_Y, POLE_RIGHT_X, POLE_BOTTOM_Y, POLE_LEFT_X, POLE_TOP_Y, 
                         h->pole.r, h->pole.g, h->pole.b);
  graphics_triangle_fill(POLE_LEFT_X, POLE_TOP_Y, POLE_RIGHT_X, POLE_TOP_Y, POLE_RIGHT_X, POLE_BOTTOM_Y, h->pole.r, h->pole.g, h->pole.b);
  
  // Define constants to hold the bounds of the connecter
  const int CONNECTER_LEFT_X = POLE_LEFT_X - 20;
  const int CONNECTER_RIGHT_X = POLE_LEFT_X;
  const int CONNECTER_BOTTOM_Y = POLE_TOP_Y + 15;
  const int CONNECTER_TOP_Y = POLE_TOP_Y;
  
  // Draw the connecter
  graphics_triangle_fill(CONNECTER_LEFT_X, CONNECTER_BOTTOM_Y, CONNECTER_RIGHT_X, CONNECTER_BOTTOM_Y, CONNECTER_LEFT_X, CONNECTER_TOP_Y, 
                         h->pole.r, h->pole.g, h->pole.b);
  graphics_triangle_fill(CONNECTER_LEFT_X, CONNECTER_TOP_Y, CONNECTER_RIGHT_X, CONNECTER_TOP_Y, CONNECTER_RIGHT_X, CONNECTER_BOTTOM_Y, 
                         h->pole.r, h->pole.g, h->pole.b);
  
  // Define constants to hold the bounds of the backboard
  const int BACKBOARD_LEFT_X = CONNECTER_LEFT_X - 15;
  const int BACKBOARD_RIGHT_X = CONNECTER_LEFT_X;
  const int BACKBOARD_BOTTOM_Y = CONNECTER_BOTTOM_Y + 10;
  const int BACKBOARD_TOP_Y = CONNECTER_TOP_Y - 114;
  
  // Draw the backboard
  graphics_triangle_fill(BACKBOARD_LEFT_X, BACKBOARD_BOTTOM_Y, BACKBOARD_RIGHT_X, BACKBOARD_BOTTOM_Y, BACKBOARD_LEFT_X, BACKBOARD_TOP_Y, 
                         h->backboard.r, h->backboard.g, h->backboard.b);
  graphics_triangle_fill(BACKBOARD_LEFT_X, BACKBOARD_TOP_Y, BACKBOARD_RIGHT_X, BACKBOARD_TOP_Y, BACKBOARD_RIGHT_X, BACKBOARD_BOTTOM_Y, 
                         h->backboard.r, h->backboard.g, h->backboard.b);
  
  // Define constants to hold the bounds of the rim connecter
  const int RIM_CONNECTER_LEFT_X = BACKBOARD_LEFT_X - 5;
  const int RIM_CONNECTER_RIGHT_X = BACKBOARD_LEFT_X;
  const int RIM_CONNECTER_BOTTOM_Y = CONNECTER_TOP_Y + 3;
  const int RIM_CONNECTER_TOP_Y = CONNECTER_TOP_Y;
  
  // Draw the rim connecter
  graphics_triangle_fill(RIM_CONNECTER_LEFT_X, RIM_CONNECTER_BOTTOM_Y, RIM_CONNECTER_RIGHT_X, RIM_CONNECTER_BOTTOM_Y, 
                         RIM_CONNECTER_LEFT_X, RIM_CONNECTER_TOP_Y, h->rim.r, h->rim.g, h->rim.b);
  graphics_triangle_fill(RIM_CONNECTER_LEFT_X, RIM_CONNECTER_TOP_Y, RIM_CONNECTER_RIGHT_X, RIM_CONNECTER_TOP_Y, 
                         RIM_CONNECTER_RIGHT_X, RIM_CONNECTER_BOTTOM_Y, h->rim.r, h->rim.g, h->rim.b);
  
  // Define constants to hold the bounds of the rim
  const int RIM_LEFT_X = RIM_CONNECTER_LEFT_X - 49;
  const int RIM_RIGHT_X = RIM_CONNECTER_LEFT_X;
  const int RIM_BOTTOM_Y = RIM_CONNECTER_BOTTOM_Y + 2;
  const int RIM_TOP_Y = RIM_CONNECTER_TOP_Y;
  
  // Draw the rim
  graphics_triangle_fill(RIM_LEFT_X, RIM_BOTTOM_Y, RIM_RIGHT_X, RIM_BOTTOM_Y, RIM_LEFT_X, RIM_TOP_Y, h->rim.r, h->rim.g, h->rim.b);
  graphics_triangle_fill(RIM_LEFT_X, RIM_TOP_Y, RIM_RIGHT_X, RIM_TOP_Y, RIM_RIGHT_X, RIM_BOTTOM_Y, h->rim.r, h->rim.g, h->rim.b);
  
  // Define constants to hold the bounds of net
  const int NET_BOTTOM_Y = RIM_BOTTOM_Y + 40;
  const int NET_TOP_Y = RIM_BOTTOM_Y;
  const int NET_LEFT_X = RIM_LEFT_X;
  const int NET_RIGHT_X = RIM_RIGHT_X;
  
  // Draw the left and right bounds of the net and the middle cross
  graphics_line(NET_LEFT_X, NET_TOP_Y, NET_LEFT_X, NET_BOTTOM_Y, h->net.r, h->net.g, h->net.b);
  graphics_line(NET_RIGHT_X, NET_TOP_Y, NET_RIGHT_X, NET_BOTTOM_Y, h->net.r, h->net.g, h->net.b);
  graphics_line(NET_LEFT_X, NET_TOP_Y, NET_RIGHT_X, NET_BOTTOM_Y, h->net.r, h->net.g, h->net.b);
  graphics_line(NET_RIGHT_X, NET_TOP_Y, NET_LEFT_X, NET_BOTTOM_Y, h->net.r, h->net.g, h->net.b);
  
  // Define constants to hold quarter increments of the net's x position
  const int NET_1_4_X = ((NET_RIGHT_X - NET_LEFT_X) * (1.0 / 4.0)) + NET_LEFT_X;
  const int NET_2_4_X = ((NET_RIGHT_X - NET_LEFT_X) * (2.0 / 4.0)) + NET_LEFT_X;
  const int NET_3_4_X = ((NET_RIGHT_X - NET_LEFT_X) * (3.0 / 4.0)) + NET_LEFT_X;
  
  // Define constants to hold quarter increments of the net's y position
  const int NET_1_4_Y = ((NET_BOTTOM_Y - NET_TOP_Y) * (1.0 / 4.0)) + NET_TOP_Y;
  const int NET_2_4_Y = ((NET_BOTTOM_Y - NET_TOP_Y) * (2.0 / 4.0)) + NET_TOP_Y;
  const int NET_3_4_Y = ((NET_BOTTOM_Y - NET_TOP_Y) * (3.0 / 4.0)) + NET_TOP_Y;
  
  // Draw the remaining net strands
  graphics_line(NET_1_4_X, NET_TOP_Y, NET_LEFT_X, NET_1_4_Y, h->net.r, h->net.g, h->net.b);
  graphics_line(NET_1_4_X, NET_TOP_Y, NET_RIGHT_X, NET_3_4_Y, h->net.r, h->net.g, h->net.b);
  graphics_line(NET_2_4_X, NET_TOP_Y, NET_LEFT_X, NET_2_4_Y, h->net.r, h->net.g, h->net.b);
  graphics_line(NET_2_4_X, NET_TOP_Y, NET_RIGHT_X, NET_2_4_Y, h->net.r, h->net.g, h->net.b); 
  graphics_line(NET_3_4_X, NET_TOP_Y, NET_LEFT_X, NET_3_4_Y, h->net.r, h->net.g, h->net.b);
  graphics_line(NET_3_4_X, NET_TOP_Y, NET_RIGHT_X, NET_1_4_Y, h->net.r, h->net.g, h->net.b);
  graphics_line(NET_1_4_X, NET_BOTTOM_Y, NET_LEFT_X, NET_3_4_Y, h->net.r, h->net.g, h->net.b);
  graphics_line(NET_1_4_X, NET_BOTTOM_Y, NET_RIGHT_X, NET_1_4_Y, h->net.r, h->net.g, h->net.b);
  graphics_line(NET_2_4_X, NET_BOTTOM_Y, NET_LEFT_X, NET_2_4_Y, h->net.r, h->net.g, h->net.b);
  graphics_line(NET_2_4_X, NET_BOTTOM_Y, NET_RIGHT_X, NET_2_4_Y, h->net.r, h->net.g, h->net.b);
  graphics_line(NET_3_4_X, NET_BOTTOM_Y, NET_LEFT_X, NET_1_4_Y, h->net.r, h->net.g, h->net.b);
  graphics_line(NET_3_4_X, NET_BOTTOM_Y, NET_RIGHT_X, NET_3_4_Y, h->net.r, h->net.g, h->net.b);
  
}