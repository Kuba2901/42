# DISCLAIMER: ONLY WORKS ON OSX
include .env
export

IMG_NAME = ${IMAGE_LABEL}
CREATE_IMAGE = docker build -t $(IMG_NAME) .
MOUNT_VOL =  -v /tmp/.X11-unix:/tmp/.X11-unix
DISPLAY_WIRELESS = -e DISPLAY=192.168.1.101:0 # $(shell ipconfig getifaddr en0):0
DISPLAY_WIRED = -e DISPLAY=$(shell ipconfig getifaddr en1):0
RUN_FLAGS = -it --rm
INFO_SCRIPT=./.get_info.sh
NET_IS_WIRELESS = $(shell ipconfig getifaddr en0 | wc -l | tr -d ' ')
NET_IS_WIRED = $(shell ipconfig getifaddr en1 | wc -l | tr -d ' ')
IMG_EXISTS = $(shell $(INFO_SCRIPT) | grep "Image exists: " | )

print_info:
	@echo "Getting info!"
	@echo $(IMG_EXISTS)

run_preconf:
	@echo "Running preconf"
	xhost +

run_wired:
	make run_preconf
	@echo "Running wired"
	open -a Xquartz
	docker run $(RUN_FLAGS) $(DISPLAY_WIRED) $(MOUNT_VOL) $(IMG_NAME)

run_wireless:
	make run_preconf
	@echo Running SO_LONG Game
	open -a Xquartz
	docker run $(RUN_FLAGS) $(DISPLAY_WIRELESS) $(MOUNT_VOL) $(IMG_NAME)

configure:
	@echo "Starting configuration..."
	@echo "Creating container image..."
	$(CREATE_IMAGE)
	@echo "Container image created!"

uninstall:
	@echo "Removing containers..."
	docker ps -a --filter "ancestor=$(IMG_NAME)" -q | xargs docker rm
	@echo "Removing the image..."
	docker rmi $(IMG_NAME)

reinstall:
	@echo "Reinstalling the app"
	@echo "Uninstalling everything"
	make uninstall
	@echo "Configuring the image"
	make configure
	@echo "Running"
