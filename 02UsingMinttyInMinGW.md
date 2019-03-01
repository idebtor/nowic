# C++ for C Coders & Data Structures
Lecture Notes by idebtor@gmail.com
-------------------
# Using Mintty in MinGW/Msys

Instead of using cmd or powershell, I recommend you to use the better terminal emulators mintty available.

## Open a mingw/msys default console
  - Create a shortcut for `c:/mingw/msys/1.0/msys.bat`. Do the right click on the msys.bat and create a shortcut. You may move the shortcut to the Desktop for your convenience.    
  - Click the shortcut and you will see a console. Execute the following commands at the console.
    - ls
    - pwd
  - Now when we open a new console, we want to make it start at the folder we often use and do something more.  This can be done using __.profile__.
  - Go to the `c:/mingw/msys/1.0/home/user/` and start Atom editor.
    - cd c:/mingw/msys/1.0/home/user
    - Atom .profile
  - Create a file at `c:/mingw/msys/1.0/home/user/.profile` with the following contents:

```  
# Created by idebtor@gmail.com
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
HOME="/c/users/${LOGNAME}/Documents/GitHub/nowic"
cd $HOME

# @$(hostname) may be added, if necessary, after $(whoami)
PS1='$(whoami) $(pwd -W)> '
```

## Install Mintty
This can be done either at the MinGW command line or via the MinGW Installation Manager.  From the MinGW command line, run mingw-get install mintty.

```
mingw-get install mintty.
```
## Configure MSYS.  
Next, you need to __edit the shortcut__ you use to run the MinGW shell.  Right-click the `msys` shortcut and select Properties. Wherever you find your link, the Target should be `C:\MinGW\msys\1.0\msys.bat`, potentially with some command-line arguments following it. If an argument selecting a shell is already present (such as `--rxvt`), remove it.  

Finally, add `--mintty` as the first argument after ` C:\MinGW\msys\1.0\msys.bat` in the shortcut.

Now, when launching the MinGW shell through that short-cut, mintty will be used instead of the Windows terminal emulator.  Refer to the complete instructions in [this site](
https://sites.google.com/site/axusdev/tutorials/installminttyformsys).

----------------------------
_One thing I know, I was blind but now I see. John 9:25_
----------------------------
