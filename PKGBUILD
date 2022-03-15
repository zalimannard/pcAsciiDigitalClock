pkgname=pctime
pkgver=1.0.0
pkgrel="1"
pkgdesc="Show current time"
arch=("x86_64")
url="https://github.com/zalimannard/pcAsciiDigitalClock"

build(){
    [[ -d build ]] && rm -r build
    mkdir build && cd build
    cmake ..
    make
}

package(){
    install -Dm777 ./build/pctime "$pkgdir/usr/bin/$pkgname"
    install -Dm777 ../README.md "$pkgdir/usr/share/doc/$pkgname"
    install -Dm777 ./pctime.txt "$pkgdir$HOME/.config/ProgrammingChallengeV4/$pkgname/pctime.txt"
}
