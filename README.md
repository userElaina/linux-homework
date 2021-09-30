[toc]
##### set proxy
```sh
export http_proxy="http://127.0.0.1:18081"
export https_proxy="http://127.0.0.1:18081"
```

##### apt
```sh
apt update
apt install unzip
apt install screen
apt install python3
apt install python3-pip
```

##### scp (when ssh)
```sh
scp "C:\All\Sakura\Mili\PY\py2o\py_userelaina\requirements.txt"  root@:~/
scp "C:\All\Sakura\Mili\html\1.html" root@:/www/index.html
scp "C:\All\Sakura\Mili\html\2.html" root@:/www/story.html
```

##### python3
```sh
pip3 install --upgrade pip
python3 -m pip install --upgrade pip
python3 -m pip install --upgrade -r requirement.txt
```

##### ASF
```sh
echo "ASF"
mkdir ASF
cd ASF
apt install libunwind8 libunwind8-dev gettext libicu-dev liblttng-ust-dev libcurl4-openssl-dev libssl-dev uuid-dev
curl https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > microsoft.gpg
mv microsoft.gpg /etc/apt/trusted.gpg.d/microsoft.gpg
sh -c 'echo "deb [arch=amd64] https://packages.microsoft.com/repos/microsoft-ubuntu-xenial-prod xenial main" > /etc/apt/sources.list.d/dotnetdev.list'
apt install apt-transport-https

mkdir old
wget https://packages.microsoft.com/config/ubuntu/20.04/packages-microsoft-prod.deb -O pmp.deb
dpkg -i pmp.deb
apt update; \
	apt install -y apt-transport-https && \
	apt update && \
	apt install -y dotnet-sdk-5.0
apt update; \
	apt install -y apt-transport-https && \
	apt update && \
	apt install -y aspnetcore-runtime-5.0
mv pmp.deb ./old/

wget https://packages.microsoft.com/ubuntu/20.04/prod/pool/main/d/dotnet-runtime-2.1/dotnet-runtime-2.1.23-x64.deb -O dr2.deb
dpkg -i dr2.deb
mv dr2.deb ./old/

mkdir mian
cd mian
wget https://github.com/JustArchi/ArchiSteamFarm/releases/download/3.1.1.1/ASF-generic.zip -O asf1.zip
unzip asf1.zip
mv asf1.zip ../old/asf1.zip

chmod +x ArchiSteamFarm.sh

screen -S asf
./ArchiSteamFarm.sh
#Ctrl+(A,D)
scp "C:\All\Sakura\Mili\PY\YaeSakura.json" root@39.102.76.82:~/asf/mian/config/
```

##### tar
```sh
tar zxvf 1.tar.gz
```

##### nginx 静态网页
```sh
apt install nginx
cd ../etc/nginx/sites-available/
#default
cd ../
ps aux
chown www-data:www-data -R www
sevice nginx reload
```

```php
//default
server {
        listen 80 default_server;
        listen [::]:80 default_server;
        root /www;
        index index.html;
        server_name _;
}
```
