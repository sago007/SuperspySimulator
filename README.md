# Linux version of SuperspySimulator

I have made some modifications to make SuperspySimulator work on Linux. This included some general fixes and a new CMake build system.
There is still a nasty bug causing defeat triggers to fire too many times but when I started they did not fire at all.

To compile and run:
```
mkdir -p build
cd build
cp -r ../Platformer/Assets ./
cp -r ../Platformer/Saves ./
cmake ..
make
./SuperspySimulator
```
Requires a C++17 compiler (tested on g++-8 and clang++-8)


## Orginal README


Attributions:

Sound effects made using BFXR:
https://www.bfxr.net/

Music by "Spring" (in original .ogg format):
https://opengameart.org/content/pretty-good-chiptune-dont-know-what-to-call-it
https://opengameart.org/content/great-boss
https://opengameart.org/content/egyptian-fortress-boss
https://opengameart.org/content/suez-crisis
https://opengameart.org/content/minor-boss-r (https://creativecommons.org/licenses/by/4.0/ Converted from .ogg to .wav)
https://opengameart.org/content/puppydog-swing
https://opengameart.org/content/operation-unthinkable
https://opengameart.org/content/bubble-cub-theme
https://opengameart.org/content/theme-of-siberia-smith-0
https://opengameart.org/content/tropical-fantasy

"Munro" font by Ed Merritt of tenbytwenty.com:
http://tenbytwenty.com/?xxxx_posts=munro

The "Snuggler" is the original creation of DavesDungeon, used with permission:
https://davesdungeon.deviantart.com/

The "Bouncy Betty" is the original creation of PolyEdit2000, used with permission:
https://www.deviantart.com/polyedit2000

The "FauxDamsel" is the original creation of IndigoSpoon, used with permission:
https://www.deviantart.com/indigospoon
