## Github使用

### **Explore模块**

- 用于搜索项目、仓库、开发者
  
#### 搜索技巧

- 直接搜索
- 添加限制

### GitHub 术语

- **Repository**：简称Repo，“仓库”，用于存放项目；

- **Issues**：“问题”，当项目有问题/bug时，可以向拥有者提出issues，解决后可关闭issues；

- **Star**：“收藏”，github项目实力的衡量标准；

- **master**：主分支；

- **Fork**：“分支”，复制项目的所有内容，在不相互影响的情况下进行开发；
  - **master**：主分支

- **Merge**：“合并”，合并fork，如果pull申请得到merge，那就是该项目的贡献者之一；

- **Pull Request**：“提交请求”，请求项目/仓库拥有者合并fork分支，即申请将独立开发的部分并入到项目中；

- **Watch**：“观察”，如果watch的仓库/项目有更新，github将会通知你；

- **Gist**：如果我们没有项目可以开源或者只是单纯的想分享一些代码片段的话，我们就可以选择Gist。不过说心里话，如果不翻墙的话，Gist并不好用。

## Git详解

> git与github：git是本地仓库，使用`.git`目录管理版本信息；github为远端仓库，两个仓库是**相似、独立**的，可以通过**push、pull**同步仓库。

### git命令

**命令使用**：在我们使用的git操作时，必须在Git仓库目录下，使用`git bush here`打开git。

- `git config`：配置git信息·
  - `--global user.name "[UseName]"`：配置用户名
  - `--global user.email "[EmailAddress]"`：配置邮箱
  - `--list`：查看当前配置
- `git status`：查看仓库状态
- `git init`：初始化仓库，将该目录设置为git仓库
- `git add [File]`：添加文件到git缓冲区
  - `[File]`：支持多个文件(空格间隔)、通配符(`*.txt`)、和目录索引(`.`目录下文件)
- `git commit`：提交，将缓冲区文件提交到git仓库
  - `-m "[CommitInfo]"`，设置提交信息为CommitInfo
  - `-a`：提交所有已修改和已删除的文件，清空工作树
- `git log`：打印当前仓库的提交日志，包含提交信息、作者、时间
- `git branch`：查看分支，当前主分支有“*”标记
  - `git branch [BranchName]`：用于创建BranchName分支
  - `-d [BranchName]`：删除分支；`-D `：强制删除
  - `-m [NewName]`：重命名分支；`- M`：强制重命名，如果分支名已存在则覆盖
- `git checkout [BranchName]`：切换到BranchName分支
  - `-b [BranchName]`：创建并切换到BranchName分支
- `git diff`：展示当前分支和主分支的区别
- `git merge [BranchName]`：合并分支BranchName到当前分支，**注意冲突**
- `git tag`：查看标签记录
  - `git tag [Tag]`：为当前位置添加标签Tag
- `git clone [Url]`：克隆github仓库到本地
- `git push [Remote] [Branch]`：将Branch分支同步到远端仓库
  - `-u`：将分支与远程仓库建立连接，设置默认`push pull`操作的对象
- `git pull [Remote] [Branch]`：将远端仓库同步到Branch分支
  - 一般远端仓库命名为`origin`
- **向远程仓库提交代码的时候，一定要先进行pull操作，再进行push操作，避免出现冲突**

### SSH通信

> SSH是一种加密的网络传输协议，可在不安全的网络中为网络服务提供安全的传输环境。通过在网络中创建安全隧道来实现SSH客户端与服务器之间的连接。

#### 生成SSH密钥并添加到github

- 检查/安装ssh：在任意命令行界面，执行`ssh`命令，查看是否安装ssh；
- 生成密钥&公钥：在git bash中，执行`ssh-keygen -t PasswordForm -C "EmailAddress"`，根据提示完成密码生成操作即可；
  - `-t PasswordForm`：选择密码类型；
  - `-C ""`：密码注释，一般选择邮箱地址；
  - 生成文件有两个：密钥(id_PasswordForm)/公钥(id_PasswordForm.pub)，默认存放在`C:/user/.ssh`目录下；
- 添加公钥到github：复制公钥内容，在github主页，点击“Setting->SSH and GPG keys->New SSH key”，根据提示完成添加即可；
- 检查连接：执行`ssh -T git@github.com`，检查连接是否成功。

#### 通信(git与github交互)

- 复制：复制ssh链接，使用clone命令，在本地生成一个与github相同的git仓库，两个仓库自动建立连接；
  - 注意：在当前目录下执行clone命令，clone生成仓库是子目录，当前目录不会变成仓库
- 同步：本地已有git，使用`push`命令，将本地仓库与github仓库同步
- ```r
  git remote add origin git@github.com:WillanSnow/Learn4work.git
  # 添加新github仓库为远程仓库
  git branch -M main
  # 强制重命名分支为main
  git push -u origin main
  # 推送本地git到github，并建立连接
  ```
  *本地git提交到github新仓库*


### **git bash**快捷键
