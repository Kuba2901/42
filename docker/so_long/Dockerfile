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

# Set environment variable for X11 forwarding
ENV DISPLAY=:0

# Clone the so_long directory
RUN git clone https://github.com/Kuba2901/42.git

RUN mv 42/so_long .
RUN rm -rf 42

# Set the working directory
WORKDIR /so_long

# Configure the MLX
RUN git clone https://github.com/42Paris/minilibx-linux.git mlx_linux
RUN cd mlx_linux && ./configure

RUN make clean_rebuild

# Run the app
CMD ["./so_long", "assets/maps/map_correct.ber"]