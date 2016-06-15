#!/bin/bash
#SA

programs="cmake"
deps="gtkmm-3.0 box2d sdl2pp"
installed=1

if hash $programs 2>/dev/null && [[ $(pkg-config --cflags --libs $deps) != *"No package"* ]] && [ ! -d "$libs" ]; then
	installed=0
fi

function tryMake {
	if [ $installed == 0 ]; then
		make $1
	else 
		echo First run install.
	fi
}

echo Welcome to Megaman 3 Multiplayer Edition
options=("Install" "All" "Client" "Server" "Editor" "Clean" "Quit")

select opt in "${options[@]}"
do
	case $opt in 
		"Install")
			sudo apt install cmake libbox2d-dev libgtkmm-3.0-dev libglademm-2.4-dev libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev
			
			cd libs/libsdl2pp/
			sudo cmake . && sudo make && sudo make install
			
			cd ../glog/
			sudo ./configure && sudo make && sudo make install
			
			if [[ $(grep "include /usr/local/lib" /etc/ld.so.conf) ]]; then
				sudo sed -i '$ a include /usr/local/lib' /etc/ld.so.conf
				sudo ldconfig
			fi

			export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib
			
			cd ../../
			sudo rm -rf libs
			
			installed=0
			;;
		"Client")
			tryMake client
			;;
		"Server")
			tryMake server
			;;
		"Editor")
		   tryMake editor						
			;;
		"Clean")
			tryMake clean
			;;
		"All")
			tryMake
			;;
		"Quit")
			break
			;;
		*)
			echo Sorry, invalid option
			;;
	esac
done
