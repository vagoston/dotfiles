#!/bin/sh
mv $(pwd)/.zshrc $(pwd)/._zshrc 
ln -s $(pwd)/.dotfiles/.zshrc ~/.zshrc
