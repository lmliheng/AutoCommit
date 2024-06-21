#!/bin/sh

REASON="自动签到提交代码"
branchName=$(git rev-parse --abbrev-ref HEAD)
git add .
git commit -m "$REASON"
git pull origin "$branchName"
git push origin "$branchName"

exit 0 # 添加此行以确保脚本在执行完毕后退出
