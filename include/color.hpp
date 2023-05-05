#ifndef __COLOR_HPP__
#define __COLOR_HPP__

#define RGBA(r,g,b,a) ((r<<24)|(g<<16)|(r<<8)|a)
#define RGB(r,g,b) ((r<<24)|(g<<16)|(r<<8)|255)

#define RED(x) (x>>24)
#define GREEN(x) ((x>>16)%(1<<8))
#define BLUE(x) ((x>>8)%(1<<8))
#define ALPHA(x) (x%(1<<8))

#endif
