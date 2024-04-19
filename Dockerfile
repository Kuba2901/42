FROM debian:stable-20240311

# Installing necessary dependencies
RUN apt update && apt-get install -y \
	xorg \
	libxext-dev \
	zlib1g-dev \
	libbsd-dev \
	git \
	build-essential \
	x11-apps

# Clone the so_long directory
RUN git clone https://github.com/Kuba2901/42.git 42_cursus

WORKDIR /42_cursus

