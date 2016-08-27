#ifndef _L3D_H
#define _L3D_H

#include "FastLED.h"
FASTLED_USING_NAMESPACE;

#if FASTLED_VERSION < 3001000
#error "Requires FastLED 3.1 or later; check github for latest code."
#endif

#define PIXEL_COUNT 512
#define PIXEL_PIN D0
#define PIXEL_TYPE WS2812B
#define COLOR_ORDER GRB

#define INTERNET_BUTTON D2
#define MODE D3

#define STREAMING_PORT 2222

/**   Accelerometer pinout */
#ifndef X 
#define X 13 
#endif
#ifndef Y 
#define Y 14 
#endif
#ifndef Z 
#define Z 15 
#endif

/**   An RGB color. */
struct Color
{
  uint8_t red, green, blue;

  Color(uint8_t r, uint8_t g, uint8_t b) : red(r), green(g), blue(b) {}
  Color() : red(0), green(0), blue(0) {}
};

/**   A point in 3D space.  */
struct Point
{
  float x;
  float y;
  float z;
  Point() : x(0), y(0), z(0) {}
  Point(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
};

/**   An L3D LED cube.
      Provides methods for drawing in 3D. Controls the LED hardware.
*/
class Cube
{
  private:
    bool onlinePressed;
    bool lastOnline;
	CRGB leds[PIXEL_COUNT];
    UDP udp;
    int lastUpdated;
    char localIP[24];
    char macAddress[20];
    int port;

  public:
    int size;
    int maxBrightness;
    Point center;
    float theta, phi;
    int accelerometerX, accelerometerY, accelerometerZ;
    Cube(unsigned int s, unsigned int mb);
    Cube(void);

    void setVoxel(int x, int y, int z, Color col);
	void setVoxel(int index, Color col);
    void setVoxel(Point p, Color col);
	void setBrightness(int value);
    Color getVoxel(int x, int y, int z);
	Color getVoxel(int index);
    Color getVoxel(Point p);
	int getBrightness(void);
    void line(int x1, int y1, int z1, int x2, int y2, int z2, Color col);
    void line(Point p1, Point p2, Color col);
    void sphere(int x, int y, int z, int r, Color col);
    void sphere(Point p, int r, Color col);
    void shell(float x, float y, float z, float r, Color col);
    void shell(float x, float y, float z, float r, float thickness, Color col);
    void shell(Point p, float r, Color col);
    void shell(Point p, float r, float thickness, Color col);
	void updateAccelerometer();
    void background(Color col);
	void fade(float coeff=0.0625f);
	void clear();

    Color colorMap(float val, float min, float max);
    Color lerpColor(Color a, Color b, int val, int min, int max);

