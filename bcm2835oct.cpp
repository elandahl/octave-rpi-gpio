/*
 Copyright (C) 2013 Andreas Weber

 stub for an octave wrapper around the bcm2835 lib from
 http://www.open.com.au/mikem/bcm2835/

 Added simple SPI and GPIO read capbilities
 Eric Landahl, September 9, 2019
*/

#include <octave/oct.h>
#include <bcm2835.h>

DEFUN_DLD (bcm2835_init, args, nargout,
  "-*- texinfo -*-\n\
@deftypefn  {@var{ret}=} bcm2835_init ()\n\
Initialise the library by opening /dev/mem and getting pointers to the\n\
internal memory for BCM 2835 device registers. You must call this\n\
(successfully) before calling any other functions in this library\n\
(except bcm2835_set_debug). If bcm2835_init() fails by returning 0,\n\
calling any other function may result in crashes or other failures.\n\
Prints messages to stderr in case of errors. \n\
@end deftypefn")
{
  octave_value_list retval;
  retval(0) = bcm2835_init ();
  return retval;
}

DEFUN_DLD (bcm2835_close, args, nargout,
  "-*- texinfo -*-\n\
@deftypefn  {@var{ret}=} bcm2835_close ()\n\
Close the library, deallocating any allocated memory and closing /dev/mem\n\
@end deftypefn")
{
  octave_value_list retval;
  retval(0) = bcm2835_close ();
  return retval;
}

DEFUN_DLD (bcm2835_gpio_fsel, args, nargout,
  "-*- texinfo -*-\n\
@deftypefn  {} bcm2835_gpio_fsel (@var{pin}, @var{mode})\n\
TDOD: document me!\n\
@end deftypefn")
{
  octave_value_list retval;
  int nargin = args.length ();
  if (nargin !=2)
    {
      print_usage ();
    }
  int pin = args(0).int_value();
  int mode = args(1).int_value();

  bcm2835_gpio_fsel (pin, mode);
  return retval;
}

DEFUN_DLD (bcm2835_gpio_set, args, nargout,
  "-*- texinfo -*-\n\
@deftypefn  {} bcm2835_gpio_set (@var{pin})\n\
TDOD: document me!\n\
@end deftypefn")
{
  octave_value_list retval;
  int nargin = args.length ();
  if (nargin !=1)
    {
      print_usage ();
    }
  int pin = args(0).int_value();

  bcm2835_gpio_set (pin);
  return retval;
}

DEFUN_DLD (bcm2835_gpio_clr, args, nargout,
  "-*- texinfo -*-\n\
@deftypefn  {} bcm2835_gpio_clr (@var{pin})\n\
TDOD: document me!\n\
@end deftypefn")
{
  octave_value_list retval;
  int nargin = args.length ();
  if (nargin !=1)
    {
      print_usage ();
    }
  int pin = args(0).int_value();

  bcm2835_gpio_clr (pin);
  return retval;
}

DEFUN_DLD (bcm2835_gpio_lev, args, nargout,
  "-*- texinfo -*-\n\
@deftypefn  {} bcm2835_gpio_lev (@var{pin})\n\
TDOD: document me!\n\
@end deftypefn")
{
  octave_value_list retval;
  int nargin = args.length ();
  if (nargin !=1)
    {
      print_usage ();
    }
  int pin = args(0).int_value();

  octave_value tmp =  bcm2835_gpio_lev (pin);
  tmp.print (octave_stdout);
  retval = tmp;

  return retval;
}

DEFUN_DLD (bcm2835_spi_transfer, args, nargout,
  "-*- texinfo -*-\n\
@deftypefn  {} bcm2835_spi_transfer (@var{data_send})\n\
TDOD: document me!\n\
@end deftypefn")
{
  octave_value_list retval;
  int nargin = args.length ();
  if (nargin !=1)
    {
      print_usage ();
    }
  int data_send = args(0).int_value();

  octave_value tmp =  bcm2835_spi_transfer (data_send);
  tmp.print (octave_stdout);
  retval = tmp;

  return retval;
}

DEFUN_DLD (bcm2835_spi_begin, args, nargout,
  "-*- texinfo -*-\n\
@deftypefn  {} bcm2835_spi_begin ()\n\
TDOD: document me!\n\
@end deftypefn")
{
  octave_value_list retval;
  int nargin = args.length ();
  if (nargin !=0)
    {
      print_usage ();
    }

  octave_value tmp =  bcm2835_spi_begin ();
  tmp.print (octave_stdout);
  retval = tmp;

  return retval;
}

DEFUN_DLD (bcm2835_spi_end, args, nargout,
  "-*- texinfo -*-\n\
@deftypefn  {} bcm2835_spi_end ()\n\
TDOD: document me!\n\
@end deftypefn")
{
  octave_value_list retval;
  int nargin = args.length ();
  if (nargin !=0)
    {
      print_usage ();
    }

  return retval;
}
