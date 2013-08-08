#include <stdio.h>
#include <stdint.h>

struct _SDL_Joystick;
typedef struct _SDL_Joystick SDL_Joystick;

/** A structure to hold a set of audio conversion filters and buffers */
#define SDLCALL
typedef struct SDL_AudioCVT {
	int needed;			/**< Set to 1 if conversion possible */
	uint16_t src_format;		/**< Source audio format */
	uint16_t dst_format;		/**< Target audio format */
	double rate_incr;		/**< Rate conversion increment */
	uint8_t *buf;			/**< Buffer to hold entire audio data */
	int    len;			/**< Length of original audio buffer */
	int    len_cvt;			/**< Length of converted audio buffer */
	int    len_mult;		/**< buffer must be len*len_mult big */
	double len_ratio; 	/**< Given len, final size is len*len_ratio */
	void (SDLCALL *filters[10])(struct SDL_AudioCVT *cvt, uint16_t format);
	int filter_index;		/**< Current audio conversion function */
} SDL_AudioCVT;

typedef struct SDL_AudioSpec {
	int freq;		/**< DSP frequency -- samples per second */
	uint16_t format;		/**< Audio data format */
	uint8_t  channels;	/**< Number of channels: 1 mono, 2 stereo */
	uint8_t  silence;		/**< Audio buffer silence value (calculated) */
	uint16_t samples;		/**< Audio buffer size in samples (power of 2) */
	uint16_t padding;		/**< Necessary for some compile environments */
	uint32_t size;		/**< Audio buffer size in bytes (calculated) */
	/**
	 *  This function is called when the audio device needs more data.
	 *
	 *  @param[out] stream	A pointer to the audio data buffer
	 *  @param[in]  len	The length of the audio buffer in bytes.
	 *
	 *  Once the callback returns, the buffer will no longer be valid.
	 *  Stereo samples are stored in a LRLRLR ordering.
	 */
	void (SDLCALL *callback)(void *userdata, uint8_t *stream, int len);
	void  *userdata;
} SDL_AudioSpec;

typedef struct SDL_Surface {
} SDL_Surface;

typedef struct SDL_Rect {
} SDL_Rect;

typedef struct SDL_PixelFormat {
} SDL_PixelFormat;

typedef struct SDL_Color {
} SDL_Color;

typedef struct SDL_Event {
} SDL_Event;

uint8_t SDL_JoystickGetButton(SDL_Joystick* joystick, int button)
{
    return 0;
}

int SDL_NumJoysticks(void)
{
    return 0;
}

int SDL_JoystickNumHats(SDL_Joystick *joystick)
{
    return 0;
}

int SDL_JoystickNumButtons(SDL_Joystick *joystick)
{
    return 0;
}

int16_t SDL_JoystickGetAxis(SDL_Joystick *joystick, int axis)
{
    return 0;
}

SDL_Joystick *SDL_JoystickOpen(int index)
{
    return 0;
}

int SDL_JoystickOpened(int index)
{
    return 0;
}

const char *SDL_JoystickName(int index)
{
    return 0;
}

int SDL_JoystickNumAxes(SDL_Joystick *joystick)
{
    return 0;
}

int SDL_JoystickEventState(int state)
{
    return 0;
}

int SDL_JoystickNumBalls(SDL_Joystick *joystick)
{
    return 0;
}

void SDL_CloseAudio(void)
{
    
}

int SDL_BuildAudioCVT(SDL_AudioCVT *cvt, uint16_t src_format, uint8_t src_channels, int src_rate, uint16_t dst_format, uint8_t dst_channels, int dst_rate)
{
    return 0;
}

int SDL_ConvertAudio(SDL_AudioCVT *cvt)
{
    return 0;
}

int SDL_OpenAudio(SDL_AudioSpec *desired, SDL_AudioSpec *obtained)
{
    return 0;
}

void SDL_LockAudio(void)
{
    
}

void SDL_PauseAudio(int pause_on)
{
    
}

void SDL_UnlockAudio(void)
{
    
}

void SDL_UpdateRects(SDL_Surface *screen, int numrects, SDL_Rect *rects)
{
    
}

SDL_Rect** SDL_ListModes(SDL_PixelFormat* format, uint32_t flags)
{
    return 0;
}

int SDL_SetColors(SDL_Surface *surface, SDL_Color *colors, int firstcolor, int ncolors)
{
    return 0;
}

char* SDL_GetError(void)
{
    return 0;
}

void SDL_UnlockSurface(SDL_Surface* surface)
{
    
}

void SDL_Quit(void)
{
    
}

int SDL_Init(uint32_t flags)
{
    return 0;
}

void SDL_WM_SetCaption(const char *title, const char *icon)
{
    
}

uint32_t SDL_MapRGB(SDL_PixelFormat *fmt, uint8_t r, uint8_t g, uint8_t b)
{
    return 0;
}

int SDL_ShowCursor(int toggle)
{
    return 0;
}

SDL_Surface* SDL_SetVideoMode(int width, int height, int bitsperpixel, uint32_t flags)
{
    return 0;
}

void SDL_PumpEvents(void)
{
    
}

int SDL_Flip(SDL_Surface* screen)
{
    return 0;
}

int SDL_LockSurface(SDL_Surface* surface)
{
    return 0;
}

uint8_t SDL_EventState(uint8_t type, int state)
{
    return 0;
}

int SDL_PollEvent(SDL_Event *event)
{
    return 0;
}

void SDL_Delay(uint32_t ms)
{
    
}

// might actually needs these in pads_cgc_linux.c
typedef struct SDL_Thread {
} SDL_Thread;
void SDL_WaitThread(SDL_Thread *thread, int *status)
{
    
}

uint32_t SDL_GetTicks(void)
{
    return 0;
}

SDL_Thread *SDL_CreateThread(int (*fn)(void *), void *data)
{
    return 0;
}
