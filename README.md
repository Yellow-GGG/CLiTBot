# CLiTBot

本仓库是北京某高校2022-2023学年秋季学期wyp老师的《程序设计基础》课程的小组作业项目。

本次小组作业项目名为“CLiTBot”，期望能够实现一个类似于机器人点灯的小游戏。项目的具体内容还处在开发过程当中，敬请期待！

---

### 编译指导

目前我们采用CMake实现跨平台构建方案，其中使用到了外部库[raylib](https://github.com/raysan5/raylib)实现图形绘制，同时使用pkg-config进行库管理。在开始构建项目前需要首先安装上述依赖，此后在此项目文件夹中打开命令行，依次输入：

```
mkdir build
cd build && cmake ..
make
```

由此即可完成项目构建。

此外，本项目的release页面也有macOS版本的预编译程序可供下载游玩（ARM64架构）。

### 备注

本游戏中的地图绘制功能采用.bmp格式输出且未经压缩，占用存储较大，不建议在游戏过程中频繁使用。这项功能更多仅用作测试用途。