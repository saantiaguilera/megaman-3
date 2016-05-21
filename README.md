# Megaman X3 in C++

> JSON Parser: https://github.com/miloyip/rapidjson

> Logging: https://github.com/google/glog


```Bash
//Santi A
Client: g++ `find . -name '*.cpp' -not -path './server/*'` -o mclient -Wall -pipe `pkg-config --cflags --libs gtkmm-3.0`
Server: g++ `find . -name '*.cpp' -not -path './client/*'` -o mserver -Wall -pipe `pkg-config --cflags --libs gtkmm-3.0`
```

----------------------------
TODO Santi A
----------------------------
[] Pass to .CPP and separate views and controllers from single .H
[] Instead of using #define PATH in controllers and views use a private const std::string ??

-----------------------------
Tree
-----------------------------

server - Server side things

client - Client side things

editor - Map Editor side things

doc - Useful documentation

common - Common stuff

res - Resources (drawables/layouts)
