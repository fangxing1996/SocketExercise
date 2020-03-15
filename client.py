import socket # 导入 socket 模块 
s = socket.socket() # 创建 socket 对象 
#print(s)
host = socket.gethostname() # 获取本地主机名 
print(host)
port = 12344 # 设置端口号 
s.connect((host, port)) 
print("connected to server") 
while(True): 
    data = input() 
    s.send(bytes(data,'utf-8')) 
    if data == '88': 
        s.close() 
        break
