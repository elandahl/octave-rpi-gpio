## Test bcm2835oct.oct
## 14.01.2013 Andreas Weber
##
## Modified by Eric Landahl, Sept. 8, 2019
## gpiotester.m adds additional capabilities

bcm2835_init()

# for RPi revision 1 GPIO header
# set output
disp('Setting pin 26 to output and pin 19 to input')
bcm2835_gpio_fsel (26, 1)
bcm2835_gpio_fsel (19,0)

disp('Setting pin 26 to LOW, reading pin 19')
bcm2835_gpio_clr (26)
x = bcm2835_gpio_lev (19)

sleep(1);

disp('Setting pin 26 to HIGH, reading pin 19')
bcm2835_gpio_set (26)
x = bcm2835_gpio_lev (19)

sleep(1);

disp('Opening spi')
spistatus = bcm2835_spi_begin()

sleep(1);
disp('Transfering 0x23')
y = bcm2835_spi_transfer(0x23)
y
disp('Done with trasfer; ending spi')

bcm2835_spi_end()

bcm2835_close()
