#!/usr/bin/env bash
REASON="自动签到提交代码"
branchName=$(git rev-parse --abbrev-ref HEAD)
git add .
git commit -m "$REASON"
git pull origin "$branchName"
git push origin "$branchName"

echo "提交结束..."
