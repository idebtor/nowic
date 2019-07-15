# C++ for C Coders & Data Structures
Lecture Notes by idebtor@gmail.com
-------------------
# Using Mintty console and bash instead of cmd or PowerShell

Instead of using cmd or PowerShell, I recommend you to use the better terminal emulators mintty available.

## Open a default console (for MINGW-w64/MSYS2)
  - Create a shortcut for `c:/mingw64/mingw64.exe`. Do the right click on the msys.bat and create a shortcut. You may move the shortcut to the Desktop at your convenience.    
  - Click the shortcut and you will see a console. Execute the following commands at the console.
    - ls
    - pwd
  - Now when we open a new console, we want to make it start at the folder we often use and do something more.  This can be done using __.bash_profile__.
  - Go to the `c:/mingw64/home/user/` and start Atom editor.
    - cd c:/mingw64/home/user
    - Atom .bash_profile
  - Add the following contents at the end of .bash_profile
```  
alias ls='ls -aGp --color=auto'
alias ll='ls -alkF'
alias rm='rm -i'
alias c='clear'
alias h='history'
LS_COLORS=$LS_COLORS':no=00:di=01;36'
LS_COLORS=$LS_COLORS':*.h=0;33:*.exe=31:*.o=1;32:*.md=1;33'

#echo c:/mingw64/home/user/.bash_profile
echo C:/mingw64/home/user/.bash_profile

# Setting my dev folder as a startup folder as you wish.
# HOME="/c/users/${LOGNAME}/DropBox"
HOME="/c/GitHub/nowic"
cd $HOME

# $(hostname) and/or $(whoami) may be added, if necessary.
PS1='$(pwd -W)> '
```

----------------------------
_One thing I know, I was blind but now I see. John 9:25_
----------------------------
