octave-rpi-gpio
===============

Adds support for reading GPIO pins and SPI.
===============

GNU Octave wrapper around libbcm2835 for GPIO control of the RaspberryPI IOs

Oct wrapper v0.0.1 around libbcm2835

1.) install octave and liboctave-dev as described on
    http://wiki.octave.org/Rasperry_Pi

2.) get and compile libbcm2835 from http://www.airspayce.com/mikem/bcm2835/:

```
    $ wget http://www.airspayce.com/mikem/bcm2835/bcm2835-1.60.tar.gz
    $ tar xzvf bcm2835-1.60.tar.gz
    $ cd bcm2835-1.60/
    $ ./configure CFLAGS=-fPIC
    $ make
    $ sudo make install
```

3.) compile the oct wrapper
```
  $ cd ..
  (current directory is now octave-rpi-gpio, the root of the repo)
  $ make
```  
4.) Test it (run octave as root to have GPIO access rights)
```
   $ sudo octave
   execute simple Test.  Physically connect MOSI to MISO; also physically connect Pins 26 and 19.
   Turns on and off Pin 26, reading Pin 19 each time.
   Sends a test byte 0x23 to SPI.  Receives the decimal equivalent when looped-thru of decimal 35.

   octave:1> test_bcm2835oct
```
