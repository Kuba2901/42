IMAGE_NAME = so_long_gui
CREATE_IMAGE = docker build -t $(IMAGE_NAME) .
UPDATED_PATH := /opt/X11/bin:${PATH}
MOUNT_VOL =  -v /tmp/.X11-unix:/tmp/.X11-unix
DISPLAY_NAME = -e DISPLAY=$$HOSTNAME:0
RUN_FLAGS = -it --rm 

run:
	open -a Xquartz
	xhost + ${hostname} \
	&& export HOSTNAME=`hostname` \
	&& docker run $(RUN_FLAGS) $(DISPLAY_NAME) $(MOUNT_VOL) $(IMAGE_NAME)

configure:
	@echo "Starting configuration..."
	@echo "Creating container image..."
	$(CREATE_IMAGE)
	@echo "Container image created!"

uninstall:
	@echo "Removing containers..."
	docker ps -a --filter "ancestor=so_long_gui" -q | xargs docker rm
	@echo "Removing the image..."
	docker rmi $(IMAGE_NAME)
