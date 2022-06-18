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
```
git clone --recursive https://github.com/liyanboy74/smg.git
#Build Submodule or replace release.
cd smg
mkdir build
cd build
cmake -G "Unix Makefiles" ..
make
sudo make install
```