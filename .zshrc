# If you come from bash you might have to change your $PATH.
  export PATH=$HOME/bin:/usr/local/bin:$PATH

# Path to your oh-my-zsh installation.
  export ZSH=~/.oh-my-zsh

  export LS_COLORS="*.py=00;38;5;208":"*.pyc=00;38;5;208":"*.ipynb=00;38;5;208":"*.sh=00;38;5;208":$LS_COLORS

# Set name of the theme to load. Optionally, if you set this to "random"
# it'll load a random theme each time that oh-my-zsh is loaded.
# See https://github.com/robbyrussell/oh-my-zsh/wiki/Themes
ZSH_THEME="michelebologna"
# PROMPT='%B%m%~%b$(git_super_status) %# '
# Uncomment the following line to use case-sensitive completion.
# CASE_SENSITIVE="true"

# Uncomment the following line to use hyphen-insensitive completion. Case
# sensitive completion must be off. _ and - will be interchangeable.
# HYPHEN_INSENSITIVE="true"

# Uncomment the following line to disable bi-weekly auto-update checks.
# DISABLE_AUTO_UPDATE="true"

# Uncomment the following line to change how often to auto-update (in days).
# export UPDATE_ZSH_DAYS=13

# Uncomment the following line to disable colors in ls.
# DISABLE_LS_COLORS="true"

# Uncomment the following line to disable auto-setting terminal title.
# DISABLE_AUTO_TITLE="true"

# Uncomment the following line to enable command auto-correction.
# ENABLE_CORRECTION="true"

# Uncomment the following line to display red dots whilst waiting for completion.
# COMPLETION_WAITING_DOTS="true"

# Uncomment the following line if you want to disable marking untracked files
# under VCS as dirty. This makes repository status check for large repositories
# much, much faster.
# DISABLE_UNTRACKED_FILES_DIRTY="true"

# Uncomment the following line if you want to change the command execution time
# stamp shown in the history command output.
# The optional three formats: "mm/dd/yyyy"|"dd.mm.yyyy"|"yyyy-mm-dd"
# HIST_STAMPS="mm/dd/yyyy"

# Would you like to use another custom folder than $ZSH/custom?
# ZSH_CUSTOM=/path/to/new-custom-folder

# Which plugins would you like to load? (plugins can be found in ~/.oh-my-zsh/plugins/*)
# Custom plugins may be added to ~/.oh-my-zsh/custom/plugins/
# Example format: plugins=(rails git textmate ruby lighthouse)
# Add wisely, as too many plugins slow down shell startup.
plugins=(git docker kubectl ubuntu z extract)


source $ZSH/oh-my-zsh.sh
# source $ZSH/zsh-git-prompt/zshrc.sh

# User configuration

# export MANPATH="/usr/local/man:$MANPATH"

# You may need to manually set your language environment
# export LANG=en_US.UTF-8

# Preferred editor for local and remote sessions
# if [[ -n $SSH_CONNECTION ]]; then
#   export EDITOR='vim'
# else
#   export EDITOR='mvim'
# fi

# Compilation flags
# export ARCHFLAGS="-arch x86_64"

# ssh
export SSH_KEY_PATH="~/.ssh/rsa_id"

export DOCKER_HOST=tcp://$HOST:2376 DOCKER_TLS_VERIFY=1

# Set personal aliases, overriding those provided by oh-my-zsh libs,
# plugins, and themes. Aliases can be placed here, though oh-my-zsh
# users are encouraged to define aliases within the ZSH_CUSTOM folder.
# For a full list of active aliases, run `alias`.
#
# Example aliases
# alias zshconfig="mate ~/.zshrc"
# alias ohmyzsh="mate ~/.oh-my-zsh"
alias vim=vim.tiny
alias v=vim
alias dc=docker-compose
j() {
	if [ -z $1 ]
	  then
	    notebook="jupyter/scipy-notebook"
	else
	  notebook=$1
	fi
	if [ -z $2 ]
	  then
	    port="8888"
	else
	  port=$2
	fi
        echo $PWD
	docker run -it -p $port:8888 -v $PWD:/home/jovyan/work $notebook}
alias di="docker images"
alias dr="docker run"
alias dps="docker ps"
alias dpsa="docker ps -a"
db() {docker exec -it $1 bash}
dbc() {db $(dps -q | head -n $1 |tail -n 1) }
alias ds="docker stop"
alias dre="docker restart"
alias ddel="docker rm --force"
dsc() {ds $(dpsa -q | head -n $1 |tail -n 1)}
drec() {dre $(dpsa -q | head -n $1 |tail -n 1)}
ddelc() {ddel $(dpsa -q | head -n $1 |tail -n 1)}
alias dsa="docker stop $(dps -q |tr '\n' ' ')"
alias drea="dre $(dpsa -q|tr '\n' ' '))"
alias ddela="ddel  $(dpsa -q|tr '\n' ' ')"
f() {find . -iname "*$1*"}
h() (grep -irn "$1" .)
alias k="clear"
