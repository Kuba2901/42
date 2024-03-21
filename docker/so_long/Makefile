# DISCLAIMER: ONLY WORKS ON OSX

IMAGE_NAME = so_long_gui
CREATE_IMAGE = docker build -t $(IMAGE_NAME) .
MOUNT_VOL =  -v /tmp/.X11-unix:/tmp/.X11-unix
# DISPLAY_NAME = -e DISPLAY=$$HOSTNAME:0
DISPLAY_WIRELESS = -e DISPLAY=$(shell ipconfig getifaddr en0):0
DISPLAY_WIRED = -e DISPLAY=$(shell ipconfig getifaddr en1):0
RUN_FLAGS = -it --rm

run_wired:
	@echo "Running wired"
	open -a Xquartz
	docker run $(RUN_FLAGS) $(DISPLAY_WIRED) $(MOUNT_VOL) $(IMAGE_NAME)

run_wireless:
	@echo Running SO_LONG Game
	open -a Xquartz
	docker run $(RUN_FLAGS) $(DISPLAY_WIRELESS) $(MOUNT_VOL) $(IMAGE_NAME)

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

reinstall:
	@echo "Reinstalling the app"
	@echo "Uninstalling everything"
	make uninstall
	@echo "Configuring the image"
	make configure
	@echo "Running"
	make run
