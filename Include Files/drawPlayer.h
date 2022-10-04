// Define a struct to represent a player
typedef struct player_struct {
  
  // Declare variables to hold the color of the shirt and its index in the color array
  rgb shirt;
  int shirtIdx;
  
  // Declare variables to hold the color of the pants and its index in the color array
  rgb pants;
  int pantsIdx;
  
  // Declare variables to hold the color of the shoes and its index in the color array
  rgb shoes;
  int shoesIdx;
  
  // Declare variables to hold the color of the skin and its index in the color array
  rgb skin; 
  int skinIdx;
  
} player;

// Define a function that initializes a given player object
void playerInitializer(player* pl) {
  
  // Declare an array to hold colors
  rgb colors[100];
  
  // Populate the array with colors
  getColors(colors);
  
  // Define variables to hold the default color of the shoes and its index in the color array
  pl->shoesIdx = 27;
  pl->shoes = colors[27];
  
  // Define variables to hold the default color of the shirt and its index in the color array
  pl->shirtIdx = 7;
  pl->shirt = colors[7];
  
  // Define variables to hold the default color of the pants and its index in the color array
  pl->pantsIdx = 18;
  pl->pants = colors[18];
  
  // Define variables to hold the default color of the skin and its index in the color array
  pl->skinIdx = 1;
  pl->skin = colors[1];
  
}

