FROM debian:latest

RUN apt-get update && \
    apt-get install -y \
        build-essential \
        valgrind \
		git \
        gdb \
		# neovim \
        && rm -rf /var/lib/apt/lists/*

# RUN git clone https://github.com/NvChad/starter ~/.config/nvim

WORKDIR /app

COPY . .

# CMD [ "nvim" ]