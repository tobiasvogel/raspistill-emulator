#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdbool.h>

typedef uint8_t byte;

struct rgb_color_struct {
	char hex[8];
	byte red;
	byte green;
	byte blue;
};

struct rgba_color_struct {
	char hex[10];
	byte red;
	byte green;
	byte blue;
	byte alpha;
};

enum selection_enum { ALPHANUMERIC, DAYTIME, RANDOM, LIST };

enum occurrence_enum { ALWAYS, RANDOMLY, ALTERNATING, NEVER };

enum camera_model_enum { PICAM1, PICAM2, CUSTOM };

enum overlay_method_enum { MULTIPLY, SCREEN, LIGHTEN, DARKEN, ADD, SUBTRACT };

typedef struct rgb_color_struct rgb_color_t;
typedef struct rgba_color_struct rgba_color_t;
typedef enum occurrence_enum occurrence_t;
typedef enum selection_enum selection_t;
typedef enum camera_model_enum camera_model_t;
typedef enum overlay_method_enum overlay_method_t;

struct overlay_struct {
	enum type { SVG, PNG };
	bool enabled;
	bool upscaling;
	bool keepaspect;
	byte opacity;
	selection_t selection;
	signed int rotation;
};

typedef struct overlay_struct overlay_t;

struct config_struct {
	char *imagepath;
	char *svgpath;
	char *pngpath;

	selection_t imageSelection;

	bool enableOverlays;
	occurrence_t overlayOccurrence;

	overlay_t svgOverlay;
	overlay_t pngOverlay;

	camera_model_t cameraModel;
	unsigned int width;
	unsigned int height;

	bool xflip;
	bool yflip;

	signed int rotation;

	struct blur_effect_struct {

		bool enabled;
		byte amount;
		byte randomness;

	} blurEffect;

	struct tint_effect_struct {

		bool enabled;
		rgb_color_t color;
		byte randomness;

	} tintEffect;

	struct vignetting_effect_struct {

		bool enabled;
		rgb_color_t color;
		byte width;
		byte amount;
		byte randomness;

	} vignettingEffect;

	struct deadpixels_effect_struct {

		bool enabled;
		bool persistentMap;
		char *mapPath;
		rgba_color_t color;
		byte amount;
		byte randomness;

	} deadpixelsEffect;

	struct noise_effect_struct {

		bool enabled;
		rgb_color_t color;
		overlay_method_t method;
		byte amount;
		byte randomness;

	} noiseEffect;

};

typedef struct config_struct config_t;


#endif // STRUCTS_H
