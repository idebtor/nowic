# Created by idebtor@gmail.com - 02/02/19
# This .profile is to be placed in C:\MinGW\msys\1.0\home\user and
#     set Target in the shortcut C:\MinGW\msys\1.0\msys.bat --rxvt
# For mintty
#     set Target in the shortcut C:\MinGW\msys\1.0\msys.bat -–mintty

alias ls='ls -aFh --color=auto'
alias ll='ls -alkF'
alias rm='rm -i'
alias c='clear'
alias h='history'

echo c:/minGW/msys/1.0$(pwd)/.profile

# Setting my dev folder as a startup folder of msys.
# HOME="/c/users/${LOGNAME}/DropBox"
# HOME="/c/users/${LOGNAME}/Documents/GitHub/nowicx"
cd $HOME

# @$(hostname) may be added, if necessary, after $(whoami)
PS1='$(whoami) $(pwd -W)> '
