Cubetube-Library-FastLED: An implementation of the beta-cube-library using FastLED instead of Neopixel to drive the WS2812 strips.

API Summary:

struct Color: An RGB color.
struct Point: A point in 3D space.

class Cube: An L3D LED cube. Provides methods for drawing in 3D. Controls the LED hardware.
    Public Properties:
      int size;
      int maxBrightness;
      Point center;
      float theta, phi;
      int accelerometerX, accelerometerY, accelerometerZ;

    Constructors:
      Cube(void);
      Cube(unsigned int s, unsigned int mb);
        s: Size of one side of the cube in number of LEDs.
        mb: Maximum brightness value. Used to prevent the LEDs from drawing too much current (which causes the colors to distort).

    Public Methods:
      Set a voxel at a position to a color:
      void setVoxel(int x, int y, int z, Color col)
        x, y, z: Coordinate of the LED to set.
        col: Color to set the LED to.
      
      void setVoxel(int index, Color col)
        index: Index of the LED to set.
        col: Color to set the LED to.
      
      void setVoxel(Point p, Color col)
        p: Coordinate of the LED to set.
        col: Color to set the LED to.
      
      Get the color of a voxel at a position:
      Color getVoxel(int x, int y, int z)
        x, y, z: Coordinate of the LED to get the color from.
      
      Color getVoxel(int index)
        index: Coordinate of the LED to get the color from.
      
      Color getVoxel(Point p)
        p: Coordinate of the LED to get the color from.

      void setBrightness(int value): Sets the brightness of the LED strips to a given value.
        value: Brightness value to be set (0 - 255).
      
      int getBrightness(void): Gets the brightness of the LED strips.
      
      Draw a line in 3D space. Uses the 3D form of Bresenham's algorithm:
      void line(int x1, int y1, int z1, int x2, int y2, int z2, Color col)
        x1, y1, z1: Coordinate of start of line.
        x2, y2, z2: Coordinate of end of line.
        col: Color of the line.      
      
      void line(Point p1, Point p2, Color col)
        p1: Coordinate of start of line.
        p2: Coordinate of end of line.
        col: Color of the line.
      
      Draw a filled sphere:
      void sphere(int x, int y, int z, int r, Color col)
        x, y, z: Position of the center of the sphere.
        r: Radius of the sphere.
        col: Color of the sphere.      
      
      void sphere(Point p, int r, Color col)
        p: Position of the center of the sphere.
        r: Radius of the sphere.
        col: Color of the sphere.
      
      Draw a shell (empty sphere):
      void shell(float x, float y, float z, float r, Color col)
        x: Position of the center of the shell.
        y: Position of the center of the shell.
        z: Position of the center of the shell.
        r: Radius of the shell.
        col: Color of the shell.
      
      void shell(float x, float y, float z, float r, float thickness, Color col)
        x: Position of the center of the shell.
        y: Position of the center of the shell.
        z: Position of the center of the shell.
        r: Radius of the shell.
        thickness: Thickness of the shell.
        col: Color of the shell.
      
      void shell(Point p, float r, Color col)
        p: Position of the center of the shell.
        r: Radius of the shell.
        col: Color of the shell.
      
      void shell(Point p, float r, float thickness, Color col)
        p: Position of the center of the shell.
        r: Radius of the shell.
        thickness: Thickness of the shell
        col: Color of the shell.
      
      void updateAccelerometer(): Updates the variables related to the accelerometer. 
      Updates accelerometerX, accelerometerY and accelerometerZ, which are directly read 
      from the analog pins, minus 2048 to remove the DC bias.
      Calculates theta and phi, which are the 3D rotation angles.
      
      void background(Color col): Set the entire cube to one color.
        col: The color to set all LEDs in the cube to.
      
      void fade(float coeff=0.0625f): Fade the entire cube to black.
        coeff: The coefficient to dim all LEDs in the cube each time (defaults to 0.0625f).
      
      void clear(): Clear the entire cube.
      
      Color colorMap(float val, float min, float max): Map a value into a color.
      The set of colors fades from blue to green to red and back again.
        val: Value to map into a color.
        min: Minimum value that val will take.
        max: Maximum value that val will take.

      Color lerpColor(Color a, Color b, int val, int min, int max): Linear interpolation between colors.
        a, b: The colors to interpolate between.
        val: Position on the line between color a and color b. When equal to min the output is color a,
             and when equal to max the output is color b.
        min: Minimum value that val will take.
        max: Maximum value that val will take.
      
      int setPort(String port): Function to be called via Particle API for updating the streaming port number.
      Resets the UDP connection with the new port.
        _port: A decimal number in a String, corresponding to the desired port number.
        
      void begin(void): Initialization of cube resources and environment.
      void show(void): Make changes to the cube visible. Causes pixel data to be written to the LED strips.
      void listen(void): Listen for the start of UDP streaming.
      void initButtons(void): Initialize online/offline switch and the join wifi button.
      void onlineOfflineSwitch(void): React to a change of the online/offline switch.
      void updateNetworkInfo(void): Update the cube's knowledge of its own network address.
      void joinWifi(void): Causes the Cube to connect the internal WiFi module.
