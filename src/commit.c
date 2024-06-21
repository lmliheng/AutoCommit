#include<stdio.h>
#include <time.h>
#include<string.h>
#include<stdlib.h>

int main() {
    // 获取当前时间
    time_t rawtime;
    struct tm *timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);

    // 创建或打开 log/commit_log 文件
    FILE *file = fopen("/root/c/AutoCommit_push/log/commit.log", "a");
    if (file == NULL) {
        printf("无法打开日志文件！\n");
        return 1;
    }

    // 向文件中写入当前时间
    fprintf(file, "提交时间: %s\n", buffer);  // 提交可能失败

    // 关闭文件
    fclose(file);

    printf("日志已经写入 /root/c/AutoCommit_push/log/commit.log\n");



    system("rm -rf /root/c/AutoCommit_push/AutoCommit");

    printf("删除拉取目录结束\n");


    system("bash /root/c/AutoCommit_push/clone.sh");

    printf("成功拉取新目录\n");



    system("yes | cp -rf /root/c/AutoCommit_push/AutoCommit/.git .");

    printf("成功复制git历史提交记录\n");
    
    system("git remote set-url origin git@github.com:lmliheng/AutoCommit.git");



    system("bash /root/c/AutoCommit_push/push.sh");



    return 0;
}