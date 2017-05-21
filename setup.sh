# manual install for chrome, ide, sublime
sudo apt install vim
echo "syntax on\ncolorscheme desert" > ~/.vimrc
sudo apt install zsh
sudo apt install curl
sh -c "$(curl -fsSL https://raw.githubusercontent.com/robbyrussell/oh-my-zsh/master/tools/install.sh)"
sudo apt-get install -y terminator

#ssh keygen
ssh-keygen -t rsa -b 4096 -C agsoton.vilmos@gmail.com
cat .ssh/id_rsa.pub 
# copy that to places, or overvrite .ssh 

# install docker 
sudo apt-get install -y linux-image-extra-$(uname -r) linux-image-extra-virtual && \
sudo apt-get install -y apt-transport-https ca-certificates software-properties-common && \
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add - && \
sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable" && \
sudo apt-get update && \
sudo apt-get install -y docker-ce && \
sudo usermod -aG docker $USER



sudo apt-key adv --keyserver hkp://p80.pool.sks-keyservers.net:80 --recv-keys 58118E89F3A912897C070ADBF76221572C52609D && \
sudo apt-add-repository 'deb https://apt.dockerproject.org/repo ubuntu-xenial main' && \
sudo apt-get update && \
apt-cache policy docker-engine && \
sudo apt-get install -y docker-engine && \
sudo systemctl status docker && \
sudo usermod -aG docker $(whoami)
# logout, login

openssl genrsa -aes256 -out ca-key.pem 4096
openssl req -new -x509 -days 365 -key ca-key.pem -sha256 -out ca.pem
openssl genrsa -out server-key.pem 4096
openssl req -subj "/CN=$HOST" -sha256 -new -key server-key.pem -out server.csr
echo subjectAltName = DNS:$HOST,IP:127.0.0.1 > extfile.cnf
openssl x509 -req -days 365 -sha256 -in server.csr -CA ca.pem -CAkey ca-key.pem \
  -CAcreateserial -out server-cert.pem -extfile extfile.cnf
openssl genrsa -out key.pem 4096
openssl req -subj '/CN=client' -new -key key.pem -out client.csr
echo extendedKeyUsage = clientAuth > extfile.cnf
openssl x509 -req -days 365 -sha256 -in client.csr -CA ca.pem -CAkey ca-key.pem \
  -CAcreateserial -out cert.pem -extfile extfile.cnf
rm -v client.csr server.csr
chmod -v 0400 ca-key.pem key.pem server-key.pem
chmod -v 0444 ca.pem server-cert.pem cert.pem
mkdir -pv ~/.docker
cp -v {ca,cert,key}.pem ~/.docker
sudo chown root:root ca.pem server-cert.pem cert.pem 
sudo mkdir /etc/docker/tls
sudo mv ca.pem server-cert.pem cert.pem server-key.pem /etc/docker/tls
mv key.pem ca.srl ca-key.pem .docker
# edit /lib/systemd/system/docker.service
# replace ExecStart=/usr/bin/dockerd -H fd://
# with ExecStart=/usr/bin/dockerd --tlsverify --tlscacert=/etc/docke/tls/ca.pem --tlscert=/etc/docke/tls/server-cert.pem --tlskey=/etc/docke/tls/server-key.pem -H=0.0.0.0:2376 -H fd://
systemctl daemon-reload
sudo service docker restart

