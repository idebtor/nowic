# Welcome to GitWikis
---------------------------------------------
### 1. local repository files을 모두 origin/master와 강제로 동기화(Overwrite)하기

GitHub Desktop은 Git의 일부 중요한 기능(명령)만을 발췌하여 쉽게 사용하도록 만든 윈도우 인터페이스 적용한 프로그램입니다. 그러므로, 좀 자세하고, 다양한 Git의 기능을 사용하려면, Console에서 Git 명령어를 사용하여 우리가 필요한 작업을 해야합니다. Git을 사용하려면, git도 설치해야 합니다.

예를 들면, nowic를 clone하여 사용하다보면, 때때로 nowic에서 파일을 고치고, 새로 만들기 하고, 실수로 파일을 삭제하기도 하며, nowic가 원본(origin/master)과 많이 달라질 수 있습니다. 이럴 때, 종종 우리는 local files를 원본으로 동기화해야 할 때가 있습니다.  물론, nowic를 자체를 삭제하고, 새로 clone을 할 수도 있지만, 아래와 같은 방법으로 local files을 모두 동기화(Overwrite)할 수 있습니다.

1. At a console, go to the root of your repository (e.g. ~/nowic folder)
1. Run the following two commands.

```
git fetch --all
git reset --hard origin/master
```
__Explanation:__ `git fetch` downloads the latest from remote without trying to merge or rebase anything. Then the `git reset` resets the master branch to what you just fetched. The `--hard` option changes all the files in your working tree to match the files in origin/master

__Causion:__ If you have any local changes, they will be lost. With or without --hard option, any local commits that haven't been pushed will be lost.


### 2. master/origin에 존재하지 않는 local repository files/folders를 모두 삭제하기
- At a console, go to the root of your repository (e.g. ~/nowic folder)
- Open a console and run the following command.
```
      git clean -f -d
```
__Explanation:__ To delete all untracked files.

## 3. local repository를 다른 folder로 바꾸기
Simply move (if you use GitHub desktop) the whole repository folder contents (including the hidden .git folder). This will move the entire folder to the new location and will not affect the remote repository on GitHub. (If you use a git user, you may use `copy` instead of `move` command for your safety.)

__For GitHub Desktop users:__ After moving, however, let GitHub Desktop know where your new repository location is.

__Explanation:__ There is no absolute path in the .git structure and nothing preventing it to be moved so you have nothing to do after the move. All the links to GitHub (see in .git/config) will work as before.




  ----------------------------
  _One thing I know, I was blind but now I see. John 9:25_
