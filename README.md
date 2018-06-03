# YSCProject
Yellow smart car project

YSC-001 目标：
1. Car可进行前，后，左，右，作运动控制。由Arduino实施控制。
2. Car可连入家庭局域网，由手机客户端登录网页进行控制。由Raspberry Pi实施。
3. Car连入家庭局域网后，可有PC机通过GUI程序控制。
4. 运动时，实时测量car与前端障碍物的距离，如果距离太近，能智能报警，同时减速或停止运动。报警用蜂鸣器实现。
5. Car上安装摄像头，可通过PC机的GUI界面实时获取图像，同时可以抓拍图片，并保存到电脑本地。
6. 可控制YSC将相关数据以邮件的形式发送出去。

主要硬件清单：
1. Yellow Car
2. Arduino
3. Raspberry Pi
4. Pi Cam
5. 蜂鸣器，超声波模块

软件模块：
1. Driver为 YSC的驱动部分，主要是运动控制，io模块的控制。（硬件平台 Arduino）
2. Server为IoT module (硬件平台：Raspberry Pi)
3. Web Client (Mobile phone or PC)
4. PC GUI （PC）


