IMAGE_LABEL=42_testing
IMG_NAME = ${IMAGE_LABEL}
CREATE_IMAGE = docker build -t $(IMG_NAME) .
IMG_EXISTS = $(shell $(INFO_SCRIPT) | grep "Image exists: " | )

print_info:
	@echo "Getting info!"
	@echo $(IMG_EXISTS)

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