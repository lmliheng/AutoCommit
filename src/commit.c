#include<stdio.h>
#include <time.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>

void execute_command(const char *command) {
    pid_t pid = fork();

    if (pid == 0) { // 子进程
        execl("/bin/sh", "sh", "-c", command, NULL);
        perror("execl");
        exit(EXIT_FAILURE);
    } else if (pid < 0) { // fork 失败
        perror("fork");
        exit(EXIT_FAILURE);
    }
}

int main() {
    // 获取当前时间
    time_t rawtime;
    struct tm *timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);

    // 创建或打开 log/commit_log 文件
    FILE *file = fopen("/root/c/AutoCommit_push/log/commit.log\n", "a");
    if (file == NULL) {
        printf("无法打开日志文件！\n");
        return 1;
    }

    // 向文件中写入当前时间
    fprintf(file, "提交时间: %s\n", buffer);

    // 关闭文件
    fclose(file);

    pid_t child_pid;
    int status;

    child_pid = fork();
    if (child_pid == 0) {
        execute_command("rm -rf /root/c/AutoCommit_push/AutoCommit");
        exit(EXIT_SUCCESS);
    } else {
        waitpid(child_pid, &status, 0);
        printf("删除拉取目录一次结束\n");
    }

    printf("日志已经写入 /root/c/AutoCommit_push/log/commit.log\n");

    printf("删除拉取目录结束\n");

    child_pid = fork();
    if (child_pid == 0) {
        execute_command("bash /root/c/AutoCommit_push/clone.sh");
        exit(EXIT_SUCCESS);
    } else {
        waitpid(child_pid, &status, 0);
        printf("成功拉取新目录\n");
    }

    sleep(5);

    child_pid = fork();
    if (child_pid == 0) {
        execute_command("yes | cp -rf /root/c/AutoCommit_push/AutoCommit/.git .");
        exit(EXIT_SUCCESS);
    } else {
        waitpid(child_pid, &status, 0);
        printf("成功复制git历史提交记录\n");
    }

    child_pid = fork();
    if (child_pid == 0) {
        execute_command("git remote set-url origin git@github.com:lmliheng/AutoCommit.git");
        exit(EXIT_SUCCESS);
    } else {
        waitpid(child_pid, &status, 0);
    }

    child_pid = fork();
    if (child_pid == 0) {
        execute_command("bash /root/c/AutoCommit_push/push.sh");
        exit(EXIT_SUCCESS);
    } else {
        waitpid(child_pid, &status, 0);
    }

    child_pid = fork();
    if (child_pid == 0) {
        execute_command("rm -rf /root/c/AutoCommit_push/AutoCommit");
        exit(EXIT_SUCCESS);
    } else {
        waitpid(child_pid, &status, 0);
        printf("删除拉取目录二次结束\n");
    }

    return 0;
}