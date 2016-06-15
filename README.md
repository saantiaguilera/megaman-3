# Megaman X3 in C++

This project is a Megaman 3 multiplayer game.
Includes the following:
- Map editor for creating own custom maps.
- Server for managing physics and being able to play multiplayer mode
- Client for a user to play the very own game

##INSTALL
```Bash
#The below steps are necessary for being able to compile and run everything ok
sudo apt-get install cmake libbox2d-dev libgtkmm-3.0-dev libglademm-2.4-dev libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev
cd libs/libsdl2pp/
sudo cmake . && sudo make && sudo make install
cd ../glog/
sudo ./configure && sudo make && sudo make install
sudo echo "include /usr/local/lib" >> /etc/ld.so.conf 
sudo ldconfig
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib
cd ..

#The below steps are for making the target you desire
make client #Creates mclient for running the client
make server #Creates mserver for running the server
make editor #Creates meditor for running the editor
make        #Creates all of the above ones
make clean  #Deletes the ld objs asociated with the rules executed
```

##RUN
```Bash
Server: ./mserver port config_filename.json
Client: ./mclient
Editor: ./meditor
```

