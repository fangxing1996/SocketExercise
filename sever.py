import os
import socket # 导入 socket 模块 
import time 
s = socket.socket() # 创建 socket 对象  
host = socket.gethostname() # 获取本地主机名
port = 12344 # 设置端口
s.bind((host, port)) # 绑定端口 
s.listen(5) # 等待客户端连接 
c, addr = s.accept() # 建立客户端连接。
# c.setblocking(True) 
while True: 
    #print("wating for client input") 
    data = c.recv(1024) 
    data = str(data,'utf-8') 
    print(data) 
    if data == '88': 
        c.close() 
        break 
        print("client closed connection") 
else:
    s.close()