// Define a function that draws a given player object and a ball at a given position and angles
void drawPlayer(player* p, int x, int y, int a, int k, int s, int e, int w, int bb, ball* b) {
  
  // Define constants to hold the bounds of the foot
  const int FOOT_BOTTOM = y;
  const int FOOT_TOP = FOOT_BOTTOM - 10;
  const int FOOT_LEFT = x;
  const int FOOT_RIGHT = FOOT_LEFT + 23;
  
  // Define constants to hold the position of the ankle joint and its radius
  const int ANKLE_X = FOOT_LEFT + 8;
  const int ANKLE_Y = FOOT_TOP;
  const int ANKLE_RADIUS = 8;
  
  // Draw the ankle joint
  graphics_circle_fill(ANKLE_X, ANKLE_Y, ANKLE_RADIUS, p->pants.r, p->pants.g, p->pants.b);
  
  // Define constants to hold the position of the knee joint and its radius
  const int KNEE_X = ANKLE_X;
  const int KNEE_Y = ANKLE_Y - 39;
  const int KNEE_RADIUS = ANKLE_RADIUS;
  
  // Convert the ankle angle to radians
  const double ANKLE_ANGLE = a * (PI / 180.8);
  
  // Draw the knee joint
  graphics_circle_fill(xRotate(KNEE_X, KNEE_Y, ANKLE_X, ANKLE_Y, ANKLE_ANGLE), yRotate(KNEE_X, KNEE_Y, ANKLE_X, ANKLE_Y, ANKLE_ANGLE),
                       KNEE_RADIUS, p->pants.r, p->pants.g, p->pants.b);
  // Draw the shin
  drawQuadrilateral(xRotate(KNEE_X - KNEE_RADIUS, KNEE_Y, ANKLE_X, ANKLE_Y, ANKLE_ANGLE),
  					yRotate(KNEE_X - KNEE_RADIUS, KNEE_Y, ANKLE_X, ANKLE_Y, ANKLE_ANGLE),
  					xRotate(KNEE_X + KNEE_RADIUS, KNEE_Y, ANKLE_X, ANKLE_Y, ANKLE_ANGLE),
 					yRotate(KNEE_X + KNEE_RADIUS, KNEE_Y, ANKLE_X, ANKLE_Y, ANKLE_ANGLE),
  					xRotate(ANKLE_X + ANKLE_RADIUS, ANKLE_Y, ANKLE_X, ANKLE_Y, ANKLE_ANGLE),
  					yRotate(ANKLE_X + ANKLE_RADIUS, ANKLE_Y, ANKLE_X, ANKLE_Y, ANKLE_ANGLE),
  					xRotate(ANKLE_X - ANKLE_RADIUS, ANKLE_Y, ANKLE_X, ANKLE_Y, ANKLE_ANGLE),
  					yRotate(ANKLE_X - ANKLE_RADIUS, ANKLE_Y, ANKLE_X, ANKLE_Y, ANKLE_ANGLE), p->pants.r, p->pants.g, p->pants.b);
  
  // Draw the foot
  drawQuadrilateral(FOOT_LEFT, FOOT_TOP, FOOT_RIGHT, FOOT_TOP, FOOT_RIGHT, FOOT_BOTTOM, FOOT_LEFT, FOOT_BOTTOM, 
                    p->shoes.r, p->shoes.g, p->shoes.b);
  drawQuarterCircleFill(FOOT_RIGHT, FOOT_BOTTOM, FOOT_BOTTOM - FOOT_TOP, 0, p->shoes.r, p->shoes.g, p->shoes.b);
  
  // Define constants to hold the position of the knee rotated about the ankle
  const int ACTUAL_KNEE_X = xRotate(ANKLE_X, ANKLE_Y - 39, ANKLE_X, ANKLE_Y, ANKLE_ANGLE);
  const int ACTUAL_KNEE_Y = yRotate(ANKLE_X, ANKLE_Y - 39, ANKLE_X, ANKLE_Y, ANKLE_ANGLE);
  
  // Define constants to hold the position of the hip joint and its radius
  const int HIP_X = ACTUAL_KNEE_X;
  const int HIP_Y = ACTUAL_KNEE_Y - 40;
  const int HIP_RADIUS = KNEE_RADIUS;
  
  // Convert the knee angle to radians
  const double KNEE_ANGLE = k * (PI / 180.0);
  
  // Draw the hip joint
  graphics_circle_fill(xRotate(HIP_X, HIP_Y, ACTUAL_KNEE_X, ACTUAL_KNEE_Y, KNEE_ANGLE), 
                       yRotate(HIP_X, HIP_Y, ACTUAL_KNEE_X, ACTUAL_KNEE_Y, KNEE_ANGLE), HIP_RADIUS, p->pants.r, p->pants.g, p->pants.b);
  
  // Draw the thigh
  drawQuadrilateral(xRotate(HIP_X - HIP_RADIUS, HIP_Y, ACTUAL_KNEE_X, ACTUAL_KNEE_Y, KNEE_ANGLE),
  					yRotate(HIP_X - HIP_RADIUS, HIP_Y, ACTUAL_KNEE_X, ACTUAL_KNEE_Y, KNEE_ANGLE),
  					xRotate(HIP_X + HIP_RADIUS, HIP_Y, ACTUAL_KNEE_X, ACTUAL_KNEE_Y, KNEE_ANGLE),
 					yRotate(HIP_X + HIP_RADIUS, HIP_Y, ACTUAL_KNEE_X, ACTUAL_KNEE_Y, KNEE_ANGLE),
  					xRotate(ACTUAL_KNEE_X + KNEE_RADIUS, ACTUAL_KNEE_Y, ACTUAL_KNEE_X, ACTUAL_KNEE_Y, KNEE_ANGLE),
  					yRotate(ACTUAL_KNEE_X + KNEE_RADIUS, ACTUAL_KNEE_Y, ACTUAL_KNEE_X, ACTUAL_KNEE_Y, KNEE_ANGLE),
  					xRotate(ACTUAL_KNEE_X - KNEE_RADIUS, ACTUAL_KNEE_Y, ACTUAL_KNEE_X, ACTUAL_KNEE_Y, KNEE_ANGLE),
  					yRotate(ACTUAL_KNEE_X - KNEE_RADIUS, ACTUAL_KNEE_Y, ACTUAL_KNEE_X, ACTUAL_KNEE_Y, KNEE_ANGLE), 
                    p->pants.r, p->pants.g, p->pants.b);
  
  // Define constants to hold the position of hip rotated about the knee
  const int ACTUAL_HIP_X = xRotate(ACTUAL_KNEE_X, ACTUAL_KNEE_Y - 40, ACTUAL_KNEE_X, ACTUAL_KNEE_Y, KNEE_ANGLE);
  const int ACTUAL_HIP_Y = yRotate(ACTUAL_KNEE_X, ACTUAL_KNEE_Y - 40, ACTUAL_KNEE_X, ACTUAL_KNEE_Y, KNEE_ANGLE);
  
  // Define constants to hold the bounds of the torso
  const int TORSO_BOTTOM = ACTUAL_HIP_Y;
  const int TORSO_TOP = TORSO_BOTTOM - 71;
  const int TORSO_LEFT = ACTUAL_HIP_X - HIP_RADIUS;
  const int TORSO_RIGHT = ACTUAL_HIP_X + HIP_RADIUS;
  
  // Draw the torso
  drawQuadrilateral(TORSO_LEFT, TORSO_TOP, TORSO_RIGHT, TORSO_TOP, TORSO_RIGHT, TORSO_BOTTOM, TORSO_LEFT, TORSO_BOTTOM, 
                    p->shirt.r, p->shirt.g, p->shirt.b);
  
  // Define constants to hold the bounds of the neck
  const int NECK_BOTTOM = TORSO_TOP;
  const int NECK_TOP = NECK_BOTTOM - 19;
  const int NECK_LEFT = ((TORSO_RIGHT - TORSO_LEFT) / 2) + TORSO_LEFT - 6;
  const int NECK_RIGHT = NECK_LEFT + 12;
  
  // Draw the neck
  drawQuadrilateral(NECK_LEFT, NECK_TOP, NECK_RIGHT, NECK_TOP, NECK_RIGHT, NECK_BOTTOM, NECK_LEFT, NECK_BOTTOM, 
                    p->skin.r, p->skin.g, p->skin.b);
  
  // Define constants to hold the position of the head and its radius
  const int HEAD_X = ((NECK_RIGHT - NECK_LEFT) / 2) + NECK_LEFT;
  const int HEAD_Y = NECK_TOP;
  const int HEAD_RADIUS = 16;
  
  // Draw the head
  graphics_circle_fill(HEAD_X, HEAD_Y, HEAD_RADIUS, p->skin.r, p->skin.g, p->skin.b);
  
  // Define constants to hold the position of the shoulder joint and its radius
  const int SHOULDER_X = ((TORSO_RIGHT - TORSO_LEFT) / 2) + TORSO_LEFT;
  const int SHOULDER_Y = TORSO_TOP + ((TORSO_RIGHT - TORSO_LEFT) / 2) + 1;
  const int SHOULDER_RADIUS = 6;
  
  // Draw the shoulder joint
  graphics_circle_fill(SHOULDER_X, SHOULDER_Y, SHOULDER_RADIUS, p->shirt.r, p->shirt.g, p->shirt.b);
  
  // Define constants to hold the positions of the elbow joint and its radius
  const int ELBOW_X = SHOULDER_X + 39;
  const int ELBOW_Y = SHOULDER_Y;
  const int ELBOW_RADIUS = SHOULDER_RADIUS;
  
  // Convert the shoulder angle to radians
  const double SHOULDER_ANGLE = s * (PI / 180.0);
  
  // Draw the elbow joint
  graphics_circle_fill(xRotate(ELBOW_X, ELBOW_Y, SHOULDER_X, SHOULDER_Y, SHOULDER_ANGLE), 
                       yRotate(ELBOW_X, ELBOW_Y, SHOULDER_X, SHOULDER_Y, SHOULDER_ANGLE), ELBOW_RADIUS, p->skin.r, p->skin.g, p->skin.b);
  
  // Draw the upper arm
  drawQuadrilateral(xRotate(SHOULDER_X, SHOULDER_Y - SHOULDER_RADIUS, SHOULDER_X, SHOULDER_Y, SHOULDER_ANGLE),
                    yRotate(SHOULDER_X, SHOULDER_Y - SHOULDER_RADIUS, SHOULDER_X, SHOULDER_Y, SHOULDER_ANGLE),
                    xRotate(ELBOW_X, ELBOW_Y - ELBOW_RADIUS, SHOULDER_X, SHOULDER_Y, SHOULDER_ANGLE),
  					yRotate(ELBOW_X, ELBOW_Y - ELBOW_RADIUS, SHOULDER_X, SHOULDER_Y, SHOULDER_ANGLE),
  					xRotate(ELBOW_X, ELBOW_Y + ELBOW_RADIUS, SHOULDER_X, SHOULDER_Y, SHOULDER_ANGLE),
  					yRotate(ELBOW_X, ELBOW_Y + ELBOW_RADIUS, SHOULDER_X, SHOULDER_Y, SHOULDER_ANGLE),
  					xRotate(SHOULDER_X, SHOULDER_Y + SHOULDER_RADIUS, SHOULDER_X, SHOULDER_Y, SHOULDER_ANGLE),
  					yRotate(SHOULDER_X, SHOULDER_Y + SHOULDER_RADIUS, SHOULDER_X, SHOULDER_Y, SHOULDER_ANGLE), 
                    p->skin.r, p->skin.g, p->skin.b);
  
  // Define constants to hold the bounds of the sleeve
  const int SLEEVE_X = SHOULDER_X + 15;
  const int SLEEVE_Y = SHOULDER_Y;
  
  // Draw the sleev
  drawQuadrilateral(xRotate(SHOULDER_X, SHOULDER_Y - SHOULDER_RADIUS, SHOULDER_X, SHOULDER_Y, SHOULDER_ANGLE),
                    yRotate(SHOULDER_X, SHOULDER_Y - SHOULDER_RADIUS, SHOULDER_X, SHOULDER_Y, SHOULDER_ANGLE),
                    xRotate(SLEEVE_X, SLEEVE_Y - ELBOW_RADIUS, SHOULDER_X, SHOULDER_Y, SHOULDER_ANGLE),
  					yRotate(SLEEVE_X, SLEEVE_Y - ELBOW_RADIUS, SHOULDER_X, SHOULDER_Y, SHOULDER_ANGLE),
  					xRotate(SLEEVE_X, SLEEVE_Y + ELBOW_RADIUS, SHOULDER_X, SHOULDER_Y, SHOULDER_ANGLE),
  					yRotate(SLEEVE_X, SLEEVE_Y + ELBOW_RADIUS, SHOULDER_X, SHOULDER_Y, SHOULDER_ANGLE),
  					xRotate(SHOULDER_X, SHOULDER_Y + SHOULDER_RADIUS, SHOULDER_X, SHOULDER_Y, SHOULDER_ANGLE),
  					yRotate(SHOULDER_X, SHOULDER_Y + SHOULDER_RADIUS, SHOULDER_X, SHOULDER_Y, SHOULDER_ANGLE), 
                    p->shirt.r, p->shirt.g, p->shirt.b);
  
  // Define constants to hold the position of elbow rotated about the shoulder
  const int ACTUAL_ELBOW_X = xRotate(SHOULDER_X + 39, SHOULDER_Y, SHOULDER_X, SHOULDER_Y, SHOULDER_ANGLE);
  const int ACTUAL_ELBOW_Y = yRotate(SHOULDER_X + 39, SHOULDER_Y, SHOULDER_X, SHOULDER_Y, SHOULDER_ANGLE);
  
  // Define constants to hold the position of the wrist joint and its radius
  const int WRIST_X = ACTUAL_ELBOW_X + 33;
  const int WRIST_Y = ACTUAL_ELBOW_Y;
  const int WRIST_RADIUS = 4;
  
  // Convert the elbow angle to radians
  const double ELBOW_ANGLE = e * (PI / 180.0);
  
  // Draw the wrist joint
  graphics_circle_fill(xRotate(WRIST_X, WRIST_Y, ACTUAL_ELBOW_X, ACTUAL_ELBOW_Y, ELBOW_ANGLE), 
                       yRotate(WRIST_X, WRIST_Y, ACTUAL_ELBOW_X, ACTUAL_ELBOW_Y, ELBOW_ANGLE), WRIST_RADIUS, 
                       p->skin.r, p->skin.g, p->skin.b);
  
  // Draw the forearm
  drawQuadrilateral(xRotate(ACTUAL_ELBOW_X, ACTUAL_ELBOW_Y - ELBOW_RADIUS, ACTUAL_ELBOW_X, ACTUAL_ELBOW_Y, ELBOW_ANGLE),
  					yRotate(ACTUAL_ELBOW_X, ACTUAL_ELBOW_Y - ELBOW_RADIUS, ACTUAL_ELBOW_X, ACTUAL_ELBOW_Y, ELBOW_ANGLE),
  					xRotate(WRIST_X, WRIST_Y - WRIST_RADIUS, ACTUAL_ELBOW_X, ACTUAL_ELBOW_Y, ELBOW_ANGLE),
  					yRotate(WRIST_X, WRIST_Y - WRIST_RADIUS, ACTUAL_ELBOW_X, ACTUAL_ELBOW_Y, ELBOW_ANGLE),
  					xRotate(WRIST_X, WRIST_Y + WRIST_RADIUS, ACTUAL_ELBOW_X, ACTUAL_ELBOW_Y, ELBOW_ANGLE),
  					yRotate(WRIST_X, WRIST_Y + WRIST_RADIUS, ACTUAL_ELBOW_X, ACTUAL_ELBOW_Y, ELBOW_ANGLE),
  					xRotate(ACTUAL_ELBOW_X, ACTUAL_ELBOW_Y + ELBOW_RADIUS, ACTUAL_ELBOW_X, ACTUAL_ELBOW_Y, ELBOW_ANGLE),
  					yRotate(ACTUAL_ELBOW_X, ACTUAL_ELBOW_Y + ELBOW_RADIUS, ACTUAL_ELBOW_X, ACTUAL_ELBOW_Y, ELBOW_ANGLE), 
                    p->skin.r, p->skin.g, p->skin.b);
  
  // Define constants to hold the position of wrist rotated about the elbow
  const int ACTUAL_WRIST_X = xRotate(ACTUAL_ELBOW_X + 33, ACTUAL_ELBOW_Y, ACTUAL_ELBOW_X, ACTUAL_ELBOW_Y, ELBOW_ANGLE);
  const int ACTUAL_WRIST_Y = yRotate(ACTUAL_ELBOW_X + 33, ACTUAL_ELBOW_Y, ACTUAL_ELBOW_X, ACTUAL_ELBOW_Y, ELBOW_ANGLE);
  
  // Define constants to hold the bounds of the hand
  const int HAND_LEFT = ACTUAL_WRIST_X;
  const int HAND_RIGHT = ACTUAL_WRIST_X + 18;
  const int HAND_TOP = ACTUAL_WRIST_Y - WRIST_RADIUS;
  const int HAND_BOTTOM = ACTUAL_WRIST_Y + WRIST_RADIUS;
  
  // Convert the wrist angle to radians
  const double WRIST_ANGLE = w * (PI / 180.0);
  
  // Draw the hand
  drawQuadrilateral(xRotate(HAND_LEFT, HAND_TOP, ACTUAL_WRIST_X, ACTUAL_WRIST_Y, WRIST_ANGLE),
  					yRotate(HAND_LEFT, HAND_TOP, ACTUAL_WRIST_X, ACTUAL_WRIST_Y, WRIST_ANGLE),
  					xRotate(HAND_RIGHT, HAND_TOP + 2, ACTUAL_WRIST_X, ACTUAL_WRIST_Y, WRIST_ANGLE),
  					yRotate(HAND_RIGHT, HAND_TOP + 2, ACTUAL_WRIST_X, ACTUAL_WRIST_Y, WRIST_ANGLE),
  					xRotate(HAND_RIGHT, HAND_BOTTOM - 2, ACTUAL_WRIST_X, ACTUAL_WRIST_Y, WRIST_ANGLE),
  					yRotate(HAND_RIGHT, HAND_BOTTOM - 2, ACTUAL_WRIST_X, ACTUAL_WRIST_Y, WRIST_ANGLE),
  					xRotate(HAND_LEFT, HAND_BOTTOM, ACTUAL_WRIST_X, ACTUAL_WRIST_Y, WRIST_ANGLE),
  					yRotate(HAND_LEFT, HAND_BOTTOM, ACTUAL_WRIST_X, ACTUAL_WRIST_Y, WRIST_ANGLE), p->skin.r, p->skin.g, p->skin.b);
  
  // Draw the finger tips
  graphics_circle_fill(xRotate(HAND_RIGHT, ((HAND_BOTTOM - HAND_TOP) / 2) + HAND_TOP, ACTUAL_WRIST_X, ACTUAL_WRIST_Y, WRIST_ANGLE), 
                       yRotate(HAND_RIGHT, ((HAND_BOTTOM - HAND_TOP) / 2) + HAND_TOP, ACTUAL_WRIST_X, ACTUAL_WRIST_Y, WRIST_ANGLE), 
                       ((HAND_BOTTOM - HAND_TOP - 4) / 2), 
                       p->skin.r, p->skin.g, p->skin.b);
  
  // If the ball is supposed to be drawn, draw it
  if (bb == 1) {
    
    // Update the position of the ball to be connected to the hand
    b->x = xRotate(((HAND_RIGHT - HAND_LEFT) / 2) + HAND_LEFT, HAND_BOTTOM - 1 + 13, ACTUAL_WRIST_X, ACTUAL_WRIST_Y, WRIST_ANGLE);
    b->y = yRotate(((HAND_RIGHT - HAND_LEFT) / 2) + HAND_LEFT, HAND_BOTTOM - 1 + 13, ACTUAL_WRIST_X, ACTUAL_WRIST_Y, WRIST_ANGLE);
    
    // Draw the ball rotated by the wrist angle
    drawBall(b, WRIST_ANGLE * (180.0 / PI));
    
  }
  
}

// Define a function that draws the player at the bottom of its stance
void drawPlayerBottom(player* pl, int x, int y, ball* b) {
  
  // Draw the player at the bottom of its stance
  drawPlayer(pl, x, y, -25, 25, -100, -15, 0, 1, b);
  
}

// Define a function that draws the player at the top of its stance
void drawPlayerTop(player* pl, int x, int y, ball* b) {
  
  // Draw the player at the top of its stance
  drawPlayer(pl, x, y, 0, 0, 70, 70, 0, 0, b);
  
}