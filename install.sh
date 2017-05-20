#!/bin/sh
mv ../.zshrc ../._zshrc 
ln -s $(pwd)/.zshrc ~/.zshrc
