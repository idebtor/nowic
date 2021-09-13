그런즉 너희가 먹든지 마시든지 무엇을 하든지 다 하나님의 영광을 위하여 하라 (고전10:31)

-------
<img src="https://github.com/idebtor/nowic/blob/c4d8ad9a5a51d14744e3e5b66da376c8bef15292/images/cplus_ds_title.jpg?raw=true" width=1000>

__NOTE:__ The following materials have been compiled and adapted from the numerous sources including my own. Please help me to keep this tutorial up-to-date by reporting any issues or questions. Send any comments or criticisms to `idebtor@gmail.com` Your assistances and comments will be appreciated.
Lecture notes by idebtor@gmail.com

-----

# Using Mintty console and bash instead of cmd or PowerShell

Instead of using `cmd` or `PowerShell`, I recommend you to use the better terminal emulators `mintty` available.

## Open a default console (for MINGW-w64/MSYS2)
  - Run the command as shown below: (`$` in the command below is a prompt, don't type it.)
  ```
    $ mintty -
  ```
      - Optionally, create a shortcut for `c:/msys64/mingw64.exe`. Do the right click on the `msys.bat` and create a shortcut. You may move the shortcut to the Desktop at your convenience.    
      - Click the shortcut and you will see a console. Execute the following commands at the console. (`$` in the command below is a prompt, don't type it.)
  ```
    $ ls              # list files in the current folder
    $ pwd             # print working directory
    $ cd ~            # change directory to HOME folder
    $ cd -            # change directory to the previous folder
  ```
  - Go the HOME folder. By default, the HOME is set to `c:/msys64/home/$USER`.  Run `cd ~` such that you move to the HOME.
  - Now when we open a new console, we want to make it start at the folder we often use and do something more.  This can be done using __.bash_profile__.
  - Go to the `c:/msys64/home/$USER` and start atom editor.
  ```
    $ cd c:/msys64/home/$USER        # cd $USER
    $ touch .bash_profile            # create an empty file
    $ code .bash_profile             # open the file to edit
  ```
  - Add the following contents at the end of `.bash_profile`
```  
alias ls='ls -Gp --color=auto'
alias ll='ls -alkF'
alias rm='rm -i'
alias c='clear'
alias h='history'
alias x='cd /c/GitHub/nowicx'
alias xp='cd /c/GitHub/nowicx/psets'
alias n='cd /c/GitHub/nowic'
alias np='cd /c/GitHub/nowic/psets'

LS_COLORS=$LS_COLORS':no=00:di=36;01'
LS_COLORS=$LS_COLORS':*.h=1;33:*.exe=31:*.o=1;32:*.md=1;33'
export LS_COLORS
export PATH=$PATH:"/c/msys64/mingw64/bin"
export PATH=$PATH:"/C/msys64/usr/bin"
export PATH=$PATH:"/c/Users/$USER/AppData/Local/Programs/Microsoft VS Code/bin"
export PATH=$PATH:"/c/Program Files/Git/bin"

echo C:/msys64/home/$USER/.bash_profile
# Setting my dev folder as a startup folder of msys64.
HOME="/c/GitHub/nowic"
cd $HOME

# @$(hostname) may be added, if necessary, after $(whoami)
GREEN="$(tput setaf 2)"
RESET="$(tput sgr0)"
PS1='${GREEN}$(pwd -W) > ${RESET}'
```

----------------------------
_One thing I know, I was blind but now I see. John 9:25_
----------------------------
