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

# Running a container
if [ $DISPLAY_TYPE = "wireless" ]; then \
	cd ../so_long && make run_wireless
elif [ $DISPLAY_TYPE = "wired" ]; then \
	cd ../so_long && make run_wireless
fi

echo "Enjoy"
