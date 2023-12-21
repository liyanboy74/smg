# SMG
Simple Sitemap Generator
```
Example: smg -s test.com -d blog -p help

-d, --dir=DIR              change dir
-n, --name=FILE            rename output file
-p, --post=POST            add post
-s, --site=SITE            site address
-?, --help                 Give this help list
    --usage                Give a short usage message
```
### Build
#### on Linux
```
git clone https://github.com/liyanboy74/smg.git
cd smg
mkdir build
cd build
cmake -G "Unix Makefiles" ..
make
sudo make install
```
#### on Windows
you need `GCC`,`Cmake`,`make`&`autoconf` tool.
```
git clone --recursive https://github.com/liyanboy74/smg.git
cd smg
cd argp-standalone
autoreconf --install #optional
sh configure
make
cd ..
mkdir build
cd build
cmake -G "Unix Makefiles" ..
make
sudo make install
```

