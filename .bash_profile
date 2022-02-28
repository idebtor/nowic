# To the extent possible under law, the author(s) have dedicated all
# copyright and related and neighboring rights to this software to the
# public domain worldwide. This software is distributed without any warranty.
# You should have received a copy of the CC0 Public Domain Dedication along
# with this software.
# If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.

# ~/.bash_profile: executed by bash(1) for login shells.

# The copy in your home directory (~/.bash_profile) is yours, please
# feel free to customise it to create a shell
# environment to your liking.  If you feel a change
# would be benifitial to all, please feel free to send
# a patch to the msys2 mailing list.

# User dependent .bash_profile file

# source the users bashrc if it exists
if [ -f "${HOME}/.bashrc" ] ; then
  source "${HOME}/.bashrc"
fi

# Set PATH so it includes user's private bin if it exists
# if [ -d "${HOME}/bin" ] ; then
#   PATH="${HOME}/bin:${PATH}"
# fi

# Set MANPATH so it includes users' private man if it exists
# if [ -d "${HOME}/man" ]; then
#   MANPATH="${HOME}/man:${MANPATH}"
# fi

# Set INFOPATH so it includes users' private info if it exists
# if [ -d "${HOME}/info" ]; then
#   INFOPATH="${HOME}/info:${INFOPATH}"
# fi

# Created by idebtor@gmail.com
# This .profile is to be placed in C:\MinGW\msys\1.0\home\user and
#     set Target in the shortcut C:\MinGW\msys\1.0\msys.bat --rxvt
# For mintty
#     set Target in the shortcut C:\MinGW\msys\1.0\msys.bat -–mintty

alias ls='ls -aGp --color=auto'
alias ll='ls -alkF'
alias rm='rm -i'
alias c='clear'
alias x='cd /c/GitHub/nowicx'
alias xpset='cd /c/GitHub/nowicx/psets'
alias xlab='cd /c/GitHub/nowicx/labs'
alias n='cd /c/GitHub/nowic'
alias pset='cd /c/GitHub/nowic/psets'
alias lab='cd /c/GitHub/nowic/labs'

LS_COLORS=$LS_COLORS':no=00:di=36;01'
LS_COLORS=$LS_COLORS':*.h=1;33:*.exe=31:*.o=1;32:*.md=1;33'
export LS_COLORS
export PATH=$PATH:"/c/msys64/mingw64/bin"
export PATH=$PATH:"/c/msys64/usr/bin"
export PATH=$PATH:"/c/Program Files/Git/bin"
export PATH=$PATH:"/c/Users/$USER/AppData/Local/atom/bin"
export PATH=$PATH:"/c/Users/$USER/AppData/Local/Programs/Microsoft VS Code/bin"
##### FYI only for macOS #####
# code () { VSCODE_CWD="$PWD" open -n -b "com.microsoft.VSCode" --args $* ;}

echo c:/msys64/home/$USER/.bash_profile
echo $PWD

# Setting my dev folder as a startup folder of msys.
# HOME="/c/users/${LOGNAME}/DropBox"
HOME="/c/GitHub/nowic"
cd $HOME

# @$(hostname) may be added, if necessary, after $(whoami)
GREEN="$(tput setaf 2)"
RESET="$(tput sgr0)"
PS1='${GREEN}$(pwd -W)> ${RESET}'
