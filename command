ssh-keygen -t rsa -b 4096 -C "parkerschmeits@gmail.com"
ssh-agent
eval $(ssh-agent -s)
ssh-add ~/.ssh/id_rsa
echo "$SSH_AUTH_SOCK"
ssh -T git@github.com