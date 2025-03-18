# 常见命令与应用

# 环境变量

linux环境变量结构：
- 系统级变量
  - `etc/environment`：所有进程
  - `etc/profile`：所有用户
- 用户级变量
  - `~/.profile`：当前用户
  - `~/.bashrc`：当前bash

常用环境变量：
```
PATH：可执行文件搜索路径；
HOME：指定当前用户的主目录路径；
USER：当前用户名；
SHELL：当前用户默认的shell；
LANG：指定系统的默认语言；
LD_LIBRARY_PATH：指定系统在哪些目录查找共享文件；
TERM：指定当前终端的类型；
```

## 环境变量相关命令

```shell
env 或 printenv：查看当前用户所有环境变量
echo $VALUENAME：查看指定环境变量值；
which：查看PATH中可执行文件的路径；

export VALUENAME = ...:$VALUENAME
```

# 文件权限修改

```shell
# 赋予文件可执行权限
chmod 777 <file>
```