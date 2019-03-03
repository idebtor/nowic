# C++ for C Coders & Data Structures
Lecture Notes by idebtor@gmail.com
-------------------

# Linux/bash equivalents for common Power Shell commands

1. `pwd` - present working directory

    gl `Get-Location`

2. `cd` - Change to the directory at the given path. Typing ..rather than a path will move up one directory.

    sl `Set-Location`

3. `ls` - List the directories and files in the current location.

    ls, dir `Get-ChildItem`

4. `cp` - Copies a file to a new location. Takes same arguments as move, but keeps the original file in its location.

    `Copy-Item`

5. `rm` - Deletes something. Permanently!

    rm, ri, rmdir, rd, del, `Remove-Item`

6. `mkdir` - Creates a new item. Used with no parameter, the item is by default a file.

    `New-Item -ItemType Directory -Name 'MyNewFolder'`

7. `touch` - create a new file or change the timestamp

    `New-Item` - create one or more files

8. `cat` - Gets the contents of a file and prints it to the screen. Adding the parameter `-TotalCount` followed by a number x prints only the first x lines. Adding the parameter `-Tail` followed by a number x prints only the final x lines.

    cat, gc, type, `Get-Contents`

9. `tail -n7 ./myfile` - display the last 7 lines of myfile

    `Get-Content -Tail 7 ./myfile`

10. `mv` - Moves something. Takes two arguments - first a filename (i.e. its present path), then a path for its new location (including the name it should have there). By not changing the path, it can be used to rename files.

    `Move-Item`

11. `man` - manual

    `Get-Help`

# How to set powershell default directory

1. Start a Powershell
2. In the Taskbar right-click and pin to keep a link there
3. __Again right click the icon in taskbar__ and then __right-click Windows PowerShell__ and choose Properties (not on the console, but on the popped-menu in taskbar).
4. Enter your preferred directory in the Start in: input field and press OK
5. Start from the taskbar icon
Done!

In the same Properties Dialog you can also change many other settings like Fonts, Colors, Sizes and on the Shortcut Tab there via button Advanced you can select if that Powershell is to be run with Administrator privileges.

__JoyNote__: You may set the default path in profile.ps1 as shown [here](https://stackoverflow.com/questions/32069265/how-to-set-powershell-default-directory). However,it is not recommended since it may have a conflict with other PowerShell scripts.

### Reference:
- [Stackoverflow](https://stackoverflow.com/questions/32069265/how-to-set-powershell-default-directory)


----------------------------
_One thing I know, I was blind but now I see. John 9:25_
