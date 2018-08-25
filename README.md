# YSCProject
Yellow smart car project

YSC-001 目标：
1. Car可进行前，后，左，右，作运动控制。由Arduino实施控制。
2. Car可连入家庭局域网，由手机客户端登录网页进行控制。由Raspberry Pi实施。
3. Car连入家庭局域网后，可有PC机通过GUI程序控制。
4. 运动时，实时测量car与前端障碍物的距离，如果距离太近，能智能报警，同时减速或停止运动。报警用蜂鸣器实现。
5. Car上安装摄像头，可通过PC机的GUI界面实时获取图像，同时可以抓拍图片，并保存到电脑本地。
6. 可控制YSC将相关数据以邮件的形式发送出去。

YSC-002 目标：
1. 电机部分：将普通电机替换为步进电机，同时带有反馈，可以通过算法精准控制。普通电机不是不行，而是很难，精度不高。
2. 摄像头部分：在可返回参数的舵机上装摄像头，物体识别分传统方法和深度学习方法，传统方法就是用opencv建模欧阳用的，深度学习方法分两步，一步是cnn处理图像，rnn处理控制算法。
3. 树莓派可当热点，直接作为服务器，可解决只能在一个wifi下的问题。
4. 树莓派与Arduino的通信模块pySerial

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

### Hardware shot

<p align="center">
  <img src="https://github.com/SailCPU/YSCProject/blob/master/Hardware/YSCar-001.jpg" alt="Screenshot"/>
</p>

