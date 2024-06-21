#!/bin/sh


# 仓库URL
REPO_URL="https://github.com/lmliheng/AutoCommit.git"

# 执行git clone并捕获输出
if git clone "$REPO_URL"; then
    echo "仓库克隆成功！"
else
    echo "克隆仓库失败，请检查URL或网络连接。"
    exit 1
fi
