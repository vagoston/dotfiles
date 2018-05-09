ssh-keygen -t rsa -b 4096 -C agsoton.vilmos@gmail.com
sudo apt install vim
echo "syntax on\ncolorscheme desert" > ~/.vimrc
git config --global core.editor vim
sudo apt install docker.io
sudo apt-get install virtualenv
sudo apt install python-pip
sudo apt install python3-pip
sudo usermod -aG docker $(whoami)
sudo apt install zsh
sudo apt install curl
sh -c "$(curl -fsSL https://raw.githubusercontent.com/robbyrussell/oh-my-zsh/master/tools/install.sh)"
