## Discription 
The is a comic translate helper tool, uploaded by Isaiah Yang.
(I would rather use the word "uploaded" because 99% of the code are written by other open sources, I just changes a little of it, contains 99.9 % Gimp 2.8.20)
This program is intend to make the translation of comic easier or even automatic. But please don't put it into illegal usage.
Still, it is not perfect and require additional functions to achieve that, however, I would keep working on perfecting it.


## The software are used and needed to be install:

1. Ubuntu (operation system, other linux system not tested yet)
2. Opencv
3. python3.5
	(or any version of python that can install pytesseract and googletrans)
4. Gimp 2.8.20 supplements


## How to install

The fellowing code are executed in ubuntu system.


>  1. step : clone or download the source code
make sure that all your path are in english
my path is only "/helper/"

		git clone https://github.com/kangaroo02/comic-translate-helper.git


>  2. step : install the dependence of gimp
https://ubuntuforums.org/showthread.php?t=1952615&page=3&p=11821399#post11821399


		sudo apt-get update
		sudo apt-get install cvs subversion git-core mercurial
		sudo apt-get build-dep gimp

(If exist error: E: You must put some 'source' URIs in your sources.list
please take a look in this web to open the sources option:
https://askubuntu.com/questions/496549/error-you-must-put-some-source-uris-in-your-sources-list)

		sudo apt-get remove libgegl-0.0-dev libbabl-0.0-0-dev
		sudo apt-get install libavformat-dev libavcodec-dev graphviz liblua5.1-0-dev

(install vala : https://askubuntu.com/questions/910443/how-to-install-vala-on-ubuntu-16-10)

		sudo add-apt-repository ppa:vala-team
		sudo apt update
		sudo apt install valac

(install ruby : https://askubuntu.com/questions/1093390/ubuntu-18-04-how-to-install-ruby1-9-1ruby1-9-1-full-rubygems1-9-1-ruby1-9-1)

		sudo apt install ruby2.5 ruby2.5-dev
		sudo apt-get install libopenexr-dev libopenraw-dev libexiv2-dev \
		libsdl1.2-dev libgs-dev
(install libjasper : https://researchxuyc.wordpress.com/2018/09/26/install-libjasper-in-ubuntu-18-04/)

		sudo add-apt-repository "deb http://security.ubuntu.com/ubuntu xenial-security main"
		sudo apt update
		sudo apt install libjasper1 libjasper-dev

		sudo apt-get install checkinstall


The following three are only valid for that session if you for any reason restart the terminal, you'll have to execute them again

	export PATH=/opt/gimp-2.8/bin:$PATH
	export PKG_CONFIG_PATH=/opt/gimp-2.8/lib/pkgconfig${PKG_CONFIG_PATH:+:${PKG_CONFIG_PATH}}
	export LD_LIBRARY_PATH=/opt/gimp-2.8/lib${LD_LIBRARY_PATH:+:${LD_LIBRARY_PATH}}


(Remember the above three have to be executed again if you restart your session. )




>  3. step : install babl

		cd into the dir of "comic-translate-helper"
		cd babl-0.1.10/
		./configure --prefix=/opt/gimp-2.8
		make
		sudo make install
		cd ..

>  4. step : install gegl

   		cd gegl-0.2.0/
		sudo apt-get install intltool
		./configure --prefix=/opt/gimp-2.8
  	  	make
 	  	sudo make install
 	  	cd ..


>  5. step : install gimp (the comic translate helper)

   		cd gimp-2.8.20/
	

### Install gimp
		sudo apt install python-gtk2 python-gtk2-dev
		

		./configure --prefix=/opt/gimp-2.8
		make
		(this process will take a long time)
		sudo make install
	
		sudo apt install libcanberra-gtk-module libcanberra-gtk3-module


>  6. step : install opencv
https://docs.opencv.org/2.4.13.7/doc/tutorials/introduction/linux_install/linux_install.html
https://pydeeplearning.com/opencv/install-opencv-with-c-on-ubuntu-18-04/

		sudo apt-get update
		sudo apt-get upgrade
		sudo apt-get install libopencv-dev


>  7. step : install  pytesseract
https://pypi.org/project/pytesseract/
https://github.com/tesseract-ocr/tesseract/wiki

		sudo apt-get install python3-pip
		sudo pip3 install pytesseract
		sudo apt-get install tesseract-ocr
		sudo apt install libtesseract-dev


(download the language package to translate)
japanese

   		sudo apt-get install tesseract-ocr-jpn
english

 	  	sudo apt-get install tesseract-ocr-eng
chinese traditional

  	 	sudo apt-get install tesseract-ocr-chi-tra
	

>  8. step : install googletrans
https://py-googletrans.readthedocs.io/en/latest/

		sudo pip3 install googletrans


>  9. step : rebuild something

		cd to your dir comic-translate-helper
		cd gimp-2.8.20/app/tools/helpercore
		make clear
		make


## Run comic translate helper (actually gimp) in terminal

	export PATH=/opt/gimp-2.8/bin:$PATH
	export PKG_CONFIG_PATH=/opt/gimp-2.8/lib/pkgconfig${PKG_CONFIG_PATH:+:${PKG_CONFIG_PATH}}
	export LD_LIBRARY_PATH=/opt/gimp-2.8/lib${LD_LIBRARY_PATH:+:${LD_LIBRARY_PATH}}
	gimp
