#ifndef SDL_MANAGER_H
#define SDL_MANAGER_H

#include <string>

#include <SDL.h>

class SDLManager
{
public:
  SDLManager(int width, int height, Uint32 flags);
  ~SDLManager(void);

  void tick(void);
  void swapBuffer(void);
  int poll_event(SDL_Event *event);
  Uint32 getDeltaTime(void);
  Uint32 getFPS(void);

private:
  void logSDLError(const char *msg);

  SDL_Window *win;
#if !defined(EMSCRIPTEN)
  SDL_GLContext glContext;
#endif

  Uint32 current_time, old_time, delta_time;
};

#endif
