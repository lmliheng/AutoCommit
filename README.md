# AutoCommit
🌟 Github自动签到仓库 🌟

## 简介🥇
这是一个使用C语言编写的简单程序，用于自动在GitHub仓库上进行提交。通过定时任务，您可以每隔一段时间自动运行此程序，从而实现自动签到的效果。

## 使用方法🚡
Fork本仓库：点击页面右上角的`Fork"`按钮，将本仓库复制到您的GitHub帐户

克隆`fork`仓库至`Linux`服务器：在Linux服务器上，使用以下命令克隆您刚刚fork的仓库：
```bash
git clone https://github.com/your_username/AutoCommit.git
```
将`your_username`替换为您的`GitHub`用户名。

✈️修改C代码中的仓库URL：打开`src/commit.c`文件和`clone.sh`，将所有`URL`更改为您fork的仓库URL。

编译程序：在项目根目录中运行以下命令以编译程序：
```bash
make
```
运行程序：运行生成的可执行文件：
```bash
./commit
```
如果一切正常，程序将成功提交更改

设置定时任务：运行crontab -e以编辑当前用户的cron表。添加以下行以每隔三小时运行一次程序：
```bash
0 */3 * * * /path/to/your/executable
```
将/path/to/your/executable替换为实际的./commit可执行文件路径。

查看定时任务运行日志` cat /var/spool/mail/root`
## 参考🚡
关于crontab的详细信息，请参考这篇[教程](http://linux.liheng.work/c/crontab.html)
## 协议💐
本项目采用`Apache 2.0`协议进行许可。
