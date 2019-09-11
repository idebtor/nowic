# C++ for C Coders & Data Structures
Lecture Notes by idebtor@gmail.com
-------------------
# Using Mintty console and bash instead of cmd or PowerShell

Instead of using cmd or PowerShell, I recommend you to use the better terminal emulators mintty available.

## Open a default console (for MINGW-w64/MSYS2)
  - Create a shortcut for `c:/msys64/mingw64.exe`. Do the right click on the msys.bat and create a shortcut. You may move the shortcut to the Desktop at your convenience.    
  - Click the shortcut and you will see a console. Execute the following commands at the console.
    - ls
    - pwd
  - Now when we open a new console, we want to make it start at the folder we often use and do something more.  This can be done using `.bash_profile`
  - Go to the `c:/msys64/home/user/` and start Atom editor.
    - cd c:/msys64/home/user
    - Atom .bash_profile
  - Add the following contents at the end of `.bash_profile`
```  
alias ls='ls -Gp --color=auto'
alias ll='ls -alkF'
alias rm='rm -i'
alias c='clear'
alias h='history'
LS_COLORS=$LS_COLORS':no=00:di=36;01'
LS_COLORS=$LS_COLORS':*.h=1;33:*.exe=31:*.o=1;32:*.md=1;33'
export LS_COLORS
#export PATH=$PATH:"C:\Program Files\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin"
export PATH=$PATH:"C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin"

### replace 'user' with your own user name in the following line:
export PATH=$PATH:"C:\Users\user\AppData\Local\atom\bin"

### print the present working directory
echo $PWD

# Setting my dev folder as a startup folder of msys.
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
