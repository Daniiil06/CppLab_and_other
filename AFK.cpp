// Written by Pioz.
// Compile with: gcc -o autoclick autoclick.c -lX11
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

// Simulate mouse click
void
click (Display *display, int button)
{
  // Create and setting up the event
  XEvent event;
  memset (&event, 0, sizeof (event));
  event.xbutton.button = button;
  event.xbutton.same_screen = True;
  event.xbutton.subwindow = DefaultRootWindow (display);
  while (event.xbutton.subwindow)
  {
    event.xbutton.window = event.xbutton.subwindow;
    XQueryPointer (display, event.xbutton.window,
                   &event.xbutton.root, &event.xbutton.subwindow,
                   &event.xbutton.x_root, &event.xbutton.y_root,
                   &event.xbutton.x, &event.xbutton.y,
                   &event.xbutton.state);
  }
  // Press
  event.type = ButtonPress;
  if (XSendEvent (display, PointerWindow, True, ButtonPressMask, &event) == 0)
    fprintf (stderr, "Error to send the event!\n");
  XFlush (display);
  usleep (1);
  // Release
  event.type = ButtonRelease;
  if (XSendEvent (display, PointerWindow, True, ButtonReleaseMask, &event) == 0)
    fprintf (stderr, "Error to send the event!\n");
  XFlush (display);
  usleep (1);
}

// Get mouse coordinates
void
coords (Display *display, int *x, int *y)
{
  XEvent event;
  XQueryPointer (display, DefaultRootWindow (display),
                 &event.xbutton.root, &event.xbutton.window,
                 &event.xbutton.x_root, &event.xbutton.y_root,
                 &event.xbutton.x, &event.xbutton.y,
                 &event.xbutton.state);
  *x = event.xbutton.x;
  *y = event.xbutton.y;
}

// Move mouse pointer (relative)
void
move (Display *display, int x, int y)
{
  XWarpPointer (display, None, None, 0, 0, 0, 0, x, y);
  XFlush (display);
  usleep (1);
}

// Move mouse pointer (absolute)
void
move_to (Display *display, int x, int y)
{
  int cur_x, cur_y;
  coords (display, &cur_x, &cur_y);
  XWarpPointer (display, None, None, 0, 0, 0, 0, -cur_x, -cur_y);
  XWarpPointer (display, None, None, 0, 0, 0, 0, x, y);
  usleep (1);
}

// Get pixel color at coordinates x,y
void
pixel_color (Display *display, int x, int y, XColor *color)
{
  XImage *image;
  image = XGetImage (display, DefaultRootWindow (display), x, y, 1, 1, AllPlanes, XYPixmap);
  color->pixel = XGetPixel (image, 0, 0);
  XFree (image);
  XQueryColor (display, DefaultColormap(display, DefaultScreen (display)), color);
}

// START HERE
int
main (int argc, char *argv[])
{
  int starting = 3;
  int x = 0;
  int y = 0;

  // Open X display
  Display *display = XOpenDisplay (NULL);
  if (display == NULL)
  {
    fprintf (stderr, "Can't open display!\n");
    return -1;
  }

  // Wait 3 seconds to start
  printf ("Starting in   ");
  fflush (stdout);
  while (starting > 0)
  {
    printf ("\b\b\b %d...", starting);
    fflush (stdout);
    sleep (1);
    starting--;
  }
  printf ("\n");

  // Start
  while (1)
  {
    sleep (10);
    move_to (display, 862, 495);
    xte 'mouseclick 1'
    sleep (1);
    move_to (display, 612, 331);
    xte 'mouseclick 1'
    sleep (1);
    move_to (display, 464, 679);
    xte 'mouseclick 1'
    sleep (1);
  }

  // Close X display and exit
  XCloseDisplay (display);
  return 0;
}