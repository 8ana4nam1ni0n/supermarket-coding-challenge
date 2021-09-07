# Install ubuntu bionic
FROM ubuntu:bionic

# Update apt-get package manager
# Install essential libraries for development setup
RUN apt-get update && apt-get install build-essential curl wget locales git vim tmux zsh powerline zsh-syntax-highlighting -y && \
    sh -c "$(wget https://raw.githubusercontent.com/robbyrussell/oh-my-zsh/master/tools/install.sh -O -)" && \
    echo "source /usr/share/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh" >> ~/.zshrc && \
    git clone https://github.com/bhilburn/powerlevel9k.git ~/.oh-my-zsh/custom/themes/powerlevel9k && \
    curl -fLo ~/.vim/autoload/plug.vim --create-dirs https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim && \
    mkdir ~/.vim/plugged && \
    git clone https://github.com/powerline/fonts.git --depth=1 && \
    ./fonts/install.sh && \
    rm -rf fonts && \
    mkdir ~/.config && mkdir ~/.config/fontconfig && mkdir ~/.config/fontconfig/config.d ~/.font && \ 
    wget https://raw.githubusercontent.com/powerline/fonts/master/fontconfig/50-enable-terminess-powerline.conf && \
    mv 50-enable-terminess-powerline.conf ~/.config/fontconfig/config.d/ && \
    fc-cache -vf && \
    sed -i -e 's/# en_US.UTF-8 UTF-8/en_US.UTF-8 UTF-8/' /etc/locale.gen && \
    dpkg-reconfigure --frontend=noninteractive locales && \
    update-locale LANG=en_US.UTF-8 && \ 
    update-locale LC_CTYPE=en_US.UTF-8 && \
    sed -i '1s;^;export TERM="xterm-256color"\n;' ~/.zshrc && \
    sed -i -e 's/ZSH_THEME="robbyrussell"/ZSH_THEME="powerlevel9k\/powerlevel9k"/' ~/.zshrc 

ENV SHELL /bin/zsh
ENV LANG en_US.UTF-8
ENTRYPOINT /bin/zsh