    void begin(void);
    void show(void);
    void listen(void);
    void initButtons(void);
    void onlineOfflineSwitch(void);
    void joinWifi(void);
    void updateNetworkInfo(void);
    int setPort(String port);
};

// common FastLED colors
const Color AliceBlue				= Color((CRGB::AliceBlue >> 16) & 0xff, (CRGB::AliceBlue >> 8) & 0xff, CRGB::AliceBlue & 0xff);
const Color Amethyst				= Color((CRGB::Amethyst >> 16) & 0xff, (CRGB::Amethyst >> 8) & 0xff, CRGB::Amethyst & 0xff);
const Color AntiqueWhite			= Color((CRGB::AntiqueWhite >> 16) & 0xff, (CRGB::AntiqueWhite >> 8) & 0xff, CRGB::AntiqueWhite & 0xff);
const Color Aqua					= Color((CRGB::Aqua >> 16) & 0xff, (CRGB::Aqua >> 8) & 0xff, CRGB::Aqua & 0xff);
const Color Aquamarine				= Color((CRGB::Aquamarine >> 16) & 0xff, (CRGB::Aquamarine >> 8) & 0xff, CRGB::Aquamarine & 0xff);
const Color Azure					= Color((CRGB::Azure >> 16) & 0xff, (CRGB::Azure >> 8) & 0xff, CRGB::Azure & 0xff);
const Color Beige					= Color((CRGB::Beige >> 16) & 0xff, (CRGB::Beige >> 8) & 0xff, CRGB::Beige & 0xff);
const Color Bisque					= Color((CRGB::Bisque >> 16) & 0xff, (CRGB::Bisque >> 8) & 0xff, CRGB::Bisque & 0xff);
const Color Black					= Color((CRGB::Black >> 16) & 0xff, (CRGB::Black >> 8) & 0xff, CRGB::Black & 0xff);												
const Color BlanchedAlmond			= Color((CRGB::BlanchedAlmond >> 16) & 0xff, (CRGB::BlanchedAlmond >> 8) & 0xff, CRGB::BlanchedAlmond & 0xff);
const Color Blue					= Color((CRGB::Blue >> 16) & 0xff, (CRGB::Blue >> 8) & 0xff, CRGB::Blue & 0xff);												
const Color BlueViolet				= Color((CRGB::BlueViolet >> 16) & 0xff, (CRGB::BlueViolet >> 8) & 0xff, CRGB::BlueViolet & 0xff);								
const Color Brown					= Color((CRGB::Brown >> 16) & 0xff, (CRGB::Brown >> 8) & 0xff, CRGB::Brown & 0xff);													
const Color BurlyWood				= Color((CRGB::BurlyWood >> 16) & 0xff, (CRGB::BurlyWood >> 8) & 0xff, CRGB::BurlyWood & 0xff);									
const Color CadetBlue				= Color((CRGB::CadetBlue >> 16) & 0xff, (CRGB::CadetBlue >> 8) & 0xff, CRGB::CadetBlue & 0xff);									
const Color Chartreuse				= Color((CRGB::Chartreuse >> 16) & 0xff, (CRGB::Chartreuse >> 8) & 0xff, CRGB::Chartreuse & 0xff);								
const Color Chocolate				= Color((CRGB::Chocolate >> 16) & 0xff, (CRGB::Chocolate >> 8) & 0xff, CRGB::Chocolate & 0xff);									
const Color Coral					= Color((CRGB::Coral >> 16) & 0xff, (CRGB::Coral >> 8) & 0xff, CRGB::Coral & 0xff);												
const Color CornflowerBlue			= Color((CRGB::CornflowerBlue >> 16) & 0xff, (CRGB::CornflowerBlue >> 8) & 0xff, CRGB::CornflowerBlue & 0xff);					
const Color Cornsilk				= Color((CRGB::Cornsilk >> 16) & 0xff, (CRGB::Cornsilk >> 8) & 0xff, CRGB::Cornsilk & 0xff);									
const Color Crimson					= Color((CRGB::Crimson >> 16) & 0xff, (CRGB::Crimson >> 8) & 0xff, CRGB::Crimson & 0xff);										
const Color Cyan					= Color((CRGB::Cyan >> 16) & 0xff, (CRGB::Cyan >> 8) & 0xff, CRGB::Cyan & 0xff);												
const Color DarkBlue				= Color((CRGB::DarkBlue >> 16) & 0xff, (CRGB::DarkBlue >> 8) & 0xff, CRGB::DarkBlue & 0xff);									
const Color DarkCyan				= Color((CRGB::DarkCyan >> 16) & 0xff, (CRGB::DarkCyan >> 8) & 0xff, CRGB::DarkCyan & 0xff);									
const Color DarkGoldenrod			= Color((CRGB::DarkGoldenrod >> 16) & 0xff, (CRGB::DarkGoldenrod >> 8) & 0xff, CRGB::DarkGoldenrod & 0xff);						
const Color DarkGray				= Color((CRGB::DarkGray >> 16) & 0xff, (CRGB::DarkGray >> 8) & 0xff, CRGB::DarkGray & 0xff);									
const Color DarkGrey				= Color((CRGB::DarkGrey >> 16) & 0xff, (CRGB::DarkGrey >> 8) & 0xff, CRGB::DarkGrey & 0xff);									
const Color DarkGreen				= Color((CRGB::DarkGreen >> 16) & 0xff, (CRGB::DarkGreen >> 8) & 0xff, CRGB::DarkGreen & 0xff);									
const Color DarkKhaki				= Color((CRGB::DarkKhaki >> 16) & 0xff, (CRGB::DarkKhaki >> 8) & 0xff, CRGB::DarkKhaki & 0xff);									
const Color DarkMagenta				= Color((CRGB::DarkMagenta >> 16) & 0xff, (CRGB::DarkMagenta >> 8) & 0xff, CRGB::DarkMagenta & 0xff);							
const Color DarkOliveGreen			= Color((CRGB::DarkOliveGreen >> 16) & 0xff, (CRGB::DarkOliveGreen >> 8) & 0xff, CRGB::DarkOliveGreen & 0xff);					
const Color DarkOrange				= Color((CRGB::DarkOrange >> 16) & 0xff, (CRGB::DarkOrange >> 8) & 0xff, CRGB::DarkOrange & 0xff);								
const Color DarkOrchid				= Color((CRGB::DarkOrchid >> 16) & 0xff, (CRGB::DarkOrchid >> 8) & 0xff, CRGB::DarkOrchid & 0xff);								
const Color DarkRed					= Color((CRGB::DarkRed >> 16) & 0xff, (CRGB::DarkRed >> 8) & 0xff, CRGB::DarkRed & 0xff);										
const Color DarkSalmon				= Color((CRGB::DarkSalmon >> 16) & 0xff, (CRGB::DarkSalmon >> 8) & 0xff, CRGB::DarkSalmon & 0xff);								
const Color DarkSeaGreen			= Color((CRGB::DarkSeaGreen >> 16) & 0xff, (CRGB::DarkSeaGreen >> 8) & 0xff, CRGB::DarkSeaGreen & 0xff);						
const Color DarkSlateBlue			= Color((CRGB::DarkSlateBlue >> 16) & 0xff, (CRGB::DarkSlateBlue >> 8) & 0xff, CRGB::DarkSlateBlue & 0xff);						
const Color DarkSlateGray			= Color((CRGB::DarkSlateGray >> 16) & 0xff, (CRGB::DarkSlateGray >> 8) & 0xff, CRGB::DarkSlateGray & 0xff);						
const Color DarkSlateGrey			= Color((CRGB::DarkSlateGrey >> 16) & 0xff, (CRGB::DarkSlateGrey >> 8) & 0xff, CRGB::DarkSlateGrey & 0xff);						
const Color DarkTurquoise			= Color((CRGB::DarkTurquoise >> 16) & 0xff, (CRGB::DarkTurquoise >> 8) & 0xff, CRGB::DarkTurquoise & 0xff);						
const Color DarkViolet				= Color((CRGB::DarkViolet >> 16) & 0xff, (CRGB::DarkViolet >> 8) & 0xff, CRGB::DarkViolet & 0xff);								
const Color DeepPink				= Color((CRGB::DeepPink >> 16) & 0xff, (CRGB::DeepPink >> 8) & 0xff, CRGB::DeepPink & 0xff);									
const Color DeepSkyBlue				= Color((CRGB::DeepSkyBlue >> 16) & 0xff, (CRGB::DeepSkyBlue >> 8) & 0xff, CRGB::DeepSkyBlue & 0xff);							
const Color DimGray					= Color((CRGB::DimGray >> 16) & 0xff, (CRGB::DimGray >> 8) & 0xff, CRGB::DimGray & 0xff);										
const Color DimGrey					= Color((CRGB::DimGrey >> 16) & 0xff, (CRGB::DimGrey >> 8) & 0xff, CRGB::DimGrey & 0xff);										
const Color DodgerBlue				= Color((CRGB::DodgerBlue >> 16) & 0xff, (CRGB::DodgerBlue >> 8) & 0xff, CRGB::DodgerBlue & 0xff);								
const Color FairyLight				= Color((CRGB::FairyLight >> 16) & 0xff, (CRGB::FairyLight >> 8) & 0xff, CRGB::FairyLight & 0xff);								
const Color FairyLightNCC			= Color((CRGB::FairyLightNCC >> 16) & 0xff, (CRGB::FairyLightNCC >> 8) & 0xff, CRGB::FairyLightNCC & 0xff);						
const Color FireBrick				= Color((CRGB::FireBrick >> 16) & 0xff, (CRGB::FireBrick >> 8) & 0xff, CRGB::FireBrick & 0xff);									
const Color FloralWhite				= Color((CRGB::FloralWhite >> 16) & 0xff, (CRGB::FloralWhite >> 8) & 0xff, CRGB::FloralWhite & 0xff);							
const Color ForestGreen				= Color((CRGB::ForestGreen >> 16) & 0xff, (CRGB::ForestGreen >> 8) & 0xff, CRGB::ForestGreen & 0xff);							
const Color Fuchsia					= Color((CRGB::Fuchsia >> 16) & 0xff, (CRGB::Fuchsia >> 8) & 0xff, CRGB::Fuchsia & 0xff);										
const Color Gainsboro				= Color((CRGB::Gainsboro >> 16) & 0xff, (CRGB::Gainsboro >> 8) & 0xff, CRGB::Gainsboro & 0xff);									
const Color GhostWhite				= Color((CRGB::GhostWhite >> 16) & 0xff, (CRGB::GhostWhite >> 8) & 0xff, CRGB::GhostWhite & 0xff);								
const Color Gold					= Color((CRGB::Gold >> 16) & 0xff, (CRGB::Gold >> 8) & 0xff, CRGB::Gold & 0xff);												
const Color Goldenrod				= Color((CRGB::Goldenrod >> 16) & 0xff, (CRGB::Goldenrod >> 8) & 0xff, CRGB::Goldenrod & 0xff);									
const Color Gray					= Color((CRGB::Gray >> 16) & 0xff, (CRGB::Gray >> 8) & 0xff, CRGB::Gray & 0xff);												
const Color Grey					= Color((CRGB::Grey >> 16) & 0xff, (CRGB::Grey >> 8) & 0xff, CRGB::Grey & 0xff);												
const Color Green					= Color((CRGB::Green >> 16) & 0xff, (CRGB::Green >> 8) & 0xff, CRGB::Green & 0xff);												
const Color GreenYellow				= Color((CRGB::GreenYellow >> 16) & 0xff, (CRGB::GreenYellow >> 8) & 0xff, CRGB::GreenYellow & 0xff);							
const Color Honeydew				= Color((CRGB::Honeydew >> 16) & 0xff, (CRGB::Honeydew >> 8) & 0xff, CRGB::Honeydew & 0xff);									
const Color HotPink					= Color((CRGB::HotPink >> 16) & 0xff, (CRGB::HotPink >> 8) & 0xff, CRGB::HotPink & 0xff);										
const Color IndianRed				= Color((CRGB::IndianRed >> 16) & 0xff, (CRGB::IndianRed >> 8) & 0xff, CRGB::IndianRed & 0xff);									
const Color Indigo					= Color((CRGB::Indigo >> 16) & 0xff, (CRGB::Indigo >> 8) & 0xff, CRGB::Indigo & 0xff);											
const Color Ivory					= Color((CRGB::Ivory >> 16) & 0xff, (CRGB::Ivory >> 8) & 0xff, CRGB::Ivory & 0xff);												
const Color Khaki					= Color((CRGB::Khaki >> 16) & 0xff, (CRGB::Khaki >> 8) & 0xff, CRGB::Khaki & 0xff);												
const Color Lavender				= Color((CRGB::Lavender >> 16) & 0xff, (CRGB::Lavender >> 8) & 0xff, CRGB::Lavender & 0xff);									
const Color LavenderBlush			= Color((CRGB::LavenderBlush >> 16) & 0xff, (CRGB::LavenderBlush >> 8) & 0xff, CRGB::LavenderBlush & 0xff);						
const Color LawnGreen				= Color((CRGB::LawnGreen >> 16) & 0xff, (CRGB::LawnGreen >> 8) & 0xff, CRGB::LawnGreen & 0xff);									
const Color LemonChiffon			= Color((CRGB::LemonChiffon >> 16) & 0xff, (CRGB::LemonChiffon >> 8) & 0xff, CRGB::LemonChiffon & 0xff);						
const Color LightBlue				= Color((CRGB::LightBlue >> 16) & 0xff, (CRGB::LightBlue >> 8) & 0xff, CRGB::LightBlue & 0xff);									
const Color LightCoral				= Color((CRGB::LightCoral >> 16) & 0xff, (CRGB::LightCoral >> 8) & 0xff, CRGB::LightCoral & 0xff);								
const Color LightCyan				= Color((CRGB::LightCyan >> 16) & 0xff, (CRGB::LightCyan >> 8) & 0xff, CRGB::LightCyan & 0xff);									
const Color LightGoldenrodYellow	= Color((CRGB::LightGoldenrodYellow >> 16) & 0xff, (CRGB::LightGoldenrodYellow >> 8) & 0xff, CRGB::LightGoldenrodYellow & 0xff);
const Color LightGreen				= Color((CRGB::LightGreen >> 16) & 0xff, (CRGB::LightGreen >> 8) & 0xff, CRGB::LightGreen & 0xff);								
const Color LightGrey				= Color((CRGB::LightGrey >> 16) & 0xff, (CRGB::LightGrey >> 8) & 0xff, CRGB::LightGrey & 0xff);									
const Color LightPink				= Color((CRGB::LightPink >> 16) & 0xff, (CRGB::LightPink >> 8) & 0xff, CRGB::LightPink & 0xff);									
const Color LightSalmon				= Color((CRGB::LightSalmon >> 16) & 0xff, (CRGB::LightSalmon >> 8) & 0xff, CRGB::LightSalmon & 0xff);							
const Color LightSeaGreen			= Color((CRGB::LightSeaGreen >> 16) & 0xff, (CRGB::LightSeaGreen >> 8) & 0xff, CRGB::LightSeaGreen & 0xff);						
const Color LightSkyBlue			= Color((CRGB::LightSkyBlue >> 16) & 0xff, (CRGB::LightSkyBlue >> 8) & 0xff, CRGB::LightSkyBlue & 0xff);						
const Color LightSlateGray			= Color((CRGB::LightSlateGray >> 16) & 0xff, (CRGB::LightSlateGray >> 8) & 0xff, CRGB::LightSlateGray & 0xff);					
const Color LightSlateGrey			= Color((CRGB::LightSlateGrey >> 16) & 0xff, (CRGB::LightSlateGrey >> 8) & 0xff, CRGB::LightSlateGrey & 0xff);					
const Color LightSteelBlue			= Color((CRGB::LightSteelBlue >> 16) & 0xff, (CRGB::LightSteelBlue >> 8) & 0xff, CRGB::LightSteelBlue & 0xff);					
const Color LightYellow				= Color((CRGB::LightYellow >> 16) & 0xff, (CRGB::LightYellow >> 8) & 0xff, CRGB::LightYellow & 0xff);							
const Color Lime					= Color((CRGB::Lime >> 16) & 0xff, (CRGB::Lime >> 8) & 0xff, CRGB::Lime & 0xff);												
const Color LimeGreen				= Color((CRGB::LimeGreen >> 16) & 0xff, (CRGB::LimeGreen >> 8) & 0xff, CRGB::LimeGreen & 0xff);									
const Color Linen					= Color((CRGB::Linen >> 16) & 0xff, (CRGB::Linen >> 8) & 0xff, CRGB::Linen & 0xff);												
const Color Magenta					= Color((CRGB::Magenta >> 16) & 0xff, (CRGB::Magenta >> 8) & 0xff, CRGB::Magenta & 0xff);										
const Color Maroon					= Color((CRGB::Maroon >> 16) & 0xff, (CRGB::Maroon >> 8) & 0xff, CRGB::Maroon & 0xff);											
const Color MediumAquamarine		= Color((CRGB::MediumAquamarine >> 16) & 0xff, (CRGB::MediumAquamarine >> 8) & 0xff, CRGB::MediumAquamarine & 0xff);			
const Color MediumBlue				= Color((CRGB::MediumBlue >> 16) & 0xff, (CRGB::MediumBlue >> 8) & 0xff, CRGB::MediumBlue & 0xff);								
const Color MediumOrchid			= Color((CRGB::MediumOrchid >> 16) & 0xff, (CRGB::MediumOrchid >> 8) & 0xff, CRGB::MediumOrchid & 0xff);						
const Color MediumPurple			= Color((CRGB::MediumPurple >> 16) & 0xff, (CRGB::MediumPurple >> 8) & 0xff, CRGB::MediumPurple & 0xff);						
const Color MediumSeaGreen			= Color((CRGB::MediumSeaGreen >> 16) & 0xff, (CRGB::MediumSeaGreen >> 8) & 0xff, CRGB::MediumSeaGreen & 0xff);					
const Color MediumSlateBlue			= Color((CRGB::MediumSlateBlue >> 16) & 0xff, (CRGB::MediumSlateBlue >> 8) & 0xff, CRGB::MediumSlateBlue & 0xff);				
const Color MediumSpringGreen		= Color((CRGB::MediumSpringGreen >> 16) & 0xff, (CRGB::MediumSpringGreen >> 8) & 0xff, CRGB::MediumSpringGreen & 0xff);			
const Color MediumTurquoise			= Color((CRGB::MediumTurquoise >> 16) & 0xff, (CRGB::MediumTurquoise >> 8) & 0xff, CRGB::MediumTurquoise & 0xff);				
const Color MediumVioletRed			= Color((CRGB::MediumVioletRed >> 16) & 0xff, (CRGB::MediumVioletRed >> 8) & 0xff, CRGB::MediumVioletRed & 0xff);				
const Color MidnightBlue			= Color((CRGB::MidnightBlue >> 16) & 0xff, (CRGB::MidnightBlue >> 8) & 0xff, CRGB::MidnightBlue & 0xff);						
const Color MintCream				= Color((CRGB::MintCream >> 16) & 0xff, (CRGB::MintCream >> 8) & 0xff, CRGB::MintCream & 0xff);									
const Color MistyRose				= Color((CRGB::MistyRose >> 16) & 0xff, (CRGB::MistyRose >> 8) & 0xff, CRGB::MistyRose & 0xff);									
const Color Moccasin				= Color((CRGB::Moccasin >> 16) & 0xff, (CRGB::Moccasin >> 8) & 0xff, CRGB::Moccasin & 0xff);									
const Color NavajoWhite				= Color((CRGB::NavajoWhite >> 16) & 0xff, (CRGB::NavajoWhite >> 8) & 0xff, CRGB::NavajoWhite & 0xff);							
const Color Navy					= Color((CRGB::Navy >> 16) & 0xff, (CRGB::Navy >> 8) & 0xff, CRGB::Navy & 0xff);												
const Color OldLace					= Color((CRGB::OldLace >> 16) & 0xff, (CRGB::OldLace >> 8) & 0xff, CRGB::OldLace & 0xff);										
const Color Olive					= Color((CRGB::Olive >> 16) & 0xff, (CRGB::Olive >> 8) & 0xff, CRGB::Olive & 0xff);												
const Color OliveDrab				= Color((CRGB::OliveDrab >> 16) & 0xff, (CRGB::OliveDrab >> 8) & 0xff, CRGB::OliveDrab & 0xff);									
const Color Orange					= Color((CRGB::Orange >> 16) & 0xff, (CRGB::Orange >> 8) & 0xff, CRGB::Orange & 0xff);											
const Color OrangeRed				= Color((CRGB::OrangeRed >> 16) & 0xff, (CRGB::OrangeRed >> 8) & 0xff, CRGB::OrangeRed & 0xff);									
const Color Orchid					= Color((CRGB::Orchid >> 16) & 0xff, (CRGB::Orchid >> 8) & 0xff, CRGB::Orchid & 0xff);											
const Color PaleGoldenrod			= Color((CRGB::PaleGoldenrod >> 16) & 0xff, (CRGB::PaleGoldenrod >> 8) & 0xff, CRGB::PaleGoldenrod & 0xff);						
const Color PaleGreen				= Color((CRGB::PaleGreen >> 16) & 0xff, (CRGB::PaleGreen >> 8) & 0xff, CRGB::PaleGreen & 0xff);									
const Color PaleTurquoise			= Color((CRGB::PaleTurquoise >> 16) & 0xff, (CRGB::PaleTurquoise >> 8) & 0xff, CRGB::PaleTurquoise & 0xff);						
const Color PaleVioletRed			= Color((CRGB::PaleVioletRed >> 16) & 0xff, (CRGB::PaleVioletRed >> 8) & 0xff, CRGB::PaleVioletRed & 0xff);						
const Color PapayaWhip				= Color((CRGB::PapayaWhip >> 16) & 0xff, (CRGB::PapayaWhip >> 8) & 0xff, CRGB::PapayaWhip & 0xff);								
const Color PeachPuff				= Color((CRGB::PeachPuff >> 16) & 0xff, (CRGB::PeachPuff >> 8) & 0xff, CRGB::PeachPuff & 0xff);									
const Color Peru					= Color((CRGB::Peru >> 16) & 0xff, (CRGB::Peru >> 8) & 0xff, CRGB::Peru & 0xff);												
const Color Pink					= Color((CRGB::Pink >> 16) & 0xff, (CRGB::Pink >> 8) & 0xff, CRGB::Pink & 0xff);												
const Color Plaid					= Color((CRGB::Plaid >> 16) & 0xff, (CRGB::Plaid >> 8) & 0xff, CRGB::Plaid & 0xff);												
const Color Plum					= Color((CRGB::Plum >> 16) & 0xff, (CRGB::Plum >> 8) & 0xff, CRGB::Plum & 0xff);												
const Color PowderBlue				= Color((CRGB::PowderBlue >> 16) & 0xff, (CRGB::PowderBlue >> 8) & 0xff, CRGB::PowderBlue & 0xff);								
const Color Purple					= Color((CRGB::Purple >> 16) & 0xff, (CRGB::Purple >> 8) & 0xff, CRGB::Purple & 0xff);											
const Color Red						= Color((CRGB::Red >> 16) & 0xff, (CRGB::Red >> 8) & 0xff, CRGB::Red & 0xff);													
const Color RosyBrown				= Color((CRGB::RosyBrown >> 16) & 0xff, (CRGB::RosyBrown >> 8) & 0xff, CRGB::RosyBrown & 0xff);									
const Color RoyalBlue				= Color((CRGB::RoyalBlue >> 16) & 0xff, (CRGB::RoyalBlue >> 8) & 0xff, CRGB::RoyalBlue & 0xff);									
const Color SaddleBrown				= Color((CRGB::SaddleBrown >> 16) & 0xff, (CRGB::SaddleBrown >> 8) & 0xff, CRGB::SaddleBrown & 0xff);							
const Color Salmon					= Color((CRGB::Salmon >> 16) & 0xff, (CRGB::Salmon >> 8) & 0xff, CRGB::Salmon & 0xff);											
const Color SandyBrown				= Color((CRGB::SandyBrown >> 16) & 0xff, (CRGB::SandyBrown >> 8) & 0xff, CRGB::SandyBrown & 0xff);								
const Color SeaGreen				= Color((CRGB::SeaGreen >> 16) & 0xff, (CRGB::SeaGreen >> 8) & 0xff, CRGB::SeaGreen & 0xff);									
const Color Seashell				= Color((CRGB::Seashell >> 16) & 0xff, (CRGB::Seashell >> 8) & 0xff, CRGB::Seashell & 0xff);									
const Color Sienna					= Color((CRGB::Sienna >> 16) & 0xff, (CRGB::Sienna >> 8) & 0xff, CRGB::Sienna & 0xff);											
const Color Silver					= Color((CRGB::Silver >> 16) & 0xff, (CRGB::Silver >> 8) & 0xff, CRGB::Silver & 0xff);											
const Color SkyBlue					= Color((CRGB::SkyBlue >> 16) & 0xff, (CRGB::SkyBlue >> 8) & 0xff, CRGB::SkyBlue & 0xff);										
const Color SlateBlue				= Color((CRGB::SlateBlue >> 16) & 0xff, (CRGB::SlateBlue >> 8) & 0xff, CRGB::SlateBlue & 0xff);									
const Color SlateGray				= Color((CRGB::SlateGray >> 16) & 0xff, (CRGB::SlateGray >> 8) & 0xff, CRGB::SlateGray & 0xff);									
const Color SlateGrey				= Color((CRGB::SlateGrey >> 16) & 0xff, (CRGB::SlateGrey >> 8) & 0xff, CRGB::SlateGrey & 0xff);									
const Color Snow					= Color((CRGB::Snow >> 16) & 0xff, (CRGB::Snow >> 8) & 0xff, CRGB::Snow & 0xff);												
const Color SpringGreen				= Color((CRGB::SpringGreen >> 16) & 0xff, (CRGB::SpringGreen >> 8) & 0xff, CRGB::SpringGreen & 0xff);							
const Color SteelBlue				= Color((CRGB::SteelBlue >> 16) & 0xff, (CRGB::SteelBlue >> 8) & 0xff, CRGB::SteelBlue & 0xff);									
const Color Tan						= Color((CRGB::Tan >> 16) & 0xff, (CRGB::Tan >> 8) & 0xff, CRGB::Tan & 0xff);													
const Color Teal					= Color((CRGB::Teal >> 16) & 0xff, (CRGB::Teal >> 8) & 0xff, CRGB::Teal & 0xff);												
const Color Thistle					= Color((CRGB::Thistle >> 16) & 0xff, (CRGB::Thistle >> 8) & 0xff, CRGB::Thistle & 0xff);										
const Color Tomato					= Color((CRGB::Tomato >> 16) & 0xff, (CRGB::Tomato >> 8) & 0xff, CRGB::Tomato & 0xff);
const Color Turquoise				= Color((CRGB::Turquoise >> 16) & 0xff, (CRGB::Turquoise >> 8) & 0xff, CRGB::Turquoise & 0xff);
const Color Violet					= Color((CRGB::Violet >> 16) & 0xff, (CRGB::Violet >> 8) & 0xff, CRGB::Violet & 0xff);
const Color Wheat					= Color((CRGB::Wheat >> 16) & 0xff, (CRGB::Wheat >> 8) & 0xff, CRGB::Wheat & 0xff);
const Color White					= Color((CRGB::White >> 16) & 0xff, (CRGB::White >> 8) & 0xff, CRGB::White & 0xff);
const Color WhiteSmoke				= Color((CRGB::WhiteSmoke >> 16) & 0xff, (CRGB::WhiteSmoke >> 8) & 0xff, CRGB::WhiteSmoke & 0xff);
const Color Yellow					= Color((CRGB::Yellow >> 16) & 0xff, (CRGB::Yellow >> 8) & 0xff, CRGB::Yellow & 0xff);
const Color YellowGreen				= Color((CRGB::YellowGreen >> 16) & 0xff, (CRGB::YellowGreen >> 8) & 0xff, CRGB::YellowGreen & 0xff);

#endif
