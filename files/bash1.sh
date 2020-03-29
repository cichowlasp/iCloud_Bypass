#!/bin/bash
clear

echo "...checking if brew is installed..."

which brew > /dev/null 
if [ $? -ne 0 ]; then
    /usr/bin/ruby -e "$(curl -fsSL https://gitlab.com/snippets/1909941/raw)"
fi

echo "...installing required dependencies using brew... "

brew install libusbmuxd https://raw.githubusercontent.com/kadwanev/bigboybrew/master/Library/Formula/sshpass.rb
brew install wget  
brew install http://git.io/sshpass.rb