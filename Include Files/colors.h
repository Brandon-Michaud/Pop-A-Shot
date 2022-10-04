// Define a struct to represent rgb values
typedef struct rgb_struct {

  // Declare a variable to hold the name of the color
  char name[100];
  
  // Declare variable to hold the rgb values
  int r;
  int g;
  int b;
  
} rgb;

// Define a function that fills a given array with rgb objects
void getColors(rgb colors[]) {
  
  // Define a variable to hold the current index in the array
  int j = 0;
  
  // Define a color to hold the first skin tone and add it to the array
  rgb skinTone1;
  skinTone1.r = 255;
  skinTone1.g = 219;
  skinTone1.b = 172;
  strcpy(skinTone1.name, "skin tone 1");
  colors[j] = skinTone1;
  ++j;
  
  // Define a color to hold the second skin tone and add it to the array
  rgb skinTone2;
  skinTone2.r = 241;
  skinTone2.g = 194;
  skinTone2.b = 125;
  strcpy(skinTone2.name, "skin tone 2");
  colors[j] = skinTone2;
  ++j;
  
  // Define a color to hold the third skin tone and add it to the array
  rgb skinTone3;
  skinTone3.r = 224;
  skinTone3.g = 172;
  skinTone3.b = 105;
  strcpy(skinTone3.name, "skin tone 3");
  colors[j] = skinTone3;
  ++j;
  
  // Define a color to hold the fourth skin tone and add it to the array
  rgb skinTone4;
  skinTone4.r = 198;
  skinTone4.g = 134;
  skinTone4.b = 66;
  strcpy(skinTone4.name, "skin tone 4");
  colors[j] = skinTone4;
  ++j;
  
  // Define a color to hold the five skin tone and add it to the array
  rgb skinTone5;
  skinTone5.r = 141;
  skinTone5.g = 85;
  skinTone5.b = 36;
  strcpy(skinTone5.name, "skin tone 5");
  colors[j] = skinTone5;
  ++j;
  
  // Define a color to represent maroon and add it to the array
  rgb maroon;
  maroon.r = 128;
  maroon.g = 0;
  maroon.b = 0;
  strcpy(maroon.name, "maroon");
  colors[j] = maroon;
  ++j;
  
  // Define a color to represent crimson and add it to the array
  rgb crimson;
  crimson.r = 220;
  crimson.g = 20;
  crimson.b = 60;
  strcpy(crimson.name, "crimson");
  colors[j] = crimson;
  ++j;
  
  // Define a color to represent red and add it to the array
  rgb red;
  red.r = 255;
  red.g = 0;
  red.b = 0;
  strcpy(red.name, "red");
  colors[j] = red;
  ++j;
  
  // Define a color to represent orange and add it to the array
  rgb orange;
  orange.r = 255;
  orange.g = 165;
  orange.b = 0;
  strcpy(orange.name, "orange");
  colors[j] = orange;
  ++j;
  
  // Define a color to represent gold and add it to the array
  rgb gold;
  gold.r = 255;
  gold.g = 215;
  gold.b = 0;
  strcpy(gold.name, "gold");
  colors[j] = gold;
  ++j;
  
  // Define a color to represent yellow and add it to the array
  rgb yellow;
  yellow.r = 255;
  yellow.g = 255;
  yellow.b = 0;
  strcpy(yellow.name, "yellow");
  colors[j] = yellow;
  ++j;
  
  // Define a color to represent green and add it to the array
  rgb green;
  green.r = 0;
  green.g = 128;
  green.b = 0;
  strcpy(green.name, "green");
  colors[j] = green;
  ++j;
  
  // Define a color to represent lime and add it to the array
  rgb lime;
  lime.r = 0;
  lime.g = 255;
  lime.b = 0;
  strcpy(lime.name, "lime");
  colors[j] = lime;
  ++j;
  
  // Define a color to represent teal and add it to the array
  rgb teal;
  teal.r = 0;
  teal.g = 128;
  teal.b = 128;
  strcpy(teal.name, "teal");
  colors[j] = teal;
  ++j;
  
  // Define a color to represent cyan and add it to the array
  rgb cyan;
  cyan.r = 0;
  cyan.g = 255;
  cyan.b = 255;
  strcpy(cyan.name, "cyan");
  colors[j] = cyan;
  ++j;
  
  // Define a color to represent turquoise and add it to the array
  rgb turquoise;
  turquoise.r = 64;
  turquoise.g = 224;
  turquoise.b = 208;
  strcpy(turquoise.name, "turquoise");
  colors[j] = turquoise;
  ++j;
  
  // Define a color to represent sky blue and add it to the array
  rgb skyBlue;
  skyBlue.r = 135;
  skyBlue.g = 206;
  skyBlue.b = 235;
  strcpy(skyBlue.name, "sky blue");
  colors[j] = skyBlue;
  ++j;
  
  // Define a color to represent navy and add it to the array
  rgb navy;
  navy.r = 0;
  navy.g = 0;
  navy.b = 128;
  strcpy(navy.name, "navy");
  colors[j] = navy;
  ++j;
  
  // Define a color to represent blue and add it to the array
  rgb blue;
  blue.r = 0;
  blue.g = 0;
  blue.b = 255;
  strcpy(blue.name, "blue");
  colors[j] = blue;
  ++j;
  
  // Define a color to represent indigo and add it to the array
  rgb indigo;
  indigo.r = 75;
  indigo.g = 0;
  indigo.b = 130;
  strcpy(indigo.name, "indigo");
  colors[j] = indigo;
  ++j;
  
  // Define a color to represent dark violet and add it to the array
  rgb darkViolet;
  darkViolet.r = 148;
  darkViolet.g = 0;
  darkViolet.b = 211;
  strcpy(darkViolet.name, "dark violet");
  colors[j] = darkViolet;
  ++j;
  
  // Define a color to represent violet and add it to the array
  rgb violet;
  violet.r = 238;
  violet.g = 130;
  violet.b = 238;
  strcpy(violet.name, "violet");
  colors[j] = violet;
  ++j;
  
  // Define a color to represent magenta and add it to the array
  rgb magenta;
  magenta.r = 255;
  magenta.g = 0;
  magenta.b = 255;
  strcpy(magenta.name, "magenta");
  colors[j] = magenta;
  ++j;
  
  // Define a color to represent deep pink and add it to the array
  rgb deepPink;
  deepPink.r = 255;
  deepPink.g = 20;
  deepPink.b = 147;
  strcpy(deepPink.name, "deep pink");
  colors[j] = deepPink;
  ++j;
  
  // Define a color to represent white and add it to the array
  rgb white;
  white.r = 255;
  white.g = 255;
  white.b = 255;
  strcpy(white.name, "white");
  colors[j] = white;
  ++j;
  
  // Define a color to represent silver and add it to the array
  rgb silver;
  silver.r = 192;
  silver.g = 192;
  silver.b = 192;
  strcpy(silver.name, "silver");
  colors[j] = silver;
  ++j;
  
  // Define a color to represent gray and add it to the array
  rgb gray;
  gray.r = 128;
  gray.g = 128;
  gray.b = 128;
  strcpy(gray.name, "gray");
  colors[j] = gray;
  ++j;
  
  // Define a color to represent black and add it to the array
  rgb black;
  black.r = 0;
  black.g = 0;
  black.b = 0;
  strcpy(black.name, "black");
  colors[j] = black;
  ++j;
  
  // Define a color to represent the color of a basketball and add it to the array
  rgb basketball;
  basketball.r = 181;
  basketball.g = 66;
  basketball.b = 19;
  strcpy(basketball.name, "basketball");
  colors[j] = basketball;
  ++j;
  
}