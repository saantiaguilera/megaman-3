# Megaman X3 in C++

> JSON Parser: https://github.com/miloyip/rapidjson

> Logging: https://github.com/google/glog


```Bash
//Santi A
Client: g++ `find . -name '*.cpp' -not -path './server/*'` -o mclient -Wall -pipe `pkg-config --cflags --libs gtkmm-3.0 sdl2 SDL2_image SDL2_mixer`
Server: g++ `find . -name '*.cpp' -not -path './client/*'` -o mserver -Wall -pipe `pkg-config --cflags --libs gtkmm-3.0` -std=c++11 -lglog
```

----------------------------
TODO Santi A
----------------------------
- [] Pass to .CPP and separate views and controllers from single .H
- [] Instead of using #define PATH in controllers and views use a private const std::string ??
- [] Should I use for views and any gtkmm/glib related thing the Glib::RefPtr<> ?? Investigate.-> Yes, its throwing free() problems because of this. pass all pointers to smartpointers

-----------------------------
Tree
-----------------------------

server - Server side things

client - Client side things

editor - Map Editor side things

doc - Useful documentation

common - Common stuff

res - Resources (drawables/layouts)

------------------------------
**How to install SDL stuff:**

Search for them, download the .tar.gz versions (Like SDL2, SDL2_mixer-2.0.1.tar.gz, SDL2_image-2.0.1.tar.gz, SDL2_ttf-2.0.14.tar.gz)

https://www.libsdl.org/projects/SDL_image/

https://www.libsdl.org/projects/SDL_mixer/

https://www.libsdl.org/projects/SDL_ttf/

https://www.libsdl.org/download-2.0.php

1. Extract
2. Run
```Bash
sudo ./configure
sudo make all
sudo make install
```
3. After running the code you can check if you install them correclty by running
```Bash

pkg-config --cflags --libs sdl2
pkg-config --cflags --libs SDL2_image
pkg-config --cflags --libs SDL2_mixer
pkg-config --cflags --libs SDL2_ttf
```
You should see something like

-D_REENTRANT -I/usr/local/include/SDL2 -L/usr/local/lib -Wl,-rpath,/usr/local/lib -lSDL2

-D_REENTRANT -I/usr/local/include/SDL2 -L/usr/local/lib -lSDL2_image -Wl,-rpath,/usr/local/lib -lSDL2

-D_REENTRANT -I/usr/local/include/SDL2 -L/usr/local/lib -lSDL2_mixer -Wl,-rpath,/usr/local/lib -lSDL2

-D_REENTRANT -I/usr/local/include/SDL2 -L/usr/local/lib -lSDL2_ttf -Wl,-rpath,/usr/local/lib -lSDL2

**This project will be using a wrapper for SDL2 in C++**

* Clone or download this repository and extract it somewhere

https://github.com/libSDL2pp/libSDL2pp/tree/b3a6c2c5935ee0ade88d3d013d5af992886a0643

(Im using that version, you can use a newer if you like)

* Run
```Bash
#If you dont have cmake
sudo apt install cmake

sudo cmake . && sudo make && sudo make install
```

Check its installed by doing
```Bash
pkg-config --cflags --libs sdl2pp
```

You should see something like

-D_REENTRANT -I/usr/local/include -I/usr/local/include/SDL2 -L/usr/local/lib /usr/local/lib/libSDL2main.a -lSDL2pp -lSDL2_image -lSDL2_ttf -lSDL2_mixer -Wl,-rpath,/usr/local/lib -lSDL2

------------------------------
