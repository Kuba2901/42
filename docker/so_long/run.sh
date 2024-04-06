#!/bin/bash
# Display configuration
DISPLAY_WIRELESS=$(ipconfig getifaddr en0 | wc -l | tr -d ' ')
DISPLAY_WIRED=$(ipconfig getifaddr en1 | wc -l | tr -d ' ')
DISPLAY_TYPE=none

if [ $DISPLAY_WIRELESS -gt 0 ]; then \
	DISPLAY_TYPE=wireless
elif [ $DISPLAY_WIRED -gt 0 ]; then \
	DISPLAY_TYPE="wired"
else \
	echo "No display attached..."
	echo "You have to be connected to a network"
	echo "Exiting"
	exit 
fi

echo "NETWORK CHECK PASSED!"

# Image exists
IMG_COUNT=$(docker image list -a --filter "reference=so_long" -q | wc -l | tr -d ' ')

if [ $IMG_COUNT -gt 0 ]; then \
	echo "An image already exists"
	echo "Would you like to rebuild or run from the existing image?"
	select option in "Rebuild" "Use existing image"; do
    case $REPLY in
        1)
            echo "Rebuilding the image..."
            make reinstall
            break
            ;;
        2)
            echo "Using the existing image."
            break
            ;;
        *)
            echo "Invalid option. Please select 1 to rebuild or 2 to use the existing image."
            ;;
    esac
done

else \
	echo "Image doesn't exist"
	echo "Creating a new one..."
	make configure
	echo "Image created!"
fi

# Running a container
if [ $DISPLAY_TYPE = "wireless" ]; then \
	make run_wireless
elif [ $DISPLAY_TYPE = "wired" ]; then \
	make run_wired
fi

echo "enjoy"
