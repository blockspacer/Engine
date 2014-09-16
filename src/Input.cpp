#include "Input.h"

Input::Input(void)
{
  mouseDelta = glm::vec2(0, 0);
}

Input::~Input(void)
{
}

void Input::handleKeyboardEvent(SDL_KeyboardEvent keyEvent)
{
  keyState[keyEvent.keysym.sym] = keyEvent.state;
}

void Input::handleMouseEvent(SDL_MouseButtonEvent buttonEvent)
{
  buttonState[buttonEvent.button] = buttonEvent.state;
}

bool Input::isPressed(SDL_Keycode key) {
  return (keyState[key] == SDL_PRESSED);
}

bool Input::isReleased(SDL_Keycode key) {
  return (keyState[key] == SDL_RELEASED);
}

bool Input::mouseIsPressed(Uint8 button)
{
  return (buttonState[button] == SDL_PRESSED);
}

bool Input::mouseIsReleased(Uint8 button)
{
  return (buttonState[button] == SDL_RELEASED);
}

void Input::setMouseDelta(int x, int y)
{
  mouseDelta.x = x;
  mouseDelta.y = y;
}

glm::vec2 Input::getMouseDelta(void)
{
  return mouseDelta;
}

void Input::grabMouse(void)
{
#if defined(EMSCRIPTEN)
  SDL_ShowCursor(0);
  SDL_WM_GrabInput(SDL_GRAB_ON);
#else
  SDL_SetRelativeMouseMode(SDL_TRUE);
#endif
}

void Input::releaseMouse(void)
{
#if defined(EMSCRIPTEN)
  SDL_ShowCursor(1);
  SDL_WM_GrabInput(SDL_GRAB_OFF);
#else
  SDL_SetRelativeMouseMode(SDL_FALSE);
#endif
}
